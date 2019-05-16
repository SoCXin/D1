
#ifndef	__YS83_84_H__
#define	__YS83_84_H__

// 20480427 BY Œ‚∆Ω…˙∫À∂‘

volatile unsigned char		IAR					;  //@	0x0000;
volatile unsigned char		TMR0				;  //@	0x0001;
volatile unsigned char		PCL					;  //@	0x0002;
volatile unsigned char		STATUS				;  //@	0x0003;
//        STATUS  Bits
volatile bit		C			;  //@	 ((unsigned)&STATUS*8)+0;
volatile bit		HC			;  //@	 ((unsigned)&STATUS*8)+1;
volatile bit		Z			;  //@	 ((unsigned)&STATUS*8)+2;
volatile bit		PF			;  //@	 ((unsigned)&STATUS*8)+3;
volatile bit		TF			;  //@	 ((unsigned)&STATUS*8)+4;
volatile bit		RP0			;  //@	 ((unsigned)&STATUS*8)+5;
volatile bit		RP1			;  //@	 ((unsigned)&STATUS*8)+6;
volatile bit		IRP			;  //@	 ((unsigned)&STATUS*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	C			: 1;
	unsigned	HC			: 1;
	unsigned	Z			: 1;
	unsigned	PF			: 1;
	unsigned	TF			: 1;
	unsigned	RP0			: 1;
	unsigned	RP1			: 1;
	unsigned	IRP			: 1;
	};
} _STATUSbits ;  //@ 0x0003;
#endif
volatile unsigned char		MSR					;  //@	0x0004;
volatile unsigned char		PORTA				;  //@	0x0005;
//        PORTA  Bits
volatile bit		PA0		;  //@	 ((unsigned)&PORTA*8)+0;
volatile bit		PA1			;  //@	 ((unsigned)&PORTA*8)+1;
volatile bit		PA2			;  //@	 ((unsigned)&PORTA*8)+2;
volatile bit		PA3			;  //@	 ((unsigned)&PORTA*8)+3;
volatile bit		PA4			;  //@	 ((unsigned)&PORTA*8)+4;
volatile bit		PA5			;  //@	 ((unsigned)&PORTA*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PA0			: 1;
	unsigned	PA1			: 1;
	unsigned	PA2			: 1;
	unsigned	PA3			: 1;
	unsigned	PA4			: 1;
	unsigned	PA5			: 1;
	};
} _PORTAbits ;  //@ 0x0005;
#endif
volatile unsigned char		PORTB				;  //@	0x0006;
//        PORTB  Bits
volatile bit		PB0		;  //@	 ((unsigned)&PORTB*8)+0;
volatile bit		PB1			;  //@	 ((unsigned)&PORTB*8)+1;
volatile bit		PB2			;  //@	 ((unsigned)&PORTB*8)+2;
volatile bit		PB3			;  //@	 ((unsigned)&PORTB*8)+3;
volatile bit		PB4			;  //@	 ((unsigned)&PORTB*8)+4;
volatile bit		PB5			;  //@	 ((unsigned)&PORTB*8)+5;
volatile bit		PB6			;  //@	 ((unsigned)&PORTB*8)+6;
volatile bit		PB7			;  //@	 ((unsigned)&PORTB*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PB0			: 1;
	unsigned	PB1			: 1;
	unsigned	PB2			: 1;
	unsigned	PB3			: 1;
	unsigned	PB4			: 1;
	unsigned	PB5			: 1;
	unsigned	PB6			: 1;
	unsigned	PB7			: 1;
	};
} _PORTBbits ;  //@ 0x0006;
#endif
volatile unsigned char		PORTC				;  //@	0x0007;
//        PORTC  Bits
volatile bit		PC0		;  //@	 ((unsigned)&PORTC*8)+0;
volatile bit		PC1			;  //@	 ((unsigned)&PORTC*8)+1;
volatile bit		PC2			;  //@	 ((unsigned)&PORTC*8)+2;
volatile bit		PC3			;  //@	 ((unsigned)&PORTC*8)+3;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PC0			: 1;
	unsigned	PC1			: 1;
	unsigned	PC2			: 1;
	unsigned	PC3			: 1;
	};
} _PORTCbits ;  //@ 0x0007;
#endif
volatile unsigned char		PORTD				;  //@	0x0008;
//        PORTD  Bits
volatile bit		PD0		;  //@	 ((unsigned)&PORTD*8)+0;
volatile bit		PD1			;  //@	 ((unsigned)&PORTD*8)+1;
volatile bit		PD2			;  //@	 ((unsigned)&PORTD*8)+2;
volatile bit		PD3			;  //@	 ((unsigned)&PORTD*8)+3;
volatile bit		PD4			;  //@	 ((unsigned)&PORTD*8)+4;
volatile bit		PD5			;  //@	 ((unsigned)&PORTD*8)+5;
volatile bit		PD6			;  //@	 ((unsigned)&PORTD*8)+6;
volatile bit		PD7			;  //@	 ((unsigned)&PORTD*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PD0			: 1;
	unsigned	PD1			: 1;
	unsigned	PD2			: 1;
	unsigned	PD3			: 1;
	unsigned	PD4			: 1;
	unsigned	PD5			: 1;
	unsigned	PD6			: 1;
	unsigned	PD7			: 1;
	};
} _PORTDbits ;  //@ 0x0008;
#endif
volatile unsigned char		PCLATH				;  //@	0x000A;
volatile unsigned char		INTS					;  //@	0x000B;
//        INTS  Bits
volatile bit		PAIF		;  //@	 ((unsigned)&INTS*8)+0;
volatile bit		INT0F		;  //@	 ((unsigned)&INTS*8)+1;
volatile bit		TIF			;  //@	 ((unsigned)&INTS*8)+2;
volatile bit		PAIE			;  //@	 ((unsigned)&INTS*8)+3;
volatile bit		INT0E		;  //@	 ((unsigned)&INTS*8)+4;
volatile bit		TIS			;  //@	 ((unsigned)&INTS*8)+5;
volatile bit		PEIE			;  //@	 ((unsigned)&INTS*8)+6;
volatile bit		GIE			;  //@	 ((unsigned)&INTS*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PAIF		: 1;
	unsigned	INT0F		: 1;
	unsigned	TIF			: 1;
	unsigned	PAIE		: 1;
	unsigned	INT0E		: 1;
	unsigned	TIS			: 1;
	unsigned	PEIE		: 1;
	unsigned	GIE			: 1;
	};
} _INTSbits ;  //@ 0x000B;
#endif
volatile unsigned char		PIFB1				;  //@	0x000C;
//        PIFB1  Bits
volatile bit		TMR1IF	;  //@	 ((unsigned)&PIFB1*8)+0;
volatile bit		OSFIF		;  //@	 ((unsigned)&PIFB1*8)+1;
volatile bit		ADCIF		;  //@	 ((unsigned)&PIFB1*8)+2;
volatile bit		INT1F		;  //@	 ((unsigned)&PIFB1*8)+3;
volatile bit		TMR1IE		;  //@	 ((unsigned)&PIFB1*8)+4;
volatile bit		OSFIE		;  //@	 ((unsigned)&PIFB1*8)+5;
volatile bit		ADCIE		;  //@	 ((unsigned)&PIFB1*8)+6;
volatile bit		INT1E		;  //@	 ((unsigned)&PIFB1*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	TMR1IF		: 1;
	unsigned	OSFIF		: 1;
	unsigned	ADCIF		: 1;
	unsigned	INT1F		: 1;
	unsigned	TMR1IE		: 1;
	unsigned	OSFIE		: 1;
	unsigned	ADCIE		: 1;
	unsigned	INT1E		: 1;
	};
} _PIFB1bits ;  //@ 0x000C;
#endif
volatile unsigned char		PIFB2				;  //@	0x000D;
//        PIFB2  Bits
volatile bit		PWMIF	;  //@	 ((unsigned)&PIFB2*8)+0;
volatile bit		PBIF			;  //@	 ((unsigned)&PIFB2*8)+1;
volatile bit		CSIF			;  //@	 ((unsigned)&PIFB2*8)+2;
volatile bit		SSP1IF		;  //@	 ((unsigned)&PIFB2*8)+3;
volatile bit		PWMIE		;  //@	 ((unsigned)&PIFB2*8)+4;
volatile bit		PBIE			;  //@	 ((unsigned)&PIFB2*8)+5;
volatile bit		CSIE			;  //@	 ((unsigned)&PIFB2*8)+6;
volatile bit		SSP1IE		;  //@	 ((unsigned)&PIFB2*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PWMIF		: 1;
	unsigned	PBIF		: 1;
	unsigned	CSIF		: 1;
	unsigned	SSP1IF		: 1;
	unsigned	PWMIE		: 1;
	unsigned	PBIE		: 1;
	unsigned	CSIE		: 1;
	unsigned	SSP1IE		: 1;
	};
} _PIFB2bits ;  //@ 0x000D;
#endif
volatile unsigned char		TMR1L				;  //@	0x000E;
volatile unsigned char		TMR1H				;  //@	0x000F;
volatile unsigned char		T1STA				;  //@	0x0010;
//        T1STA  Bits
volatile bit		TMR1ON		;  //@	 ((unsigned)&T1STA*8)+0;
volatile bit		TMR1CS			;  //@	 ((unsigned)&T1STA*8)+1;
volatile bit		T1SYNC			;  //@	 ((unsigned)&T1STA*8)+2;
volatile bit		T1OSCEN			;  //@	 ((unsigned)&T1STA*8)+3;
volatile bit		T1CKPS0			;  //@	 ((unsigned)&T1STA*8)+4;
volatile bit		T1CKPS1			;  //@	 ((unsigned)&T1STA*8)+5;
volatile bit		TMR1GE			;  //@	 ((unsigned)&T1STA*8)+6;
volatile bit		T1GINV			;  //@	 ((unsigned)&T1STA*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	TMR1ON		: 1;
	unsigned	TMR1CS		: 1;
	unsigned	T1SYNC		: 1;
	unsigned	T1OSCEN	: 1;
	unsigned	T1CKPS0	: 1;
	unsigned	T1CKPS1	: 1;
	unsigned	TMR1GE		: 1;
	unsigned	T1GINV		: 1;
	};
} _T1STAbits ;  //@ 0x0010;
#endif
volatile unsigned char		SSP1STAT			;  //@	0x0011;
//        SSP1STAT  Bits
volatile bit		BF				;  //@	 ((unsigned)&SSP1STAT*8)+0;
volatile bit		UA				;  //@	 ((unsigned)&SSP1STAT*8)+1;
volatile bit		R_W				;  //@	 ((unsigned)&SSP1STAT*8)+2;
volatile bit		S				;  //@	 ((unsigned)&SSP1STAT*8)+3;
volatile bit		P				;  //@	 ((unsigned)&SSP1STAT*8)+4;
volatile bit		D_A				;  //@	 ((unsigned)&SSP1STAT*8)+5;
//volatile bit		CKE				;  //@	 ((unsigned)&SSP1STAT*8)+6;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	BF			: 1;
	unsigned	UA			: 1;
	unsigned	R_W		: 1;
	unsigned	S			: 1;
	unsigned	P			: 1;
	unsigned	D_A			: 1;
	//unsigned	CKE			: 1;
	};
} _SSP1STATbits ;  //@ 0x0011;
#endif
volatile unsigned char		SSP1CON1			;  //@	0x0012;
//        SSP1CON1  Bits
volatile bit		SSP1M0		;  //@	 ((unsigned)&SSP1CON1*8)+0;
volatile bit		SSP1M1			;  //@	 ((unsigned)&SSP1CON1*8)+1;
volatile bit		SSP1M2			;  //@	 ((unsigned)&SSP1CON1*8)+2;
volatile bit		SSP1M3			;  //@	 ((unsigned)&SSP1CON1*8)+3;
volatile bit		CKP				;  //@	 ((unsigned)&SSP1CON1*8)+4;
volatile bit		SSP1EN			;  //@	 ((unsigned)&SSP1CON1*8)+5;
volatile bit		SSP1OV			;  //@	 ((unsigned)&SSP1CON1*8)+6;
volatile bit		WCOL			;  //@	 ((unsigned)&SSP1CON1*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	SSP1M0		: 1;
	unsigned	SSP1M1		: 1;
	unsigned	SSP1M2		: 1;
	unsigned	SSP1M3		: 1;
	unsigned	CKP			: 1;
	unsigned	SSP1EN		: 1;
	unsigned	SSP1OV		: 1;
	unsigned	WCOL		: 1;
	};
} _SSP1CON1bits ;  //@ 0x0012;
#endif
volatile unsigned char		SSP1CON2			;  //@	0x0013;
//        SSP1CON2  Bits
volatile bit		SEN			;  //@	 ((unsigned)&SSP1CON2*8)+0;
volatile bit		RSEN			;  //@	 ((unsigned)&SSP1CON2*8)+1;
volatile bit		PEN				;  //@	 ((unsigned)&SSP1CON2*8)+2;
volatile bit		RCEN			;  //@	 ((unsigned)&SSP1CON2*8)+3;
volatile bit		ACKEN			;  //@	 ((unsigned)&SSP1CON2*8)+4;
volatile bit		ACKDT			;  //@	 ((unsigned)&SSP1CON2*8)+5;
volatile bit		ACKSTAT			;  //@	 ((unsigned)&SSP1CON2*8)+6;
volatile bit		GCEN			;  //@	 ((unsigned)&SSP1CON2*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	SEN			: 1;
	unsigned	RSEN		: 1;
	unsigned	PEN			: 1;
	unsigned	RCEN		: 1;
	unsigned	ACKEN		: 1;
	unsigned	ACKDT		: 1;
	unsigned	ACKSTAT	: 1;
	unsigned	GCEN		: 1;
	};
} _SSP1CON2bits ;  //@ 0x0013;
#endif
volatile unsigned char		SSP1CON3			;  //@	0x0014;
//        SSP1CON3  Bits
volatile bit		DHEN			;  //@	 ((unsigned)&SSP1CON3*8)+0;
volatile bit		AHEN			;  //@	 ((unsigned)&SSP1CON3*8)+1;
volatile bit		SBCDE			;  //@	 ((unsigned)&SSP1CON3*8)+2;

