#include "DMD3.h" //https://github.com/bmzstore/DMD-Uno-Shield
#include "bmzSegment16.h"

DMD3 display (2,1);

char font[]={'0','1','2','3','4','5','6','7','8','9'};

#define s1 A1
#define s2 A2
#define s3 A3

boolean st=0;
boolean p=0;
void scan()
{
    display.refresh();
}

void setup() {
    pinMode(s1,INPUT_PULLUP);
    pinMode(s2,INPUT_PULLUP);
    pinMode(s3,INPUT_PULLUP);
    pinMode(s4,INPUT_PULLUP);
    pinMode(s5,INPUT_PULLUP);

    Timer1.initialize(400);
    Timer1.attachInterrupt(scan);  
    Timer1.pwm(9,255);

    Serial.begin(9600); 
}

unsigned long jam=0, menit=0,detik=0,milidetik=0;
unsigned long h,m,s,ms;

void loop() {
  
    if(digitalRead(s1)==LOW){  
      if(st==0){ 
    
    }
      st=1;p=0;
    
   } //start
    if(digitalRead(s2)==LOW){ p=1;}// pause
    if(digitalRead(s3)==LOW){ st=0;p=0;jam=00;menit=00;detik=00;milidetik=00;}// reset
  

    
tampilanBesar(jam,menit,detik);  


if(st==0){
}
else{
    if(p==0){
    milidetik++;
    
    if(milidetik>1){
      detik++;
      milidetik=00;
      
      
    if(detik>59){
      menit++;
      detik=00;
   
        } 

   if(menit>59){
      jam++;
      menit=00;
   
        } 

    if(jam>23){
      jam=00;
     
        }
        
    }
  }



      
}}

void tampilanBesar(int jm,int mn,int dt){
   //if(digitalRead(s4)==LOW){  setmenit++;delay(500);}
     
       //if(digitalRead(s5)==LOW){  setmenit--;delay(500);}
    
    char buff[7];
    sprintf(buff,"%02d%02d%02d",jm,mn,dt);
    
    
    display.setFont(bmzSegment16);
    display.drawText(0, 0, (String)buff[0]);
    display.drawText(10, 0, (String)buff[1]);
    display.drawText(23, 0, (String)buff[2]);
    display.drawText(33, 0, (String)buff[3]);
    display.drawText(46, 0, (String)buff[4]);
    display.drawText(56, 0, (String)buff[5]);
    display.drawCircle(20,3,1);
    display.drawCircle(20,12,1);
    display.drawCircle(43,3,1);
    display.drawCircle(43,12,1);   
    display.drawCircle(20,3,0);
    display.drawCircle(20,12,0);
    display.drawCircle(43,3,0);
    display.drawCircle(43,12,0);
           
}

