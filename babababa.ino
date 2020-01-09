#include <LiquidCrystal.h>



float Temperature; 
float value; 
int lm35pin=A0;  
int motor=9;

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup () {
  Serial.begin(9600); 
  pinMode(motor,OUTPUT);
  
  lcd.begin(16,2);
}

void loop () {
 value = analogRead(lm35pin); //read analog values from A0
 value = (value/1023.00)*5000.00; //converting analog value into mV
 Temperature = value/10.00;  // converting mV to Celcius

 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Sicaklik" );
 lcd.setCursor(0,1);
 lcd.print(Temperature);
 lcd.print(" ^C");

 
 Serial.print("Sicaklik : "); //TEMPERATURE
 Serial.println (Temperature);
 Serial.println (" ^C");

 
 
 if (Temperature>=24 )
 {
  digitalWrite(motor,HIGH);
 }

 
 else{
    digitalWrite(motor,LOW);
  }
delay(1500);
}
