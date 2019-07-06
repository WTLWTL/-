#汪童乐的开源硬件作业

> 汪童乐

##第一天



###学习内容

-为什么要学习开源硬件

-如何学习开源硬件

-三个软件

​	arduino

![](D:\桌面\开源硬件\hardware\图片\arduino.png)

​	fritzing

![](D:\桌面\开源硬件\hardware\图片\fritzing.png)

​	processing

![](D:\桌面\开源硬件\hardware\图片\processing.png)

-几个常用网站

[arduino](www.arduino.cc)

[ubuntu](www.ubuntu.com)

[fritzing](www.fritzing.org)

[processing](processing.org)

[Github](github.com)

[thinkercad](thinkercad.com)

##第二天



#####学习内容

-arduino编程

Morse.h

```c

```



#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
​    Morse(int pin);
​    void dot();
​    void dash();
​    void c_space();
​    void w_space();
  private:
​    int _pin;
​    int _dottime;
};
#endif /*_MORSE_H*/

```c
库函数
```

#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
​	pinMode(pin,OUTPUT);
​	_pin=pin;
​	_dottime=250;
}

void Morse::dot()
{
​	digitalWrite(_pin,HIGH);
​	delay(_dottime);
​	digitalWrite(_pin,LOW);
​	delay(_dottime);
}

void Morse::dash()
{
​	digitalWrite(_pin,HIGH);
​	delay(_dottime*4);
​	digitalWrite(_pin,LOW);
​	delay(_dottime);
}

void Morse::c_space()
{
​	digitalWrite(_pin,LOW);
​	delay(_dottime*3);
}

void Morse::w_space()
{
​	digitalWrite(_pin,LOW);
​	delay(_dottime*7);
}

```c
主函数
```

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
  splitString(buffer);
  for(i=1;i<=index;i++)
  {k=buffer[i];
   switch(k)
  {
​    case 'a':{dash();dot();} break;
​    case 'b':{dash();dot();dot();dot();}break;
​    case 'c':{dash();dot();dash();dot();}break;
​    case 'd':{dash();dot;dot();}break;
​    case 'e':{dot();}break;
​    case 'f':{dot();dot();dash();dot();}break;
​    case 'g':{dash();dash();dot();}break;
​    case 'h':{dot();dot();dot();dot();}break;
​    case 'i':{dot();dot();}break;
​    case 'j':{dot();dot();dot();}break;
​    case 'k':{dash();dot();dash();}break;
​    case 'l':{dot();dash();dot();dot();}break;
​    case 'm':{dash();dash;}break;
​    case 'n':{dash();dot();}break;
​    case 'o':{dash();dash();dash();}break;
​    case 'p':{dot();dash();dash();dot();}break;
​    case 'q':{dash();dash();dot();dash();}break;
​    case 'r':{dot();dash();dot();}break;
​    case 's':{dot();dot();dot();}break;
​    case 't':dash();break;
​    case 'u':{dot();dot();dash();}break;
​    case 'v':{dot();dot();dot();dash();}break;
​    case 'w':{dot();dash();dash();}break;
​    case 'x':{dash();dot();dot();dash();}break;
​    case 'y':{dash();dot();dash();dash();}break;
​    case 'z':{dash();dash();dot();dot();}break;
​    case ' ':w_space();break;
​    case '\r':c_space();break;
 }
 }
}

```

```

##第三天



###学习内容

-小车编程

```c

```

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

```c

```

-小车电路图

![](D:\桌面\开源硬件\hardware\car\ScreenClip.png)

-数字显示

通过串口输入数字，在数码管显示

单片机型号CD4511 

```c

```

void setup()
{
   pinMode(0, OUTPUT);
   pinMode(1, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   Serial.begin(9600);
}
byte income;
void loop()
{
  if(Serial.available()>0)
  {
  income=Serial.read();
  income=income-'0';
​    if(income&0x1)
​    {
​    digitalWrite(1,HIGH);
​    }
​    else
​    {
   digitalWrite(1,LOW);
​    }
​    if((income>>1)&0x1)
​    {
​    digitalWrite(2,HIGH);   
​    }
​    else
​    {
​     digitalWrite(2,LOW);
​    }
​    if((income>>2)&0x1)
​    {
​    digitalWrite(3,HIGH);   
​    }
​    else
​    {
​     digitalWrite(3,LOW);
​    }
​    if((income>>3)&0x1)
​    {
​    digitalWrite(4,HIGH);
​    }
​    else
​    {
​     digitalWrite(4,LOW);
​    }
​     
  }

  delay(10);
  digitalWrite(0,HIGH);
}

```c

```

-数码管电路图

![](D:\桌面\开源硬件\hardware\数字显示\ScreenClip.png)

##第四天



####学习内容

-github本地上传

-摩尔斯电码（不用函数库）

-学习总结

```C

```

int _pin=13;
int _dottime=250;

void dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}
char MORSE[][4] = {
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}  //Z
};

void setup()
{ pinMode(_pin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  String str = "";  
  String morse_s = "";  
  int i, t , temp = 0;
  int n = 0; 
  while (Serial.available() > 0)
  {
​    temp = 1;  
​    str += char(Serial.read()); 
​    delay(2);  
​    n++;
  }

  if (temp)
  {
​    

```c
for (i = 0; i < n; i++)
{
  for (t = 0; t < 4; t++)
  {
    
    if (str[i] >= 97 && str[i] <= 122)
    {
      morse_s += char(MORSE[int(str[i] - 97)][t]);
    }
  }
  
  morse_s += ' ';
}
Serial.println(morse_s);  
for (i = 0; morse_s[i]!='\0' ; i++)
{
  if (morse_s[i] == '.')dot();
  else if (morse_s[i] == '-')dash();
  else if (morse_s[i] == ' ')w_space();
  if (morse_s[i] != ' ' && str[i] != '*')c_space();
}
delay(2);
```
  }
}

```c

```

-电路图

![](D:\桌面\开源硬件\hardware\morse(不含库)\ScreenClip.png)

