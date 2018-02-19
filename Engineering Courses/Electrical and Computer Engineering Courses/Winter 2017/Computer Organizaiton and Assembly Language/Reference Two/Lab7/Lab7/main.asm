;***********************************************************
;*
;* main.asm
;*
;* Speed-adjustable fast PWM lab
;*
;***********************************************************
;*
;* Author: Jack Neff, Rhea Mae Edwards
;* Date: February 28th, 2017
;*
;***********************************************************
 
.include "m128def.inc" ; Include definition file
 
;***********************************************************
;* Internal Register Definitions and Constants
;***********************************************************

.def	mpr = r16 ; Multipurpose register
.def	speedr = r17 ; Holds the value to be put into OCR registers
.def	step = r18	; Hold the value by which we increment speed (17)
.def	speedlevel = r19 ; Hold the binary value of the speed (0-15)

.equ	Wskr0 = 0
.equ	Wskr1 = 1
.equ	Wskr2 = 2
.equ	Wskr3 = 3
.equ	EngEnR = 4 ; Right Engine Enable Bit
.equ	EngEnL = 7 ; Left Engine Enable Bit
.equ	EngDirR = 5 ; Right Engine Direction Bit
.equ	EngDirL = 6 ; Left Engine Direction Bit
.equ	GoFwd = (1<<EngDirR|1<<EngDirL)

;***********************************************************
;* Start of Code Segment
;***********************************************************

.cseg	; Beginning of code segment
 
;***********************************************************
;* Interrupt Vectors
;***********************************************************

.org $0000
	rjmp INIT ; Reset interrupt

.org $0002
	rcall spdinc
	reti

.org $0004
	rcall spddec
	reti

.org $0006
	rcall maxspd
	reti

.org $0008
	rcall minspd
	reti

; Place instructions in interrupt vectors here, if needed

.org $0046
 
;***********************************************************
;* Program Initialization
;***********************************************************

INIT:
	; Configure I/O ports
	LDI mpr, low(RAMEND)
	OUT SPL, mpr
	LDI mpr, high(RAMEND)
	OUT SPH, mpr
	
	LDI mpr, $FF
	OUT DDRB, mpr
	LDI mpr, $00
	OUT PORTB, mpr

	LDI mpr, $00
	OUT DDRD, mpr
	LDI mpr, $FF
	OUT PORTD, mpr

	LDI mpr, 0b11111111
	STS EICRA, mpr

	LDI mpr, 0b00001111
	OUT EIMSK, mpr

	LDI mpr, 0b01111001
	OUT TCCR0, mpr
	OUT TCCR2, mpr

	LDI mpr, 255
	OUT OCR0, mpr
	OUT OCR2, mpr

	LDI step, 17

	LDI speedr, 255
	LDI speedlevel, 0

	LDI mpr, GoFwd
	OUT PORTB, mpr

	SEI

	; Initialize the Stack Pointer
	; Configure I/O ports 
	; Configure External Interrupts, if needed
	; Configure 8-bit Timer/Counters
	; No prescaling 
	; Set TekBot to Move Forward (1<<EngDirR|1<<EngDirL)
	; Set initial speed, display on Port B pins 3:0
	; Enable global interrupts (if any are used)
 
;***********************************************************
;* Main Program
;***********************************************************

MAIN:
	; Poll Port D pushbuttons (if needed)

	rjmp	MAIN ; Continue through main

	; If pressed, adjust speed
	; Also, adjust speed indication

;***********************************************************
;* Functions and Subroutines
;***********************************************************

;-----------------------------------------------------------
; Func: maxspd
; Desc: 
;-----------------------------------------------------------

maxspd: 
		LDI speedr, 0
		OUT OCR0, speedr
		OUT OCR2, speedr
		LDI speedlevel, 15
		in mpr, PINB
		andi mpr, 0b11110000
		ori mpr, 15
		out PORTB, mpr
		reti

;-----------------------------------------------------------
; Func: minspd
; Desc: 
;-----------------------------------------------------------

minspd:
		LDI speedr, 255
		OUT OCR0, speedr
		OUT OCR2, speedr
		LDI speedlevel, 0
		in mpr, PINB
		andi mpr, 0b11110000
		ori mpr, 0
		out PORTB, mpr
		reti

;-----------------------------------------------------------
; Func: spddec
; Desc: 
;-----------------------------------------------------------

spddec:
		ldi mpr, 255
		cp speedr, mpr
		breq overflow
		add speedr, step
		out OCR0, speedr
		out OCR2, speedr
		;dec speedlevel
		in mpr, PINB
		andi mpr, 0b11110000
		or mpr, speedlevel
		dec mpr
		dec speedlevel
		out PORTB, mpr

;-----------------------------------------------------------
; Func: spdinc
; Desc: 
;-----------------------------------------------------------

spdinc:
		ldi mpr, 0
		cp speedr, mpr
		breq overflow
		sub speedr, step
		out OCR0, speedr
		out OCR2, speedr
		;inc speedlevel
		in mpr, PINB
		andi mpr, 0b11110000
		or mpr, speedlevel
		inc mpr
		inc speedlevel
		out PORTB, mpr
	
;-----------------------------------------------------------
; Func: overflow
; Desc: 
;-----------------------------------------------------------

overflow:
		
		reti

	; If needed, save variables by pushing to the stack
 
;***********************************************************
;* Stored Program Data
;***********************************************************

	; Enter any stored data you might need here
 
;***********************************************************
;* Additional Program Includes
;***********************************************************

	; There are no additional file includes for this program
