#ifndef	__MDT66FXXXX_H__
#define	__MDT66FXXXX_H__

#ifndef NO_ADDR_DEFINES
#define	IAR_ADDR			0x0000
#define	TMR0_ADDR			0x0001
#define	PCL_ADDR			0x0002
#define	STATUS_ADDR			0x0003
#define	MSR_ADDR			0x0004
#define	PORTA_ADDR			0x0005
#define	PORTB_ADDR			0x0006
#define	PORTC_ADDR			0x0007
#define	PORTD_ADDR			0x0008
#define	PCLATH_ADDR			0x000A
#define	INTS_ADDR			0x000B
#define	PIFB1_ADDR			0x000C
#define	PIFB2_ADDR			0x000D
#define	TMR1L_ADDR			0x000E
#define	TMR1H_ADDR			0x000F
#define	T1STA_ADDR			0x0010
#define	SSP1STAT_ADDR			0x0011
#define	SSP1CON1_ADDR			0x0012
#define	SSP1CON2_ADDR			0x0013
#define	SSP1CON3_ADDR			0x0014
#define	SSP1MSK_ADDR			0x0015
#define	SSP1ADD_ADDR			0x0016
#define	SSP1BUF_ADDR			0x0017
#define	WDTCON_ADDR			0x0018
#define	PIFB3_ADDR			0x0019
#define	PWMCON_ADDR			0x001A
#define	ADRESH_ADDR			0x001E
#define	OPT_REG_ADDR			0x0081
#define	CPIOA_ADDR			0x0085
#define	CPIOB_ADDR			0x0086
#define	CPIOC_ADDR			0x0087
#define	CPIOD_ADDR			0x0088
#define	PSTA_ADDR			0x008E
#define	OSCCON_ADDR			0x008F
#define	ADINS_ADDR			0x0091
#define	IRCTRIML_ADDR			0x0092
#define	IRCTRIMH_ADDR			0x0093
#define	PAPHR_ADDR			0x0095
#define	PBPHR_ADDR			0x0096
#define	PCPHR_ADDR			0x0097
#define	PDPHR_ADDR			0x0098
#define	PAINTR_ADDR			0x0099
#define	PBINTR_ADDR			0x009A
#define	ADRESL_ADDR			0x009E
#define	ADC0TH_ADDR			0x009F
#define	PRL0L_ADDR			0x0112
#define	PRL1L_ADDR			0x0113
#define	T1PRLL_ADDR			0x0117
#define	ET1PRL_ADDR			0x0118
#define	ADC0CN_ADDR			0x011E
#define	CSCTL_ADDR			0x0190
#define	THCTL_ADDR			0x0191
#define	PWMOL_ADDR			0x0192
#define	PWM1L_ADDR			0x0193
#define	CHRLTH_ADDR			0x0194
#define	CHRLTL_ADDR			0x0195
#define	CHSELH_ADDR			0x0196
#define	CHSELL_ADDR			0x0197
#define	EPR0_ADDR			0x0198
#define	EPR1_ADDR			0x0199
#define	T1PRLH_ADDR			0x019A
#define	CSTMRH_ADDR			0x019B
#define	CSTMRL_ADDR			0x019C
#define	ADS0_ADDR			0x019D
#define	CSANA0_ADDR			0x019E
#define	CSANA1_ADDR			0x019F
#endif // #ifndef NO_ADDR_DEFINES

//	Register Definitions
extern __at(0x0000) __sfr IAR;
extern __at(0x0001) __sfr TMR0;
extern __at(0x0002) __sfr PCL;
//        STATUS  Bits
extern __at(0x0003) __sfr STATUS;
typedef union
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
}__STATUSbits_t;
extern __at(0x0003) volatile __STATUSbits_t STATUSbits;

#define _C			0x01
#define _HC			0x02
#define _Z			0x04
#define _PF			0x08
#define _TF			0x10
#define _RP0			0x20
#define _RP1			0x40
#define _IRP			0x80
//===========

