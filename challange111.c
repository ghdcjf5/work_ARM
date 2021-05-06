#include "mbed.h"
#include "rtos.h"

  Serial pc(SERIAL_TX,SERIAL_RX);
  
  DigitalOut led(PC_8);
  int main(void){
       pc.baud(9600);
       
      
      
     
       
       while(true){
           if(pc.readable()){
               
                 char userInput = pc.getc();
                    if(userInput=='n'){
                           pc.printf("%c",userInput);
                           led=1;
        
                       }
      
                   else if(userInput=='f'){
                           pc.printf("%c",userInput);
                         led=0;}
          
          
      
      }  
                   }
    
      
      
}
 