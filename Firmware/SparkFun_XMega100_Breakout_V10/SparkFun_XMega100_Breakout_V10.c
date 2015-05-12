/*
    2-8-10
    Copyright Spark Fun Electronics© 2010
    Aaron Weiss
    aaron at sparkfun dot com
 
 	XMega100 BOB, pulses every other port pin to test solder connections
	Also, UART support is included, just commented out
*/

#include <stdio.h>
#include "clksys_driver.h"
//#include "usart.h"
 
#ifndef F_CPU  
#define F_CPU 32000000
#endif

#define EVEN 0x55 
#define ODD	 0xAA

//#define sbi(port,pinno) port.OUTSET=1<<pinno
//#define cbi(port,pinno) port.OUTCLR=1<<pinno 

///============Initialize Prototypes=========/////////////////
void clock_init(void);
//void UsartC_init(void);
void IoInit();
//int uart_putchar(char c, FILE *stream);
/////===================================////////////////////

int main(void)
{
	IoInit();
	clock_init();
	//UsartC_init();
    
	while(1)
	{	
		for(int i=0; i<8; i++)
		{
			//PORTA
			PORTA.OUTSET = ODD;
			_delay_ms(400);
			PORTA.OUTSET = 0;
			PORTA.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTA.OUTSET = EVEN;
			_delay_ms(400);
			PORTA.OUTSET = 0;
			PORTA.OUTCLR = 0xFF;
			_delay_ms(400);
			
			//PORTB
			PORTB.OUTSET = ODD;
			_delay_ms(400);
			PORTB.OUTSET = 0;
			PORTB.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTB.OUTSET = EVEN;
			_delay_ms(400);
			PORTB.OUTSET = 0;
			PORTB.OUTCLR = 0xFF;
			_delay_ms(400);
	
			//PORTC
			PORTC.OUTSET = ODD;
			_delay_ms(400);
			PORTC.OUTSET = 0;
			PORTC.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTC.OUTSET = EVEN;
			_delay_ms(400);
			PORTC.OUTSET = 0;
			PORTC.OUTCLR = 0xFF;
			_delay_ms(400);

			//PORTD
			PORTD.OUTSET = ODD;
			_delay_ms(400);
			PORTD.OUTSET = 0;
			PORTD.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTD.OUTSET = EVEN;
			_delay_ms(400);
			PORTD.OUTSET = 0;
			PORTD.OUTCLR = 0xFF;
			_delay_ms(400);

			//PORTE
			PORTE.OUTSET = ODD;
			_delay_ms(400);
			PORTE.OUTSET = 0;
			PORTE.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTE.OUTSET = EVEN;
			_delay_ms(400);
			PORTE.OUTSET = 0;
			PORTE.OUTCLR = 0xFF;
			_delay_ms(400);

			//PORTF
			PORTF.OUTSET = ODD;
			_delay_ms(400);
			PORTF.OUTSET = 0;
			PORTF.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTF.OUTSET = EVEN;
			_delay_ms(400);
			PORTF.OUTSET = 0;
			PORTF.OUTCLR = 0xFF;
			_delay_ms(400);

			//PORTH
			PORTH.OUTSET = ODD;
			_delay_ms(400);
			PORTH.OUTSET = 0;
			PORTH.OUTCLR = 0xFF;
			_delay_ms(10);

			PORTH.OUTSET = EVEN;
			_delay_ms(400);
			PORTH.OUTSET = 0;
			PORTH.OUTCLR = 0xFF;
			_delay_ms(400);

			//PORTJ
			PORTJ.OUTSET = ODD;
			_delay_ms(400);
			PORTJ.OUTSET = 0;
			PORTJ.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTJ.OUTSET = EVEN;
			_delay_ms(400);
			PORTJ.OUTSET = 0;
			PORTJ.OUTCLR = 0xFF;
			_delay_ms(400);

			//PORTK
			PORTK.OUTSET = ODD;
			_delay_ms(400);
			PORTK.OUTSET = 0;
			PORTK.OUTCLR = 0xFF;
			//_delay_ms(10);

			PORTK.OUTSET = EVEN;
			_delay_ms(400);
			PORTK.OUTSET = 0;
			PORTK.OUTCLR = 0xFF;
			_delay_ms(400);
		}		
	}
}

/*********************
 ****Initialize****
 *********************/

void clock_init(void)
{   
    CLKSYS_Enable( OSC_RC32MEN_bm ); //32MHz
	CLKSYS_Prescalers_Config( CLK_PSADIV_1_gc, CLK_PSBCDIV_1_1_gc );
	do {} while ( CLKSYS_IsReady( OSC_RC32MRDY_bm ) == 0 );
	CLKSYS_Main_ClockSource_Select( CLK_SCLKSEL_RC32M_gc );
	CLKSYS_Disable(OSC_RC2MCREF_bm);
	CLKSYS_AutoCalibration_Enable(OSC_RC32MCREF_bm,1);
}

//static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

/*void UsartC_init(void)
{
	usart_init(&PORTC, &USARTC0, 115200);

	stdout = &mystdout; //printf 
	usart_rx_buf_flush(); //remove bad data we got at startup
}*/

void IoInit()
{	
	//FUSEBYTE4 = 0xFE;
	PORTA.DIRSET = 0xFF;
	PORTB.DIRSET = 0xFF;
	PORTC.DIRSET = 0xFF;
	PORTD.DIRSET = 0xFF;	
	PORTE.DIRSET = 0xFF;
	PORTF.DIRSET = 0xFF;
	PORTH.DIRSET = 0xFF;
	PORTJ.DIRSET = 0xFF;
	PORTK.DIRSET = 0xFF;
}

/*int uart_putchar(char c, FILE *stream)
{
   if (c == '\n') uart_putchar('\r', stream);
   usart_send_byte(c);
   return 0;
}*/
