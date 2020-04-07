/*
  Blink 

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink

  Zhiheng Ma(404950730)
  Jeffery Lee(105128818)
  Project: Auduino Car 
  Data: Nov 23, 2018
*/
bool done = false ; 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (2, OUTPUT); //blue
  pinMode (3, OUTPUT); //green
  pinMode (4, OUTPUT);//red
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A4, INPUT);
  Serial.begin (9600);

}

// the loop function runs over and over again forever
void loop() {
  
  if (!done)
 {
 int right_sensor = 0, left_sensor = 0, middle_sensor = 0;
  int speed_left = 0, speed_right = 0;
  
  right_sensor = analogRead(A0);
  left_sensor = analogRead(A4);
  middle_sensor = analogRead(A1);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);

/*
  Serial.print(left_sensor);
  Serial.print("      ");//485                     50
  Serial.print(middle_sensor);//595(not cover)      50(cover)
  Serial.print("      ");
  Serial.print(right_sensor);//615(not cover)   50(cover)
  Serial.print(" \n  ");
*/

 if (left_sensor<45 && middle_sensor<45 && 85<right_sensor) 
  {
    speed_left = 150;
    speed_right = 15;
    digitalWrite(4, HIGH);
  }
  
else if (85<left_sensor && middle_sensor<45 && right_sensor<45) //left 85,45,45
  {
    speed_right = 150;  //backup(150r,15l)
    speed_left = 15;
    digitalWrite(2, HIGH);
   
  }


  else if (100<left_sensor &&  100<middle_sensor && 100<right_sensor)//stop 
  {
   speed_right =0; speed_left =0; 
    digitalWrite (2, HIGH);
    digitalWrite (4, HIGH);
    done = true; 
  }
 
  else
  {
    speed_right = 120, speed_left = 120; 
    digitalWrite(3, HIGH);
  }
  
  analogWrite (6, speed_right);//right
  analogWrite(5, speed_left);//left
  }
}
