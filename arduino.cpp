#include "FastLED.h"

//#include <iostream>  
//#include <string>  

//using namespace std; 

// Constant variables 
#define NUM_LEDS 256

#define DATA_PIN 6
#define CLOCK_PIN 8

#define DELAY 200
#define COLOR CRGB::Yellow
#define LCD_WIDTH 64

CRGB leds[NUM_LEDS];

char ch1 ,ch2  ,ch3 ,ch4;
            
void setup() {
    FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);        
    Serial.begin(9600);    
    char t[] = __TIME__  ;
    ch1 = t[0];
    ch2 = t[1] ;
    ch3 = t[3] ;
    ch4 = t[4] ;

    // Display name   
    
    int first_monitor_address = 0 , second_monitor_address = LCD_WIDTH , 
          third_monitor_address = 2 * LCD_WIDTH , fourth_monitor_address = 3 * LCD_WIDTH ;    
    Draw_P(fourth_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_A(fourth_monitor_address);
    Draw_P(third_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_R(fourth_monitor_address);
    Draw_A(third_monitor_address);
    Draw_P(second_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_S(fourth_monitor_address);
    Draw_R(third_monitor_address);
    Draw_A(second_monitor_address);
    Draw_P(first_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_A(fourth_monitor_address);
    Draw_S(third_monitor_address);
    Draw_R(second_monitor_address);
    Draw_A(first_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_E(fourth_monitor_address);
    Draw_A(third_monitor_address);
    Draw_S(second_monitor_address);
    Draw_R(first_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_I(fourth_monitor_address);
    Draw_E(third_monitor_address);
    Draw_A(second_monitor_address);
    Draw_S(first_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_S(fourth_monitor_address);
    Draw_I(third_monitor_address);
    Draw_E(second_monitor_address);
    Draw_A(first_monitor_address);
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_A(fourth_monitor_address);
    Draw_S(third_monitor_address);
    Draw_I(second_monitor_address);
    Draw_E(first_monitor_address);      
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_Z(fourth_monitor_address);      
    Draw_A(third_monitor_address);
    Draw_S(second_monitor_address);
    Draw_I(first_monitor_address);      
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_A(fourth_monitor_address);      
    Draw_Z(third_monitor_address);      
    Draw_A(second_monitor_address);
    Draw_S(first_monitor_address);      
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_D(fourth_monitor_address);      
    Draw_A(third_monitor_address);      
    Draw_Z(second_monitor_address);      
    Draw_A(first_monitor_address);      
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_E(fourth_monitor_address);      
    Draw_D(third_monitor_address);      
    Draw_A(second_monitor_address);      
    Draw_Z(first_monitor_address);            
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear();   

    Draw_H(fourth_monitor_address);            
    Draw_E(third_monitor_address);      
    Draw_D(second_monitor_address);      
    Draw_A(first_monitor_address);            
    FastLED.show();  
    delay (DELAY) ;
    FastLED.clear(); 
      

    pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);

    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);

    setClockDisplay();
}

void loop() {    
      
     // Display clock      
      int inc = digitalRead(13);      
      int dec = digitalRead(12);      

      int h_inc = digitalRead(11);      
      int h_dec = digitalRead(10);      

      
      if (inc == HIGH ) {
        Serial.println("minute increased");        
        if(ch4 == '9'){
          ch4 = '0' ;
          ch3 = ch3 + 1 ; 
          if(ch3 == '6'){
            ch3 == '0';                        
          } 
        } else {
          ch4 = ch4 + 1 ;           
        }        

        setClockDisplay();
        Serial.println(ch4);
      }                  

      if (dec == HIGH ) {
        Serial.println("minute decreased");        
        if(ch4 == '0'){
          ch4 = '9' ;          
          if(ch3 == '0'){
            ch3 == '9';                        
          } else {
            ch3 = ch3 - 1 ; 
          }
        } else {
          ch4 = ch4 - 1 ;           
        }        

        setClockDisplay();
        Serial.println(ch4);
      }   

      if (h_inc == HIGH ) {
        Serial.println("hour increased");        

        if(ch2 == '3' && ch1=='2'){
          ch1 = '0' ;
          ch2 = '0' ;
        } else if(ch2 == '9'){
          ch2 = '0' ;
          ch1 = ch1 + 1 ; 
        } else 
          ch2 = ch2 + 1 ;  


        setClockDisplay();
        Serial.println(ch4);
      }                  

      if (h_dec == HIGH ) {
        Serial.println("hour decreased");        
        
        if(ch2 == '0' && ch1=='0'){
          ch1 = '2' ;
          ch2 = '3' ;
        } else if(ch2 == '0'){
          ch2 = '9' ;          
          if(ch1 == '0'){
            ch1 == '9';                        
          } else {
            ch1 = ch3 - 1 ; 
          }
        } else {
          ch2 = ch2 - 1 ;           
        }        

        setClockDisplay();
        Serial.println(ch4);
      }   
      delay(80);
        
}

void setClockDisplay(){
  int first_monitor_address = 0 , second_monitor_address = LCD_WIDTH , 
            third_monitor_address = 2 * LCD_WIDTH , fourth_monitor_address = 3 * LCD_WIDTH ;    

  FastLED.clear();         
      
  addDigit(ch1 , first_monitor_address ) ;
  addDigit(ch2 , second_monitor_address ) ;
  addDigit(ch3 , third_monitor_address ) ;
  addDigit(ch4 , fourth_monitor_address ) ; 

  FastLED.show();
}

void addDigit(char num, int lcd){
  switch(num){
    case '0' :
      Draw_0(lcd);
      break ;

    case '1' :
      Draw_1(lcd);
      break ;

    case '2' :
      Draw_2(lcd);
      break ;

    case '3' :
      Draw_3(lcd);
      break ;

    case '4' :
      Draw_4(lcd);
      break ;

    case '5' :
      Draw_5(lcd);
      break ;

    case '6' :
      Draw_6(lcd);
      break ;

    case '7' :
      Draw_7(lcd);
      break ;

    case '8' :
      Draw_8(lcd);
      break ;

    case '9' :
      Draw_9(lcd);
      break ;
     
  }
}

void Draw_7(int pos){
  for(int i =0 ; i<6 ; i++){
        leds[pos + i] = COLOR ;         
        for(int j =0 ; j<6 ; j++){
          if( i + j == 5 ){           
            leds[pos + i*8 + j] = COLOR;     
          }
        }
     } 

  FastLED.show();
}

void Draw_6(int pos){
  for(int i =0 ; i < 5 ; i ++ ){
    leds[pos +i] = COLOR ;
    leds[pos +48+ i] = COLOR ;
    leds[pos +24+ i] = COLOR ;
  }
  for(int i =3 ; i < 6 ; i ++ )
    leds[pos +i*8+4] = COLOR ;

  for(int i =1 ; i < 6 ; i ++ )
    leds[pos +i*8] = COLOR ;  
    
  FastLED.show();
}

void Draw_9(int pos){
  for(int i =0 ; i < 5 ; i ++ ){
    leds[pos +i] = COLOR ;
    leds[pos +48+ i] = COLOR ;
    leds[pos +24+ i] = COLOR ;
  }
  for(int i =1 ; i < 6 ; i ++ )
    leds[pos +i*8+4] = COLOR ;

  for(int i =1 ; i < 3 ; i ++ )
    leds[pos +i*8] = COLOR ;  
    
  FastLED.show(); 
}

void Draw_8(int pos){
  for(int i =0 ; i < 5 ; i ++ ){
    leds[pos +i] = COLOR ;
    leds[pos +48+ i] = COLOR ;
    leds[pos +24+ i] = COLOR ;
  }
  for(int i =1 ; i < 6 ; i ++ ){
    leds[pos +i*8] = COLOR ;
    leds[pos +i*8+4] = COLOR ;
  }
  
  FastLED.show();
   
}

void Draw_5(int pos){
  Draw_S(pos);
}

void Draw_4(int pos){
  for(int i =0 ; i < 7 ; i ++ ){
    if(i <4 ) 
      leds[pos +i*8] = COLOR ;
    leds[pos +i*8+4] = COLOR ;
    if(i<5)
      leds[pos +24 + i] = COLOR ;
  }

  FastLED.show();
}

void Draw_3(int pos){
     leds[pos +12] = COLOR ; leds[pos +20] = COLOR ; 
     leds[pos +36] = COLOR ; leds[pos +44] = COLOR ; 
     for(int i =0 ; i<5 ; i++)
         leds[pos +i] = COLOR;

     for(int i =0 ; i<5 ; i++)
         leds[pos +24 + i] = COLOR;

     for(int i =0 ; i<5 ; i++)
         leds[pos +48 + i] = COLOR;

     FastLED.show();
}

void Draw_2 (int pos) {
     leds[pos +12] = COLOR ; leds[pos +20] = COLOR ; 
     leds[pos +32] = COLOR ; leds[pos +40] = COLOR ; 
     for(int i =0 ; i<5 ; i++)
         leds[pos +i] = COLOR;

     for(int i =0 ; i<5 ; i++)
         leds[pos +24 + i] = COLOR;

     for(int i =0 ; i<5 ; i++)
         leds[pos +48 + i] = COLOR;

     FastLED.show();    
}

void Draw_1(int pos){
  Draw_I(pos);
}

void Draw_0 (int pos){

  for(int i =0 ; i < 7 ; i ++ ){
    leds[pos +i] = COLOR ;
    leds[pos +48+ i] = COLOR ;
  }
  for(int i =1 ; i < 6 ; i ++ ){
    leds[pos +i*8] = COLOR ;
    leds[pos +i*8+6] = COLOR ;
  }
  
  FastLED.show();  
}

void Draw_H (int pos){
  for(int i =0 ; i < 7 ; i ++ ){
    leds[pos + i*8] = COLOR ;
    leds[pos +i*8+6] = COLOR ;
    leds[pos +24 + i] = COLOR ;
  }

}

void Draw_D (int pos){
  for(int i =0 ; i < 6 ; i ++ ){
    leds[pos + i] = COLOR ;
    leds[pos + 48+ i] = COLOR ;
  }
  for(int i =1 ; i < 6 ; i ++ ){
    leds[pos + i*8] = COLOR ;
    leds[pos +i*8+6] = COLOR ;
  }

}

void Draw_I (int pos ) {
  for(int i =0 ; i<7 ; i++)
    leds[pos + i*8] = COLOR ; 

//  FastLED.show();
}

void Draw_Z (int pos) { 
  
  for(int i =0 ; i<7 ; i++){
        leds[pos + i] = COLOR ; 
        leds[pos + i+48] = COLOR ; 
        for(int j =0 ; j<7 ; j++){
          if( i + j == 6 ){           
            leds[pos + i*8 + j] = COLOR;     
          }
        }
     } 

}

void Draw_E (int pos) {
  for(int i =0 ; i<7 ; i++)
      leds[pos +i*8] = COLOR ; 
   
   for(int i =0 ; i<5 ; i++)
      leds[pos +i] = COLOR;
  
   for(int i =0 ; i<5 ; i++)
       leds[pos +24 + i] = COLOR;
  
  for(int i =0 ; i<5 ; i++)
       leds[pos +48 + i] = COLOR;

}

void Draw_S (int pos) {
     leds[pos + 8] = COLOR ; leds[pos +16] = COLOR ; 
     leds[pos +36] = COLOR ; leds[pos +44] = COLOR ; 
     for(int i =0 ; i<5 ; i++)
         leds[pos +i] = COLOR;

     for(int i =0 ; i<5 ; i++)
         leds[pos +24 + i] = COLOR;

     for(int i =0 ; i<5 ; i++)
         leds[pos +48 + i] = COLOR;

}

void Draw_A (int pos ) {
  for (int i =0 ; i<5 ; i++ )
    leds[pos+i] = COLOR;
          
  for (int i =0 ; i<4 ; i++)
    leds[pos+i+24] = COLOR;
          
  for(int i =0 ; i<7 ; i++){
    leds[pos+i*8] = COLOR;     
    leds[pos+i*8 + 4] = COLOR;
  }
}

void Draw_P (int pos) {
  for (int i =0 ; i<4 ; i++ )
    leds[pos + i] = COLOR;
    
  for (int i =0 ; i<4 ; i++)
     leds[pos + i+24] = COLOR;
    
  for(int i =0 ; i<7 ; i++)
     leds[pos + i*8] = COLOR;

  for (int i =0 ; i<4; i++ )
    leds[pos + i*8 + 4] = COLOR;
    
}

void Draw_R ( int pos ) { 
  for (int i =0 ; i<5 ; i++ )
    leds[pos+i] = COLOR;
          
  for (int i =0 ; i<4 ; i++)
    leds[pos+i+24] = COLOR;
          
  for(int i =0 ; i<7 ; i++){
    leds[pos+i*8] = COLOR;     
    leds[pos+i*8 + 4] = COLOR;
  }
  leds[pos + 28] = CRGB::Black ;  
}
