#include <Wire.h>
#define Slave1 48
#define Adress 1

void setup() {
  // Pines en modo salida
  for(int k=2;k<=9;k++){
    pinMode(k,OUTPUT);
  }
  // Configuración de Memoria y tipo de esclavo.
  Wire.setClock(400000);
  Wire.begin(Slave1);
  Wire.onReceive(Recibir); // Write.
  Wire.onRequest(Send);   // Send.
}
int led = 0;

void loop() {
}

void Send(){
    if(led == 2){
    Wire.write("Done");
    }else{
      Wire.write("W");
    }
}

void Recibir(int howMany){
  while(Wire.available() > 0){
    led=2;
    byte N = Wire.read();
    for(int k = 0; k<=7 ; k++){
      digitalWrite(led,bitRead(N,k)); // Activa, según el bit (0 LOW, 1 HIGH).
      led++;
    }
    delay(100);
  }
  delay(100);
}
