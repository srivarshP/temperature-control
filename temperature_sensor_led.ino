#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16, 2);

int baselineTemp = 0;

int celsius = 0;

void setup()
{
  	pinMode(A0, INPUT);
  	Serial.begin(9600);
   	pinMode(3, OUTPUT);
	lcd.init();
	lcd.backlight();
}

void loop()
{
  	baselineTemp = 40;
  	celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
    Serial.print(celsius);
    Serial.print(" C, ");
  	lcd.clear(); 
	lcd.setCursor(0, 0);
  	lcd.print(celsius);
  if(celsius>38){
    digitalWrite(3,HIGH);
  }
  else
  	digitalWrite(3,LOW);
   
}


