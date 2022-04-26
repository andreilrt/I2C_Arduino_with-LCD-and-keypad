//MAESTRO
#include <Wire.h>
#include <Keypad.h>

const byte filas = 4;
const byte columnas = 4;

char keys[filas][columnas] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pinesf[filas] = {9, 8, 7, 6}; 
byte pinesc[columnas] = {5, 4, 3, 2};

Keypad tec = Keypad( makeKeymap(keys), pinesf, pinesc, filas, columnas );

char ingreso[7];
char contra[]="123456";
byte pos = 0;

void setup()
{
  Wire.begin(1);
  Serial.begin(9600);
  Serial.println("Soy el maestro");
}

void loop()
{
  char key = tec.getKey();
  if (key!=NO_KEY){
  	Serial.println(key);
    ingreso[pos]=key;
    pos++;
  }
  if (pos == 6)
  {
  	byte check =0;
    for(int i=0;i<6;i++)
    {
      Serial.print(ingreso[i]);
      if(ingreso[i]==contra[i]){
      	check++;
      }
    }
    Wire.beginTransmission(1);
    if (check==6)
    {
      Wire.write('T');
    }
    else
    {
      Wire.write('F');
    }
    pos = 0;
  	}
  	Wire.endTransmission(1);
  delay(200);
}