volatile bit		BOEN			;  //@	 ((unsigned)&SSP1CON3*8)+4;
volatile bit		SCIE				;  //@	 ((unsigned)&SSP1CON3*8)+5;
volatile bit		PCIE				;  //@	 ((unsigned)&SSP1CON3*8)+6;
volatile bit		ACKTIM			;  //@	 ((unsigned)&SSP1CON3*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	DHEN		: 1;
	unsigned	AHEN		: 1;
	unsigned	SBCDE		: 1;
	unsigned RESERVE	: 1;
	unsigned	BOEN		: 1;
	unsigned	SCIE		: 1;
	unsigned	PCIE		: 1;
	unsigned	ACKTIM		: 1;
	};
} _SSP1CON3bits ;  //@ 0x0014;
#endif
volatile unsigned char		SSP1MSK				;  //@	0x0015;
volatile unsigned char		SSP1ADD				;  //@	0x0016;
volatile unsigned char		SSP1BUF				;  //@	0x0017;
volatile unsigned char		WDTCON				;  //@	0x0018;
//        WDTCON  Bits
volatile bit		SWDTEN		;  //@	 ((unsigned)&WDTCON*8)+0;
volatile bit		WDTPS0			;  //@	 ((unsigned)&WDTCON*8)+1;
volatile bit		WDTPS1			;  //@	 ((unsigned)&WDTCON*8)+2;
volatile bit		WDTPS2			;  //@	 ((unsigned)&WDTCON*8)+3;
volatile bit		WDTPS3			;  //@	 ((unsigned)&WDTCON*8)+4;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	SWDTEN		: 1;
	unsigned	WDTPS0		: 1;
	unsigned	WDTPS1		: 1;
	unsigned	WDTPS2		: 1;
	unsigned	WDTPS3		: 1;
	};
} _WDTCONbits ;  //@ 0x0018;
#endif
volatile unsigned char		PIFB3				;  //@	0x0019;
//        PIFB3  Bits
volatile bit		BCL1IF		;  //@	 ((unsigned)&PIFB3*8)+0;
volatile bit		BCL1IE			;  //@	 ((unsigned)&PIFB3*8)+4;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	BCL1IF		: 1;
	unsigned RESERVE	: 3;
	unsigned	BCL1IE		: 1;
	};
} _PIFB3bits ;  //@ 0x0019;
#endif
volatile unsigned char		PWMCON				;  //@	0x001A;
//        PWMCON  Bits
volatile bit		T1GSS			;  //@	 ((unsigned)&PWMCON*8)+0;
volatile bit		TMR0EN			;  //@	 ((unsigned)&PWMCON*8)+1;
volatile bit		PWM0EN			;  //@	 ((unsigned)&PWMCON*8)+2;
volatile bit		PWM1EN			;  //@	 ((unsigned)&PWMCON*8)+3;
volatile bit		PWM0OE			;  //@	 ((unsigned)&PWMCON*8)+4;
volatile bit		PWM1OE			;  //@	 ((unsigned)&PWMCON*8)+5;
volatile bit		PWMFS			;  //@	 ((unsigned)&PWMCON*8)+6;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	T1GSS		: 1;
	unsigned	TMR0EN		: 1;
	unsigned	PWM0EN	: 1;
	unsigned	PWM1EN	: 1;
	unsigned	PWM0OE	: 1;
	unsigned	PWM1OE	: 1;
	unsigned	PWMFS		: 1;
	};
} _PWMCONbits ;  //@ 0x001A;
#endif


