
#include "mdt66fxxxx.h"


__at(0x0000) __sfr IAR;

__at(0x0001) __sfr TMR0;

__at(0x0002) __sfr PCL;

__at(0x0003) __sfr STATUS;
__at(0x0003) volatile __STATUSbits_t STATUSbits;

__at(0x0004) __sfr MSR;

__at(0x0005) __sfr PORTA;
__at(0x0005) volatile __PORTAbits_t PORTAbits;

__at(0x0006) __sfr PORTB;
__at(0x0006) volatile __PORTBbits_t PORTBbits;

__at(0x0007) __sfr PORTC;
__at(0x0007) volatile __PORTCbits_t PORTCbits;

__at(0x0008) __sfr PORTD;
__at(0x0008) volatile __PORTDbits_t PORTDbits;

__at(0x000A) __sfr PCLATH;

__at(0x000B) __sfr INTS;
__at(0x000B) volatile __INTSbits_t INTSbits;

__at(0x000C) __sfr PIFB1;
__at(0x000C) volatile __PIFB1bits_t PIFB1bits;

__at(0x000D) __sfr PIFB2;
__at(0x000D) volatile __PIFB2bits_t PIFB2bits;

__at(0x000E) __sfr TMR1L;

__at(0x000F) __sfr TMR1H;

__at(0x0010) __sfr T1STA;
__at(0x0010) volatile __T1STAbits_t T1STAbits;

__at(0x0011) __sfr SSP1STAT;
__at(0x0011) volatile __SSP1STATbits_t SSP1STATbits;

__at(0x0012) __sfr SSP1CON1;
__at(0x0012) volatile __SSP1CON1bits_t SSP1CON1bits;

__at(0x0013) __sfr SSP1CON2;
__at(0x0013) volatile __SSP1CON2bits_t SSP1CON2bits;

__at(0x0014) __sfr SSP1CON3;
__at(0x0014) volatile __SSP1CON3bits_t SSP1CON3bits;

__at(0x0015) __sfr SSP1MSK;

__at(0x0016) __sfr SSP1ADD;

__at(0x0017) __sfr SSP1BUF;

__at(0x0018) __sfr WDTCON;
__at(0x0018) volatile __WDTCONbits_t WDTCONbits;

__at(0x0019) __sfr PIFB3;
__at(0x0019) volatile __PIFB3bits_t PIFB3bits;

__at(0x001A) __sfr PWMCON;
__at(0x001A) volatile __PWMCONbits_t PWMCONbits;

__at(0x001E) __sfr ADRESH;

__at(0x0081) __sfr OPT_REG;
__at(0x0081) volatile __OPT_REGbits_t OPT_REGbits;

__at(0x0085) __sfr CPIOA;
__at(0x0085) volatile __CPIOAbits_t CPIOAbits;

__at(0x0086) __sfr CPIOB;
__at(0x0086) volatile __CPIOBbits_t CPIOBbits;

__at(0x0087) __sfr CPIOC;
__at(0x0087) volatile __CPIOCbits_t CPIOCbits;

__at(0x0088) __sfr CPIOD;
__at(0x0088) volatile __CPIODbits_t CPIODbits;

__at(0x008E) __sfr PSTA;
__at(0x008E) volatile __PSTAbits_t PSTAbits;

__at(0x008F) __sfr OSCCON;
__at(0x008F) volatile __OSCCONbits_t OSCCONbits;

__at(0x0091) __sfr ADINS;
__at(0x0091) volatile __ADINSbits_t ADINSbits;

__at(0x0092) __sfr IRCTRIML;

__at(0x0093) __sfr IRCTRIMH;
__at(0x0093) volatile __IRCTRIMHbits_t IRCTRIMHbits;

__at(0x0095) __sfr PAPHR;
__at(0x0095) volatile __PAPHRbits_t PAPHRbits;

__at(0x0096) __sfr PBPHR;
__at(0x0096) volatile __PBPHRbits_t PBPHRbits;

__at(0x0097) __sfr PCPHR;
__at(0x0097) volatile __PCPHRbits_t PCPHRbits;

__at(0x0098) __sfr PDPHR;
__at(0x0098) volatile __PDPHRbits_t PDPHRbits;

__at(0x0099) __sfr PAINTR;
__at(0x0099) volatile __PAINTRbits_t PAINTRbits;

__at(0x009A) __sfr PBINTR;
__at(0x009A) volatile __PBINTRbits_t PBINTRbits;

__at(0x009E) __sfr ADRESL;

__at(0x009F) __sfr ADC0TH;

__at(0x0112) __sfr PRL0L;

__at(0x0113) __sfr PRL1L;

__at(0x0117) __sfr T1PRLL;

__at(0x0118) __sfr ET1PRL;

__at(0x011E) __sfr ADC0CN;
__at(0x011E) volatile __ADC0CNbits_t ADC0CNbits;

__at(0x0190) __sfr CSCTL;
__at(0x0190) volatile __CSCTLbits_t CSCTLbits;

__at(0x0191) __sfr THCTL;
__at(0x0191) volatile __THCTLbits_t THCTLbits;

__at(0x0192) __sfr PWMOL;

__at(0x0193) __sfr PWM1L;

__at(0x0194) __sfr CHRLTH;

__at(0x0195) __sfr CHRLTL;

__at(0x0196) __sfr CHSELH;

__at(0x0197) __sfr CHSELL;

__at(0x0198) __sfr EPR0;

__at(0x0199) __sfr EPR1;

__at(0x019A) __sfr T1PRLH;

__at(0x019B) __sfr CSTMRH;

__at(0x019C) __sfr CSTMRL;

__at(0x019D) __sfr ADS0;
__at(0x019D) volatile __ADS0bits_t ADS0bits;

__at(0x019E) __sfr CSANA0;
__at(0x019E) volatile __CSANA0bits_t CSANA0bits;

__at(0x019F) __sfr CSANA1;
__at(0x019F) volatile __CSANA1bits_t CSANA1bits;

