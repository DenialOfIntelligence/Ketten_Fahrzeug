#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10); // (CE, CSN)
char text[0]="";
const byte address[6] = "1RF24";

void setup() {
  radio.begin();
  radio.setPALevel(RF24_PA_MAX); 
  radio.setChannel(125);
  radio.openWritingPipe(address); 
  radio.stopListening();
  Serial.begin(9600);
}

void loop() {
  //  Serial.println(radio.isChipConnected());

  if (analogRead(1)>700){
    char text[]="w";
    Serial.println(text);
    radio.write(&text, sizeof(text)); 
  }
  
  if (analogRead(1)<100){
    char text[]="s";
    Serial.println(text);
    radio.write(&text, sizeof(text));  
  }
  
  else{
  if(analogRead(0)>700){
    char text[]="d";
    Serial.println(text);
    radio.write(&text, sizeof(text));
  }
  
  if (analogRead(0)<100){
    char text[]="a";
    Serial.println(text);
    radio.write(&text, sizeof(text));
  }
  
  delay(10);
  }
}
