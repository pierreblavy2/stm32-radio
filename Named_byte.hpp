#ifndef NAMED_BYTE_HPP_
#define NAMED_BYTE_HPP_

#include <Arduino.h>



struct Named_byte{    
    byte b0:1;
    byte b1:1;
    byte b2:1;
    byte b3:1;
    byte b4:1;
    byte b5:1;
    byte b6:1;
    byte b7:1;
    
    operator byte&      ()     {return reinterpret_cast<byte&>(*this);}
    operator const byte&()const{return reinterpret_cast<const byte&>(*this);}
    Named_byte& operator=(const Named_byte&)=default;
    Named_byte& operator=(const byte&b){reinterpret_cast<byte&>(*this)=b; return *this;}
    Named_byte()=default;
    Named_byte(const byte &b){reinterpret_cast<byte&>(*this)=b;}
    
    void print()const;
    
    

  };
  
//  std::ostream& operator<<(std::ostream &out, const Named_byte&b){};

#endif
