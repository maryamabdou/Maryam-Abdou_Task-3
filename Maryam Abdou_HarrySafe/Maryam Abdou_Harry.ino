#define RightSensor 2
#define FrontSensor 3
#define LeftSensor 4
int Rightobstacle = LOW;
int Frontobstacle = HIGH;
int Leftobstacle = LOW;
int i = 0;
void setup()
{
  pinMode(RightSensor, INPUT);
  pinMode(FrontSensor, INPUT);
  pinMode(LeftSensor, INPUT);
}

void loop()
{
  // reads the front, right and left IR sensors
  Rightobstacle = digitalRead(RightSensor);
  Frontobstacle = digitalRead(FrontSensor);
  Leftobstacle = digitalRead(LeftSensor);
  // when he needs to go right and the maze ends in front of him
  if(Frontobstacle == LOW && Rightobstacle == HIGH && Leftobstacle == LOW){
       rotate90right();
  }
  // when he needs to go right or left if the two ways are possible
  else if(Rightobstacle == HIGH && Leftobstacle == HIGH && Frontobstacle == LOW){
     i+=1;
     if(i==1)
       rotate90left();
     else if(i==2)
       rotate90right();
  }
  // when he needs to go left and the maze ends in front of him
  else if(Frontobstacle == LOW && Leftobstacle == HIGH && Rightobstacle == LOW){
    rotate90left();
  }
  // when he needs to go right and the maze did not end
  else if(Rightobstacle == HIGH && Leftobstacle == LOW && Frontobstacle == HIGH){
    rotate90right();
  }
  // moves forward when no need to change direction
  else{
    moveForward(); 
  }
}
