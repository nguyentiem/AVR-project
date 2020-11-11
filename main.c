
#include <mega328p.h>
#include <delay.h>
#include <stdio.h>

char data_recevses[100];
int i =0;
int j = 0 ;
//
//interrupt [SPI_STC] void spi_isr(void)
//{
//
// 
//}
interrupt [SPI_STC] void spi_isr(void)
{
   data_recevses[i] = SPDR; /*read out new data received*/ 
       i++; 
      if(i>100) i=0;
}
void main(void)
{
UCSR0A = 0x00; 
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
//UCSR0C=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);
UBRR0H = 0x00;
UBRR0L = 0x67;


DDRB &= (~(1 << 2)) &(~(1 << 3))&(~(1 << 5));
DDRB |=(1<<4); 

   
SPCR = 0xC1;        
#asm
in r30,spsr
in r30,spdr
#endasm
// Global enable interrupts
#asm("sei")
SPSR =0x00;  //   reset flag 
SPDR = 0x00;  // xoa bo dem

   

while (1)
      {
      
//       while (!SPSR&(1<<SPIF));   
//      
//       //SPDR= data_recevses ;
//       
//      
//      
//  
 for(j=0 ; j<i;j++){
 putchar(data_recevses[j]); 
 } 
 if(i>100)i =0 ; 
 if(j>100)j =0 ; 
   
            
     }

}
