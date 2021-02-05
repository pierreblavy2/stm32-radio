#ifndef LEDS_PIERRE_HPP
#define LEDS_PIERRE_HPP

#include <Arduino.h>
#include "Named_byte.hpp"

struct Leds{
  Named_byte data;
  
  const int pin_data;
  const int pin_clock_data;
  const int pin_clock_update;
  
  Leds(int pin_data_, int pin_clock_data_, int pin_clock_update_);
  
  void init();
  void pulse(int pin);
  void update();
  

  //not copyable
  Leds(const Leds&)=delete;
  Leds& operator=(const Leds&)=delete;
};


#endif
