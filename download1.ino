int turnSpeed=50;

void back(int speed) //speed is a variable ranging from 0-255
{
  analogWrite(5, speed);
  analogWrite(6, speed);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
}

void front(int speed) //speed is a variable ranging from 0-255
{
  analogWrite(5, speed);
  analogWrite(6, speed);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
}

void stop() 
{
  analogWrite(6,0);
  analogWrite(5,0);
}

void turnRight()
{
  analogWrite(5, turnSpeed);
  analogWrite(6, turnSpeed);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
}

void turnLeft()
{
  analogWrite(5, turnSpeed);
  analogWrite(6, turnSpeed);
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  int left=analogRead(A0); // 54 when 0, 974 when used
  int right=analogRead(A1);
   
  if(left==right)
  {
    if(left==54 and right==54)
      stop();
    else
      front(50);
  }
  else if(left>right)
    turnLeft();
  else
    turnRight();
  
  
  Serial.println(right);
  Serial.println(left);
}