#include "FastLED.h"

#define NUM_LEDS 256

#define DATA_PIN 6
#define CLOCK_PIN 8

#define DELAY 200
#define COLOR CRGB::Yellow
#define LCD_WIDTH 64

CRGB leds[NUM_LEDS];
void setup() {
    FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
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
    /*
     while( lcd_address >= 0) {
      first_letter_index = lcd_address* LCD_WIDTH + offset ;
      
      
      
      Draw_P( first_letter_index);
      if (lcd_address<=2)
        Draw_A( first_letter_index+LCD_WIDTH );
      if (lcd_address<=1)
        Draw_R( first_letter_index+ 2 * LCD_WIDTH );


        
      offset -- ; 
      if(offset  == -1){
       lcd_address -- ;
       offset = 3 ;  
      }        
      delay (DELAY) ;
      FastLED.clear();   
     }
      */ 
      
     // Display clock 
     /*
      Draw_7(128);
      delay(1000);
      FastLED.clear();
      Draw_8(128);

      delay(1000);
      FastLED.clear();
      */

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
