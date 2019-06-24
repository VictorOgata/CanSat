#include <SoftwareSerial.h>
SoftwareSerial HC12(10,11);
void setup() {
  Serial.begin(9600);          // Porta Serial do computador 
  HC12.begin(9600);            // Porta Serial do HC12
}
void loop() {
  while (HC12.available()) {   // Enquanto HC12 receber dados
    Serial.print(HC12.read()); // Escreve os dados na Serial
  }
}
