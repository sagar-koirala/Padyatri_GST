#include <SPI.h>
#include <LoRa.h>

int counter = 0;
unsigned long lasttime = 0;
int interval = 0;

void receivepckt(int pcktsize){
  if (pcktsize) {
    // received a packet
    Serial.print("Received message: ");

    // read packet
    while (LoRa.available()) {
     Serial.print((char)LoRa.read());
      // Serial.print(LoRa.read());

    }

    // print RSSI of packet
    Serial.print(" with RSSI ");
    Serial.println(LoRa.packetRssi());
    }
}

void setup() {
   LoRa.setPins(7, 8, 3);   //uncomment for receiver board
  Serial.begin(9600);
  while (!Serial);  

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  if (millis() - lasttime > 100){
    Serial.print("Sending  message: Packet no: ");
    Serial.println(counter);
    LoRa.beginPacket();
    LoRa.print("HELLO FROM TRANSMITTER, Packet no: ");
    LoRa.print(counter);
    LoRa.endPacket();
    lasttime = millis();
    interval = random(1000)+800;
    counter++;
    Serial.println();
  }
receivepckt(LoRa.parsePacket());
}
