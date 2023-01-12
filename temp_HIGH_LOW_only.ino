#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int humi = dht.readHumidity();
  int temp = dht.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("\t Humidity = ");
  Serial.print(humi);
  Serial.println();
  while(temp < 25)
  {
    temp = dht.readTemperature();
    humi = dht.readHumidity();
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    delay(200);
  }
  while(25 <= temp && temp < 40)
  {
    humi = dht.readHumidity();
    temp = dht.readTemperature();
    Serial.print("Temperature = ");
    Serial.print(temp);
    Serial.print("\t Humidity = ");
    Serial.print(humi);
    Serial.println("   up");
    digitalWrite(4, HIGH);
    digitalWrite(3,LOW);
    delay(200);
  }

  while(40 <= temp && temp <= 50)
  {
    humi = dht.readHumidity();
    temp = dht.readTemperature();
    Serial.print("Temperature = ");
    Serial.print(temp);
    Serial.print("\t Humidity = ");
    Serial.print(humi);
    Serial.println("   down");
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    delay(200);
  }
}
