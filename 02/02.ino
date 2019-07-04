//f:前进，b：后退，l：左转，r：右转，s：停止
void setup()
{
 pinMode(5,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(6,OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  char income;
  if (Serial.available()>0)
  income = Serial.read();
  switch(income)
 { case 'f':forward();break;
  case 'b':back();break;
  case 'l':left();break;
  case 'r':right();break;
  case 's':stop();break;
  default:break;
  }
}
void forward()
{
   digitalWrite(5,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(10,LOW);
}
void back()
{
   digitalWrite(6,HIGH);
   digitalWrite(5,LOW);
   digitalWrite(10,HIGH);
   digitalWrite(9,LOW);
}
void left()
{
   digitalWrite(6,HIGH);
   digitalWrite(5,LOW);
   digitalWrite(10,HIGH);
   digitalWrite(9,LOW);
}
void right()
{
   digitalWrite(6,HIGH);
   digitalWrite(5,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(10,LOW);
}
void stop()
{
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(9,LOW);
   digitalWrite(10,LOW);
}
//b:6高5低，10高9低
//l：6高5低，10低9高
//s:全低
