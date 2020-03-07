#include <SPI.h>
#include <LoRa.h>

//byte n;
  int counter=0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
 
  LoRa.setTxPower(20);
  LoRa.setSpreadingFactor(12);
}
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter,BIN);

  // send packet
  LoRa.beginPacket();
  LoRa.print(counter,BIN);
  LoRa.endPacket();
  counter++;
  

  delay(5000);
}
