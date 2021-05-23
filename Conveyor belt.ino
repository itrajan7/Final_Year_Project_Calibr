int enA = 10;
int enB = 11;

#include <Servo.h>

Servo top1;
Servo top2;

#define cen 4
#define top 2
#define in 8
#define out 7
#define con1 10
#define con2 11
#define def 12

int total=0;
int count=0;
int pro=0;
int totaldef=0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(def, INPUT);
  pinMode(cen, INPUT);
  pinMode(top, INPUT);
  top1.attach(3);
  top2.attach(5);
  pinMode(con1, OUTPUT);
  pinMode(con2, OUTPUT);
  Serial.begin(9600);
}


void loop() {
    
    analogWrite(enA, 100);
    analogWrite(enB, 100);

  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  int def_value = digitalRead(def);
  int high = digitalRead(top);
  int mid = digitalRead(cen);

  top2.write(180);
  delay(15);
  if(mid == LOW)
  {
    delay(1000);
    for (int i=180; i>90; i--)
    {
      top2.write(i);
    }
    delay(3000);
  }

  
  top1.write(0);
  delay(15);
  if(high == LOW)
  {
    delay(1000);
    for (int i=0; i<90; i++)
    {
      top1.write(i);
    }
    delay(3000);
  }


 if(in_value == LOW)
  {
    count++;
    total++;
    Serial.println(count);
    delay(1000);
  }

  if(def_value == LOW)
  {
    count--;
    totaldef++;
    Serial.println(count);
    delay(1000);
  }
  if(out_value == LOW)
  {
   count--;
    pro++;
    Serial.println(count);
    digitalWrite(con1, LOW);
    digitalWrite(con2, LOW);
    delay(5000);
  }

   if(count==0)
  {
    digitalWrite(con1, LOW);
    digitalWrite(con2, LOW);
    Serial.println("*******************************************************************************");
    Serial.println("Products are Finished So Conveyor is Stop");
    delay(1000);
    Serial.print("Total Number of Products Produced = ");
    Serial.println(total);
    Serial.print("Total Number of Defective Products Produced = ");
    Serial.println(totaldef);
    Serial.print("Total Number of Correct Products Produced = ");
    Serial.println(pro);
  }

  else
  {
    digitalWrite(con1, HIGH);
    digitalWrite(con2, HIGH);
  }
   

}
