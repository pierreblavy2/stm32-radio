// ----- Fixed settings here. -----
#include "Radio_pierre.hpp"




void Radio_pierre::init(RADIO_FREQ frequency, uint8_t volume_){
  Serial.println("Radio init b");

  this->volume=volume_;
  rds_name[0]='\0';
  rds.init();
  /*
  radio.attachReceiveRDS(RDS_process);
  rds.attachServicenNameCallback(RDS_display);
  */


  //NOTE : getMaxFrequency() and getMinFrequency() return zero if band is not set
  radio.init();
  radio.setBandFrequency(FIX_BAND, frequency );
  freq=frequency;
  
  radio.setVolume(volume);
  radio.setMono(false );
  radio.setMute(false);
  delay(100);

  rds.init();
  Serial.println("Radio init OK");
}

const char* Radio_pierre::get_frequency_str(){

  for(size_t i = 0; i < 12; ++i){freq_r[i]='\0';}

  //remove the MHz
  radio.formatFrequency(freq_s, sizeof(freq_s));
  size_t j=0;
  size_t i=0;
  char c;
  while(i<12){
    c = freq_s[i];
    if(c=='\0'){ break; }
    if(isDigit(c) or c=='.'){
      freq_r[j]=c;
      ++j;
    }
    ++i;
  }
  freq_r[j]='\0';
  return freq_r;
}

void Radio_pierre::set_frequency(RADIO_FREQ freqency){
    if(freqency>radio.getMaxFrequency()){freqency=radio.getMaxFrequency();}
    if(freqency<radio.getMinFrequency()){freqency=radio.getMinFrequency();}
    radio.setBandFrequency(FIX_BAND, freqency);
    freq=freqency;
}


void  Radio_pierre::inc_frequency(int delta){
  if(delta==0){return;}
  RADIO_FREQ x= radio.getFrequency() + delta*radio.getFrequencyStep();
  set_frequency(x);
}



const char* Radio_pierre::get_name()const{
  return rds_name;
}

const char* Radio_pierre::get_volume_str()const{
    static const char* v[MAX_VOLUME+1]{
      "00","05","10","20","25",
      "30","40","45","55","60",
      "65","70","80","85","90",
      "99"
    };
    
    static const char xx[3]="xx";
    if(this->volume<=MAX_VOLUME){
      return v[volume];
    }else{
      return xx;
    }
}

void Radio_pierre::inc_volume(int delta){
    if(delta==0){return;} 
    int x = int(volume)+delta; 
    if (x>MAX_VOLUME){volume=MAX_VOLUME;} 
    else if(x<0){volume=0;}
    else{volume=x;} 
    update_volume();
}

void Radio_pierre::set_volume(uint8_t b){
    if(b==volume){return;}
    volume = b>MAX_VOLUME?MAX_VOLUME:b;
    update_volume();
}

  
