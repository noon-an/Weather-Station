
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
    
  dht.begin();
}

void loop () {
  delay(2000);
  float t = dht.readHumidity ();
  float h = dht.readTemperature();


  if(isnan(h) || isnan(t)){
    lcd.setCursor(0,0);
    lcd.print("Failed to read ");
    lcd.setCursor(0,1);
    lcd.print("from DHT sensor!");
    return;
  }
  {}
  lcd.setCursor(0,0);
  lcd.print("Humi: ");
  lcd.print(h);
  lcd.print("%   ");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C   ");

  //heat index
  float hic = dht.computeHeatIndex(t,h,false);
  delay(3000);
  lcd.setCursor(0, 0);
  lcd.print("   Heat Index   ");
  lcd.setCursor(0,1);
  lcd.print("   ");
  lcd.print(hic);
  lcd.print((char)223);
  lcd.print("C   ");

}