#include <Servo.h>
#include<NewPing.h>
#define trig 12
#define echo 11
#define max_dist 200
int pos = 90;
int md1=4 , md2=5 , mg1=6 , mg2= 7;
NewPing sonar(trig, echo, max_dist);
Servo servo;
void tourne_d(){
  digitalWrite(md1,HIGH);
  digitalWrite(md2,LOW);
  digitalWrite(mg1,HIGH);
  digitalWrite(mg2,LOW);

   delay(500);
  }
  void tourne_g(){
  digitalWrite(md1,LOW);
  digitalWrite(md2,HIGH);
  digitalWrite(mg1,LOW);
  digitalWrite(mg2,HIGH);

   delay(500);
  }
  void stopp(){
  digitalWrite(md1,LOW);
  digitalWrite(md2,LOW);
  digitalWrite(mg1,LOW);
  digitalWrite(mg2,LOW);

   delay(500);
  }
  void marche_ar(){
  digitalWrite(md1,HIGH);
  digitalWrite(md2,LOW);
  digitalWrite(mg1,LOW);
  digitalWrite(mg2,HIGH);

  delay(1000);
    }
    void marche_av(){
  digitalWrite(md1,LOW);
  digitalWrite(md2,HIGH);
  digitalWrite(mg1,HIGH);
  digitalWrite(mg2,LOW);
//  Serial.print("Avant");
  delay(750);
    }
 
void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  Serial.begin(115200);
  pinMode(md1,OUTPUT);
  pinMode(md2,OUTPUT);
  pinMode(mg1,OUTPUT);
  pinMode(mg2,OUTPUT);
}

void loop() {
servo.write(90);
if(sonar.ping_cm()>20 && sonar.ping_cm()<200 ){
  marche_av();
  }
  if(sonar.ping_cm()<30){
    stopp();
    servo.write(0);
    delay(1000);
    if(sonar.ping_cm()>20 && sonar.ping_cm()<200){
    servo.write(90);
    delay(1000);
    while(sonar.ping_cm()<20){
    tourne_d();}
    }
    else if(sonar.ping_cm()>0){
      servo.write(90);
      delay(1000);
      while(sonar.ping_cm()<25){
    tourne_g();}
      
    }
    }
    }
  












  
