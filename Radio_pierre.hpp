#ifndef RADIO_PIERRE_HPP
#define RADIO_PIERRE_HPP

#include <Arduino.h>
#include <Wire.h>
#include <radio.h>
#include <RDA5807M.h>  
#include <RDSParser.h>   //https://github.com/mathertel/Radio/issues/14


//TODO change me
#define FIX_BAND     RADIO_BAND_FM   ///< The band that will be tuned by this sketch is FM.
//#define FIX_STATION  9180            ///< The station that will be tuned by this sketch is 89.30 MHz.  8790  9180
//#define FIX_VOLUME   15              ///< The volume that will be set by this sketch is level 4.




void RDS_process(uint16_t block1, uint16_t block2, uint16_t block3, uint16_t block4);
void RDS_display(char *name);



/*
typedef struct RADIO_INFO {
  bool active;  ///< receiving is active.
  uint8_t rssi; ///< Radio Station Strength Information.
  uint8_t snr;  ///< Signal Noise Ratio.
  bool rds;     ///< RDS information is available.
  bool tuned;   ///< A stable frequency is tuned.
  bool mono;    ///< Mono mode is on.
  bool stereo;  ///< Stereo audio is available
};*/

struct Radio_pierre{
  Radio_pierre(){}
  Radio_pierre(const Radio_pierre&)=delete;
  Radio_pierre& operator=(const Radio_pierre&)=delete;

  
  void init(RADIO_FREQ freq, uint8_t volume=0); //freq = 8530 for 85.30 MHz
  
  const char* get_name     ()const; //get station name, using RDS


  
  /*(100.0*volume)/MAX_VOLUME;*/
  byte get_quality()const{
    radio.getRadioInfo(&info);
    return info.rssi;
  }


  mutable RADIO_INFO info;
  mutable RDA5807M  radio;    // Create an instance of Class for RDA5807M Chip
  RDSParser rds;
  //byte      rds_count=0; //don't check for ever, as it makes ckicks. TODO reset on station change
  //static constexpr byte    rds_max=60;
  static constexpr uint8_t MAX_VOLUME = 15;


  //--- volume ---
  byte        get_volume()    const{return volume;}
  const char* get_volume_str()const;
  void set_volume(uint8_t b);
  void inc_volume(){if(volume<MAX_VOLUME){++volume; update_volume();}}
  void dec_volume(){if(volume>0){--volume; update_volume();}}
  void inc_volume(int delta);
  void update_volume(){radio.setVolume(volume);}

  //---frequency ---
  const char* get_frequency_str();
  RADIO_FREQ  get_frequency()const{
    return freq; //return cached value to avoid noise
    //return radio.getFrequency();
    
    }
  void set_frequency(RADIO_FREQ);
  void inc_frequency(int delta);//1 = 0.01MHz
  
 
  private:
  uint8_t volume=0;
  RADIO_FREQ freq; //Cache frequency, as asking it to the radio create noise

  //buffers for computing frequency
  char freq_s[12];
  char freq_r[12];
  
  //buffers for station name (RDS)
  char rds_name[16];
  
  
  };


#endif
