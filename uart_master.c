
#include <mega16.h>
#include <stdio.h>
#include <delay.h>
void main(void)
{



char mess[]="NGUYEN VAN TIEM";
char*p ; 
char tem; 
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
// UCSRA = 0x00 ; // 
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
// UCSRB = 0x18 ; // trasmit and recever no interupt
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;  //0x 67 16Mhz



while (1)
      {    
       p = mess; 
       while((tem=*p++)!=NULL){
         while ((UCSRA&0x20)==0);
         UDR = tem; 
       }
       delay_ms(1000);
      }
      
}
