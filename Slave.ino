//ESCLAVO
#include <Wire.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char c = ' ';
int ledRojo =8;
int ledVerde=7; 
int ledAzul=6;


void setup()
{
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAzul,OUTPUT);

  Serial.begin(9600);
  Serial.println("Soy el esclavo");
  Wire.begin(1);
  lcd.begin(16, 2); 
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int howMany)
{   
  if(Wire.available()) 
  {
    c = Wire.read();  
  }
  Serial.print("Informacion recibida: ");
  Serial.println(c);
}

void loop()
{
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,LOW);
  while(c==' ')
  { 
  	lcd.setCursor(2,2);
  	lcd.print("Digitar clave ");
    digitalWrite(ledAzul,HIGH);
    delay(500);
  }
  if(c=='T')
  {
    lcd.setCursor(2,2);
    lcd.print("Hola mundo!!! ");
    digitalWrite(ledVerde,HIGH);
    delay(100);
  }
  else
  {
    lcd.setCursor(2,2);
    lcd.print("Incorrecto :((");
    c=' ';
    digitalWrite(ledRojo,HIGH);
    delay(1000);
    
  }
}
