/*-------------------------------------------------------------------------
   8051.h: Register Declarations for the Intel 8051 Processor

   Copyright (C) 2000, Bela Torok / bela.torok@kssg.ch

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License 
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/

#ifndef __STC15F2K60S2_H_
#define __STC15F2K60S2_H_

/*  BYTE Register  */
__sfr __at (0x80) P0   ;
__sfr __at (0x81) SP   ;
__sfr __at (0x82) DPL  ;
__sfr __at (0x83) DPH  ;
__sfr __at (0x87) PCON ;
__sfr __at (0x88) TCON ;
__sfr __at (0x89) TMOD ;
__sfr __at (0x8A) TL0  ;
__sfr __at (0x8B) TL1  ;
__sfr __at (0x8C) TH0  ;
__sfr __at (0x8D) TH1  ;
__sfr __at (0x90) P1   ;
__sfr __at (0x98) SCON ;
__sfr __at (0x99) SBUF ;
__sfr __at (0xA0) P2   ;
__sfr __at (0xA8) IE   ;
__sfr __at (0xAF) IE2  ;
__sfr __at (0xB0) P3   ;
__sfr __at (0xB8) IP   ;
__sfr __at (0xC8) P5	;
__sfr __at (0xD0) PSW  ;
__sfr __at (0xE0) ACC  ;
__sfr __at (0xF0) B    ;
__sfr __at (0xD6) TH2	;
__sfr __at (0xD7) TL2	;


/*  BIT Register  */
/* P0 */
__sbit __at (0x80) P0_0 ;
__sbit __at (0x81) P0_1 ;
__sbit __at (0x82) P0_2 ;
__sbit __at (0x83) P0_3 ;
__sbit __at (0x84) P0_4 ;
__sbit __at (0x85) P0_5 ;
__sbit __at (0x86) P0_6 ;
__sbit __at (0x87) P0_7 ;

/*  TCON  */
__sbit __at (0x88) IT0  ;
__sbit __at (0x89) IE0  ;
__sbit __at (0x8A) IT1  ;
__sbit __at (0x8B) IE1  ;
__sbit __at (0x8C) TR0  ;
__sbit __at (0x8D) TF0  ;
__sbit __at (0x8E) TR1  ;
__sbit __at (0x8F) TF1  ;

/* P1 */
__sbit __at (0x90) P1_0 ;
__sbit __at (0x91) P1_1 ;
__sbit __at (0x92) P1_2 ;
__sbit __at (0x93) P1_3 ;
__sbit __at (0x94) P1_4 ;
__sbit __at (0x95) P1_5 ;
__sbit __at (0x96) P1_6 ;
__sbit __at (0x97) P1_7 ;

/*  SCON  */
__sbit __at (0x98) RI   ;
__sbit __at (0x99) TI   ;
__sbit __at (0x9A) RB8  ;
__sbit __at (0x9B) TB8  ;
__sbit __at (0x9C) REN  ;
__sbit __at (0x9D) SM2  ;
__sbit __at (0x9E) SM1  ;
__sbit __at (0x9F) SM0  ;

/* P2 */
__sbit __at (0xA0) P2_0 ;
__sbit __at (0xA1) P2_1 ;
__sbit __at (0xA2) P2_2 ;
__sbit __at (0xA3) P2_3 ;
__sbit __at (0xA4) P2_4 ;
__sbit __at (0xA5) P2_5 ;
__sbit __at (0xA6) P2_6 ;
__sbit __at (0xA7) P2_7 ;

/*  IE   */
__sbit __at (0xA8) EX0  ;
__sbit __at (0xA9) ET0  ;
__sbit __at (0xAA) EX1  ;
__sbit __at (0xAB) ET1  ;
__sbit __at (0xAC) ES   ;
__sbit __at (0xAF) EA   ;

