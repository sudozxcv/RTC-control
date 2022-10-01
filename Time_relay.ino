
//SPECIFIC TIME TRIGGER RELAY
#include <DS3231.h>

int Relay = 2;

DS3231  rtc(SDA, SCL);
Time t;

const int OnHour = 8; //SET TIME TO ON RELAY (24 HOUR FORMAT)
const int OnMin = 0;
const int OnSec = 1;
const int OffHour = 8; //SET TIME TO OFF RELAY
const int OffMin = 0;
const int OffSec = 5;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.print(t.sec);
  Serial.print(" second(s), ");
  Serial.println(" ");
  delay (1000);
  
  if(t.hour == OnHour && t.min == OnMin && t.sec == OnSec){
    digitalWrite(Relay,HIGH);
    Serial.println("LIGHT ON");
    }
    
    else if(t.hour == OffHour && t.min == OffMin && t.sec == OnSec){
      digitalWrite(Relay,LOW);
      Serial.println("LIGHT OFF");
    }
}
