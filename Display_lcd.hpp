//Lazy update LCD on text change

#ifndef DISPLAY_LCD_PIERRE
#define DISPLAY_LCD_PIERRE

#include <LiquidCrystal_I2C.h>
#include <Wire.h>


// LCD
class Display_lcd{

  
  public:
  Display_lcd():lcd(0x27, 20, 4){
      
  }

  void init(){
    lcd.init();
    lcd.backlight();
  }
  
  void set_frequency(const String &x){update_xxx(freq,    x);}
  void set_name     (const String &x){update_xxx(st_name, x);}
  void set_volume   (const String &x){update_xxx(volume,  x);}
  void set_quality  (const String &x){update_xxx(quality, x);}

  void set_volume   (int i){update_xxx(volume,  String(i) );}
  void set_quality  (int i){update_xxx(quality, String(i) );}
  

  void update(){
    //if(!need_update){return;}
    //need_update=false;
    lcd.setCursor(0, 0); 
    lcd.clear();
    lcd.print(freq); lcd.print(" "); lcd.print(st_name ); 
    
    lcd.setCursor(0, 1); 
    lcd.print ("VOL:");   lcd.print(volume); 
    lcd.print(" Q:"); lcd.print(quality); 
  }

  private:
  void update_xxx(String &old_val, const String &new_val){
    if( old_val == new_val){return;}
    old_val=new_val;
    this->update();
    //need_update=true;
  }


  LiquidCrystal_I2C lcd;
  //bool need_update;
  String freq;
  String st_name;
  String volume;
  String quality;

};

#endif
