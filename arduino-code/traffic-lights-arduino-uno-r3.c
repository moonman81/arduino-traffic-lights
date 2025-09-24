// C++ code
//
void setup()
{pinMode(13,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(9,INPUT);
}

void loop()
{
  digitalWrite(13,HIGH);// makes the red LED turn on
  delay(5000);// makes the LED stay on gor 5 seconds
  
  
  digitalWrite(12,HIGH);// makes the orange LED turn on
  delay(2500);
  digitalWrite(13,LOW);// makes the red LED turn off
  delay(800);
  digitalWrite(12,LOW);
  delay(100);
  
  digitalWrite(11,HIGH);// makes the green LED trun on
  delay(6000);
  digitalWrite(11,LOW);
  delay(100);
  digitalWrite(12,HIGH);
  delay(400);
  digitalWrite(12,LOW);

  if (digitalRead(10)==HIGH)
      {digitalWrite(10,HIGH); }
      else digitalWrite(10,LOW);
}
