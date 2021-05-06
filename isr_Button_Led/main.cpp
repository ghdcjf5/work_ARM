#include "mbed.h"

InterruptIn button(PA_8);
DigitalOut led(PC_8);

volatile int led_state = 0;
volatile bool led_state_changed = false;

void buttonPressed(){
    led_state= (led_state ==0) ? 1: 0 ;
    led_state_changed = true;
    
    
    }
int main(){
     button.rise(buttonPressed);
      
      while(true){
          if(led_state_changed){
              led_state_changed = false;
              led=led_state;
              
              }
          
          
          }
}
       
        
      
        
       
      
        
    
