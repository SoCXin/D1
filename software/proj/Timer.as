opt subtitle "HI-TECH Software Omniscient Code Generator (PRO mode) build 10920"

opt pagewidth 120

	opt pm

	processor	16F688
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
	FNCALL	_main,_cleal_sfr
	FNCALL	_main,_clear_ram
	FNCALL	_main,_init_tim0
	FNCALL	_main,_pwm_init
	FNCALL	_main,_pwm_duty
	FNCALL	_pwm_duty,___wmul
	FNCALL	_pwm_duty,___lldiv
	FNROOT	_main
	FNCALL	intlevel1,_XXX
	global	intlevel1
	FNROOT	intlevel1
	global	_pwm_cyc
	global	_temp_duty
	global	_FLAG0
	global	_Timer_500ms_ctr
	global	_Timer_ctr
	global	_count
	global	_IAR
psect	text200,local,class=CODE,delta=2
global __ptext200
__ptext200:
_IAR	set	0
	global	_INTS
_INTS	set	11
	global	_MSR
_MSR	set	4
	global	_PORTA
_PORTA	set	5
	global	_TMR0
_TMR0	set	1
	global	_GIE
_GIE	set	95
	global	_PWM0EN
_PWM0EN	set	210
	global	_PWM0OE
_PWM0OE	set	212
	global	_PWMFS
_PWMFS	set	214
	global	_TIF
_TIF	set	90
	global	_TIS
_TIS	set	93
	global	_TMR0EN
_TMR0EN	set	209
	global	_TMR1ON
_TMR1ON	set	128
	global	_ADINS
_ADINS	set	145
	global	_PAINTR
_PAINTR	set	153
	global	_PBINTR
_PBINTR	set	154
	global	_CPIOD7
_CPIOD7	set	1095
	global	_HTS
_HTS	set	1146
	global	_PSC
_PSC	set	1035
	global	_SCS
_SCS	set	1144
	global	_TCS
_TCS	set	1037
	global	_PRL0L
_PRL0L	set	274
	global	_T1PRLL
_T1PRLL	set	279
	global	_EPR0
_EPR0	set	408
	global	_T1PRLH
_T1PRLH	set	410
	global	_OPT_REG
_OPT_REG	set	129
	global	_OSCCON
_OSCCON	set	143
	file	"Timer.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssBANK0,class=BANK0,space=1
global __pbssBANK0
__pbssBANK0:
_pwm_cyc:
       ds      2

_temp_duty:
       ds      2

_FLAG0:
       ds      1

_Timer_500ms_ctr:
       ds      1

_Timer_ctr:
       ds      1

_count:
       ds      1

; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2
	clrf	((__pbssBANK0)+0)&07Fh
	clrf	((__pbssBANK0)+1)&07Fh
	clrf	((__pbssBANK0)+2)&07Fh
	clrf	((__pbssBANK0)+3)&07Fh
	clrf	((__pbssBANK0)+4)&07Fh
	clrf	((__pbssBANK0)+5)&07Fh
	clrf	((__pbssBANK0)+6)&07Fh
	clrf	((__pbssBANK0)+7)&07Fh
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_cleal_sfr
?_cleal_sfr:	; 0 bytes @ 0x0
	global	?_clear_ram
?_clear_ram:	; 0 bytes @ 0x0
	global	?_pwm_duty
?_pwm_duty:	; 0 bytes @ 0x0
	global	?_init_tim0
?_init_tim0:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?_XXX
?_XXX:	; 0 bytes @ 0x0
	global	??_XXX
??_XXX:	; 0 bytes @ 0x0
	ds	2
	global	??_cleal_sfr
??_cleal_sfr:	; 0 bytes @ 0x2
	global	??_clear_ram
??_clear_ram:	; 0 bytes @ 0x2
	global	??_init_tim0
??_init_tim0:	; 0 bytes @ 0x2
	global	?_pwm_init
?_pwm_init:	; 0 bytes @ 0x2
	global	?___wmul
?___wmul:	; 2 bytes @ 0x2
	global	?___lldiv
?___lldiv:	; 4 bytes @ 0x2
	global	___wmul@multiplier
___wmul@multiplier:	; 2 bytes @ 0x2
	global	pwm_init@Hz
