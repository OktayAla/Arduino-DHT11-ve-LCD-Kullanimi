//--------------------------------------//
//---------------OKTAY ALA--------------//
//---Arduino | DHT11 ve LCD Kullanımı---//
//--------------------------------------//

#include <dht11.h> //Sıcaklık ve nem sensörünün kütüphane tanımlamasını yapıyoruz
#include <LiquidCrystal_I2C.h> //I2C LCD Ekranımızın kütüphane tanımlamasını yapıyoruz

int sicakliksensoru=2; //2 Numaralı dijital pinimize bağlı olan sensörü tanımlyıoruz

dht11 DHT11_sensor; //DHT11 veri tipini çağırıyoruz

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); //Kullanacağımız ekranın pixel boyutunu tanımlıyoruz

void setup()
{
  //LCD Ekranımızın arka ışığını ve çalışması için gereken kodları yazıyoruz
  lcd.init(); 
  lcd.backlight();
}

void loop()
{
int chk = DHT11_sensor.read(DHT11_pin); //Sensör üzerinden gelen verileri işleyip okutuyoruz

   lcd.setCursor(0,0); //İlk satır 0 olarak belirlenmektedir. Sıcaklık değerini ilk satırda yazmak için konumlandırmasını yapıyoruz
lcd.print("Sicaklik = ");
lcd.print((double)DHT11_sensor.temperature, 2); //DHT11 Kütüphanesinden sıcaklık değerini çağırıyoruz

   lcd.setCursor(0,1); //İkinci satır 1 olarak belirlenmektedir. Nem değerini ikinci satırda yazmak için konumlandırmasını yapıyoruz
lcd.print("Nem Orani = ");
lcd.print((double)DHT11_sensor.humidity, 2); //DHT11 Kütüphanesinden nem değerini çağırıyoruz

delay(1000); //Sensör üzerinden gelecek verileri 1 saniye aralıklarla güncellemesini yaptırıyoruz
}
