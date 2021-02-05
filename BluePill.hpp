#ifndef BLUE_PILL_PIERRE_HPP_
#define BLUE_PILL_PIERRE_HPP_

//Some info here : https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html
//Pin numbers are not the one used in arduino, but avoid pin used for a specific purpose for GPIO usage

/*
     USB   
B12       GND
 (15) B13       GND
 (14) B14       +3.3V
 (13) B15       RESET
 (12) A8        B11 (31)
 (11) A9        B10 (30)
 (10) A10       B1  (29)
USBD- A11       B0  (28)
USBD+ A12       A7  (27)
 (7)  A15       A6  (26)
 (6)  B3        A5  (25)
 (5)  B4        A4  (24)
 (4)  B5        A3  (23)
 (3)  B6        A2  (22)
 (2)  B7        A1  (21)
 (1)  B8        A0  (20)
 (  ) B9        C15 (19)
     +5V       C14 (18)
     GND       C13 (17) LED
     +3.3V     +V_BAT
*/


//#define BluePill_A11 0
//#define BluePill_A12 0
//#define BluePill_B9  0


#define BluePill_B8  1
#define BluePill_B7  2
#define BluePill_B6  3
#define BluePill_B5  4
#define BluePill_B4  5
#define BluePill_B3  6
#define BluePill_A15 7
//8
//9
#define BluePill_A10 10
#define BluePill_A9 11
#define BluePill_A8 12
#define BluePill_B15 13
#define BluePill_B14 14
#define BluePill_B13 15
//16
#define BluePill_C15 17
#define BluePill_C14 18
#define BluePill_C15 19
#define BluePill_A0  20
#define BluePill_A1  21
#define BluePill_A2  22
#define BluePill_A3  23
#define BluePill_A4  24
#define BluePill_A5  25
#define BluePill_A6  26
#define BluePill_A7  27
#define BluePill_B0  28
#define BluePill_B1  29
#define BluePill_B10 30
#define BluePill_B11 31

#endif
