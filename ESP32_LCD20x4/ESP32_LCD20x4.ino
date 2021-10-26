#include <BH1750FVI.h>
#include <LiquidCrystal_I2C.h>

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
int lcdColumns = 20;
int lcdRows = 4;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup()
{
  Serial.begin(115200);
 lcd.init();
 lcd.backlight();
  LightSensor.begin();
}
void loop()
{
  uint16_t lux = LightSensor.GetLightIntensity();
  int adc_1 = analogRead(34);
  int adc_2 = analogRead(35);
  lcd.setCursor(3, 0);
  lcd.print("ELECTRONIC ENG.");
  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.setCursor(7, 1);
  lcd.print(String(lux));
  lcd.setCursor(0, 2);
  lcd.print("ADC0:  " + String(adc_1));
  lcd.setCursor(0, 3);
  lcd.print("ADC1:  " + String(adc_2));
  delay(1000);
  lcd.clear();
}
