int pin = 13,_dottime=250;
char buffer[1000];
void setup() 
{
 Serial.begin(9600);
 Serial.flush();
 pinMode(pin,OUTPUT);
}
void dash()//Dah闪烁
{
  digitalWrite(pin,HIGH);
  delay(_dottime*4);
  digitalWrite(pin,LOW);
  delay(_dottime);
  }
  void dot()//Dit
{
  digitalWrite(pin,HIGH);
  delay(_dottime);
  digitalWrite(pin,LOW);
  delay(_dottime);
  }
  void c_space()//回车闪烁
{
  digitalWrite(pin,LOW);
  delay(_dottime*3);
 }
 void w_space()//空格闪烁
{
  digitalWrite(pin,LOW);
  delay(_dottime*7);
}
void splitString()
{
  
}

void loop() 
{
  int index=0,i,numChar;
  char k;
  if (Serial.available()>0)
  {
  delay(100);
  numChar = Serial.available();
  }
  while (numChar--)
  {
  buffer[index++]=Serial.read();
  }
  for(i=1;i<=index;i++)
  {k=buffer[i];
   switch(k)
  {
    case 'a':{dash();dot();} break;
    case 'b':{dash();dot();dot();dot();}break;
    case 'c':{dash();dot();dash();dot();}break;
    case 'd':{dash();dot;dot();}break;
    case 'e':{dot();}break;
    case 'f':{dot();dot();dash();dot();}break;
    case 'g':{dash();dash();dot();}break;
    case 'h':{dot();dot();dot();dot();}break;
    case 'i':{dot();dot();}break;
    case 'j':{dot();dot();dot();}break;
    case 'k':{dash();dot();dash();}break;
    case 'l':{dot();dash();dot();dot();}break;
    case 'm':{dash();dash;}break;
    case 'n':{dash();dot();}break;
    case 'o':{dash();dash();dash();}break;
    case 'p':{dot();dash();dash();dot();}break;
    case 'q':{dash();dash();dot();dash();}break;
    case 'r':{dot();dash();dot();}break;
    case 's':{dot();dot();dot();}break;
    case 't':dash();break;
    case 'u':{dot();dot();dash();}break;
    case 'v':{dot();dot();dot();dash();}break;
    case 'w':{dot();dash();dash();}break;
    case 'x':{dash();dot();dot();dash();}break;
    case 'y':{dash();dot();dash();dash();}break;
    case 'z':{dash();dash();dot();dot();}break;
    case ' ':w_space();break;
    case '\r':c_space();break;
 }
 }
}
