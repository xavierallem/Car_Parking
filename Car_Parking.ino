#define BLYNK_PRINT Serial



#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo myservo;
Servo myservo1;
char auth[] = "X1z-Gg9FeXz6c1P3LPGJQhSS9_8lLTZk";

char ssid[] = "thisone1";
char pass[] = "12345678";

BlynkTimer timer;

#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
  int state;
void send()
{
  
  if(state==0)
  {
    pinMode(D1,OUTPUT);
    
  }
  
  else
  {
    pinMode(D1,INPUT);
    
  }
  
  }

int pos;
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1,INPUT_PULLUP);
  pinMode(D2,INPUT_PULLUP);
  pinMode(D3,INPUT);
  pinMode(D4,INPUT);
  pinMode(D5,INPUT);
  pinMode(D6,INPUT);
  myservo.attach(D7);
  myservo1.attach(D8); 
  
timer.setTimeout(10000L, send);
}
  


BLYNK_WRITE(V5)
{
  int state=param.asInt();
  
  
  if(state==0)
  {
    myservo.write(90);
    
    
    
    delay(15);
        
  }
    else
    {
      myservo.write(180);
      
                   
    delay(15);   
    }
  }
  BLYNK_WRITE(V6)
{
  int state=param.asInt();
  
  
  if(state==0)
  {
    myservo1.write(180);
    
    
    
    delay(15);
        
  }
    else
    {
      myservo1.write(90);
      
                   
    delay(15);   
    }
  }
  
BLYNK_WRITE(V7)
{
 state=param.asInt();
  
  send();
   
  
  
 
}
BLYNK_WRITE(V8)
{
  int state=param.asInt();
  if(state==0)
  {
    pinMode(D2,OUTPUT);
    Serial.print("1");
  }
  else
  {
    pinMode(D2,INPUT);
  }
}
BLYNK_WRITE(V9)
{
  int state=param.asInt();
  if(state==0)
  {
    pinMode(D3,OUTPUT);
    Serial.print("1");
  }
  else
  {
    pinMode(D3,INPUT);
  }
}
BLYNK_WRITE(V10)
{
  int state=param.asInt();
  if(state==0)
  {
    pinMode(D4,OUTPUT);
    
  }
  else
  {
    pinMode(D4,INPUT);
  }
}
void loop() {
timer.run();
Blynk.run();
Blynk.virtualWrite(V0,(digitalRead(D1)));
Blynk.virtualWrite(V1,(digitalRead(D2)));
Blynk.virtualWrite(V3,(digitalRead(D3)));
Blynk.virtualWrite(V4,(digitalRead(D4)));
//Blynk.virtualWrite(V2,(digitalRead(D5)));
//Blynk.virtualWrite(V5,(digitalRead(D6)));

delay(50);
}
