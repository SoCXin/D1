
#include "Typedef.h"

#ifndef _UART_H_
#define _UART_H_

#define UART_EN

#define SET_UART_OUTPUT()		do {CPIOA &= ~0X04;} while (0)		/* ÅäÖÃUART ÎªÊä³ö¿Ú*/
#define UART_H()					do {PORTA |= 0X04;} while (0)
#define UART_L()					do {PORTA &= ~0X04;} while (0)


extern void UartSend(u8 dat);
extern void UartString(const char *s);
extern void UartSendUintByDecimal(u16 *p, u8 num);
extern void UartSendUintByHex(u16 *p, u8 num);
extern void UartSendCap(u16 *p, u8 mode);

#endif