volatile unsigned char		ADRESH				;  //@	0x001E;


volatile unsigned char		OPT_REG				;  //@	0x0081;
//        OPT_REG  Bits
volatile bit		PS0			;  //@	 ((unsigned)&OPT_REG*8)+0;
volatile bit		PS1				;  //@	 ((unsigned)&OPT_REG*8)+1;
volatile bit		PS2				;  //@	 ((unsigned)&OPT_REG*8)+2;
volatile bit		PSC				;  //@	 ((unsigned)&OPT_REG*8)+3;
volatile bit		TCE				;  //@	 ((unsigned)&OPT_REG*8)+4;
volatile bit		TCS				;  //@	 ((unsigned)&OPT_REG*8)+5;
volatile bit		INT0EG			;  //@	 ((unsigned)&OPT_REG*8)+6;
volatile bit		INT1EG			;  //@	 ((unsigned)&OPT_REG*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PS0			: 1;
	unsigned	PS1			: 1;
	unsigned	PS2			: 1;
	unsigned	PSC			: 1;
	unsigned	TCE			: 1;
	unsigned	TCS			: 1;
	unsigned	INT0EG		: 1;
	unsigned	INT1EG		: 1;
	};
} _OPT_REGbits ;  //@ 0x0081;
#endif


volatile unsigned char		CPIOA				;  //@	0x0085;
//        CPIOA  Bits
volatile bit		CPIOA0		;  //@	 ((unsigned)&CPIOA*8)+0;
volatile bit		CPIOA1			;  //@	 ((unsigned)&CPIOA*8)+1;
volatile bit		CPIOA2			;  //@	 ((unsigned)&CPIOA*8)+2;
volatile bit		CPIOA3			;  //@	 ((unsigned)&CPIOA*8)+3;
volatile bit		CPIOA4			;  //@	 ((unsigned)&CPIOA*8)+4;
volatile bit		CPIOA5			;  //@	 ((unsigned)&CPIOA*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CPIOA0		: 1;
	unsigned	CPIOA1		: 1;
	unsigned	CPIOA2		: 1;
	unsigned	CPIOA3		: 1;
	unsigned	CPIOA4		: 1;
	unsigned	CPIOA5		: 1;
	};
} _CPIOAbits ;  //@ 0x0085;
#endif
volatile unsigned char		CPIOB				;  //@	0x0086;
//        CPIOB  Bits
volatile bit		CPIOB0		;  //@	 ((unsigned)&CPIOB*8)+0;
volatile bit		CPIOB1			;  //@	 ((unsigned)&CPIOB*8)+1;
volatile bit		CPIOB2			;  //@	 ((unsigned)&CPIOB*8)+2;
volatile bit		CPIOB3			;  //@	 ((unsigned)&CPIOB*8)+3;
volatile bit		CPIOB4			;  //@	 ((unsigned)&CPIOB*8)+4;
volatile bit		CPIOB5			;  //@	 ((unsigned)&CPIOB*8)+5;
volatile bit		CPIOB6			;  //@	 ((unsigned)&CPIOB*8)+6;
volatile bit		CPIOB7			;  //@	 ((unsigned)&CPIOB*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CPIOB0		: 1;
	unsigned	CPIOB1		: 1;
	unsigned	CPIOB2		: 1;
	unsigned	CPIOB3		: 1;
	unsigned	CPIOB4		: 1;
	unsigned	CPIOB5		: 1;
	unsigned	CPIOB6		: 1;
	unsigned	CPIOB7		: 1;
	};
} _CPIOBbits ;  //@ 0x0086;
#endif
volatile unsigned char		CPIOC				;  //@	0x0087;
//        CPIOC  Bits
volatile bit		CPIOC0		;  //@	 ((unsigned)&CPIOC*8)+0;
volatile bit		CPIOC1			;  //@	 ((unsigned)&CPIOC*8)+1;
volatile bit		CPIOC2			;  //@	 ((unsigned)&CPIOC*8)+2;
volatile bit		CPIOC3			;  //@	 ((unsigned)&CPIOC*8)+3;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CPIOC0		: 1;
	unsigned	CPIOC1		: 1;
	unsigned	CPIOC2		: 1;
	unsigned	CPIOC3		: 1;
	};
} _CPIOCbits ;  //@ 0x0087;
#endif
volatile unsigned char		CPIOD				;  //@	0x0088;
//        CPIOD  Bits
volatile bit		CPIOD0		;  //@	 ((unsigned)&CPIOD*8)+0;
volatile bit		CPIOD1			;  //@	 ((unsigned)&CPIOD*8)+1;
volatile bit		CPIOD2			;  //@	 ((unsigned)&CPIOD*8)+2;
volatile bit		CPIOD3			;  //@	 ((unsigned)&CPIOD*8)+3;
volatile bit		CPIOD4			;  //@	 ((unsigned)&CPIOD*8)+4;
volatile bit		CPIOD5			;  //@	 ((unsigned)&CPIOD*8)+5;
volatile bit		CPIOD6			;  //@	 ((unsigned)&CPIOD*8)+6;
volatile bit		CPIOD7			;  //@	 ((unsigned)&CPIOD*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CPIOD0		: 1;
	unsigned	CPIOD1		: 1;
	unsigned	CPIOD2		: 1;
	unsigned	CPIOD3		: 1;
	unsigned	CPIOD4		: 1;
	unsigned	CPIOD5		: 1;
	unsigned	CPIOD6		: 1;
	unsigned	CPIOD7		: 1;
	};
} _CPIODbits ;  //@ 0x0088;
#endif


