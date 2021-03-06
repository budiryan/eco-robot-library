#ifndef LIGHTSENSORH
#define LIGHTSENSORH

#include "stm32f10x.h"
#include "can.h"
#include "can_protocol.h"
#include "delay.h"
#include "flashMem.h"
#include "ticks.h"
#include "uart.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_dma.h"
#include "approx_math.h"
#include <stdlib.h>
#include <stdbool.h>


/*
The old cupboard:
THRES: 70
R G B : 0.2126 0.2 0.2

The new shit:
THRES: 
R G B : 

*/

#define DELAY_US 1000 //800
#define scalar 1000
#define NUMOFAREAS 6
#define NUMCALI 4
#define SATOFFSET 30
#define HUEOFFSET 30
#define VALUEOFFSET 18
#define THRESHOLD 67    

#define RIGHT

#ifdef LEFT
#define DARKGREENLEFT 180
#define DARKGREENRIGHT 220
#define DARKGREENBORDER 48
#define ORANGELEFT 15
#define ORANGERIGHT 38
#define ORANGEBORDER 60
#define RIVERLEFT 220
#define RIVERRIGHT 240 
#define RIVERBORDER 51
#define LIGHTGREENLEFT 100
#define LIGHTGREENRIGHT 180
#define LIGHTGREENBORDER 14
#define PINKLEFT 38
#define PINKRIGHT 100
#define PINKBORDER 65
#endif

#ifdef RIGHT
#define DARKGREENLEFT 160
#define DARKGREENRIGHT 200
#define DARKGREENBORDER 55
#define ORANGELEFT 15
#define ORANGERIGHT 75
#define ORANGEBORDER 69
#define RIVERLEFT 210
#define RIVERRIGHT 225
#define RIVERBORDER 45
#define LIGHTGREENLEFT 80
#define LIGHTGREENRIGHT 155
#define LIGHTGREENBORDER 16
#define PINKLEFT 226
#define PINKRIGHT 270
#define PINKBORDER 80
#endif

typedef enum{
	PINK = 0, 
    LIGHTBLUE,
    DARKGREEN, 
    ORANGE, 
    RIVER,
    LIGHTGREEN,
    UNKNOWN
}Colour;

typedef struct
{
	u16 red_reading[16];
	u16 blue_reading[16];
	u16 green_reading[16];
	u16 off_reading[16];
	u16 h[16];
	u16 s[16];
	u16 v[16];
}Reading;



void sensor_init(Reading*  max);
void initToZero(void);
void dataCollect(void);
void rgb_hsv_converter(Reading* reading);
void printInformation(void);
void sendData(void);
void LED_Control(u8 R, u8 G, u8 B);
void analysisData(void);
void receive(CanRxMsg msg);

#endif