pwm_init@Hz:	; 4 bytes @ 0x2
	global	___lldiv@divisor
___lldiv@divisor:	; 4 bytes @ 0x2
	ds	2
	global	___wmul@multiplicand
___wmul@multiplicand:	; 2 bytes @ 0x4
	ds	2
	global	??_pwm_init
??_pwm_init:	; 0 bytes @ 0x6
	global	??___wmul
??___wmul:	; 0 bytes @ 0x6
	global	___wmul@product
___wmul@product:	; 2 bytes @ 0x6
	global	___lldiv@dividend
___lldiv@dividend:	; 4 bytes @ 0x6
	ds	4
	global	??_pwm_duty
??_pwm_duty:	; 0 bytes @ 0xA
	global	??___lldiv
??___lldiv:	; 0 bytes @ 0xA
	global	pwm_init@buff_hz
pwm_init@buff_hz:	; 2 bytes @ 0xA
	ds	2
	global	??_main
??_main:	; 0 bytes @ 0xC
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	___lldiv@quotient
___lldiv@quotient:	; 4 bytes @ 0x0
	ds	4
	global	___lldiv@counter
___lldiv@counter:	; 1 bytes @ 0x4
	ds	1
	global	pwm_duty@buff
pwm_duty@buff:	; 4 bytes @ 0x5
	ds	4
	global	pwm_duty@ratio
pwm_duty@ratio:	; 1 bytes @ 0x9
	ds	1
	global	pwm_duty@temp
pwm_duty@temp:	; 2 bytes @ 0xA
	ds	2
;;Data sizes: Strings 0, constant 0, data 0, bss 8, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14     12      12
;; BANK0           80     12      20
;; BANK1           80      0       0
;; BANK2           80      0       0

;;
;; Pointer list with targets:

;; ?___wmul	unsigned int  size(1) Largest target is 0
;;
;; ?___lldiv	unsigned long  size(1) Largest target is 0
;;


;;
;; Critical Paths under _main in COMMON
;;
;;   _main->_pwm_init
;;   _pwm_duty->___lldiv
;;
;; Critical Paths under _XXX in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
;;
;;   _main->_pwm_duty
;;   _pwm_duty->___lldiv
;;
;; Critical Paths under _XXX in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _XXX in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _XXX in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0     436
;;                          _cleal_sfr
;;                          _clear_ram
;;                          _init_tim0
;;                           _pwm_init
;;                           _pwm_duty
;; ---------------------------------------------------------------------------------
;; (1) _pwm_duty                                             7     7      0     368
;;                                              5 BANK0      7     7      0
;;                             ___wmul
;;                            ___lldiv
;; ---------------------------------------------------------------------------------
;; (2) ___lldiv                                             13     5      8     162
;;                                              2 COMMON     8     0      8
;;                                              0 BANK0      5     5      0
;; ---------------------------------------------------------------------------------
;; (2) ___wmul                                               6     2      4      92
;;                                              2 COMMON     6     2      4
;; ---------------------------------------------------------------------------------
;; (1) _clear_ram                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _cleal_sfr                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _pwm_init                                            10     6      4      68
;;                                              2 COMMON    10     6      4
;; ---------------------------------------------------------------------------------
;; (1) _init_tim0                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 2
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (3) _XXX                                                  2     2      0       0
;;                                              0 COMMON     2     2      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 3
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _cleal_sfr
;;   _clear_ram
;;   _init_tim0
;;   _pwm_init
;;   _pwm_duty
;;     ___wmul
;;     ___lldiv
;;
;; _XXX (ROOT)
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      C       C       1       85.7%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       2       2        0.0%
;;BANK0               50      C      14       3       25.0%
;;BITBANK1            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK1               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK2            50      0       0       6        0.0%
;;BANK2               50      0       0       7        0.0%
;;ABS                  0      0      20       8        0.0%
;;BITBANK0            50      0       0       9        0.0%
;;DATA                 0      0      22      10        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 143 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 20/0
;;		Unchanged: FFE00/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_cleal_sfr
;;		_clear_ram
;;		_init_tim0
;;		_pwm_init
;;		_pwm_duty
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"main.c"
	line	143
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 5
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	144
	
l4297:	
;main.c: 144: cleal_sfr();
	fcall	_cleal_sfr
	line	145
	
