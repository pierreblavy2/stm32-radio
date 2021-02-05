#include "Rotary.hpp"


void Rotary::init(bool use_interrupts){
      pinMode(pin_a, INPUT);
      pinMode(pin_b, INPUT);
      if(use_interrupts){
          attachInterrupt(digitalPinToInterrupt(pin_a), [this](){this->update();}, CHANGE);
          attachInterrupt(digitalPinToInterrupt(pin_b), [this](){this->update();}, CHANGE);
      }
}

void Rotary::update(){
      auto val=read_rotary() ;//0=no change, 1=rotate clockwise, -1=rotate counter clockwise
      if( val !=0 ) {
        count +=val;
        //The following code was removed, as we want to keep interrupts small. Call run_callbacks() in your main loop instead
        // if ( prevNextCode==0x0b) {on_decrease(count);}
        // if ( prevNextCode==0x07) {on_increase(count);}
      }
}


int8_t Rotary::read_rotary() {
    prevNextCode <<= 2;
    if (digitalRead(pin_b)) prevNextCode |= 0x02; //0000 0010
    if (digitalRead(pin_a)) prevNextCode |= 0x01; //0000 0001
    prevNextCode &= 0x0f;                         //0000 xxxx
  
     // If valid then store as 16 bit data.
     if  (rot_enc_table[prevNextCode] ) {
        store <<= 4;
        store |= prevNextCode;
        if ((store&0xff)==0x2b) return -1; //xxxx xxxx 0010 1011
        if ((store&0xff)==0x17) return 1;  //xxxx xxxx 0001 0111
     }
     return 0;
}

void Rotary::run_callbacks(){
  if(count==old_count){return;}
  auto delta = old_count-count;
  if(delta>0){on_increase(delta); old_count=count;}
  if(delta<0){on_decrease(delta); old_count=count; }
}
