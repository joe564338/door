//. Motor driver shield- 2012 Copyright (c) Seeed Technology Inc.
// 
//  Original Author: Jimbo.we
//  Contribution: LG
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
int spead =127;//define the spead of motor
int movePin =4;//the pin to check for button press
int switchSpeedPin =3;// for slow down or speed up
int switchDirectionPin =2;// for changing direction
boolean closeDoor = true;
int stopSwitch = 1//magnetic switch
void setup()
{
  pinMode(stopSwitch, INPUT);//stops movement 
  digitalWrite(stopSwitch, LOW);
  pinMode(switchSpeedPin, INPUT);//changes speed if high speed up low slow down
  digitalWrite(switchSpeedPin, LOW);
  pinMode(switchDirectionPin, INPUT);//changes direction
  digitalWrite(switchDirectionPin, LOW);
  pinMode(movePin,INPUT);//checks for button press
  digitalWrite(movePin,LOW);
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  pinMode(pinI3,OUTPUT);
  pinMode(pinI4,OUTPUT);
  pinMode(speedpinB,OUTPUT);
}
 
void forward()
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
     digitalWrite(pinI3,LOW);
     digitalWrite(pinI2,LOW);//turn DC Motor A move anticlockwise
     digitalWrite(pinI1,HIGH);
}
void backward()//
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
     digitalWrite(pinI3,HIGH);
     digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
     digitalWrite(pinI1,LOW);
}
void left()//
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
     digitalWrite(pinI3,LOW);
     digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
     digitalWrite(pinI1,LOW);
}
void right()//
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
     digitalWrite(pinI3,HIGH);
     digitalWrite(pinI2,LOW);//turn DC Motor A move clockwise
     digitalWrite(pinI1,HIGH);
}
void stop()//
{
     digitalWrite(speedpinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor. 
     digitalWrite(speedpinB,LOW);
     delay(1000);
 
}
void speedUp()
{
  spead =300;
}
void slowDown()
{
  spead =150;
}
//changes direction of door
void directional()
{
  if(switchDirectionPin==LOW){
    closeDoor =true;
  }
  else
  {
    closeDoor =false;
  }
}
//executable
void loop()
{
  //if button is pressed it goes through checking if movement should continue and in what direction
  if(movePin==HIGH){
    //if pin is high then motor speeds up if not then slowdown
    if (switchSpeedPin == HIGH){
      speedUp();
    }
    else{
      slowDown();
    }
    directional();// checks for direction
    //checks if door is closed or opened if neither then it opens automatically
    if(closeDoor == false){
      while(stopSwitch == LOW){
        forward();
      }
      stop();
    }
    else{
      while(stopSwitch == LOW){
        backward(); 
      }
      stop();
    }
  } 
}