volatile unsigned char		PSTA				;  //@	0x008E;
//        PSTA  Bits
volatile bit		LVR			;  //@	 ((unsigned)&PSTA*8)+0;
volatile bit		POR				;  //@	 ((unsigned)&PSTA*8)+1;
volatile bit		IER				;  //@	 ((unsigned)&PSTA*8)+2;
volatile bit		MCR				;  //@	 ((unsigned)&PSTA*8)+3;
volatile bit		SLVREN			;  //@	 ((unsigned)&PSTA*8)+4;
volatile bit		ULPWUE			;  //@	 ((unsigned)&PSTA*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	LVR			: 1;
	unsigned	POR			: 1;
	unsigned	IER			: 1;
	unsigned	MCR			: 1;
	unsigned	SLVREN		: 1;
	unsigned	ULPWUE		: 1;
	};
} _PSTAbits ;  //@ 0x008E;
#endif
volatile unsigned char		OSCCON				;  //@	0x008F;
//        OSCCON  Bits
volatile bit		SCS			;  //@	 ((unsigned)&OSCCON*8)+0;
volatile bit		LTS				;  //@	 ((unsigned)&OSCCON*8)+1;
volatile bit		HTS				;  //@	 ((unsigned)&OSCCON*8)+2;
volatile bit		OSTS			;  //@	 ((unsigned)&OSCCON*8)+3;
volatile bit		IRCF0			;  //@	 ((unsigned)&OSCCON*8)+4;
volatile bit		IRCF1			;  //@	 ((unsigned)&OSCCON*8)+5;
volatile bit		IRCF2			;  //@	 ((unsigned)&OSCCON*8)+6;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	SCS			: 1;
	unsigned	LTS			: 1;
	unsigned	HTS			: 1;
	unsigned	OSTS		: 1;
	unsigned	IRCF0		: 1;
	unsigned	IRCF1		: 1;
	unsigned	IRCF2		: 1;
	};
} _OSCCONbits ;  //@ 0x008F;
#endif