/*  P3  */
__sbit __at (0xB0) P3_0 ;
__sbit __at (0xB1) P3_1 ;
__sbit __at (0xB2) P3_2 ;
__sbit __at (0xB3) P3_3 ;
__sbit __at (0xB4) P3_4 ;
__sbit __at (0xB5) P3_5 ;
__sbit __at (0xB6) P3_6 ;
__sbit __at (0xB7) P3_7 ;

__sbit __at (0xB0) RXD  ;
__sbit __at (0xB1) TXD  ;
__sbit __at (0xB2) INT0 ;
__sbit __at (0xB3) INT1 ;
__sbit __at (0xB4) T0   ;
__sbit __at (0xB5) T1   ;
__sbit __at (0xB6) WR   ;
__sbit __at (0xB7) RD   ;

/*  IP   */
__sbit __at (0xB8) PX0  ;
__sbit __at (0xB9) PT0  ;
__sbit __at (0xBA) PX1  ;
__sbit __at (0xBB) PT1  ;
__sbit __at (0xBC) PS   ;

/*  P5  */
__sbit __at (0xC8) P5_0 ;
__sbit __at (0xC9) P5_1 ;
__sbit __at (0xCA) P5_2 ;
__sbit __at (0xCB) P5_3 ;
__sbit __at (0xCC) P5_4 ;
__sbit __at (0xCD) P5_5 ;
__sbit __at (0xCE) P5_6 ;
__sbit __at (0xCF) P5_7 ;

/*  PSW   */
__sbit __at (0xD0) P    ;
__sbit __at (0xD1) F1   ;
__sbit __at (0xD2) OV   ;
__sbit __at (0xD3) RS0  ;
__sbit __at (0xD4) RS1  ;
__sbit __at (0xD5) F0   ;
__sbit __at (0xD6) AC   ;
__sbit __at (0xD7) CY   ;

__sfr __at (0x94) P0M0;   //0000,0000 Port 0 mode register0
__sfr __at (0x93) P0M1;   //0000,0000 ¶Ë¿Ú0Ä£Ê½¼Ä´æÆ÷1
__sfr __at (0x92) P1M0 ;   //0000,0000 ¶Ë¿Ú1Ä£Ê½¼Ä´æÆ÷0
__sfr __at (0x91) P1M1 ;   //0000,0000 ¶Ë¿Ú1Ä£Ê½¼Ä´æÆ÷1
__sfr __at (0x96) P2M0 ;   //0000,0000 ¶Ë¿Ú2Ä£Ê½¼Ä´æÆ÷0
__sfr __at (0x95) P2M1;   //0000,0000 ¶Ë¿Ú2Ä£Ê½¼Ä´æÆ÷1
__sfr __at (0xB2) P3M0;   //0000,0000 ¶Ë¿Ú3Ä£Ê½¼Ä´æÆ÷0
__sfr __at (0xB1) P3M1;   //0000,0000 ¶Ë¿Ú3Ä£Ê½¼Ä´æÆ÷1
__sfr __at (0xB4) P4M0;   //0000,0000 ¶Ë¿Ú4Ä£Ê½¼Ä´æÆ÷0
__sfr __at (0xB3) P4M1;   //0000,0000 ¶Ë¿Ú4Ä£Ê½¼Ä´æÆ÷1
__sfr __at (0xCA) P5M0 ;   //0000,0000 ¶Ë¿Ú5Ä£Ê½¼Ä´æÆ÷0
__sfr __at (0xC9) P5M1 ;   //0000,0000 ¶Ë¿Ú5Ä£Ê½¼Ä´æÆ÷1
__sfr __at (0xCC) P6M0 ;   //0000,0000 ¶Ë¿Ú6Ä£Ê½¼Ä´æÆ÷0
__sfr __at (0xCB) P6M1;   //0000,0000 ¶Ë¿Ú6Ä£Ê½¼Ä´æÆ÷1
__sfr __at (0xE2) P7M0;   //0000,0000 ¶Ë¿Ú7Ä£Ê½¼Ä´æÆ÷0
__sfr __at (0xE1) P7M1;   //0000,0000 ¶Ë¿Ú7Ä£Ê½¼Ä´æÆ÷1


