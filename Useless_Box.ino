/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
  bool done = false;
  int pos = 0;    // variable to store the servo position
  int posend = 110;
  int boring = 0;

void slowservo(int from,int to, int duration, int dir);
void setup() {
  randomSeed(analogRead(2));
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  myservo.write(5);
  Serial.println(digitalRead(3));
  if(digitalRead(3) == 0 && done == false)
  {
    int ran = random(1,11);
    if(boring == 0)
      ran = 1;
    Serial.println(ran); //debug
//    if (ran == 0)
//    {
//      Serial.println("debug");
//      slowservo(0,130,2,1);
//      Serial.println("up");
//      slowservo(pos,0,3,-1);
//      Serial.println("down");
//      slowservo(0,130,2,1);
//      Serial.println("up");
//      done = true;
//    }
    if (ran == 1 || ran>=9)
    {//Normal
      Serial.println("Normal Behaviour");
      for (pos = 5; pos <= posend; pos += 1) 
      { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      done = true;
    }
    else if (ran == 2 && boring >= 3)
    {//Fucking Seizure 
      Serial.println("Seizure");
      for(int i = 0; i <= 50;i++)
      {
        myservo.write(random(20,80));
        delay(65);
      }
      done = true;
      boring = 0;
    }
    else if (ran == 3 && boring >= 10)
    {//Hold and I'm watching you
      Serial.println("Hold and I'm watching you");
      myservo.write(posend-25);
      delay(1500);
      myservo.write(posend);
      delay(500);
      slowservoCW(posend, posend-105,15);
     // delay(1500);
      myservo.write(posend-25);
      delay(1500);
      myservo.write(12);
      delay(1500);
      myservo.write(posend);
      delay(1500);
      done=true;
      boring = 0;
    }
    else if (ran == 4)
    {//Not this shit again
      Serial.println("not this shit again");
      myservo.write(posend-45);
      delay(2000);
      slowservoCW(posend-45, posend-105,15);
      delay(1400);
      myservo.write(posend);
      delay(300);
      done=true;
    }
    else if (ran == 5 && boring >=10)
    {//slowaf
      Serial.println("slowaf");
      slowservoCCW(0,posend,50);
      slowservoCW(posend, 0 ,50);
      done = true;
      boring = -1;
    }
    else if(ran == 6 && boring >=3)
    {//close seizure
      Serial.println("close seizure");
      Serial.println("Seizure");
      for(int i = 0; i <= 50;i++)
      {
        myservo.write(random(70,100));
        delay(75);
      }
      done = true;
       boring = 0;
    }
    else if(ran == 7)
    {//knock knock
      myservo.write(50);
      delay(400);
      myservo.write(10);
      delay(500);
      myservo.write(50);
      delay(400);
      myservo.write(posend);
      delay(150);
      done = true;
    }
    else if(ran==8)
    {//patterned knock
      myservo.write(40*1.5);//bing
      delay(20*1.5);
      myservo.write(10*1.5);
      delay(180*1.5);
      myservo.write(40*1.5);//bong
      delay(20*1.5);
      myservo.write(10*1.5);
      delay(80*1.5);
      myservo.write(40*1.5);//bong
      delay(20*1.5);
      myservo.write(10*1.5);
      delay(80*1.5);
      myservo.write(40*1.5);//bong
      delay(20*1.5);
      myservo.write(10*1.5);
      delay(180*1.5);
      myservo.write(40*1.5);//bang
      delay(20*1.5);
      myservo.write(10*1.5);
      delay(380*1.5);
      myservo.write(40*1.5);//bing
      delay(20*1.5);
      myservo.write(10*1.5);
      delay(180*1.5);
      myservo.write(40*1.5);//bing
      delay(20*1.5);
      myservo.write(10*1.5);
      delay(180*1.5);
      myservo.write(posend);
      delay(150);
      done = true;
    }
  }//back
  else if (done == true)
  {
    for (pos = 130; pos >= 5; pos -= 1) 
    { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    done = false;
    boring++;
    Serial.println("Cool");
  }
}

void slowservoCW(int from,int to, int lag)
{
  pos = from;
  for (pos; pos >= to; pos -= 1) 
    { // goes from 180 degrees to 0 degrees
      Serial.println(pos);
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(lag);                       // waits 15ms for the servo to reach the position
    }
}

void slowservoCCW(int from,int to, int lag)
{
  pos = from;
  for (pos; pos <= to; pos += 1) 
    { // goes from 180 degrees to 0 degrees
      Serial.println(pos);
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(lag);                       // waits 15ms for the servo to reach the position
    }
}
