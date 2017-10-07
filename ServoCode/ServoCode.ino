/*
General instructions: This is C, NOT C++.  There are some major differences:

- We use #defines instead of consts in order to save memory
- We use global variables SPARINGLY.  Do not take this to mean that you are
	free to use global variables in GENE121!
- The "loop" function is where the main part of your code will run.  As far as you are
 	concerned, loop is the same as main.
- DO NOT modify "setup".  It...sets...stuff up.  It's important...

What this code does:

You will be able to use the two ports Servo1 and Servo2, as well as the Cylinder1 port
(Once Eugene or Mike show(s) you how to hook it up).

Servo 1 is *currently* set up to be a position servo and Servo2 is *currently* set up to be
a continuous servo.  Learn how they work by studying our code, then modify as far as you want.

Servo1 has a limits from 10 to 70 degrees.  These are the limits you would use if you are using
the Tetrix gripper's servo.  If you aren't, you may feel free to remove those limits.  However,
if you are using the gripper, please leave those limits in.

*/


//DO NOT MODIFY ANYTHING HERE
#include <Servo.h>
Servo servoA;     //180 servo
Servo servoB;     //continious servo
Servo servoC;     //Mapping on 'Servo 3' pin
Servo servoD;     //Mapping on 'Servo 4' pin
#define b1 P2_0   //increment 180 servo by 1 degree button // 2_0
#define b2 P1_5   //decrement 180 servo by 1 degree button // 1_5
#define b3 P1_4   //rotate continious servo CW button // 1_4
#define b4 P1_3   //rotate continious servo CCW button // 1_3
#define b5 P1_1   //extend pneumatic cylinder button // 1_1
#define b6 P1_2   //retract pneumatic cylinder button // 1_2
#define b7 P1_2   //retract pneumatic cylinder button // 1_2
#define b8 P1_2   //retract pneumatic cylinder button // 1_2
#define s1 P2_1   //solenoid //2_1
#define s2 P2_2 // 2_2
#define d1 P1_0   //LED for confirmation (remove later)


void setup() 
{
  Serial.begin(9600); 
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(b5,INPUT);
  pinMode(b6,INPUT);
  pinMode(b7,INPUT);
  pinMode(b8,INPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(d1,OUTPUT);
  servoA.attach(P2_3);
  servoB.attach(P2_4);
  servoC.attach(P2_5);
  servoD.attach(P1_6);
}

//Gasp! Global variables! (In embedded systems, judicious use of
//global variables is allowed.  HOWEVER, in GENE121 they are NOT. 
int x=0, y=0, a=0, b=0, c=0, d=0, e=0, f=0;
int position = 45;      //initial position
int speed[3] = {5,94,175};


//OK, START MODIFYING STUFF
void loop() 
{
	//This is an exercise in how not to name your variables... 
    x = digitalRead(b1);
    y = digitalRead(b2);
    a = digitalRead(b3);
    b = digitalRead(b4);
    c = digitalRead(b5);
    d = digitalRead(b6);
    e = digitalRead(b7);
    f = digitalRead(b8);
    
    //ensure that the servos go back to idle when you aren't using them
    servoA.write(position);
    servoB.write(speed[1]);n/
    
    //Read the buttons and move the servos
    if(a==HIGH && position <180)   //forward
    {
        digitalWrite(d1,HIGH);
       servoA.write(position++);
        delay(5);
    }
    if(b == HIGH && position>0)     //back
    {
      
       digitalWrite(d1,HIGH);
       servoA.write(position--);
       delay(5); 
    }
      if(x == HIGH) //
      {
        digitalWrite(d1,HIGH);
        servoB.write(speed[2]);
        delay(5);
      }
      if(y == HIGH) //right
      {
        digitalWrite(d1,HIGH);
        servoB.write(speed[0]);
        delay(5);
      }
      if(c==HIGH && position <180)   //forward
    {
        digitalWrite(d1,HIGH);
       servoC.write(position++);
        delay(5);
    }
    if(d == HIGH && position>0)     //back
    {
      
       digitalWrite(d1,HIGH);
       servoC.write(position--);
       delay(5); 
    }
} 
