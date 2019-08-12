#define IR 8
#define IR1 9
#define IR2 10 
#define IR3 12
#include <Servo.h>
int othersensor=1;
int sensorSet = 3;
Servo myservo_0;
//Servo myservo_1;    
int det0 = HIGH;    // no obstacle
int det1 = HIGH;
int det2 = HIGH;
int det3= HIGH;
int setbit = 0;
int setbit_for_open = 0;
void setup() {
Serial.begin(9600);   
  pinMode(IR, INPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT); 
  myservo_0.attach(7);
  //myservo_1.attach(8);
  myservo_0.write(90);
  //myservo_0.write(180);
  
}
void loop() {  
 
  det0 = digitalRead(IR);  
 // Serial.println(det0);
  if(det0 == LOW && sensorSet != 2){
    sensorSet=2;
    while(othersensor){
    det1 = digitalRead(IR1);
    if(det1 == LOW)
            {
              Serial.println("Gate open by 0 to 1");
              myservo_0.write(90);
              othersensor = 0;
              setbit = 1;} 
                  }
  }
det0 = HIGH;    // no obstacle
det1 = HIGH;         
det1 = digitalRead(IR1);
othersensor = 1;
if(det1 == LOW && sensorSet != 2 && setbit_for_open != 1 )
  {
    sensorSet=2;
    while(othersensor){
    det0 = digitalRead(IR);
    if(det0 == LOW)
    {
      Serial.println("Gate closed by 2 to 1");
      myservo_0.write(0);
      othersensor=0;
    }
  }
  }
det0 = HIGH;    // no obstacle
det1 = HIGH;   
othersensor = 1;      
det2 = digitalRead(IR2);   
if(det2 == LOW && sensorSet != 1){
  sensorSet=1;
  while(othersensor){
    det3 = digitalRead(IR3);
    if(det3 == LOW){
            Serial.println("Gate Closed by 3 to 4");
            myservo_0.write(0);
            othersensor = 0;
            setbit_for_open = 1;}
}
}

det2 = HIGH;
det3= HIGH;
othersensor = 1;
det3 = digitalRead(IR2);
  if(det3 == LOW && sensorSet !=1 && setbit != 1)
  {
    sensorSet=1;
    while(othersensor){
    det2 = digitalRead(IR3);
    if(det2 == LOW){
    Serial.println("Gate Open by 4 to 3");
       myservo_0.write(90);
       othersensor = 0;
  }  
  }
  }
det2 = HIGH;
det3= HIGH;
//sensorSet  = 0;

}
