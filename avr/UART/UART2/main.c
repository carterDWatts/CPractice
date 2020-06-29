/*
  UART
*/

#include <stdio.h>
#include <avr/io.h>

#define FOSC 16000000  //1843200  //System clock speed
#define BAUD 9600                 //transmission rate
#define MYUBRR FOSC/16/BAUD-1     //( 16000000 / (16*9600) ) - 1

void USART_Init(unsigned int);
void USART_Transmit(unsigned char);
unsigned char USART_Receive(void);
void USART_Flush(void);

int main(void){

  USART_Init(MYUBRR);
  USART_Transmit('a');

	return 0;
}

void USART_Init(unsigned int ubrr){
  // Set baud rate
  UBRR0H = (unsigned char)(ubrr>>8);
  UBRR0L = (unsigned char)ubrr;

  // enable receiver & transmitter
  UCSR0B = (1<<RXEN0)|(1<<TXEN0);

  // Set frame format: 8 data, 2 stop bit
  UCSR0C = (1<<USBS0)|(3<<UCSZ00);

}

void USART_Transmit(unsigned char data){
  // wait for empty transmit buffer
  while(!(UCSRnA & (1<<UDREn)));
  UDRn = data;
}

unsigned char USART_Receive(void){

  // wait for data to be received
  while(!(UCSRnA & (1<<RXCn)));
  return UDRn;
}

void USART_Flush(void){

	unsigned char dummy;
	while(UCSRnA & (1<<RXCn)) dummy = UDRn;
}
