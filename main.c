/*******************************************************
This program was created by the CodeWizardAVR V3.39b 
Automatic Program Generator
© Copyright 1998-2020 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 5/26/2020
Author  : 
Company : 
Comments: 


Chip type               : ATmega328P
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/


#include <mega328p.h>
#include <delay.h>
#include <stdio.h>

 

char data_send;
char*p ; 

char mess[]="NGUYEN VAN TIEM";


void main(void)
{
UCSR0A = 0x00; 
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
//UCSR0C=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);
UBRR0H = 0x00;
UBRR0L = 0x67;

DDRB |= (1 << 2) | (1 << 3)|(1 << 5);
DDRB  &=~(1<<4); 
PORTB |= (1<<2);
    // enable SPI, set as master, and clock to fosc/128
SPCR = 0x53;        

SPSR =0x00;  //   reset flag 
SPDR = 0x00;  // xoa bo dem 

while (1)
      {  
           
      delay_ms(1000);
      PORTB.2=0; 
      p = mess ; 
      while ((data_send=*p++)!=NULL){     
       while(!(SPSR & (1 << SPIF)));
       SPDR = data_send;
       
       }
       while(!(SPSR & (1 << SPIF)));
        PORTB.2=1; 
      }
}
