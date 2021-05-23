#include <Servo.h>

Servo pickServo;
Servo dropServo;

const int s0 = 4;  
const int s1 = 5;  
const int s2 = 6;  
const int s3 = 7;  
const int out = 9;   
int red = 0;  
int green = 0;  
int blue = 0; 
int color=0;
int redcolor = 0;
int greencolor = 0;
int orangecolor = 0;
int yellowcolor = 0;
int CLOSE_ANGLE = 30;  // The closing angle of the servo motor arm
int OPEN_ANGLE = 10;  // The opening angle of the servo motor arm
void setup()   
{   
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  

  pickServo.attach(2);
  dropServo.attach(3);
  pickServo.write(30);
  dropServo.write(73);

  Serial.begin(9600);
  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH); 
  
}  
void loop() 
{  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 
  
  if((red<20 && red>9) && (green<32 && green>21) && (blue<22 && blue>12)){
    dropServo.write(73);
    delay(7000);
    redcolor++;
    Serial.print("Red");
    open1();
    delay(2000);
    close1();
  }
  if((green<13 && green>6) && (green<29 && green>20) && (blue<24 && blue>16)){
    dropServo.write(107);
    delay(7000);
    orangecolor++;
    Serial.print("Orange");
    open1();
    delay(2000);
    close1();
  }
  if(red<46 & red>36 & green<46 & green>37){
    dropServo.write(132);
    delay(7000);
    greencolor++;
    Serial.print("Green");
    open1();
    delay(2000);
    close1();
  }
  if(red<34 & red>25 & green<37 & green>28 & blue<53 & blue>43){
    dropServo.write(162);
    delay(7000);
    yellowcolor++;
    Serial.print("Yellow");
    open1();
    delay(2000);
    close1();
  } 
  Serial.println();  
 // delay(1000); 
} 
void open1(){ 
  pickServo.write(OPEN_ANGLE);   // Send the command to the servo motor to open the trap door
}
void close1(){ 
  pickServo.write(CLOSE_ANGLE);   // Send te command to the servo motor to close the trap door
}
