int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int PPR = 150;
#define Signal_A1 2
#define Signal_B1 3
#define Signal_A2 4
#define Signal_B2 5
#define Signal_A3 6
#define Signal_B3 7
#define greenLed 8

void setup()
{
  pinMode(greenLed, OUTPUT);
  pinMode(Signal_A1, INPUT_PULLUP);
  pinMode(Signal_B1, INPUT_PULLUP);
  pinMode(Signal_A2, INPUT_PULLUP);
  pinMode(Signal_B2, INPUT_PULLUP);
  pinMode(Signal_A3, INPUT_PULLUP);
  pinMode(Signal_B3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Signal_A1), ISR_A1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(Signal_B1), ISR_B1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(Signal_A2), ISR_A2,CHANGE);
  attachInterrupt(digitalPinToInterrupt(Signal_B2), ISR_B2,CHANGE);
  attachInterrupt(digitalPinToInterrupt(Signal_A3), ISR_A3,CHANGE);
  attachInterrupt(digitalPinToInterrupt(Signal_B3), ISR_B3,CHANGE);
}

void loop()
{
  // calculating the angle of each encoder
  int angle1 = (counter1/(PPR*4))*360;
  int angle2 = (counter2/(PPR*4))*360;
  int angle3 = (counter3/(PPR*4))*360;
  // when angle of first encoder is 37 the green led is turned on
  if(angle1 == 37){ 
    digitalWrite(greenLed, HIGH);
    delay(1000);
  }
  else  
    digitalWrite(greenLed, LOW);

  // when angle of second encoder is 10 the green led is turned on
  if(angle2 == 10){
    digitalWrite(greenLed, HIGH);
    delay(1000);
  }
  else  
    digitalWrite(greenLed, LOW);

  // when angle of third encoder is 54 the green led is turned on
  if(angle3 == 54){
    digitalWrite(greenLed, HIGH);
    delay(1000);
  }
  else  
    digitalWrite(greenLed, LOW);
}

void ISR_A1(){ 
  // increasing the counter when moving clockwise and decreasing when moving in opposite direction
  if(digitalRead(Signal_A1) != digitalRead(Signal_B1))
    counter1++;
  else
    counter1--;
}
void ISR_B1(){
  // increasing the counter when moving clockwise and decreasing when moving in opposite direction
  if(digitalRead(Signal_A1) == digitalRead(Signal_B1))
    counter1++;
  else
    counter1--;
}
void ISR_A2(){
  // increasing the counter when moving clockwise and decreasing when moving in opposite direction
  if(digitalRead(Signal_A2) != digitalRead(Signal_B2))
    counter2++;
  else
    counter2--;
}
void ISR_B2(){
  // increasing the counter when moving clockwise and decreasing when moving in opposite direction
  if(digitalRead(Signal_A2) == digitalRead(Signal_B2))
    counter2++;
  else
    counter2--;
}
void ISR_A3(){
  // increasing the counter when moving clockwise and decreasing when moving in opposite direction
  if(digitalRead(Signal_A3) != digitalRead(Signal_B3))
    counter3++;
  else
    counter3--;
}
void ISR_B3(){
  // increasing the counter when moving clockwise and decreasing when moving in opposite direction
  if(digitalRead(Signal_A3) == digitalRead(Signal_B3))
    counter3++;
  else
    counter3--;
}
