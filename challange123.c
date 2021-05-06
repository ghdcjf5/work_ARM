#include "mbed.h"
#include "rtos.h"

 
  
  InterruptIn button(PF_4);
  PwmOut buzzer(PF_2);
  
  volatile int buzzer_state =0;
  volatile int buzzer_state_changed = 0;
   volatile int flag=0;
  void buttonPressed(){
      flag++;
      if(flag==1){
          
            if(buzzer_state==0){
                 buzzer_state=262;
    
              }
          
             else if(buzzer_state == 262)buzzer_state =294;
             else if(buzzer_state == 294)buzzer_state =330;
              else if(buzzer_state == 330)buzzer_state =349;
             else if(buzzer_state == 340)buzzer_state =392;
            else if(buzzer_state == 392)buzzer_state =440;
             else if(buzzer_state ==440)buzzer_state =494;
              else if(buzzer_state ==494)buzzer_state =523;
             
             
             else buzzer_state=262;
      
      
      buzzer_state_changed=1; 
          
      }
      
     else flag=0;
      
    }
      
  int main(void){
      
       button.rise(buttonPressed);
       
       
       while(true){
          if(buzzer_state_changed){
               buzzer_state_changed=0;
               flag=0;
              buzzer.period_us(1000000/buzzer_state);
            buzzer.pulsewidth_us(1000000/buzzer_state/2);
                wait(0.5);
            }
               
        buzzer.pulsewidth_us(0);        
                   
                     
              
      }
    
      
      
}
    