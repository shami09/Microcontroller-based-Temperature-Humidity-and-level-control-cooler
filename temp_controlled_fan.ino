#include<DHT.h>
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int tempPin = A0;   // the output pin of LM35
int fan = 11;       // the pin where fan is
int temp;
int tempMin = 30;   // the temperature to start the fan
int tempMax = 50;   // the maximum temperature when fan is at 100%
int fanSpeed;
 
void setup() {
  pinMode(fan, OUTPUT);
  pinMode(tempPin, INPUT);
  Serial.begin(9600);
  dht.begin();
}
 
void loop() {
   float humi = dht.readHumidity();
   int temp = dht.readTemperature(); 
   
   if((temp >= tempMin) && (temp <= tempMax)) {  // if temperature is higher than minimum temp
       fanSpeed = map(temp, tempMin, tempMax, 140, 255); // the actual speed of fan
       analogWrite(fan, fanSpeed);  // spin the fan at the fanSpeed speed
   } 

   if(temp < tempMin) {   // if temp is lower than minimum temp
    fanSpeed = 0;      // fan is not spinning
    digitalWrite(fan, LOW);       
   } 
   
   if(temp > tempMax) {        // if temp is higher than tempMax
    digitalWrite(fan, HIGH); 
   }
}
 
int readTemp() {  // get the temperature and convert it to celsius
  temp = analogRead(tempPin);
  return temp * 0.48828125;
}
