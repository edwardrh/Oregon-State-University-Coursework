;***********************************************************
;*
;*	main.asm
;*
;*	Moves a TekBot forward, but when a right or left whisker
;*	is hit, it will cause it to back up for 1 second, turn
;*	away for 1 second, and then move forward again by using
;*	external interrupts to detect a falling edge on either
;*	of the whisker inputs.
;*
;***********************************************************
;*
;*	 Author: Rhea Mae Edwards, Jackson Neff
;*	   Date: February 21st, 2017
;*
;***********************************************************

.include "m128def.inc"	; Include definition file

;***********************************************************
;*	Internal Register Definitions and Constants
;***********************************************************

.def	mpr = r16	; Multipurpose register
.def	waitcnt = r17

.equ	WskrR = 0	; Right Whisker Input Bit
.equ	WskrL = 1	; Left Whisker Input Bit
.equ	wTime = 100

.def	ilcnt = r18	; Inner Loop Counter
.def	olcnt = r19	; Outer Loop Counter

;***********************************************************
;*	Start of Code Segment
;***********************************************************

.cseg	; Beginning of code segment

;***********************************************************
;*	Interrupt Vectors
;***********************************************************

.org	$0000	; Beginning of IVs
		
		rjmp INIT	; Reset interrupt

		; Set up interrupt vectors for any interrupts being used

		; This is just an example:

.org	$0002	

		rcall	LeftWhiskerHit	; Call function to handle interrupt
		reti	; Return from interrupt

.org	$0004	

		rcall	RightWhiskerHit	; Call function to handle interrupt
		reti	; Return from interrupt

.org	$0046	; End of Interrupt Vectors

;***********************************************************
;*	Program Initialization
;***********************************************************

INIT:	; The initialization routine

	ldi	mpr, low(RAMEND)
	out	SPL, mpr	
	ldi	mpr, high(RAMEND)
	out	SPH, mpr

	; Initialize Stack Pointer

	ldi	mpr, $FF	; Set Port B Data Direction Register
	out	DDRB, mpr	; for output
	ldi	mpr, $00	; Initialize Port B Data Register
	out	PORTB, mpr	; so all Port B outputs are low

	; Initialize Port B for output

	ldi	mpr, $00	; Set Port D Data Direction Register
	out	DDRD, mpr	; for input
	ldi	mpr, $FF	; Initialize Port D Data Register
	out	PORTD, mpr	; so all Port D inputs are Tri-State

	; Initialize Port D for input
	
	; Initialize external interrupts
		; Set the Interrupt Sense Control to falling edge

	ldi mpr, 0b00001010
	sts EICRA, mpr
	ldi mpr, 0b00000011
	out EIMSK, mpr

	; Configure the External Interrupt Mask

	; Turn on interrupts
		; NOTE: This must be the last thing to do in the INIT function

	sei

;***********************************************************
;*	Main Program
;***********************************************************

MAIN:	; The Main program

	ldi mpr, 0b11110000
	out PORTB, mpr
	rjmp	MAIN	
	
	; Create an infinite while loop to signify the
	; end of the program.

;***********************************************************
;*	Functions and Subroutines
;***********************************************************

;-----------------------------------------------------------
; Func: LeftWiskerHit
; Desc: When the left whisker of the TekBot is hit, it will
;		react by backing up for 1 second, turning it away
;		for another second, and continues it by moving 
;		forward again by using external interrupts.
;-----------------------------------------------------------

LeftWhiskerHit:

	push	mpr	; Save mpr register
	push	waitcnt	; Save wait register
	in	mpr, SREG	; Save program state
	push	mpr	;

	; Move Backwards for a second
	
	ldi	mpr, 0b10010000	; Load Move Backward command
	out	PORTB, mpr	; Send command to port
	ldi	waitcnt, WTime	; Wait for 1 second
	rcall	Wait	; Call wait function

	; Turn right for a second

	ldi	mpr, 0b11010000	; Load Turn Left Command
	out	PORTB, mpr	; Send command to port
	ldi	waitcnt, WTime	; Wait for 1 second
	rcall	Wait	; Call wait function

	; Move Forward again

	ldi	mpr, 0b11110000 ; Load Move Forward command
	out	PORTB, mpr	; Send command to port
	pop	mpr	; Restore program state
	out	SREG, mpr	;
	pop	waitcnt	; Restore wait register
	pop	mpr	; Restore mpr

	ret	; Return from subroutine

;-----------------------------------------------------------
; Func: RightWhiskerHit
; Desc: When the right whisker of the TekBot is hit, it will
;		react by backing up for 1 second, turning it away
;		for another second, and continues it by moving 
;		forward again by using external interrupts.
;-----------------------------------------------------------

RightWhiskerHit:

	push	mpr	; Save mpr register
	push	waitcnt	; Save wait register
	in	mpr, SREG	; Save program state
	push	mpr	;

	; Move Backwards for a second

	ldi	mpr, 0b10010000	; Load Move Backward command
	out	PORTB, mpr	; Send command to port
	ldi	waitcnt, WTime	; Wait for 1 second
	rcall	Wait	; Call wait function

	; Turn right for a second

	ldi	mpr, 0b10110000	; Load Turn Left Command
	out	PORTB, mpr	; Send command to port
	ldi	waitcnt, WTime	; Wait for 1 second
	rcall	Wait	; Call wait function

	; Move Forward again

	ldi	mpr, 0b11110000 ; Load Move Forward command
	out	PORTB, mpr	; Send command to port
	pop	mpr	; Restore program state
	out	SREG, mpr	;
	pop	waitcnt	; Restore wait register
	pop	mpr	; Restore mpr
	
	ret	; Return from subroutine

;-----------------------------------------------------------
; Func: Wait
; Desc: It has the TekBot waits, and then clears all queued
;		interrupts.
;-----------------------------------------------------------

Wait:

	push	waitcnt	; Save wait register
	push	ilcnt	; Save ilcnt register
	push	olcnt	; Save olcnt register

	Loop:	ldi	olcnt, 224	; load olcnt register

	OLoop:	ldi	ilcnt, 237	; load ilcnt register

	ILoop:	dec	ilcnt	; decrement ilcnt

	brne	ILoop	; Continue Inner Loop
	dec	olcnt	; decrement olcnt
	brne	OLoop	; Continue Outer Loop
	dec	waitcnt	; Decrement wait
	brne	Loop	; Continue Wait loop
	ldi mpr, (0xff)
	out eifr, mpr	; Clears all interrupts, resetting all interrupts flags
	pop	olcnt	; Restore olcnt register
	pop	ilcnt	; Restore ilcnt register
	pop	waitcnt	; Restore wait register

	ret	; Return from subroutine

;***********************************************************
;*	Stored Program Data
;***********************************************************

; Enter any stored data you might need here

;***********************************************************
;*	Additional Program Includes
;***********************************************************
; There are no additional file includes for this program
