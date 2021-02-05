#include "Switches.hpp"

Switches::Switches(int pin_data_, int pin_clock_data_, int pin_clock_update_, int pin_in_):
	pin_data        (pin_data_),
	pin_clock_data  (pin_clock_data_),
	pin_clock_update(pin_clock_update_),
	pin_in(pin_in_)
{}

void Switches::init(){
  pinMode(pin_data        ,OUTPUT); digitalWrite(pin_data        ,LOW);
  pinMode(pin_clock_data  ,OUTPUT); digitalWrite(pin_clock_data  ,LOW);
  pinMode(pin_clock_update,OUTPUT); digitalWrite(pin_clock_update,LOW);
  pinMode(pin_in          ,INPUT);
  shiftOut(pin_data, pin_clock_data, MSBFIRST, 0);
}


Named_byte Switches::read_all(){
	Named_byte r;
	//flush the first one
	digitalWrite(pin_data, HIGH);pulse2();digitalWrite(pin_data, LOW);

	//Serial.print("XX");
	//Serial.println(digitalRead(pin_in)==HIGH);

	//read bit, shift the one
	r.b0=digitalRead(pin_in)==HIGH;pulse2();
	r.b1=digitalRead(pin_in)==HIGH;pulse2();
	r.b2=digitalRead(pin_in)==HIGH;pulse2();
	r.b3=digitalRead(pin_in)==HIGH;pulse2();
	r.b4=digitalRead(pin_in)==HIGH;pulse2();
	r.b5=digitalRead(pin_in)==HIGH;pulse2();
	r.b6=digitalRead(pin_in)==HIGH;pulse2();
	r.b7=digitalRead(pin_in)==HIGH;

	//pulse2();//optional
	return r;
}

void Switches::pulse(int pin){
    digitalWrite(pin,HIGH);
    digitalWrite(pin,LOW);
}

void Switches::pulse2(){
	pulse(pin_clock_data); 
	pulse(pin_clock_update);  
}
