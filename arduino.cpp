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
void setup() {
    FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);    
    Serial.begin(9600);    
}

void loop() {    
      int first_monitor_address = 0 , second_monitor_address = LCD_WIDTH , 
            third_monitor_address = 2 * LCD_WIDTH , fourth_monitor_address = 3 * LCD_WIDTH ;    

      // Display name   
      /*
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
      */ 
      
     // Display clock      

      char t[] = __TIME__ ;          
      Serial.println(t);
//      Serial.print(t[1]);      

//      Serial.print(t[3]);
//      Serial.print(t[4]);
      delay(1000);
      
      addDigit(t[0] , first_monitor_address ) ;
      addDigit(t[1] , second_monitor_address ) ;
      addDigit(t[3] , third_monitor_address ) ;
      addDigit(t[4] , fourth_monitor_address ) ;
      
      delay(1000);
        
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
  Draw_S(0);
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
  Draw_I(0);
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