extern __at(0x0004) __sfr MSR;
//        PORTA  Bits
extern __at(0x0005) __sfr PORTA;
typedef union
{
	struct
	{
	unsigned	PA0			: 1;
	unsigned	PA1			: 1;
	unsigned	PA2			: 1;
	unsigned	PA3			: 1;
	unsigned	PA4			: 1;
	unsigned	PA5			: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__PORTAbits_t;
extern __at(0x0005) volatile __PORTAbits_t PORTAbits;

#define _PA0			0x01
#define _PA1			0x02
#define _PA2			0x04
#define _PA3			0x08
#define _PA4			0x10
#define _PA5			0x20
//===========

//        PORTB  Bits
extern __at(0x0006) __sfr PORTB;
typedef union
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
}__PORTBbits_t;
extern __at(0x0006) volatile __PORTBbits_t PORTBbits;

#define _PB0			0x01
#define _PB1			0x02
#define _PB2			0x04
#define _PB3			0x08
#define _PB4			0x10
#define _PB5			0x20
#define _PB6			0x40
#define _PB7			0x80
//===========

//        PORTC  Bits
extern __at(0x0007) __sfr PORTC;
typedef union
{
	struct
	{
	unsigned	PC0			: 1;
	unsigned	PC1			: 1;
	unsigned	PC2			: 1;
	unsigned	PC3			: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__PORTCbits_t;
extern __at(0x0007) volatile __PORTCbits_t PORTCbits;

#define _PC0			0x01
#define _PC1			0x02
#define _PC2			0x04
#define _PC3			0x08
//===========

//        PORTD  Bits
extern __at(0x0008) __sfr PORTD;
typedef union
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
}__PORTDbits_t;
extern __at(0x0008) volatile __PORTDbits_t PORTDbits;

#define _PD0			0x01
#define _PD1			0x02
#define _PD2			0x04
#define _PD3			0x08
#define _PD4			0x10
#define _PD5			0x20
#define _PD6			0x40
#define _PD7			0x80
//===========

extern __at(0x000A) __sfr PCLATH;
//        INTS  Bits
extern __at(0x000B) __sfr INTS;
typedef union
{
	struct
	{
	unsigned	PAIF			: 1;
	unsigned	INT0F			: 1;
	unsigned	TIF			: 1;
	unsigned	PAIE			: 1;
	unsigned	INT0E			: 1;
	unsigned	TIS			: 1;
	unsigned	PE1E			: 1;
	unsigned	GIE			: 1;
	};
}__INTSbits_t;
extern __at(0x000B) volatile __INTSbits_t INTSbits;

#define _PAIF			0x01
#define _INT0F			0x02
#define _TIF			0x04
#define _PAIE			0x08
#define _INT0E			0x10
#define _TIS			0x20
#define _PE1E			0x40
#define _GIE			0x80
//===========

//        PIFB1  Bits
extern __at(0x000C) __sfr PIFB1;
typedef union
{
	struct
	{
	unsigned	TMR1IF			: 1;
	unsigned	OSFIF			: 1;
	unsigned	ADCIF			: 1;
	unsigned	INT1F			: 1;
	unsigned	TMR1IE			: 1;
	unsigned	OSFIE			: 1;
	unsigned	ADCIE			: 1;
	unsigned	INT1E			: 1;
	};
}__PIFB1bits_t;
extern __at(0x000C) volatile __PIFB1bits_t PIFB1bits;

#define _TMR1IF			0x01
#define _OSFIF			0x02
#define _ADCIF			0x04
#define _INT1F			0x08
#define _TMR1IE			0x10
#define _OSFIE			0x20
#define _ADCIE			0x40
#define _INT1E			0x80
//===========

//        PIFB2  Bits
extern __at(0x000D) __sfr PIFB2;
typedef union
{
	struct
	{
	unsigned	PWMIF			: 1;
	unsigned	PBIF			: 1;
	unsigned	CSIF			: 1;
	unsigned	SSP1IF			: 1;
	unsigned	PWMIE			: 1;
	unsigned	PBIE			: 1;
	unsigned	CSIE			: 1;
	unsigned	SSP1IE			: 1;
	};
}__PIFB2bits_t;
extern __at(0x000D) volatile __PIFB2bits_t PIFB2bits;

#define _PWMIF			0x01
#define _PBIF			0x02
#define _CSIF			0x04
#define _SSP1IF			0x08
#define _PWMIE			0x10
#define _PBIE			0x20
#define _CSIE			0x40
#define _SSP1IE			0x80
//===========

extern __at(0x000E) __sfr TMR1L;
extern __at(0x000F) __sfr TMR1H;
//        T1STA  Bits
extern __at(0x0010) __sfr T1STA;
typedef union
{
	struct
	{
	unsigned	TMR1ON			: 1;
	unsigned	TMR1CS			: 1;
	unsigned	T1SYNC			: 1;
	unsigned	T1OSCEN			: 1;
	unsigned	T1CKPS0			: 1;
	unsigned	T1CKPS1			: 1;
	unsigned	TMR1GE			: 1;
	unsigned	T1GINV			: 1;
	};
}__T1STAbits_t;
extern __at(0x0010) volatile __T1STAbits_t T1STAbits;

#define _TMR1ON			0x01
#define _TMR1CS			0x02
#define _T1SYNC			0x04
#define _T1OSCEN			0x08
#define _T1CKPS0			0x10
#define _T1CKPS1			0x20
#define _TMR1GE			0x40
#define _T1GINV			0x80
//===========

//        SSP1STAT  Bits
extern __at(0x0011) __sfr SSP1STAT;
typedef union
{
	struct
	{
	unsigned	BF			: 1;
	unsigned	UA			: 1;
	unsigned	R_W			: 1;
	unsigned	S			: 1;
	unsigned	P			: 1;
	unsigned	D_A			: 1;
	unsigned	CKE			: 1;
	unsigned				: 1;
	};
}__SSP1STATbits_t;
extern __at(0x0011) volatile __SSP1STATbits_t SSP1STATbits;

#define _BF			0x01
#define _UA			0x02
#define _R_W			0x04
#define _S			0x08
#define _P			0x10
#define _D_A			0x20
#define _CKE			0x40
//===========

//        SSP1CON1  Bits
extern __at(0x0012) __sfr SSP1CON1;
typedef union
{
	struct
	{
	unsigned	SSP1M0			: 1;
	unsigned	SSP1M1			: 1;
	unsigned	SSP1M2			: 1;
	unsigned	SSP1M3			: 1;
	unsigned	CKP			: 1;
	unsigned	SSP1EN			: 1;
	unsigned	SSP1OV			: 1;
	unsigned	WCOL			: 1;
	};
}__SSP1CON1bits_t;
extern __at(0x0012) volatile __SSP1CON1bits_t SSP1CON1bits;

#define _SSP1M0			0x01
#define _SSP1M1			0x02
#define _SSP1M2			0x04
#define _SSP1M3			0x08
#define _CKP			0x10
#define _SSP1EN			0x20
#define _SSP1OV			0x40
#define _WCOL			0x80
//===========

//        SSP1CON2  Bits
extern __at(0x0013) __sfr SSP1CON2;
typedef union
{
	struct
	{
	unsigned	SEN			: 1;
	unsigned	RSEN			: 1;
	unsigned	PEN			: 1;
	unsigned	RCEN			: 1;
	unsigned	ACKEN			: 1;
	unsigned	ACKDT			: 1;
	unsigned	ACKSTAT			: 1;
	unsigned	GCEN			: 1;
	};
}__SSP1CON2bits_t;
extern __at(0x0013) volatile __SSP1CON2bits_t SSP1CON2bits;

#define _SEN			0x01
#define _RSEN			0x02
#define _PEN			0x04
#define _RCEN			0x08
#define _ACKEN			0x10
#define _ACKDT			0x20
#define _ACKSTAT			0x40
#define _GCEN			0x80
//===========

//        SSP1CON3  Bits
extern __at(0x0014) __sfr SSP1CON3;
typedef union
{
	struct
	{
	unsigned	DHEN			: 1;
	unsigned	AHEN			: 1;
	unsigned	SBCDE			: 1;
	unsigned				: 1;
	unsigned	BOEN			: 1;
	unsigned	SCIE			: 1;
	unsigned	PCIE			: 1;
	unsigned	ACKTIM			: 1;
	};
}__SSP1CON3bits_t;
extern __at(0x0014) volatile __SSP1CON3bits_t SSP1CON3bits;

#define _DHEN			0x01
#define _AHEN			0x02
#define _SBCDE			0x04
#define _BOEN			0x10
#define _SCIE			0x20
#define _PCIE			0x40
#define _ACKTIM			0x80
//===========

extern __at(0x0015) __sfr SSP1MSK;
extern __at(0x0016) __sfr SSP1ADD;
extern __at(0x0017) __sfr SSP1BUF;
//        WDTCON  Bits
extern __at(0x0018) __sfr WDTCON;
typedef union
{
	struct
	{
	unsigned	SWDTEN			: 1;
	unsigned	WDTPS0			: 1;
	unsigned	WDTPS1			: 1;
	unsigned	WDTPS2			: 1;
	unsigned	WDTPS3			: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__WDTCONbits_t;
extern __at(0x0018) volatile __WDTCONbits_t WDTCONbits;

#define _SWDTEN			0x01
#define _WDTPS0			0x02
#define _WDTPS1			0x04
#define _WDTPS2			0x08
#define _WDTPS3			0x10
//===========

//        PIFB3  Bits
extern __at(0x0019) __sfr PIFB3;
typedef union
{
	struct
	{
	unsigned	BCL1IF			: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned	BCL1IE			: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__PIFB3bits_t;
extern __at(0x0019) volatile __PIFB3bits_t PIFB3bits;

#define _BCL1IF			0x01
#define _BCL1IE			0x10
//===========

//        PWMCON  Bits
extern __at(0x001A) __sfr PWMCON;
typedef union
{
	struct
	{
	unsigned	T1GSS			: 1;
	unsigned	TMR0EN			: 1;
	unsigned	PWM0EN			: 1;
	unsigned	PWM1EN			: 1;
	unsigned	PWM0OE			: 1;
	unsigned	PWM1OE			: 1;
	unsigned	PWMFS			: 1;
	unsigned				: 1;
	};
}__PWMCONbits_t;
extern __at(0x001A) volatile __PWMCONbits_t PWMCONbits;

#define _T1GSS			0x01
#define _TMR0EN			0x02
#define _PWM0EN			0x04
#define _PWM1EN			0x08
#define _PWM0OE			0x10
#define _PWM1OE			0x20
#define _PWMFS			0x40
//===========

extern __at(0x001E) __sfr ADRESH;
//        OPT_REG  Bits
extern __at(0x0081) __sfr OPT_REG;
typedef union
{
	struct
	{
	unsigned	PS0			: 1;
	unsigned	PS1			: 1;
	unsigned	PS2			: 1;
	unsigned	PSC			: 1;
	unsigned	TCE			: 1;
	unsigned	TCS			: 1;
	unsigned	INT0EG			: 1;
	unsigned	INT1EG			: 1;
	};
}__OPT_REGbits_t;
extern __at(0x0081) volatile __OPT_REGbits_t OPT_REGbits;

#define _PS0			0x01
#define _PS1			0x02
#define _PS2			0x04
#define _PSC			0x08
#define _TCE			0x10
#define _TCS			0x20
#define _INT0EG			0x40
#define _INT1EG			0x80
//===========

//        CPIOA  Bits
extern __at(0x0085) __sfr CPIOA;
typedef union
{
	struct
	{
	unsigned	CPIOA0			: 1;
	unsigned	CPIOA1			: 1;
	unsigned	CPIOA2			: 1;
	unsigned	CPIOA3			: 1;
	unsigned	CPIOA4			: 1;
	unsigned	CPIOA5			: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__CPIOAbits_t;
extern __at(0x0085) volatile __CPIOAbits_t CPIOAbits;

#define _CPIOA0			0x01
#define _CPIOA1			0x02
#define _CPIOA2			0x04
#define _CPIOA3			0x08
#define _CPIOA4			0x10
#define _CPIOA5			0x20
//===========

//        CPIOB  Bits
extern __at(0x0086) __sfr CPIOB;
typedef union
{
	struct
	{
	unsigned	CPIOB0			: 1;
	unsigned	CPIOB1			: 1;
	unsigned	CPIOB2			: 1;
	unsigned	CPIOB3			: 1;
	unsigned	CPIOB4			: 1;
	unsigned	CPIOB5			: 1;
	unsigned	CPIOB6			: 1;
	unsigned	CPIOB7			: 1;
	};
}__CPIOBbits_t;
extern __at(0x0086) volatile __CPIOBbits_t CPIOBbits;

#define _CPIOB0			0x01
#define _CPIOB1			0x02
#define _CPIOB2			0x04
#define _CPIOB3			0x08
#define _CPIOB4			0x10
#define _CPIOB5			0x20
#define _CPIOB6			0x40
#define _CPIOB7			0x80
//===========

//        CPIOC  Bits
extern __at(0x0087) __sfr CPIOC;
typedef union
{
	struct
	{
	unsigned	CPIOC0			: 1;
	unsigned	CPIOC1			: 1;
	unsigned	CPIOC2			: 1;
	unsigned	CPIOC3			: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__CPIOCbits_t;
extern __at(0x0087) volatile __CPIOCbits_t CPIOCbits;

#define _CPIOC0			0x01
#define _CPIOC1			0x02
#define _CPIOC2			0x04
#define _CPIOC3			0x08
//===========

//        CPIOD  Bits
extern __at(0x0088) __sfr CPIOD;
typedef union
{
	struct
	{
	unsigned	CPIOD0			: 1;
	unsigned	CPIOD1			: 1;
	unsigned	CPIOD2			: 1;
	unsigned	CPIOD3			: 1;
	unsigned	CPIOD4			: 1;
	unsigned	CPIOD5			: 1;
	unsigned	CPIOD6			: 1;
	unsigned	CPIOD7			: 1;
	};
}__CPIODbits_t;
extern __at(0x0088) volatile __CPIODbits_t CPIODbits;

#define _CPIOD0			0x01
#define _CPIOD1			0x02
#define _CPIOD2			0x04
#define _CPIOD3			0x08
#define _CPIOD4			0x10
#define _CPIOD5			0x20
#define _CPIOD6			0x40
#define _CPIOD7			0x80
//===========

//        PSTA  Bits
extern __at(0x008E) __sfr PSTA;
typedef union
{
	struct
	{
	unsigned	BOR			: 1;
	unsigned	POR			: 1;
	unsigned	IER			: 1;
	unsigned	MCR			: 1;
	unsigned	SBOREN			: 1;
	unsigned	ULPWUE			: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__PSTAbits_t;
extern __at(0x008E) volatile __PSTAbits_t PSTAbits;

#define _BOR			0x01
#define _POR			0x02
#define _IER			0x04
#define _MCR			0x08
#define _SBOREN			0x10
#define _ULPWUE			0x20
//===========

//        OSCCON  Bits
extern __at(0x008F) __sfr OSCCON;
typedef union
{
	struct
	{
	unsigned	SCS			: 1;
	unsigned	LTS			: 1;
	unsigned	HTS			: 1;
	unsigned	OSTS			: 1;
	unsigned	IRCF0			: 1;
	unsigned	IRCF1			: 1;
	unsigned	IRCF2			: 1;
	unsigned				: 1;
	};
}__OSCCONbits_t;
extern __at(0x008F) volatile __OSCCONbits_t OSCCONbits;

#define _SCS			0x01
#define _LTS			0x02
#define _HTS			0x04
#define _OSTS			0x08
#define _IRCF0			0x10
#define _IRCF1			0x20
#define _IRCF2			0x40
//===========

//        ADINS  Bits
extern __at(0x0091) __sfr ADINS;
typedef union
{
	struct
	{
	unsigned	ANS0			: 1;
	unsigned	ANS1			: 1;
	unsigned	ANS2			: 1;
	unsigned	ANS3			: 1;
	unsigned	ANS4			: 1;
	unsigned	ANS5			: 1;
	unsigned	ANS6			: 1;
	unsigned	ANS7			: 1;
	};
}__ADINSbits_t;
extern __at(0x0091) volatile __ADINSbits_t ADINSbits;

#define _ANS0			0x01
#define _ANS1			0x02
#define _ANS2			0x04
#define _ANS3			0x08
#define _ANS4			0x10
#define _ANS5			0x20
#define _ANS6			0x40
#define _ANS7			0x80
//===========

extern __at(0x0092) __sfr IRCTRIML;
//        IRCTRIMH  Bits
extern __at(0x0093) __sfr IRCTRIMH;
typedef union
{
	struct
	{
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned	IRCTEN			: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__IRCTRIMHbits_t;
extern __at(0x0093) volatile __IRCTRIMHbits_t IRCTRIMHbits;

#define _IRCTEN			0x20
//===========

//        PAPHR  Bits
extern __at(0x0095) __sfr PAPHR;
typedef union
{
	struct
	{
	unsigned	PAPHR0			: 1;
	unsigned	PAPHR1			: 1;
	unsigned	PAPHR2			: 1;
	unsigned	PAPHR3			: 1;
	unsigned	PAPHR4			: 1;
	unsigned	PAPHR5			: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__PAPHRbits_t;
extern __at(0x0095) volatile __PAPHRbits_t PAPHRbits;

#define _PAPHR0			0x01
#define _PAPHR1			0x02
#define _PAPHR2			0x04
#define _PAPHR3			0x08
#define _PAPHR4			0x10
#define _PAPHR5			0x20
//===========

//        PBPHR  Bits
extern __at(0x0096) __sfr PBPHR;
typedef union
{
	struct
	{
	unsigned	PBPHR0			: 1;
	unsigned	PBPHR1			: 1;
	unsigned	PBPHR2			: 1;
	unsigned	PBPHR3			: 1;
	unsigned	PBPHR4			: 1;
	unsigned	PBPHR5			: 1;
	unsigned	PBPHR6			: 1;
	unsigned	PBPHR7			: 1;
	};
}__PBPHRbits_t;
extern __at(0x0096) volatile __PBPHRbits_t PBPHRbits;

#define _PBPHR0			0x01
#define _PBPHR1			0x02
#define _PBPHR2			0x04
#define _PBPHR3			0x08
#define _PBPHR4			0x10
#define _PBPHR5			0x20
#define _PBPHR6			0x40
#define _PBPHR7			0x80
//===========

//        PCPHR  Bits
extern __at(0x0097) __sfr PCPHR;
typedef union
{
	struct
	{
	unsigned	PCPHR0			: 1;
	unsigned	PCPHR1			: 1;
	unsigned	PCPHR2			: 1;
	unsigned	PCPHR3			: 1;
	unsigned	PDC0			: 1;
	unsigned	PDC1			: 1;
	unsigned	PDC2			: 1;
	unsigned	PDC3			: 1;
	};
}__PCPHRbits_t;
extern __at(0x0097) volatile __PCPHRbits_t PCPHRbits;

#define _PCPHR0			0x01
#define _PCPHR1			0x02
#define _PCPHR2			0x04
#define _PCPHR3			0x08
#define _PDC0			0x10
#define _PDC1			0x20
#define _PDC2			0x40
#define _PDC3			0x80
//===========

//        PDPHR  Bits
extern __at(0x0098) __sfr PDPHR;
typedef union
{
	struct
	{
	unsigned	PDPHR0			: 1;
	unsigned	PDPHR1			: 1;
	unsigned	PDPHR2			: 1;
	unsigned	PDPHR3			: 1;
	unsigned	PDPHR4			: 1;
	unsigned	PDPHR5			: 1;
	unsigned	PDPHR6			: 1;
	unsigned	PDPHR7			: 1;
	};
}__PDPHRbits_t;
extern __at(0x0098) volatile __PDPHRbits_t PDPHRbits;

#define _PDPHR0			0x01
#define _PDPHR1			0x02
#define _PDPHR2			0x04
#define _PDPHR3			0x08
#define _PDPHR4			0x10
#define _PDPHR5			0x20
#define _PDPHR6			0x40
#define _PDPHR7			0x80
//===========

//        PAINTR  Bits
extern __at(0x0099) __sfr PAINTR;
typedef union
{
	struct
	{
	unsigned	PAINTR0			: 1;
	unsigned	PAINTR1			: 1;
	unsigned	PAINTR2			: 1;
	unsigned	PAINTR3			: 1;
	unsigned	PAINTR4			: 1;
	unsigned	PAINTR5			: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__PAINTRbits_t;
extern __at(0x0099) volatile __PAINTRbits_t PAINTRbits;

#define _PAINTR0			0x01
#define _PAINTR1			0x02
#define _PAINTR2			0x04
#define _PAINTR3			0x08
#define _PAINTR4			0x10
#define _PAINTR5			0x20
//===========

//        PBINTR  Bits
extern __at(0x009A) __sfr PBINTR;
typedef union
{
	struct
	{
	unsigned	PBINTR0			: 1;
	unsigned	PBINTR1			: 1;
	unsigned	PBINTR2			: 1;
	unsigned	PBINTR3			: 1;
	unsigned	PBINTR4			: 1;
	unsigned	PBINTR5			: 1;
	unsigned	PBINTR6			: 1;
	unsigned	PBINTR7			: 1;
	};
}__PBINTRbits_t;
extern __at(0x009A) volatile __PBINTRbits_t PBINTRbits;

#define _PBINTR0			0x01
#define _PBINTR1			0x02
#define _PBINTR2			0x04
#define _PBINTR3			0x08
#define _PBINTR4			0x10
#define _PBINTR5			0x20
#define _PBINTR6			0x40
#define _PBINTR7			0x80
//===========

extern __at(0x009E) __sfr ADRESL;
extern __at(0x009F) __sfr ADC0TH;
extern __at(0x0112) __sfr PRL0L;
extern __at(0x0113) __sfr PRL1L;
extern __at(0x0117) __sfr T1PRLL;
extern __at(0x0118) __sfr ET1PRL;
//        ADC0CN  Bits
extern __at(0x011E) __sfr ADC0CN;
typedef union
{
	struct
	{
	unsigned	CM0			: 1;
	unsigned	CM1			: 1;
	unsigned	GO_DONE			: 1;
	unsigned	ADC_EN			: 1;
	unsigned	SC0			: 1;
	unsigned	SC1			: 1;
	unsigned	ADFM			: 1;
	unsigned	ADCTHSEL			: 1;
	};
}__ADC0CNbits_t;
extern __at(0x011E) volatile __ADC0CNbits_t ADC0CNbits;

#define _CM0			0x01
#define _CM1			0x02
#define _GO_DONE			0x04
#define _ADC_EN			0x08
#define _SC0			0x10
#define _SC1			0x20
#define _ADFM			0x40
#define _ADCTHSEL			0x80
//===========

//        CSCTL  Bits
extern __at(0x0190) __sfr CSCTL;
typedef union
{
	struct
	{
	unsigned	CSACU0			: 1;
	unsigned	CSACU1			: 1;
	unsigned	CSACU2			: 1;
	unsigned	CSINTS			: 1;
	unsigned	CSBUSY			: 1;
	unsigned	XRAM			: 1;
	unsigned	RAMEN			: 1;
	unsigned	CSEN			: 1;
	};
}__CSCTLbits_t;
extern __at(0x0190) volatile __CSCTLbits_t CSCTLbits;

#define _CSACU0			0x01
#define _CSACU1			0x02
#define _CSACU2			0x04
#define _CSINTS			0x08
#define _CSBUSY			0x10
#define _XRAM			0x20
#define _RAMEN			0x40
#define _CSEN			0x80
//===========

//        THCTL  Bits
extern __at(0x0191) __sfr THCTL;
typedef union
{
	struct
	{
	unsigned	THDS0			: 1;
	unsigned	THDS1			: 1;
	unsigned	THMOD0			: 1;
	unsigned	THMOD1			: 1;
	unsigned	THMOD2			: 1;
	unsigned	THGAP0			: 1;
	unsigned	THGAP1			: 1;
	unsigned	THFIB			: 1;
	};
}__THCTLbits_t;
extern __at(0x0191) volatile __THCTLbits_t THCTLbits;

#define _THDS0			0x01
#define _THDS1			0x02
#define _THMOD0			0x04
#define _THMOD1			0x08
#define _THMOD2			0x10
#define _THGAP0			0x20
#define _THGAP1			0x40
#define _THFIB			0x80
//===========

extern __at(0x0192) __sfr PWMOL;
extern __at(0x0193) __sfr PWM1L;
extern __at(0x0194) __sfr CHRLTH;
extern __at(0x0195) __sfr CHRLTL;
extern __at(0x0196) __sfr CHSELH;
extern __at(0x0197) __sfr CHSELL;
extern __at(0x0198) __sfr EPR0;
extern __at(0x0199) __sfr EPR1;
extern __at(0x019A) __sfr T1PRLH;
extern __at(0x019B) __sfr CSTMRH;
extern __at(0x019C) __sfr CSTMRL;
//        ADS0  Bits
extern __at(0x019D) __sfr ADS0;
typedef union
{
	struct
	{
	unsigned	VREFSEL			: 1;
	unsigned				: 1;
	unsigned	REFSL0			: 1;
	unsigned	REFSL1			: 1;
	unsigned	CHNSEL0			: 1;
	unsigned	CHNSEL1			: 1;
	unsigned	CHNSEL2			: 1;
	unsigned	CHNSEL3			: 1;
	};
}__ADS0bits_t;
extern __at(0x019D) volatile __ADS0bits_t ADS0bits;

#define _VREFSEL			0x01
#define _REFSL0			0x04
#define _REFSL1			0x08
#define _CHNSEL0			0x10
#define _CHNSEL1			0x20
#define _CHNSEL2			0x40
#define _CHNSEL3			0x80
//===========

//        CSANA0  Bits
extern __at(0x019E) __sfr CSANA0;
typedef union
{
	struct
	{
	unsigned	VTSEL0			: 1;
	unsigned	VTSEL1			: 1;
	unsigned	CMPTRM0			: 1;
	unsigned	CMPTRM1			: 1;
	unsigned	BSTRM0			: 1;
	unsigned	BSTRM1			: 1;
	unsigned	BSTRM2			: 1;
	unsigned				: 1;
	};
}__CSANA0bits_t;
extern __at(0x019E) volatile __CSANA0bits_t CSANA0bits;

#define _VTSEL0			0x01
#define _VTSEL1			0x02
#define _CMPTRM0			0x04
#define _CMPTRM1			0x08
#define _BSTRM0			0x10
#define _BSTRM1			0x20
#define _BSTRM2			0x40
//===========

//        CSANA1  Bits
extern __at(0x019F) __sfr CSANA1;
typedef union
{
	struct
	{
	unsigned	CTTRM0			: 1;
	unsigned	CTTRM1			: 1;
	unsigned	CTTRM2			: 1;
	unsigned	DTTRM0			: 1;
	unsigned	DTTRM1			: 1;
	unsigned				: 1;
	unsigned				: 1;
	unsigned				: 1;
	};
}__CSANA1bits_t;
extern __at(0x019F) volatile __CSANA1bits_t CSANA1bits;

#define _CTTRM0			0x01
#define _CTTRM1			0x02
#define _CTTRM2			0x04
#define _DTTRM0			0x08
#define _DTTRM1			0x10
//===========

#ifndef NO_BIT_DEFINES

#define C			STATUSbits.C
#define HC			STATUSbits.HC
#define Z			STATUSbits.Z
#define PF			STATUSbits.PF
#define TF			STATUSbits.TF
#define RP0			STATUSbits.RP0
#define RP1			STATUSbits.RP1
#define IRP			STATUSbits.IRP

#define PA0			PORTAbits.PA0
#define PA1			PORTAbits.PA1
#define PA2			PORTAbits.PA2
#define PA3			PORTAbits.PA3
#define PA4			PORTAbits.PA4
#define PA5			PORTAbits.PA5

#define PB0			PORTBbits.PB0
#define PB1			PORTBbits.PB1
#define PB2			PORTBbits.PB2
#define PB3			PORTBbits.PB3
#define PB4			PORTBbits.PB4
#define PB5			PORTBbits.PB5
#define PB6			PORTBbits.PB6
#define PB7			PORTBbits.PB7

#define PC0			PORTCbits.PC0
#define PC1			PORTCbits.PC1
#define PC2			PORTCbits.PC2
#define PC3			PORTCbits.PC3

#define PD0			PORTDbits.PD0
#define PD1			PORTDbits.PD1
#define PD2			PORTDbits.PD2
#define PD3			PORTDbits.PD3
#define PD4			PORTDbits.PD4
#define PD5			PORTDbits.PD5
#define PD6			PORTDbits.PD6
#define PD7			PORTDbits.PD7

#define PAIF			INTSbits.PAIF
#define INT0F			INTSbits.INT0F
#define TIF			INTSbits.TIF
#define PAIE			INTSbits.PAIE
#define INT0E			INTSbits.INT0E
#define TIS			INTSbits.TIS
#define PE1E			INTSbits.PE1E
#define GIE			INTSbits.GIE

#define TMR1IF			PIFB1bits.TMR1IF
#define OSFIF			PIFB1bits.OSFIF
#define ADCIF			PIFB1bits.ADCIF
#define INT1F			PIFB1bits.INT1F
#define TMR1IE			PIFB1bits.TMR1IE
#define OSFIE			PIFB1bits.OSFIE
#define ADCIE			PIFB1bits.ADCIE
#define INT1E			PIFB1bits.INT1E

#define PWMIF			PIFB2bits.PWMIF
#define PBIF			PIFB2bits.PBIF
#define CSIF			PIFB2bits.CSIF
#define SSP1IF			PIFB2bits.SSP1IF
#define PWMIE			PIFB2bits.PWMIE
#define PBIE			PIFB2bits.PBIE
#define CSIE			PIFB2bits.CSIE
#define SSP1IE			PIFB2bits.SSP1IE

#define TMR1ON			T1STAbits.TMR1ON
#define TMR1CS			T1STAbits.TMR1CS
#define T1SYNC			T1STAbits.T1SYNC
#define T1OSCEN			T1STAbits.T1OSCEN
#define T1CKPS0			T1STAbits.T1CKPS0
#define T1CKPS1			T1STAbits.T1CKPS1
#define TMR1GE			T1STAbits.TMR1GE
#define T1GINV			T1STAbits.T1GINV

#define BF			SSP1STATbits.BF
#define UA			SSP1STATbits.UA
#define R_W			SSP1STATbits.R_W
#define S			SSP1STATbits.S
#define P			SSP1STATbits.P
#define D_A			SSP1STATbits.D_A
#define CKE			SSP1STATbits.CKE

#define SSP1M0			SSP1CON1bits.SSP1M0
#define SSP1M1			SSP1CON1bits.SSP1M1
#define SSP1M2			SSP1CON1bits.SSP1M2
#define SSP1M3			SSP1CON1bits.SSP1M3
#define CKP			SSP1CON1bits.CKP
#define SSP1EN			SSP1CON1bits.SSP1EN
#define SSP1OV			SSP1CON1bits.SSP1OV
#define WCOL			SSP1CON1bits.WCOL

#define SEN			SSP1CON2bits.SEN
#define RSEN			SSP1CON2bits.RSEN
#define PEN			SSP1CON2bits.PEN
#define RCEN			SSP1CON2bits.RCEN
#define ACKEN			SSP1CON2bits.ACKEN
#define ACKDT			SSP1CON2bits.ACKDT
#define ACKSTAT			SSP1CON2bits.ACKSTAT
#define GCEN			SSP1CON2bits.GCEN

#define DHEN			SSP1CON3bits.DHEN
#define AHEN			SSP1CON3bits.AHEN
#define SBCDE			SSP1CON3bits.SBCDE
#define BOEN			SSP1CON3bits.BOEN
#define SCIE			SSP1CON3bits.SCIE
#define PCIE			SSP1CON3bits.PCIE
#define ACKTIM			SSP1CON3bits.ACKTIM

#define SWDTEN			WDTCONbits.SWDTEN
#define WDTPS0			WDTCONbits.WDTPS0
#define WDTPS1			WDTCONbits.WDTPS1
#define WDTPS2			WDTCONbits.WDTPS2
#define WDTPS3			WDTCONbits.WDTPS3

#define BCL1IF			PIFB3bits.BCL1IF
#define BCL1IE			PIFB3bits.BCL1IE

#define T1GSS			PWMCONbits.T1GSS
#define TMR0EN			PWMCONbits.TMR0EN
#define PWM0EN			PWMCONbits.PWM0EN
#define PWM1EN			PWMCONbits.PWM1EN
#define PWM0OE			PWMCONbits.PWM0OE
#define PWM1OE			PWMCONbits.PWM1OE
#define PWMFS			PWMCONbits.PWMFS

#define PS0			OPT_REGbits.PS0
#define PS1			OPT_REGbits.PS1
#define PS2			OPT_REGbits.PS2
#define PSC			OPT_REGbits.PSC
#define TCE			OPT_REGbits.TCE
#define TCS			OPT_REGbits.TCS
#define INT0EG			OPT_REGbits.INT0EG
#define INT1EG			OPT_REGbits.INT1EG

#define CPIOA0			CPIOAbits.CPIOA0
#define CPIOA1			CPIOAbits.CPIOA1
#define CPIOA2			CPIOAbits.CPIOA2
#define CPIOA3			CPIOAbits.CPIOA3
#define CPIOA4			CPIOAbits.CPIOA4
#define CPIOA5			CPIOAbits.CPIOA5

#define CPIOB0			CPIOBbits.CPIOB0
#define CPIOB1			CPIOBbits.CPIOB1
#define CPIOB2			CPIOBbits.CPIOB2
#define CPIOB3			CPIOBbits.CPIOB3
#define CPIOB4			CPIOBbits.CPIOB4
#define CPIOB5			CPIOBbits.CPIOB5
#define CPIOB6			CPIOBbits.CPIOB6
#define CPIOB7			CPIOBbits.CPIOB7

#define CPIOC0			CPIOCbits.CPIOC0
#define CPIOC1			CPIOCbits.CPIOC1
#define CPIOC2			CPIOCbits.CPIOC2
#define CPIOC3			CPIOCbits.CPIOC3

#define CPIOD0			CPIODbits.CPIOD0
#define CPIOD1			CPIODbits.CPIOD1
#define CPIOD2			CPIODbits.CPIOD2
#define CPIOD3			CPIODbits.CPIOD3
#define CPIOD4			CPIODbits.CPIOD4
#define CPIOD5			CPIODbits.CPIOD5
#define CPIOD6			CPIODbits.CPIOD6
#define CPIOD7			CPIODbits.CPIOD7

#define BOR			PSTAbits.BOR
#define POR			PSTAbits.POR
#define IER			PSTAbits.IER
#define MCR			PSTAbits.MCR
#define SBOREN			PSTAbits.SBOREN
#define ULPWUE			PSTAbits.ULPWUE

#define SCS			OSCCONbits.SCS
#define LTS			OSCCONbits.LTS
#define HTS			OSCCONbits.HTS
#define OSTS			OSCCONbits.OSTS
#define IRCF0			OSCCONbits.IRCF0
#define IRCF1			OSCCONbits.IRCF1
#define IRCF2			OSCCONbits.IRCF2

#define ANS0			ADINSbits.ANS0
#define ANS1			ADINSbits.ANS1
#define ANS2			ADINSbits.ANS2
#define ANS3			ADINSbits.ANS3
#define ANS4			ADINSbits.ANS4
#define ANS5			ADINSbits.ANS5
#define ANS6			ADINSbits.ANS6
#define ANS7			ADINSbits.ANS7

#define IRCTEN			IRCTRIMHbits.IRCTEN

#define PAPHR0			PAPHRbits.PAPHR0
#define PAPHR1			PAPHRbits.PAPHR1
#define PAPHR2			PAPHRbits.PAPHR2
#define PAPHR3			PAPHRbits.PAPHR3
#define PAPHR4			PAPHRbits.PAPHR4
#define PAPHR5			PAPHRbits.PAPHR5

#define PBPHR0			PBPHRbits.PBPHR0
#define PBPHR1			PBPHRbits.PBPHR1
#define PBPHR2			PBPHRbits.PBPHR2
#define PBPHR3			PBPHRbits.PBPHR3
#define PBPHR4			PBPHRbits.PBPHR4
#define PBPHR5			PBPHRbits.PBPHR5
#define PBPHR6			PBPHRbits.PBPHR6
#define PBPHR7			PBPHRbits.PBPHR7

#define PCPHR0			PCPHRbits.PCPHR0
#define PCPHR1			PCPHRbits.PCPHR1
#define PCPHR2			PCPHRbits.PCPHR2
#define PCPHR3			PCPHRbits.PCPHR3
#define PDC0			PCPHRbits.PDC0
#define PDC1			PCPHRbits.PDC1
#define PDC2			PCPHRbits.PDC2
#define PDC3			PCPHRbits.PDC3

#define PDPHR0			PDPHRbits.PDPHR0
#define PDPHR1			PDPHRbits.PDPHR1
#define PDPHR2			PDPHRbits.PDPHR2
#define PDPHR3			PDPHRbits.PDPHR3
#define PDPHR4			PDPHRbits.PDPHR4
#define PDPHR5			PDPHRbits.PDPHR5
#define PDPHR6			PDPHRbits.PDPHR6
#define PDPHR7			PDPHRbits.PDPHR7

#define PAINTR0			PAINTRbits.PAINTR0
#define PAINTR1			PAINTRbits.PAINTR1
#define PAINTR2			PAINTRbits.PAINTR2
#define PAINTR3			PAINTRbits.PAINTR3
#define PAINTR4			PAINTRbits.PAINTR4
#define PAINTR5			PAINTRbits.PAINTR5

#define PBINTR0			PBINTRbits.PBINTR0
#define PBINTR1			PBINTRbits.PBINTR1
#define PBINTR2			PBINTRbits.PBINTR2
#define PBINTR3			PBINTRbits.PBINTR3
#define PBINTR4			PBINTRbits.PBINTR4
#define PBINTR5			PBINTRbits.PBINTR5
#define PBINTR6			PBINTRbits.PBINTR6
#define PBINTR7			PBINTRbits.PBINTR7

#define CM0			ADC0CNbits.CM0
#define CM1			ADC0CNbits.CM1
#define GO_DONE			ADC0CNbits.GO_DONE
#define ADC_EN			ADC0CNbits.ADC_EN
#define SC0			ADC0CNbits.SC0
#define SC1			ADC0CNbits.SC1
#define ADFM			ADC0CNbits.ADFM
#define ADCTHSEL			ADC0CNbits.ADCTHSEL

#define CSACU0			CSCTLbits.CSACU0
#define CSACU1			CSCTLbits.CSACU1
#define CSACU2			CSCTLbits.CSACU2
#define CSINTS			CSCTLbits.CSINTS
#define CSBUSY			CSCTLbits.CSBUSY
#define XRAM			CSCTLbits.XRAM
#define RAMEN			CSCTLbits.RAMEN
#define CSEN			CSCTLbits.CSEN

#define THDS0			THCTLbits.THDS0
#define THDS1			THCTLbits.THDS1
#define THMOD0			THCTLbits.THMOD0
#define THMOD1			THCTLbits.THMOD1
#define THMOD2			THCTLbits.THMOD2
#define THGAP0			THCTLbits.THGAP0
#define THGAP1			THCTLbits.THGAP1
#define THFIB			THCTLbits.THFIB

#define VREFSEL			ADS0bits.VREFSEL
#define REFSL0			ADS0bits.REFSL0
#define REFSL1			ADS0bits.REFSL1
#define CHNSEL0			ADS0bits.CHNSEL0
#define CHNSEL1			ADS0bits.CHNSEL1
#define CHNSEL2			ADS0bits.CHNSEL2
#define CHNSEL3			ADS0bits.CHNSEL3

#define VTSEL0			CSANA0bits.VTSEL0
#define VTSEL1			CSANA0bits.VTSEL1
#define CMPTRM0			CSANA0bits.CMPTRM0
#define CMPTRM1			CSANA0bits.CMPTRM1
#define BSTRM0			CSANA0bits.BSTRM0
#define BSTRM1			CSANA0bits.BSTRM1
#define BSTRM2			CSANA0bits.BSTRM2

#define CTTRM0			CSANA1bits.CTTRM0
#define CTTRM1			CSANA1bits.CTTRM1
#define CTTRM2			CSANA1bits.CTTRM2
#define DTTRM0			CSANA1bits.DTTRM0
#define DTTRM1			CSANA1bits.DTTRM1

#endif // #ifndef NO_BIT_DEFINES

#define	SLEEP()		__asm\
	sleep\
	nop\
	nop\
	__endasm;
#define	CLRWDT()	__asm\
	clrwt\
	__endasm;
#endif // #ifndef __MDT66FXXXX_H__
