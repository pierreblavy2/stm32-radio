#ifndef SWITCHES_PIERRE_HPP_
#define SWITCHES_PIERRE_HPP_

#include <Arduino.h>
#include "Named_byte.hpp"


  

struct Switches{
 
  const int pin_data;
  const int pin_clock_data;
  const int pin_clock_update;
  const int pin_in;

  void init();
  
  Switches(int pin_data_, int pin_clock_data_, int pin_clock_update_, int pin_in_);
  Named_byte read_all();
  
  //not copyable
  Switches(const Switches&)=delete;
  Switches& operator=(const Switches&)=delete;

  private:
  void pulse2();
  void pulse(int pin);
};





#endif