volatile unsigned char		ADINS				;  //@	0x0091;
//        ADINS  Bits
volatile bit		ANS0			;  //@	 ((unsigned)&ADINS*8)+0;
volatile bit		ANS1			;  //@	 ((unsigned)&ADINS*8)+1;
volatile bit		ANS2			;  //@	 ((unsigned)&ADINS*8)+2;
volatile bit		ANS3			;  //@	 ((unsigned)&ADINS*8)+3;
volatile bit		ANS4			;  //@	 ((unsigned)&ADINS*8)+4;
volatile bit		ANS5			;  //@	 ((unsigned)&ADINS*8)+5;
volatile bit		ANS6			;  //@	 ((unsigned)&ADINS*8)+6;
volatile bit		ANS7			;  //@	 ((unsigned)&ADINS*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	ANS0		: 1;
	unsigned	ANS1		: 1;
	unsigned	ANS2		: 1;
	unsigned	ANS3		: 1;
	unsigned	ANS4		: 1;
	unsigned	ANS5		: 1;
	unsigned	ANS6		: 1;
	unsigned	ANS7		: 1;
	};
} _ADINSbits ;  //@ 0x0091;
#endif
volatile unsigned char		IRCTRIML				;  //@	0x0092;
volatile unsigned char		IRCTRIMH			;  //@	0x0093;
//        IRCTRIMH  Bits
volatile bit		IRCTEN		;  //@	 ((unsigned)&IRCTRIMH*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{

	unsigned RESERVE	: 5;
	unsigned	IRCTEN		: 1;
	};
} _IRCTRIMHbits ;  //@ 0x0093;
#endif

