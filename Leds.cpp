#include "Leds.hpp"


Leds::Leds(int pin_data_, int pin_clock_data_, int pin_clock_update_):
    pin_data        (pin_data_),
    pin_clock_data  (pin_clock_data_),
    pin_clock_update(pin_clock_update_)
{  

}

void Leds::init(){
    pinMode(pin_data        ,OUTPUT); digitalWrite(pin_data        ,LOW);
    pinMode(pin_clock_data  ,OUTPUT); digitalWrite(pin_clock_data  ,LOW);
    pinMode(pin_clock_update,OUTPUT); digitalWrite(pin_clock_update,LOW);
}

void Leds::pulse(int pin){
    digitalWrite(pin,HIGH); //delay(50);
    digitalWrite(pin,LOW);  //delay(50);
}
  
void Leds::update(){
	shiftOut(pin_data, pin_clock_data, MSBFIRST, data);
	pulse(pin_clock_update);
	/*
	digitalWrite(pin_data,data&0b00000001!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	digitalWrite(pin_data,data&0b00000010!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	digitalWrite(pin_data,data&0b00000100!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	digitalWrite(pin_data,data&0b00001000!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	digitalWrite(pin_data,data&0b00010000!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	digitalWrite(pin_data,data&0b00100000!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	digitalWrite(pin_data,data&0b01000000!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	digitalWrite(pin_data,data&0b10000000!=0?HIGH:LOW); pulse(pin_clock_data); delay(1);
	pulse(pin_clock_update);*/
}
  
