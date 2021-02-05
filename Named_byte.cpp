#include "Named_byte.hpp"

void Named_byte::print()const{
      int i = byte(*this);
      Serial.print("{");     
      Serial.print(i);
      Serial.print(":");         
      Serial.print(this->b0?"1":"0");
      Serial.print(this->b1?"1":"0");
      Serial.print(this->b2?"1":"0");
      Serial.print(this->b3?"1":"0");
      Serial.print(this->b4?"1":"0");
      Serial.print(this->b5?"1":"0");
      Serial.print(this->b6?"1":"0");
      Serial.print(this->b7?"1":"0");
      Serial.print("}");
}

