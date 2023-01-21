#include "ArduinoTimer.h";
ArduinoTimer timer; // we have to include timer
int num,x=0,temp2=0,temp,Score=0;
void setup()
{
    Serial.begin(9600);
    pinMode(2,OUTPUT); // this is for led output. 
    pinMode(3,OUTPUT); // this is for led output.
    pinMode(4,OUTPUT); // this is for led output.
    pinMode(5,OUTPUT); // this is for led output.
    pinMode(6,OUTPUT); // this is for led output.
    timer = millis();  // start timer 
    
}

void loop()
{
  if(x<=30)// game will run for 30 second
  {
    int value0 =analogRead(A0); // read analog value for piezo as a button
    int value1 =analogRead(A1); // read analog value for piezo as a button
    int value2 =analogRead(A2); // read analog value for piezo as a button
    int value3 =analogRead(A3); // read analog value for piezo as a button
    int value4 =analogRead(A4); // read analog value for piezo as a button
    
    if(temp==1)
    {
      
      num = random(2,7); // get random number for led
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }
    temp=0;
    if(timer.TimePassed_Seconds(1)) // for reset timer after every 1 second
    {
      timer.Reset();
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      num = random(2,7);
    }
    
    if(num==2) // start led after getting random number
    {
      digitalWrite(2,HIGH);
    }
    else if(num==3) // start led after getting random number
    {
      digitalWrite(3,HIGH);
    }
    else if(num==4) // start led after getting random number
    {
      digitalWrite(4,HIGH);
    }
    else if(num==5) // start led after getting random number
    {
      digitalWrite(5,HIGH);
    }
    else if(num==6) // start led after getting random number
    {
      digitalWrite(6,HIGH);
    }
    
    if(num==2 && value0==0) // for count score when led is high 
    {   
      timer.Reset();
      digitalWrite(2,LOW);
      temp=1;
      Score++;
      
    }
    else if(num==3 && value1==0) // for count score when led is high
    {
      timer.Reset();
      digitalWrite(3,LOW);
      temp=1;
      Score++;
    }
    else if(num==4 && value2==0) // for count score when led is high
    {
      timer.Reset();
      digitalWrite(4,LOW);
      temp=1;
      Score++;
    }
    else if(num==5 && value3==0) // for count score when led is high
    {
      timer.Reset();
      digitalWrite(5,LOW);
      temp=1;
      Score++;
    }
    else if(num==6 && value4==0) // for count score when led is high
    {
      timer.Reset();
      digitalWrite(6,LOW);
      temp=1;
      Score++;
    }
    x++;
    delay(1000); // wait for 1 second
  }
  else
  {
    if(temp2==0) // For print score only one time
    {
      Serial.print("your Score is : ");
      Serial.println(Score); 
      temp2=1;
    }
    else // sign for game over
    {
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      delay(30000);
    }
  }
}
