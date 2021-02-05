#ifndef ROTARY_PIERRE_HPP_
#define ROTARY_PIERRE_HPP_

//This is a modified version of the code originally developped by 
// John Main - best-microcontroller-projects.com
// https://www.best-microcontroller-projects.com/rotary-encoder.html


//=== Usage EXAMPLE ===
/*
Rotary r(PA9,PA10); // pin_a or CLK, pin_b or DATA

void setup(){
  r.init(true); //true=use interrupt, false= don't use interrupts
  r.on_increase=[](int8_t c){Serial.print("inc "); Serial.println(c);}; //user defined callback, c is the counter
  r.on_decrease=[](int8_t c){Serial.print("dec "); Serial.println(c);}; //user defined callback, c is the counter
}

void loop(){
  //if you use interrupt, you don't have to do anything here.
  //if you don't use interrupts, call r.update() here.
}
*/

//=== Wireing ===
//WARNING, don't fry pin_a and pin_b, ESP8266 and STM32 require VCC=3.3V, arduino require VCC=5V
// (encoder_A) ---[10K ohms]--- VCC
// (encoder_A) --- pin_a
//
// (encoder_G) --- GND 
//
// (encoder_B) ---[10K ohms]--- VCC
// (encoder_B) --- pin_b


#include "Arduino.h"

struct Rotary{
  typedef long int count_t;
  count_t count = 0;
  count_t old_count=0;
  const int pin_a; //CLK
  const int pin_b; //DATA
  
  Rotary(int pin_a_, int pin_b_):pin_a(pin_a_),pin_b(pin_b_){}

  //if use_interrupts is false, you must call update() manually in the main loop
  void init(bool use_interrupts);

  //inject yout code here
  std::function<void(count_t)> on_increase=[](count_t){};
  std::function<void(count_t)> on_decrease=[](count_t){};
  
  //Call this in your main loop only if you don't use interrupts (see init)
  void update();
  void run_callbacks();//Call this in your main loop, will call on_increase or on_decrease if counter has changed

  int8_t read_rotary();
  //return 0 for no change or invalid code
  //return 1 for increase
  //return -1 for decrease


  private:
  uint8_t prevNextCode = 0;
  uint16_t store=0; //store 4 Grey codes
  // xxxx xxxx 0010 1011 => counter clockwise (-1)
  // xxxx xxxx 0001 0111 => clockwise (1)

  static constexpr inline int8_t rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};
    //index is a 4 bits Grey code 0b00001234
    //1=old_pin_b
    //2=old_pin_a
    //3=pin_b
    //4=pin_a
    //value is 0 for wrong Grey codes, 1 for valid Grey code
    
  
};








/*


// Robust Rotary encoder reading : ORIGINAL CODE FROM  John Main

//
// Copyright John Main - best-microcontroller-projects.com
// https://www.best-microcontroller-projects.com/rotary-encoder.html
//
#define CLK PA9
#define DATA PA10

void setup() {
  pinMode(CLK, INPUT);
  //pinMode(CLK, INPUT_PULLUP);
  pinMode(DATA, INPUT);
  //pinMode(DATA, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.println("KY-040 Start:");
}

static uint8_t prevNextCode = 0;
static uint16_t store=0;

void loop() {
static int8_t c,val;

   if( val=read_rotary() ) {
      c +=val;
      Serial.print(c);Serial.print(" ");

      if ( prevNextCode==0x0b) {
         Serial.print("eleven ");
         Serial.println(store,HEX);
      }

      if ( prevNextCode==0x07) {
         Serial.print("seven ");
         Serial.println(store,HEX);
      }
   }
}

// A vald CW or  CCW move returns 1, invalid returns 0.
int8_t read_rotary() {
  static int8_t rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};

  prevNextCode <<= 2;
  if (digitalRead(DATA)) prevNextCode |= 0x02;
  if (digitalRead(CLK)) prevNextCode |= 0x01;
  prevNextCode &= 0x0f;

   // If valid then store as 16 bit data.
   if  (rot_enc_table[prevNextCode] ) {
      store <<= 4;
      store |= prevNextCode;
      //if (store==0xd42b) return 1;
      //if (store==0xe817) return -1;
      if ((store&0xff)==0x2b) return -1;
      if ((store&0xff)==0x17) return 1;
   }
   return 0;
}

*/

#endif