volatile unsigned char		PAPHR				;  //@	0x0095;
//        PAPHR  Bits
volatile bit		PAPHR0		;  //@	 ((unsigned)&PAPHR*8)+0;
volatile bit		PAPHR1			;  //@	 ((unsigned)&PAPHR*8)+1;
volatile bit		PAPHR2			;  //@	 ((unsigned)&PAPHR*8)+2;
volatile bit		PAPHR3			;  //@	 ((unsigned)&PAPHR*8)+3;
volatile bit		PAPHR4			;  //@	 ((unsigned)&PAPHR*8)+4;
volatile bit		PAPHR5			;  //@	 ((unsigned)&PAPHR*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PAPHR0		: 1;
	unsigned	PAPHR1		: 1;
	unsigned	PAPHR2		: 1;
	unsigned	PAPHR3		: 1;
	unsigned	PAPHR4		: 1;
	unsigned	PAPHR5		: 1;
	};
} _PAPHRbits ;  //@ 0x0095;
#endif
volatile unsigned char		PBPHR				;  //@	0x0096;
//        PBPHR  Bits
volatile bit		PBPHR0		;  //@	 ((unsigned)&PBPHR*8)+0;
volatile bit		PBPHR1			;  //@	 ((unsigned)&PBPHR*8)+1;
volatile bit		PBPHR2			;  //@	 ((unsigned)&PBPHR*8)+2;
volatile bit		PBPHR3			;  //@	 ((unsigned)&PBPHR*8)+3;
volatile bit		PBPHR4			;  //@	 ((unsigned)&PBPHR*8)+4;
volatile bit		PBPHR5			;  //@	 ((unsigned)&PBPHR*8)+5;
volatile bit		PBPHR6			;  //@	 ((unsigned)&PBPHR*8)+6;
volatile bit		PBPHR7			;  //@	 ((unsigned)&PBPHR*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PBPHR0		: 1;
	unsigned	PBPHR1		: 1;
	unsigned	PBPHR2		: 1;
	unsigned	PBPHR3		: 1;
	unsigned	PBPHR4		: 1;
	unsigned	PBPHR5		: 1;
	unsigned	PBPHR6		: 1;
	unsigned	PBPHR7		: 1;
	};
} _PBPHRbits ;  //@ 0x0096;
#endif
volatile unsigned char		PCPHR				;  //@	0x0097;
//        PCPHR  Bits
volatile bit		PCPHR0		;  //@	 ((unsigned)&PCPHR*8)+0;
volatile bit		PCPHR1			;  //@	 ((unsigned)&PCPHR*8)+1;
volatile bit		PCPHR2			;  //@	 ((unsigned)&PCPHR*8)+2;
volatile bit		PCPHR3			;  //@	 ((unsigned)&PCPHR*8)+3;
volatile bit		PDC0			;  //@	 ((unsigned)&PCPHR*8)+4;
volatile bit		PDC1			;  //@	 ((unsigned)&PCPHR*8)+5;
volatile bit		PDC2			;  //@	 ((unsigned)&PCPHR*8)+6;
volatile bit		PDC3			;  //@	 ((unsigned)&PCPHR*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PCPHR0		: 1;
	unsigned	PCPHR1		: 1;
	unsigned	PCPHR2		: 1;
	unsigned	PCPHR3		: 1;
	unsigned	PDC0		: 1;
	unsigned	PDC1		: 1;
	unsigned	PDC2		: 1;
	unsigned	PDC3		: 1;
	};
} _PCPHRbits ;  //@ 0x0097;
#endif
volatile unsigned char		PDPHR				;  //@	0x0098;
//        PDPHR  Bits
volatile bit		PDPHR0		;  //@	 ((unsigned)&PDPHR*8)+0;
volatile bit		PDPHR1			;  //@	 ((unsigned)&PDPHR*8)+1;
volatile bit		PDPHR2			;  //@	 ((unsigned)&PDPHR*8)+2;
volatile bit		PDPHR3			;  //@	 ((unsigned)&PDPHR*8)+3;
volatile bit		PDPHR4			;  //@	 ((unsigned)&PDPHR*8)+4;
volatile bit		PDPHR5			;  //@	 ((unsigned)&PDPHR*8)+5;
volatile bit		PDPHR6			;  //@	 ((unsigned)&PDPHR*8)+6;
volatile bit		PDPHR7			;  //@	 ((unsigned)&PDPHR*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PDPHR0		: 1;
	unsigned	PDPHR1		: 1;
	unsigned	PDPHR2		: 1;
	unsigned	PDPHR3		: 1;
	unsigned	PDPHR4		: 1;
	unsigned	PDPHR5		: 1;
	unsigned	PDPHR6		: 1;
	unsigned	PDPHR7		: 1;
	};
} _PDPHRbits ;  //@ 0x0098;
#endif
volatile unsigned char		PAINTR				;  //@	0x0099;
//        PAINTR  Bits
volatile bit		PAINTR0		;  //@	 ((unsigned)&PAINTR*8)+0;
volatile bit		PAINTR1			;  //@	 ((unsigned)&PAINTR*8)+1;
volatile bit		PAINTR2			;  //@	 ((unsigned)&PAINTR*8)+2;
volatile bit		PAINTR3			;  //@	 ((unsigned)&PAINTR*8)+3;
volatile bit		PAINTR4			;  //@	 ((unsigned)&PAINTR*8)+4;
volatile bit		PAINTR5			;  //@	 ((unsigned)&PAINTR*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PAINTR0	: 1;
	unsigned	PAINTR1	: 1;
	unsigned	PAINTR2	: 1;
	unsigned	PAINTR3	: 1;
	unsigned	PAINTR4	: 1;
	unsigned	PAINTR5	: 1;
	};
} _PAINTRbits ;  //@ 0x0099;
#endif
volatile unsigned char		PBINTR				;  //@	0x009A;
//        PBINTR  Bits
volatile bit		PBINTR0		;  //@	 ((unsigned)&PBINTR*8)+0;
volatile bit		PBINTR1			;  //@	 ((unsigned)&PBINTR*8)+1;
volatile bit		PBINTR2			;  //@	 ((unsigned)&PBINTR*8)+2;
volatile bit		PBINTR3			;  //@	 ((unsigned)&PBINTR*8)+3;
volatile bit		PBINTR4			;  //@	 ((unsigned)&PBINTR*8)+4;
volatile bit		PBINTR5			;  //@	 ((unsigned)&PBINTR*8)+5;
volatile bit		PBINTR6			;  //@	 ((unsigned)&PBINTR*8)+6;
volatile bit		PBINTR7			;  //@	 ((unsigned)&PBINTR*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PBINTR0	: 1;
	unsigned	PBINTR1	: 1;
	unsigned	PBINTR2	: 1;
	unsigned	PBINTR3	: 1;
	unsigned	PBINTR4	: 1;
	unsigned	PBINTR5	: 1;
	unsigned	PBINTR6	: 1;
	unsigned	PBINTR7	: 1;
	};
} _PBINTRbits ;  //@ 0x009A;
#endif