//IAP/ISP 特殊功能寄存器
__sfr __at (0xC2) IAP_DATA;		//0000,0000 EEPROM数据寄存器
__sfr __at (0xC3) IAP_ADDRH;	//0000,0000 EEPROM地址高字节
__sfr __at (0xC4) IAP_ADDRL;	//0000,0000 EEPROM地址第字节
__sfr __at (0xC5) IAP_CMD;		//xxxx,xx00 EEPROM命令寄存器
__sfr __at (0xC6) IAP_TRIG;		//0000,0000 EEPRPM命令触发寄存器
__sfr __at (0xC7) IAP_CONTR;	//0000,x000 EEPROM控制寄存器

//auxregister
__sfr __at (0x8E) AUXR;	//not bit addressable
__sfr __at (0x8F) AUXR2;	//not bit addressable

/* AUXR bits */
#define S1ST2	0x01
#define EXTRAM	0x02
#define T2X12	0x04
#define T2_CT	0x08
#define T2R		0x10
#define UART_M0X6	0x20
#define T1X12	0x40
#define T0X12	0x80

/* AUXR2 bits */
#define T0CLKOUT	0x01
#define T1CLKOUT	0x02
#define T2CLKOUT	0x04
//BIT3 NOT USED
#define EX2		0x10
#define EX3	0x20
#define EX4	0x40
//BIT 7 NOT USED

/* IE2 bits */
#define ES2	0x01
#define ESPI 0x02
#define ET2	0x04
#define ES3 0x08
#define ES4	0x10
#define ET3	0x20
#define ET4	0x40
//BIT 7 NOT USED

//comparator
__sfr __at (0xE6) CMPCR1;	//not bit addressable
#define CMPEN 0x80	//CMPCR1.7 : Enable bit of comparator
#define CMPIF 0x40	//CMPCR1.6 : Interrupt flag bit of comparator
#define PIE 0x20	//CMPCR1.5 : Pos-edge Interrupt Enabling bit
#define NIE 0x10	//CMPCR1.4 : Neg-edge Interrupt Enabling bit
#define PIS 0x08	//CMPCR1.3 : bit to choose the postive pole of comparator
#define NIS 0x04	//CMPCR1.2 : bit to choose the negative pole of comparator
#define CMPOE 0x02	//CMPCR1.1 : Control bit of outputing comparing result
#define CMPRES 0x01	//CMPCR1.0 : Flag bit of Comparator Result

__sfr __at (0xE7) CMPCR2;	//not bit addressable
#define INVCMPO 0x80	//CMPCR2.7 : Inverse Comparator Output
#define DISFLT 0x40	//CMPCR2.6 : Disable the 0.1uS Filter output by comparator
#define LCDTY 0x3F	//CMPCR2.[5:0] : set the Duty of Level-Change control filter in
					//the output terminal of comparatorsbit 




/* BIT definitions for bits that are not directly accessible */
/* PCON bits */
#define IDL             0x01
#define PD              0x02
#define GF0             0x04
#define GF1             0x08
#define SMOD            0x80

/* TMOD bits */
#define T0_M0           0x01
#define T0_M1           0x02
#define T0_CT           0x04
#define T0_GATE         0x08
#define T1_M0           0x10
#define T1_M1           0x20
#define T1_CT           0x40
#define T1_GATE         0x80

#define T0_MASK         0x0F
#define T1_MASK         0xF0

/* Interrupt numbers: address = (number * 8) + 3 */
#define IE0_VECTOR      0       /* 0x03 external interrupt 0 */
#define TF0_VECTOR      1       /* 0x0b timer 0 */
#define IE1_VECTOR      2       /* 0x13 external interrupt 1 */
#define TF1_VECTOR      3       /* 0x1b timer 1 */
#define SI0_VECTOR      4       /* 0x23 serial port 0 */

#endif