l4299:	
;main.c: 145: clear_ram();
	fcall	_clear_ram
	line	147
	
l4301:	
;main.c: 147: SCS = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1144/8)^080h,(1144)&7
	line	148
	
l4303:	
;main.c: 148: OSCCON = ( 0x50 | (OSCCON & 0x8f) );
	movf	(143)^080h,w
	andlw	08Fh
	iorlw	050h
	movwf	(143)^080h	;volatile
	line	149
;main.c: 149: while(HTS == 0) asm("clrwdt");
	goto	l756
	
l757:	
# 149 "main.c"
clrwdt ;#
psect	maintext
	
l756:	
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	btfss	(1146/8)^080h,(1146)&7
	goto	u381
	goto	u380
u381:
	goto	l757
u380:
	line	152
	
l4305:	
;main.c: 152: init_tim0();
	fcall	_init_tim0
	line	156
;main.c: 156: pwm_init(4000);
	movlw	0
	movwf	(?_pwm_init+3)
	movlw	0
	movwf	(?_pwm_init+2)
	movlw	0Fh
	movwf	(?_pwm_init+1)
	movlw	0A0h
	movwf	(?_pwm_init)

	fcall	_pwm_init
	line	163
	
l4307:	
;main.c: 163: GIE = 1;
	bsf	(95/8),(95)&7
	line	166
	