volatile unsigned char		ADRESL				;  //@	0x009E;
volatile unsigned char		ADC0TH				;  //@	0x009F;


volatile unsigned char		PRL0L				;  //@	0x0112;
volatile unsigned char		PRL1L				;  //@	0x0113;

volatile unsigned char		T1PRLL				;  //@	0x0117;
volatile unsigned char		ET1PRL				;  //@	0x0118;

volatile unsigned char		ADC0CN				;  //@	0x011E;
//        ADC0CN  Bits
volatile bit		CM0			;  //@	 ((unsigned)&ADC0CN*8)+0;
volatile bit		CM1				;  //@	 ((unsigned)&ADC0CN*8)+1;
volatile bit		GO_DONE		;  //@	 ((unsigned)&ADC0CN*8)+2;
volatile bit		ADC0EN			;  //@	 ((unsigned)&ADC0CN*8)+3;
volatile bit		SC0				;  //@	 ((unsigned)&ADC0CN*8)+4;
volatile bit		SC1				;  //@	 ((unsigned)&ADC0CN*8)+5;
volatile bit		ADFM			;  //@	 ((unsigned)&ADC0CN*8)+6;
volatile bit		ADCTHSEL		;  //@	 ((unsigned)&ADC0CN*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CM0			: 1;
	unsigned	CM1			: 1;
	unsigned	GO_DONE	: 1;
	unsigned	ADC0EN		: 1;
	unsigned	SC0			: 1;
	unsigned	SC1			: 1;
	unsigned	ADFM		: 1;
	unsigned	ADCTHSEL	: 1;
	};
} _ADC0CNbits ;  //@ 0x011E;
#endif


