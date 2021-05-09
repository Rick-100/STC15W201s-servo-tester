/*
Print the results of the readPot() function and the mapped values  for calibrating the servo tester 
Hello world with some utility functions for printing numbers to P3.1 at 2400 baud with 12 MHz clock
functions to print an unsigned char in hex or binary
functions to print an unsigned int in hex or decimal

*/

#include "my_stc_.h"	// converted header file

//#define led  P3_3
#define txLine  P3_1
#define POT P5_5		//CMP+ pin
#define POTCHARGE P3_3


#define TX_HIGH txLine = 1
#define TX_LOW txLine = 0


void setPortMode(unsigned char port,unsigned char bitNum, unsigned char mode)	// only works on ports 0, 3 , 5 for now
{
	unsigned char tmp1 = 0;
	unsigned char tmp2 = 0;
	unsigned char tmp3 = 0;
	unsigned char tmp4 = 0;
	
		if(mode & 0x01){
			tmp1 = 1 << bitNum;
		}
		if(mode & 0x02){
			tmp2 = 1 << bitNum;
		}

	switch(port){
		case 1 :
			tmp3 = (P1M0 & ~tmp1) | tmp1;
			tmp4 = (P1M1 & ~tmp1) | tmp2;

			P1M0 = tmp3;
			P1M1 = tmp4;
			break;
		case 3 :
			tmp3 = (P3M0 & ~tmp1) | tmp1;
			tmp4 = (P3M1 & ~tmp1) | tmp2;

			P3M0 = tmp3;
			P3M1 = tmp4;
			break;
		case 5 :
			tmp3 = (P5M0 & ~tmp1) | tmp1;
			tmp4 = (P5M1 & ~tmp1) | tmp2;

			P5M0 = tmp3;
			P5M1 = tmp4;
			break;
	}	
	
}


void Delay2400(){	// 1 bit time for 2400 baud at 12 MHz
	__asm
		push 0x30
		push 0x31
		mov 0x30,#4
		mov 0x31,#220
NEXT:
		djnz 0x31,NEXT
		djnz 0x30,NEXT
		pop 0x31
		pop 0x30
	__endasm;
}


void sendChar(unsigned char c)	//send an ASCII character
{
	unsigned char mask = 1;	//bit mask
	unsigned char i;
         
	Delay2400();// wait 2 Stop bits before sending the char to give a stop bit if routine is called again before a stop bit time period has passed
	Delay2400();

	TX_LOW;              // low the line for start bit

	Delay2400();	//wait 1 bit time for start bit

	for (i=0; i<8 ;i++){
		if (c & mask){
			TX_HIGH;
		}
		else{
			TX_LOW;
		}
		mask <<= 1;
		Delay2400();
	}
	TX_HIGH;            //Return TXDATA pin to "1".
}



void sendByteAsHex(unsigned char b)	// send byte as 2 digit hex number
{
	unsigned char digitToDisplay;
	unsigned char byteToDisplay;

	byteToDisplay = b;
	digitToDisplay = byteToDisplay >> 4;
	if(digitToDisplay < 10){
		digitToDisplay = digitToDisplay + 48;
		sendChar(digitToDisplay);
	}
	else{
		digitToDisplay = digitToDisplay + 55;
		sendChar(digitToDisplay);			
	}

	digitToDisplay = byteToDisplay & 0xf;
	if(digitToDisplay < 10){
		digitToDisplay = digitToDisplay + 48;
		sendChar(digitToDisplay);
	}
	else{
		digitToDisplay = digitToDisplay + 55;
		sendChar(digitToDisplay);			
	}	

}

void sendIntAsDec(unsigned int number)	//print unsigned int as decimal number
{
	unsigned int divider = 10000;
	unsigned char zero = 0;
	
	unsigned int n;
	if(number == 0)
	{
		sendChar('0');
		return;		// bust out of function
	}
	for(n = 0;n < 5; n++)
	{
		if(number >= divider)
			{
			zero = 1;
			sendChar((number / divider) + 48);
			number %= divider;	//get remainder

			}
		else if(zero)
			{
			sendChar('0');
			}
	divider /= 10;
	}
}


void sendCRLF(void)
{
	sendChar(13);
	sendChar(10);
}

