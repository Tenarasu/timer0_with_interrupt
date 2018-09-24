#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS&WDTE_OFF&PWRTE_OFF&BOREN_EN&LVP_OFF);
unsigned char val=0;
void delay_ms();
void interrupt_ISR(void)
{
	TIMR0IF=0;
	TMR0=224;
	val=~val;
	PORTB=PORTC=PORTD=~val; // we can't read the Previous written value, as design is mode avoid it.
}
void delay_ms()
{
	T0CS=0;
	/* To select Prescalar bits which enables 1:32 */
	PS2=1;
	PS1=0;
	PS0=0;
	TMR0IF=0;
	TMR0IE=1;
	TMR0=224;  //Load timer to bring 31 cycles
}
int main()
{
	GIE=1;
	TRISB=TRISC=TRISD=0X00;
	PORTB=PORTC=PORTD=0X00;
	delay_ms();
	while(1)
	{
		
	}
}