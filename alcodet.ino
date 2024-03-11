
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#define BLYNK_TEMPLATE_ID "TMPL-zNcs3G0"
#define BLYNK_TEMPLATE_NAME "alcodet1"
#define BLYNK_AUTH_TOKEN "AntN16YOTSETD0GFztGxxy9smFPMHZhV"

char auth[] =BLYNK_AUTH_TOKEN; //Enter the Auth code which was send by Blink

char ssid[] = "Anusha";  //Enter your WIFI Name
char pass[] = "chikky27";  //Enter your WIFI Password

#define DHTPIN 2         
#define DHTTYPE DHT11     
const int buzzer=D0;
const int led1=D5;
const int led2=D7;

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
int gasSensor;
float ac;
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  gasSensor=analogRead(A0);
  float ac = (gasSensor / 1024.0) * 5.0 * 5.0;

  
  Serial.println("humidity");
  Serial.println(h);
  Serial.println("temperature:");
  Serial.println(t);
  Serial.println(ac);
  Serial.println("ppm");
  if(ac<8.3)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH); 
    digitalWrite(buzzer,LOW);
    Serial.println("Safe");
    
  }
  
  else if(ac>=8.3)
  {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(buzzer,HIGH);
      Serial.println("Warning");
      Blynk.logEvent("notification","High Alcohol");
  }
  delay(1000);

  Blynk.virtualWrite(V0, ac);
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature
  
}

void setup()
{
  Serial.begin(115200);
  delay(10);// See the connection status in Serial Monitor
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Blynk.begin(auth, ssid, pass);

  dht.begin();
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  
  timer.setInterval(1000L, sendSensor);
  
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer

 
  
}
