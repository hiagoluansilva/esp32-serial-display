#include <LiquidCrystal_I2C.h>
int dados;
int crt=0;
String buf;
int i=0;

int lcdColumns = 16;
int lcdRows = 2;

 LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
 
void setup()
{
  lcd.init();                     
  lcd.backlight();

 Serial.begin(9600);

}

void loop() 
{
  
 if (Serial.available()>0)
 {
    dados = Serial.read();

      if(dados == 'W')
      {
        crt=0;
        Serial.print('W');
        Serial.print(buf);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("End");
        buf="";
      }
      
      if(crt==1)
      {
        buf+=char(dados);
        buf.replace(" ", "");
        buf.replace("\n", "");
        buf.replace("'", "");
      }
      
      if(dados == 'Y')
      {
        crt=1;
        Serial.print('Y');
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Begin");
      }

 }
 
}
