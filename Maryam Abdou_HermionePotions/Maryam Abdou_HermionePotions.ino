#include <Timer.h>
Timer myTimer; // creating object
#define button 7
#define redLed 2
#define greenLed 3
#define whiteLed 4
int buttonState = 0;
void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(button, INPUT);
  myTimer.after(900000, red); //red led turns on for 15 minutes
  digitalWrite(redLed, LOW);
  myTimer.every(120000, green); //green led turns on every 2 minutes
  digitalWrite(greenLed, LOW);
  myTimer.every(300000, white); //white led turns on every 5 minutes
  digitalWrite(whiteLed, LOW);
  myTimer.every(480000, white); //white led turns o every 8 minutes
  digitalWrite(whiteLed, LOW);
}

void loop()
{
  // when the button is turned on the timer is executed
  buttonState = digitalRead(button); 
  if(buttonState == HIGH){ 
    myTimer.update();
  }
  //when the button is off the led are turned off
  else{
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(whiteLed, LOW);
  }
}
void red(){ //turn red led on
  digitalWrite(redLed, HIGH);
}
void green(){ //green led blinks for 5 seconds
  for(int i=0;i<5;i++){
     digitalWrite(greenLed, HIGH);
     delay(500);                       
     digitalWrite(greenLed, LOW);   
     delay(500);
    }
}
void white(){ //white led blinks for 10 seconds
  for(int i=0;i<10;i++){
     digitalWrite(whiteLed, HIGH);
     delay(500);                       
     digitalWrite(whiteLed, LOW);   
     delay(500);
    }
}