void sendIntAsHex(unsigned int out_data)	//send an 
{

    sendByteAsHex((unsigned char)(out_data >> 8));
    sendByteAsHex((unsigned char)(out_data));
}
void sendByteAsBin(unsigned char number)
{
	unsigned char bitNum;
	unsigned char mask = 128;
	
	for(bitNum = 8;bitNum > 0;bitNum--)
	{
		if(number & mask) 
		{
			sendChar('1');
		}
		else{
			sendChar('0');
		}
		mask >>= 1;
	}
}

unsigned int readPot()
{
	unsigned int time;
	time = 0;

	POTCHARGE = 0;	//start discharging cap
	//while(POT)
	while(CMPCR1 & CMPRES)
	{
		time++;
	}
	POTCHARGE = 1;	//recharge cap before next reading
	return time;
}

unsigned int conv(unsigned int x, unsigned int upper)
{
	unsigned int temp;
	
	temp = upper >> 8;
	if(x > temp)
	{
		return x / temp;
	}
	else
	{
		return 0;
	}
	
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void initComparator()
{
	CMPCR1 = 0;		//Initilize the Comparator control register 1
	CMPCR2 = 0;		//Initilize the Comparator control register 2
	CMPCR1 &= ~PIS;	//choose external pin P5.5(CMP+) as the postive pole of comparator by clearing PIS bit
	CMPCR1 |= CMPOE;	//Make the comparing result of comparator outputting on P1.2P1.2
	CMPCR2 |= INVCMPO;	//Invert output the comparing result of comparator on P1.2
	CMPCR1 &= ~NIS;	//choose BGV as the negative pole of comparator
	CMPCR2 &= ~DISFLT;	//enable the 0.1uS Filter output by comparatoroutput by comparator
	CMPCR2 &= LCDTY;	// all 6 bits aet to 1 for max filter/debounce
	CMPCR1 |= CMPEN;	//Enable Comparator
}


void main()
{

	unsigned char temp;
	unsigned int delayCtr, miscCtr;
	unsigned int pot_val;
	unsigned int conv_val;
	
	// if line is commented out the port will be in default mode 0
	setPortMode(1,2,1);		//this should make bit 3 on P3 a push pull output for led
	setPortMode(3,3,1);		//this should make bit 3 on P3 a push pull output
	//setPortMode(3,4,1);		//this should make bit 4 on P3 a push pull output
	//setPortMode(3,5,1);		//this should make bit 5 on P3 a push pull output
	setPortMode(5,5,2);		//this should make bit 2 on P3 an input
	//led = 0;
	POTCHARGE = 1;		//charge cap
	initComparator();

	sendChar('H');
	sendChar('I');
	sendChar(13);
	sendChar(10);
	
/* 	for(temp = 0;temp < 32;temp++)	//print some bytes as hex and binary numbers
	{
		sendByteAsHex(temp);
		sendCRLF();
		sendByteAsBin(temp);
		sendCRLF();
	}
	for(miscCtr = 0; miscCtr < 16; miscCtr++)	//print some 16 bit numbers as decimal and hex
	{
		sendIntAsDec(miscCtr);
		sendCRLF();
		sendIntAsHex(miscCtr);
		sendCRLF();
	} */
	
	
/* 	sendIntAsDec(65535);
	sendCRLF();
	sendIntAsHex(0xff00);
	sendCRLF();
	sendIntAsHex(0x00ff);
	sendCRLF(); */
	
    while(1)
    {
		for(delayCtr = 2400;delayCtr > 0;delayCtr--)	//wait 1 second
		{
			Delay2400();
		}
		//led = !led;	//toggle led
		//sendChar('H');
		//sendChar('I');
		sendCRLF();
		//temp = P3;
		sendByteAsBin(P3);	// print the port pin states as binary
		pot_val = readPot();
		sendCRLF();
		sendIntAsDec(pot_val);
		sendCRLF();
		//conv_val  = (pot_val,12000);
		conv_val = map((long)pot_val,0, 1750, 0, 1500);
/* 		conv_val = conv_val / 10;
		conv_val = conv_val * 10; */
		sendIntAsDec(conv_val);
		sendCRLF();
		

		
    }		
}	  