volatile unsigned char		CSCTL				;  //@	0x0190;
//        CSCTL  Bits
volatile bit		CSACU0		;  //@	 ((unsigned)&CSCTL*8)+0;
volatile bit		CSACU1			;  //@	 ((unsigned)&CSCTL*8)+1;
volatile bit		CSACU2			;  //@	 ((unsigned)&CSCTL*8)+2;
volatile bit		CSINTS			;  //@	 ((unsigned)&CSCTL*8)+3;
volatile bit		CSBUSY			;  //@	 ((unsigned)&CSCTL*8)+4;
volatile bit		XRAM			;  //@	 ((unsigned)&CSCTL*8)+5;
volatile bit		RAMEN			;  //@	 ((unsigned)&CSCTL*8)+6;
volatile bit		CSEN			;  //@	 ((unsigned)&CSCTL*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CSACU0		: 1;
	unsigned	CSACU1		: 1;
	unsigned	CSACU2		: 1;
	unsigned	CSINTS		: 1;
	unsigned	CSBUSY		: 1;
	unsigned	XRAM		: 1;
	unsigned	RAMEN		: 1;
	unsigned	CSEN		: 1;
	};
} _CSCTLbits ;  //@ 0x0190;
#endif
volatile unsigned char		THCTL				;  //@	0x0191;
//        THCTL  Bits
volatile bit		THDS0			;  //@	 ((unsigned)&THCTL*8)+0;
volatile bit		THDS1			;  //@	 ((unsigned)&THCTL*8)+1;
volatile bit		THMOD0			;  //@	 ((unsigned)&THCTL*8)+2;
volatile bit		THMOD1			;  //@	 ((unsigned)&THCTL*8)+3;
volatile bit		THMOD2			;  //@	 ((unsigned)&THCTL*8)+4;
volatile bit		THGAP0			;  //@	 ((unsigned)&THCTL*8)+5;
volatile bit		THGAP1			;  //@	 ((unsigned)&THCTL*8)+6;
//volatile bit		THFIB			;  //@	 ((unsigned)&THCTL*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	THDS0		: 1;
	unsigned	THDS1		: 1;
	unsigned	THMOD0		: 1;
	unsigned	THMOD1		: 1;
	unsigned	THMOD2		: 1;
	unsigned	THGAP0		: 1;
	unsigned	THGAP1		: 1;
	//unsigned	THFIB			: 1;
	};
} _THCTLbits ;  //@ 0x0191;
#endif
volatile unsigned char		PWM0L				;  //@	0x0192;
volatile unsigned char		PWM1L				;  //@	0x0193;
volatile unsigned char		CHRLTH				;  //@	0x0194;
volatile unsigned char		CHRLTL				;  //@	0x0195;
volatile unsigned char		CHSELH				;  //@	0x0196;
volatile unsigned char		CHSELL				;  //@	0x0197;
volatile unsigned char		EPR0				;  //@	0x0198;
volatile unsigned char		EPR1				;  //@	0x0199;
volatile unsigned char		T1PRLH				;  //@	0x019A;
volatile unsigned char		CSTMRH				;  //@	0x019B;
volatile unsigned char		CSTMRL				;  //@	0x019C;
volatile unsigned char		ADS0				;  //@	0x019D;
//        ADS0  Bits
volatile bit		VREFSEL		;  //@	 ((unsigned)&ADS0*8)+0;
volatile bit		REFSL0			;  //@	 ((unsigned)&ADS0*8)+2;
volatile bit		REFSL1			;  //@	 ((unsigned)&ADS0*8)+3;
volatile bit		CHNSEL0			;  //@	 ((unsigned)&ADS0*8)+4;
volatile bit		CHNSEL1			;  //@	 ((unsigned)&ADS0*8)+5;
volatile bit		CHNSEL2			;  //@	 ((unsigned)&ADS0*8)+6;
volatile bit		CHNSEL3			;  //@	 ((unsigned)&ADS0*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	VREFSEL		: 1;
	unsigned RESERVE	: 1;
	unsigned	REFSL0		: 1;
	unsigned	REFSL1		: 1;
	unsigned	CHNSEL0	: 1;
	unsigned	CHNSEL1	: 1;
	unsigned	CHNSEL2	: 1;
	unsigned	CHNSEL3	: 1;
	};
} _ADS0bits ;  //@ 0x019D;
#endif
volatile unsigned char		CSANA0				;  //@	0x019E;
//        CSANA0  Bits
volatile bit		VTSEL0		;  //@	 ((unsigned)&CSANA0*8)+0;
volatile bit		VTSEL1			;  //@	 ((unsigned)&CSANA0*8)+1;
volatile bit		CMPTRM0			;  //@	 ((unsigned)&CSANA0*8)+2;
volatile bit		CMPTRM1			;  //@	 ((unsigned)&CSANA0*8)+3;
volatile bit		BSTRM0			;  //@	 ((unsigned)&CSANA0*8)+4;
volatile bit		BSTRM1			;  //@	 ((unsigned)&CSANA0*8)+5;
volatile bit		BSTRM2			;  //@	 ((unsigned)&CSANA0*8)+6;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	VTSEL0		: 1;
	unsigned	VTSEL1		: 1;
	unsigned	CMPTRM0	: 1;
	unsigned	CMPTRM1	: 1;
	unsigned	BSTRM0		: 1;
	unsigned	BSTRM1		: 1;
	unsigned	BSTRM2		: 1;
	};
} _CSANA0bits ;  //@ 0x019E;
#endif
volatile unsigned char		CSANA1				;  //@	0x019F;
//        CSANA1  Bits
volatile bit		CTTRM0		;  //@	 ((unsigned)&CSANA1*8)+0;
volatile bit		CTTRM1			;  //@	 ((unsigned)&CSANA1*8)+1;
volatile bit		CTTRM2			;  //@	 ((unsigned)&CSANA1*8)+2;
volatile bit		DTTRM0			;  //@	 ((unsigned)&CSANA1*8)+3;
volatile bit		DTTRM1			;  //@	 ((unsigned)&CSANA1*8)+4;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CTTRM0		: 1;
	unsigned	CTTRM1		: 1;
	unsigned	CTTRM2		: 1;
	unsigned	DTTRM0		: 1;
	unsigned	DTTRM1		: 1;
	};
} _CSANA1bits ;  //@ 0x019F;
#endif


#define CLR_WDT() do {asm("clrwdt");} while (0)
#define SLEEP() 	do {asm("sleep"); asm("clrwdt"); asm("NOP"); asm("NOP"); asm("clrwdt");} while (0)

#endif // #ifndef __YS83_84_H__
