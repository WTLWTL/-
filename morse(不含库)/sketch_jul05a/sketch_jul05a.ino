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
    temp = 1;  
    str += char(Serial.read()); 
    delay(2);  
    n++;
  }

  if (temp)
  {
    
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
  }
}
