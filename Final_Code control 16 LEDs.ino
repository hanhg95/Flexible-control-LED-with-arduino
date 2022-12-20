This code was made by: Nguyen Van Han
Email: hanhg95@gmail.com

byte data[] [2] ={
  B00110000,B00110000,
  B00000011,B00000011,
  B11000000,B11000000,
  B00011000,B00110000,
  B00001100,B00001100,
};

int latchPin = 8;
int clockPin =12;
int dataPin = 11;

void setup(){
  pinMode (latchPin,OUTPUT);
  pinMode (clockPin,OUTPUT);
  pinMode (dataPin,OUTPUT);
  Serial.begin(9600); 
}

void read_bit (int k)
{
  int i,j;
  byte b;
  digitalWrite(clockPin,0);
  digitalWrite(latchPin,0);

  for (i=1;i>=0;i--)
    for (j=0;j<=7;j++)
    {
      b=bitRead(data[k][i],j);
      digitalWrite(clockPin,1);
      digitalWrite(clockPin,0);
    }
  digitalWrite(latchPin,1);
  digitalWrite(latchPin,0);
}

void loop()
{
  int k;
  for (k=0;k<=4;k++){read_bit(k); delay (500);}
}
