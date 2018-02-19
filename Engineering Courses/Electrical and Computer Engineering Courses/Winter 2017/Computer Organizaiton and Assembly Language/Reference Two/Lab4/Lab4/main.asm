;***********************************************************
;*	File Name:
;*	main.asm
;*	ece375-L4 skeleton.asm
;*
;*	Enter the description of the program here
;*
;*  Prints out two strings on the LCD Display on the AVR Board
;*
;*	This is the skeleton file for Lab 4 of ECE 375
;*
;***********************************************************
;*
;*	 Author: Rhea Mae Edwards, Jackson Neff
;*	   Date: Feburary 7th, 2017
;*
;***********************************************************

.include "m128def.inc"			; Include definition file

;***********************************************************
;*	Internal Register Definitions and Constants
;***********************************************************
.def	mpr = r16				; Multipurpose register is
.def	waitcnt = r17				; Wait Loop Counter
.equ	WTime = 100				; Time to wait in wait loop
								; required for LCD Driver

;***********************************************************
;*	Start of Code Segment
;***********************************************************
.cseg							; Beginning of code segment

;***********************************************************
;*	Interrupt Vectors
;***********************************************************
.org	$0000					; Beginning of IVs
		rjmp INIT				; Reset interrupt

.org	$0046					; End of Interrupt Vectors

;***********************************************************
;*	Program Initialization
;***********************************************************
INIT:							; The initialization routine
		; Initialize Stack Pointer
		LDI   R16, LOW(RAMEND)
		OUT   SPL, R16
		LDI   R16, HIGH(RAMEND)
		OUT   SPH, R16

		; Initialize LCD Display
		rcall   LCDInit
		
		; Move strings from Program Memory to Data Memory
			LDI ZL, low(NAME_STRING_BEG<<1)
			LDI ZH, high(NAME_STRING_BEG<<1)
			LDI YL, low(LCDLn1Addr)
			LDI YH, high(LCDLn1Addr)

		loop:
			LPM		mpr, Z+
			st		Y+, mpr
			CPI		ZL, low(NAME_STRING_END<<1)
			brne	loop
			cpi		ZH, high(NAME_STRING_END<<1)

			LDI	ZL, low(HELLO_STRING_BEG<<1)
			LDI	ZH, high(HELLO_STRING_END<<1)
			LDI	YL, low(LCDLn2Addr)
			LDI	YH, high(LCDLn2Addr)

		loop2:
			LPM		mpr, Z+
			st		Y+, mpr
			CPI		ZL, low(HELLO_STRING_END<<1)
			brne	loop2
			cpi		ZH, high(HELLO_STRING_END<<1)


		; NOTE that there is no RET or RJMP from INIT, this
		; is because the next instruction executed is the
		; first instruction of the main program

;***********************************************************
;*	Main Program
;***********************************************************
MAIN:							; The Main program
		rcall LCDWrite
		
			; Display the strings on the LCD Display
		
		rjmp	MAIN			; jump back to main and create an infinite
								; while loop.  Generally, every main program is an
								; infinite while loop, never let the main program
								; just run off

;***********************************************************
;*	Functions and Subroutines
;***********************************************************

;-----------------------------------------------------------
; Func: Template function header
; Desc: Cut and paste this and fill in the info at the 
;		beginning of your functions
;-----------------------------------------------------------
FUNC:							; Begin a function with a label
		; Save variables by pushing them to the stack

		; Execute the function here
		
		; Restore variables by popping them from the stack,
		; in reverse order

		ret						; End a function with RET

;***********************************************************
;*	Stored Program Data
;***********************************************************

;-----------------------------------------------------------
; An example of storing a string. Note the labels before and
; after the .DB directive; these can help to access the data
;-----------------------------------------------------------
NAME_STRING_BEG:
.DB		"Rhea Mae Edwards "		; Declaring data in ProgMem
NAME_STRING_END:
HELLO_STRING_BEG:
.DB		"Hello World "		; Declaring data in ProgMem
HELLO_STRING_END:

;***********************************************************
;*	Additional Program Includes
;***********************************************************
.include "LCDDriver.asm"		; Include the LCD Driver