l4309:	
;main.c: 165: {
;main.c: 166: if(FLAG0.bit_type.b0 == 1)
	bcf	status, 6	;RP1=0, select bank0
	btfss	(_FLAG0),0
	goto	u391
	goto	u390
u391:
	goto	l4309
u390:
	line	168
	
l4311:	
;main.c: 167: {
;main.c: 168: FLAG0.bit_type.b0 = 0;
	bcf	(_FLAG0),0
	line	169
# 169 "main.c"
clrwdt ;#
psect	maintext
	line	170
	
l4313:	
;main.c: 170: PORTA ^= 0x20;
	movlw	(020h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	xorwf	(5),f	;volatile
	line	171
	
l4315:	
;main.c: 171: count ++ ;
	incf	(_count),f
	line	172
;main.c: 172: if(count >= 250)
	movlw	(0FAh)
	subwf	(_count),w
	skipc
	goto	u401
	goto	u400
u401:
	goto	l4309
u400:
	line	174
	
l4317:	
;main.c: 173: {
;main.c: 174: count = 0;
	clrf	(_count)
	line	175
	
l4319:	
;main.c: 175: PORTA ^= 0x10;
	movlw	(010h)
	xorwf	(5),f	;volatile
	line	176
	
l4321:	
;main.c: 176: pwm_duty(60);
	movlw	(03Ch)
	fcall	_pwm_duty
	goto	l4309
	global	start
	ljmp	start
	opt stack 0
psect	maintext
	line	221
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_pwm_duty
psect	text201,local,class=CODE,delta=2
global __ptext201
__ptext201:

;; *************** function _pwm_duty *****************
;; Defined at:
;;		line 97 in file "main.c"
;; Parameters:    Size  Location     Type
;;  ratio           1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  ratio           1    9[BANK0 ] unsigned char 
;;  buff            4    5[BANK0 ] unsigned long 
;;  temp            2   10[BANK0 ] unsigned int 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 60/0
;;		On exit  : 20/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       7       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       7       0       0
;;Total ram usage:        7 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		___wmul
;;		___lldiv
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text201
	file	"main.c"
	line	97
	global	__size_of_pwm_duty
	__size_of_pwm_duty	equ	__end_of_pwm_duty-_pwm_duty
	
_pwm_duty:	
	opt	stack 5
; Regs used in _pwm_duty: [wreg+status,2+status,0+pclath+cstack]
;pwm_duty@ratio stored from wreg
	movwf	(pwm_duty@ratio)
	line	99
	
l4283:	
	line	100
	
l4285:	
;main.c: 100: if(ratio <= 100 && pwm_cyc> 0)
	movlw	(065h)
	subwf	(pwm_duty@ratio),w
	skipnc
	goto	u361
	goto	u360
u361:
	goto	l745
u360:
	
l4287:	
	movf	(_pwm_cyc+1),w
	iorwf	(_pwm_cyc),w
	skipnz
	goto	u371
	goto	u370
u371:
	goto	l745
u370:
	line	102
	
l4289:	
;main.c: 101: {
;main.c: 102: buff = (pwm_cyc + 1)*ratio;
	movf	(_pwm_cyc+1),w
	movwf	(?___wmul+1)
	movf	(_pwm_cyc),w
	movwf	(?___wmul)
	incf	(?___wmul),f
	skipnz
	incf	(?___wmul+1),f
	movf	(pwm_duty@ratio),w
	movwf	0+(?___wmul)+02h
	clrf	1+(?___wmul)+02h
	fcall	___wmul
	movf	(0+(?___wmul)),w
	movwf	(pwm_duty@buff)
	movf	(1+(?___wmul)),w
	movwf	((pwm_duty@buff))+1
	clrf	2+((pwm_duty@buff))
	clrf	3+((pwm_duty@buff))
	line	103
;main.c: 103: temp = (u16)(buff/100) - 1;
	movlw	064h
	movwf	(?___lldiv)
	clrf	(?___lldiv+1)
	clrf	(?___lldiv+2)
	clrf	(?___lldiv+3)

	movf	(pwm_duty@buff+3),w
	movwf	3+(?___lldiv)+04h
	movf	(pwm_duty@buff+2),w
	movwf	2+(?___lldiv)+04h
	movf	(pwm_duty@buff+1),w
	movwf	1+(?___lldiv)+04h
	movf	(pwm_duty@buff),w
	movwf	0+(?___lldiv)+04h

	fcall	___lldiv
	movf	1+(((0+(?___lldiv)))),w
	movwf	(pwm_duty@temp+1)
	movf	0+(((0+(?___lldiv)))),w
	movwf	(pwm_duty@temp)
	
l4291:	
	movlw	low(0FFFFh)
	addwf	(pwm_duty@temp),f
	skipnc
	incf	(pwm_duty@temp+1),f
	movlw	high(0FFFFh)
	addwf	(pwm_duty@temp+1),f
	line	104
	
l4293:	
;main.c: 104: EPR0 = (temp & 0x03ff ) >> 8;
	movf	(pwm_duty@temp+1),w
	andlw	03h
	bsf	status, 5	;RP0=1, select bank3
	bsf	status, 6	;RP1=1, select bank3
	movwf	(408)^0180h	;volatile
	line	105
	
l4295:	
;main.c: 105: PRL0L = (temp & 0x00ff );
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(pwm_duty@temp),w
	bsf	status, 6	;RP1=1, select bank2
	movwf	(274)^0100h	;volatile
	line	107
	
l745:	
	return
	opt stack 0
GLOBAL	__end_of_pwm_duty
	__end_of_pwm_duty:
;; =============== function _pwm_duty ends ============

	signat	_pwm_duty,4216
	global	___lldiv
psect	text202,local,class=CODE,delta=2
global __ptext202
__ptext202:

;; *************** function ___lldiv *****************
;; Defined at:
;;		line 5 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.83\sources\lldiv.c"
;; Parameters:    Size  Location     Type
;;  divisor         4    2[COMMON] unsigned long 
;;  dividend        4    6[COMMON] unsigned long 
;; Auto vars:     Size  Location     Type
;;  quotient        4    0[BANK0 ] unsigned long 
;;  counter         1    4[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  4    2[COMMON] unsigned long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 60/0
;;		On exit  : 60/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         8       0       0       0
;;      Locals:         0       5       0       0
;;      Temps:          0       0       0       0
;;      Totals:         8       5       0       0
;;Total ram usage:       13 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_pwm_duty
;; This function uses a non-reentrant model
;;
psect	text202
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.83\sources\lldiv.c"
	line	5
	global	__size_of___lldiv
	__size_of___lldiv	equ	__end_of___lldiv-___lldiv
	
___lldiv:	
	opt	stack 5
; Regs used in ___lldiv: [wreg+status,2+status,0]
	line	9
	
l4257:	
	clrf	(___lldiv@quotient)
	clrf	(___lldiv@quotient+1)
	clrf	(___lldiv@quotient+2)
	clrf	(___lldiv@quotient+3)
	line	10
	
l4259:	
	movf	(___lldiv@divisor+3),w
	iorwf	(___lldiv@divisor+2),w
	iorwf	(___lldiv@divisor+1),w
	iorwf	(___lldiv@divisor),w
	skipnz
	goto	u321
	goto	u320
u321:
	goto	l4279
u320:
	line	11
	
l4261:	
	clrf	(___lldiv@counter)
	incf	(___lldiv@counter),f
	line	12
	goto	l4265
	line	13
	
l4263:	
	clrc
	rlf	(___lldiv@divisor),f
	rlf	(___lldiv@divisor+1),f
	rlf	(___lldiv@divisor+2),f
	rlf	(___lldiv@divisor+3),f
	line	14
	incf	(___lldiv@counter),f
	line	12
	
l4265:	
	btfss	(___lldiv@divisor+3),(31)&7
	goto	u331
	goto	u330
u331:
	goto	l4263
u330:
	line	17
	
l4267:	
	clrc
	rlf	(___lldiv@quotient),f
	rlf	(___lldiv@quotient+1),f
	rlf	(___lldiv@quotient+2),f
	rlf	(___lldiv@quotient+3),f
	line	18
	
l4269:	
	movf	(___lldiv@divisor+3),w
	subwf	(___lldiv@dividend+3),w
	skipz
	goto	u345
	movf	(___lldiv@divisor+2),w
	subwf	(___lldiv@dividend+2),w
	skipz
	goto	u345
	movf	(___lldiv@divisor+1),w
	subwf	(___lldiv@dividend+1),w
	skipz
	goto	u345
	movf	(___lldiv@divisor),w
	subwf	(___lldiv@dividend),w
u345:
	skipc
	goto	u341
	goto	u340
u341:
	goto	l4275
u340:
	line	19
	
l4271:	
	movf	(___lldiv@divisor),w
	subwf	(___lldiv@dividend),f
	movf	(___lldiv@divisor+1),w
	skipc
	incfsz	(___lldiv@divisor+1),w
	subwf	(___lldiv@dividend+1),f
	movf	(___lldiv@divisor+2),w
	skipc
	incfsz	(___lldiv@divisor+2),w
	subwf	(___lldiv@dividend+2),f
	movf	(___lldiv@divisor+3),w
	skipc
	incfsz	(___lldiv@divisor+3),w
	subwf	(___lldiv@dividend+3),f
	line	20
	
l4273:	
	bsf	(___lldiv@quotient)+(0/8),(0)&7
	line	22
	
l4275:	
	clrc
	rrf	(___lldiv@divisor+3),f
	rrf	(___lldiv@divisor+2),f
	rrf	(___lldiv@divisor+1),f
	rrf	(___lldiv@divisor),f
	line	23
	
l4277:	
	decfsz	(___lldiv@counter),f
	goto	u351
	goto	u350
u351:
	goto	l4267
u350:
	line	25
	
l4279:	
	movf	(___lldiv@quotient+3),w
	movwf	(?___lldiv+3)
	movf	(___lldiv@quotient+2),w
	movwf	(?___lldiv+2)
	movf	(___lldiv@quotient+1),w
	movwf	(?___lldiv+1)
	movf	(___lldiv@quotient),w
	movwf	(?___lldiv)

	line	26
	
l3720:	
	return
	opt stack 0
GLOBAL	__end_of___lldiv
	__end_of___lldiv:
;; =============== function ___lldiv ends ============

	signat	___lldiv,8316
	global	___wmul
psect	text203,local,class=CODE,delta=2
global __ptext203
__ptext203:

;; *************** function ___wmul *****************
;; Defined at:
;;		line 3 in file "C:\Program Files (x86)\HI-TECH Software\PICC\9.83\sources\wmul.c"
;; Parameters:    Size  Location     Type
;;  multiplier      2    2[COMMON] unsigned int 
;;  multiplicand    2    4[COMMON] unsigned int 
;; Auto vars:     Size  Location     Type
;;  product         2    6[COMMON] unsigned int 
;; Return value:  Size  Location     Type
;;                  2    2[COMMON] unsigned int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 60/0
;;		On exit  : 60/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         4       0       0       0
;;      Locals:         2       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         6       0       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_pwm_duty
;; This function uses a non-reentrant model
;;
psect	text203
	file	"C:\Program Files (x86)\HI-TECH Software\PICC\9.83\sources\wmul.c"
	line	3
	global	__size_of___wmul
	__size_of___wmul	equ	__end_of___wmul-___wmul
	
___wmul:	
	opt	stack 5
; Regs used in ___wmul: [wreg+status,2+status,0]
	line	4
	
l4215:	
	clrf	(___wmul@product)
	clrf	(___wmul@product+1)
	line	7
	
l4217:	
	btfss	(___wmul@multiplier),(0)&7
	goto	u261
	goto	u260
u261:
	goto	l4221
u260:
	line	8
	
l4219:	
	movf	(___wmul@multiplicand),w
	addwf	(___wmul@product),f
	skipnc
	incf	(___wmul@product+1),f
	movf	(___wmul@multiplicand+1),w
	addwf	(___wmul@product+1),f
	line	9
	
l4221:	
	clrc
	rlf	(___wmul@multiplicand),f
	rlf	(___wmul@multiplicand+1),f
	line	10
	
l4223:	
	clrc
	rrf	(___wmul@multiplier+1),f
	rrf	(___wmul@multiplier),f
	line	11
	
l4225:	
	movf	((___wmul@multiplier+1)),w
	iorwf	((___wmul@multiplier)),w
	skipz
	goto	u271
	goto	u270
u271:
	goto	l4217
u270:
	line	12
	
l4227:	
	movf	(___wmul@product+1),w
	movwf	(?___wmul+1)
	movf	(___wmul@product),w
	movwf	(?___wmul)
	line	13
	
l3544:	
	return
	opt stack 0
GLOBAL	__end_of___wmul
	__end_of___wmul:
;; =============== function ___wmul ends ============

	signat	___wmul,8314
	global	_clear_ram
psect	text204,local,class=CODE,delta=2
global __ptext204
__ptext204:

;; *************** function _clear_ram *****************
;; Defined at:
;;		line 428 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 17F/20
;;		On exit  : 15F/0
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text204
	file	"main.c"
	line	428
	global	__size_of_clear_ram
	__size_of_clear_ram	equ	__end_of_clear_ram-_clear_ram
	
_clear_ram:	
	opt	stack 6
; Regs used in _clear_ram: [wreg+status,2+status,0]
	line	429
	
l4195:	
;main.c: 429: MSR = 0x20;
	movlw	(020h)
	movwf	(4)	;volatile
	line	430
;main.c: 430: while(MSR <= 0x7f)
	goto	l4201
	line	432
	
l4197:	
;main.c: 431: {
;main.c: 432: IAR = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(0)	;volatile
	line	433
	
l4199:	
;main.c: 433: MSR ++ ;
	incf	(4),f	;volatile
	line	430
	
l4201:	
	movlw	(080h)
	subwf	(4),w	;volatile
	skipc
	goto	u231
	goto	u230
u231:
	goto	l4197
u230:
	line	436
	
l4203:	
;main.c: 434: }
;main.c: 436: MSR = 0xa0;
	movlw	(0A0h)
	movwf	(4)	;volatile
	line	437
;main.c: 437: while(MSR <= 0xef)
	goto	l4209
	line	439
	
l4205:	
;main.c: 438: {
;main.c: 439: IAR = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(0)	;volatile
	line	440
	
l4207:	
;main.c: 440: MSR ++ ;
	incf	(4),f	;volatile
	line	437
	
l4209:	
	movlw	(0F0h)
	subwf	(4),w	;volatile
	skipc
	goto	u241
	goto	u240
u241:
	goto	l4205
u240:
	line	442
	
l830:	
	return
	opt stack 0
GLOBAL	__end_of_clear_ram
	__end_of_clear_ram:
;; =============== function _clear_ram ends ============

	signat	_clear_ram,88
	global	_cleal_sfr
psect	text205,local,class=CODE,delta=2
global __ptext205
__ptext205:

;; *************** function _cleal_sfr *****************
;; Defined at:
;;		line 473 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		status,2
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 17F/20
;;		Unchanged: FFE80/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text205
	file	"main.c"
	line	473
	global	__size_of_cleal_sfr
	__size_of_cleal_sfr	equ	__end_of_cleal_sfr-_cleal_sfr
	
_cleal_sfr:	
	opt	stack 6
; Regs used in _cleal_sfr: [status,2]
	line	474
	
l4193:	
;main.c: 474: INTS = 0x00;
	clrf	(11)	;volatile
	line	475
;main.c: 475: PAINTR= 0x00;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(153)^080h	;volatile
	line	476
;main.c: 476: PBINTR= 0x00;
	clrf	(154)^080h	;volatile
	line	477
;main.c: 477: ADINS = 0x00;
	clrf	(145)^080h	;volatile
	line	479
	
l833:	
	return
	opt stack 0
GLOBAL	__end_of_cleal_sfr
	__end_of_cleal_sfr:
;; =============== function _cleal_sfr ends ============

	signat	_cleal_sfr,88
	global	_pwm_init
psect	text206,local,class=CODE,delta=2
global __ptext206
__ptext206:

;; *************** function _pwm_init *****************
;; Defined at:
;;		line 121 in file "main.c"
;; Parameters:    Size  Location     Type
;;  Hz              4    2[COMMON] unsigned long 
;; Auto vars:     Size  Location     Type
;;  buff_hz         2   10[COMMON] unsigned int 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 60/0
;;		On exit  : 60/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         4       0       0       0
;;      Locals:         2       0       0       0
;;      Temps:          4       0       0       0
;;      Totals:        10       0       0       0
;;Total ram usage:       10 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text206
	file	"main.c"
	line	121
	global	__size_of_pwm_init
	__size_of_pwm_init	equ	__end_of_pwm_init-_pwm_init
	
_pwm_init:	
	opt	stack 6
; Regs used in _pwm_init: [wreg+status,2+status,0]
	line	123
	
l4167:	
	line	125
	
l4169:	
;main.c: 125: PWMFS = 0;
	bcf	(214/8),(214)&7
	line	127
	
l4171:	
;main.c: 127: CPIOD7 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1095/8)^080h,(1095)&7
	line	128
	
l4173:	
;main.c: 128: PWM0OE = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(212/8),(212)&7
	line	129
	
l4175:	
;main.c: 129: PWM0EN = 1;
	bsf	(210/8),(210)&7
	line	130
	
l4177:	
;main.c: 130: if(Hz>4000)
	movlw	0
	subwf	(pwm_init@Hz+3),w
	skipz
	goto	u215
	movlw	0
	subwf	(pwm_init@Hz+2),w
	skipz
	goto	u215
	movlw	0Fh
	subwf	(pwm_init@Hz+1),w
	skipz
	goto	u215
	movlw	0A1h
	subwf	(pwm_init@Hz),w
u215:
	skipc
	goto	u211
	goto	u210
u211:
	goto	l4185
u210:
	line	132
	
l4179:	
;main.c: 131: {
;main.c: 132: buff_hz = (u16)(Hz/16);
	movf	(pwm_init@Hz),w
	movwf	(??_pwm_init+0)+0
	movf	(pwm_init@Hz+1),w
	movwf	((??_pwm_init+0)+0+1)
	movf	(pwm_init@Hz+2),w
	movwf	((??_pwm_init+0)+0+2)
	movf	(pwm_init@Hz+3),w
	movwf	((??_pwm_init+0)+0+3)
	movlw	04h
u225:
	clrc
	rrf	(??_pwm_init+0)+3,f
	rrf	(??_pwm_init+0)+2,f
	rrf	(??_pwm_init+0)+1,f
	rrf	(??_pwm_init+0)+0,f
u220:
	addlw	-1
	skipz
	goto	u225
	movf	1+(??_pwm_init+0)+0,w
	movwf	(pwm_init@buff_hz+1)
	movf	0+(??_pwm_init+0)+0,w
	movwf	(pwm_init@buff_hz)
	line	133
	
l4181:	
;main.c: 133: pwm_cyc = (buff_hz - 1);
	movf	(pwm_init@buff_hz+1),w
	movwf	(_pwm_cyc+1)
	movf	(pwm_init@buff_hz),w
	movwf	(_pwm_cyc)
	
l4183:	
	movlw	low(0FFFFh)
	addwf	(_pwm_cyc),f
	skipnc
	incf	(_pwm_cyc+1),f
	movlw	high(0FFFFh)
	addwf	(_pwm_cyc+1),f
	line	135
;main.c: 135: }
	goto	l4187
	line	136
	
l4185:	
;main.c: 136: else pwm_cyc=1000;
	movlw	low(03E8h)
	movwf	(_pwm_cyc)
	movlw	high(03E8h)
	movwf	((_pwm_cyc))+1
	line	137
	
l4187:	
;main.c: 137: T1PRLH = (pwm_cyc & 0x03ff) >> 8;
	movf	(_pwm_cyc+1),w
	andlw	03h
	bsf	status, 5	;RP0=1, select bank3
	bsf	status, 6	;RP1=1, select bank3
	movwf	(410)^0180h	;volatile
	line	138
	
l4189:	
;main.c: 138: T1PRLL = (pwm_cyc & 0x00ff);
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(_pwm_cyc),w
	bsf	status, 6	;RP1=1, select bank2
	movwf	(279)^0100h	;volatile
	line	139
	
l4191:	
;main.c: 139: TMR1ON = 1;
	bcf	status, 6	;RP1=0, select bank0
	bsf	(128/8),(128)&7
	line	140
	
l753:	
	return
	opt stack 0
GLOBAL	__end_of_pwm_init
	__end_of_pwm_init:
;; =============== function _pwm_init ends ============

	signat	_pwm_init,4216
	global	_init_tim0
psect	text207,local,class=CODE,delta=2
global __ptext207
__ptext207:

;; *************** function _init_tim0 *****************
;; Defined at:
;;		line 109 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 60/20
;;		On exit  : 60/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text207
	file	"main.c"
	line	109
	global	__size_of_init_tim0
	__size_of_init_tim0	equ	__end_of_init_tim0-_init_tim0
	
_init_tim0:	
	opt	stack 6
; Regs used in _init_tim0: [wreg+status,2]
	line	110
	
l4155:	
;main.c: 110: OPT_REG = ( 0x02 | (0xf8 & OPT_REG) );
	movf	(129)^080h,w
	andlw	0F8h
	iorlw	02h
	movwf	(129)^080h	;volatile
	line	112
	
l4157:	
;main.c: 112: (PSC = 0);
	bcf	(1035/8)^080h,(1035)&7
	line	113
	
l4159:	
;main.c: 113: (TCS = 0);
	bcf	(1037/8)^080h,(1037)&7
	line	115
	
l4161:	
;main.c: 115: TMR0 = 6;
	movlw	(06h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(1)	;volatile
	line	116
	
l4163:	
;main.c: 116: TMR0EN = 1;
	bsf	(209/8),(209)&7
	line	117
	
l4165:	
;main.c: 117: TIS = 1;
	bsf	(93/8),(93)&7
	line	118
	
l748:	
	return
	opt stack 0
GLOBAL	__end_of_init_tim0
	__end_of_init_tim0:
;; =============== function _init_tim0 ends ============

	signat	_init_tim0,88
	global	_XXX
psect	text208,local,class=CODE,delta=2
global __ptext208
__ptext208:

;; *************** function _XXX *****************
;; Defined at:
;;		line 385 in file "main.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: FFF9F/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          2       0       0       0
;;      Totals:         2       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text208
	file	"main.c"
	line	385
	global	__size_of_XXX
	__size_of_XXX	equ	__end_of_XXX-_XXX
	
_XXX:	
	opt	stack 5
; Regs used in _XXX: []
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_XXX+0)
	movf	pclath,w
	movwf	(??_XXX+1)
	ljmp	_XXX
psect	text208
	line	386
	
i1l4211:	
;main.c: 386: if(TIF == 1)
	btfss	(90/8),(90)&7
	goto	u25_21
	goto	u25_20
u25_21:
	goto	i1l815
u25_20:
	line	388
	
i1l4213:	
;main.c: 387: {
;main.c: 388: TIF = 0;
	bcf	(90/8),(90)&7
	line	389
;main.c: 389: FLAG0.bit_type.b0 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(_FLAG0),0
	line	392
	
i1l815:	
	movf	(??_XXX+1),w
	movwf	pclath
	swapf	(??_XXX+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_XXX
	__end_of_XXX:
;; =============== function _XXX ends ============

	signat	_XXX,88
psect	text209,local,class=CODE,delta=2
global __ptext209
__ptext209:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
