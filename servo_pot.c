//servo using pot and comparator to make a servo tester
//STC15W204S or 201sif program size under 1K
//produce servo pulse on P3.2 using timer 2
#include "my_stc_.h"	// converted header file
 

#define SERVO P3_2
#define POT P5_5		//CMP+ pin
#define POTCHARGE P3_3
#define LED P3_1



volatile __bit flag;	//if flag = 0 then set servo line low and reload with servo pulse width
						//if flag = 1 then set servo line high and relad with 50 Hz values
						


volatile __bit ok_change;	// set when timer starts it's 20 mS phase

volatile unsigned int servo_pos;


void t2int()__interrupt 12 __using 1	//timer 2 int routine
{

		flag = !flag;
		if(flag)
		{
			SERVO = 1;
			ok_change = 0;
			TL2 = 0xC8;	//Initial timer value for 19 mS into reload register
			TH2 = 0xB5;	//Initial timer value
		}
		else
		{
			SERVO = 0;
			ok_change = 1;	//foreground has to poll this bit so it nows it has plenty of time to change position
			TL2 = servo_pos & 0xFF;
			TH2 = servo_pos >> 8;
		}	
}



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
	CMPCR2 &= LCDTY;	// all 6 bits aet to 0 for no filter/debounce
	CMPCR1 |= CMPEN;	//Enable Comparator
}


void main()
{
	unsigned int pot_val;
	unsigned int conv_val;

	//unsigned int new_servo_pos;

	setPortMode(3,1,1);		//this should make bit 1 on P3 a push pull output for led
	setPortMode(3,2,1);		//this should make bit 2 on P3 a push pull output for servo
	setPortMode(3,3,1);		//this should make bit 3 on P3 a push pull output for charging/discharging POT
	
	servo_pos = 65536 - 1500;	// each timer tick is 1 uS so 1500 ticks for middle servo position / count up from
	

	SERVO = 0;	//initial state of servo line
	POTCHARGE = 1;		//charge cap
	initComparator();
	
	flag = 0;		//keeps track of the next reload value
	ok_change = 0;	//set at start of timer 20 mS timer phase to allow foreground task to chnage both bytes of servo_pos
	
	
	AUXR &= 0xFB;	//Timer 1 clock is 12T mode
	TL2 = 0xC8;		//Initial timer value for 19 mS or apprx 50 Hertz
	TH2 = 0xB5;		//Initial timer value

	IE2 |= ET2;		//enable timer 2 interrupt
	AUXR |= T2R;	//start timer 2 running
	EA = 1;			//global interrupt enable
		
	
	while(1)
	{	
		if(ok_change)
		{
			ok_change = 0;
			pot_val = readPot();
			//conv_val = map((long)pot_val,0, 2250, 0, 1500); //point to point soldered up board
			conv_val = map((long)pot_val,0, 1750, 0, 1500); //dev board
			servo_pos = 65536 - (conv_val + 750);

		}

	}
}