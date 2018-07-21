

/*
 
 
 Proyecto de prueba eMGing para test de Shield eMGing Bluetooth

 Recibe mensajes desde el puerto Serie de HARDWARE del Arduino y se lo envía a los 
 puertos Serie de SoftwareSerial, recibe desde SoftwareSerial y lo envía al Serie Hardware.

 El cicuíto:
 * RX es el pin digital número 10 del Arduino(conecta a TX del otro dispositivo)
 * TX es el pin digital número 8 del Arduino(conecta a RX del otro dispositivo)

 Nota:
 NO todos los pines del MEGA o MEGA2560 soporta cambio en los pines de interrupción,
 por lo tanto solo los siguientes pueden utilizarse: RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 NO todos los pines del Leonardo soporta cambio en los pines de interrupción,
 por lo tanto solo los siguientes pueden utilizarse: RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 Para TX pueden usar cualquier PIN sin problemas.
 
 consultas: info@eMGing.com.ar
 www.eMGing.com.ar

  */
#include <SoftwareSerial.h>

#define EMGING_RX 10    // corresponde al pin RX del Shield Bluetooth y TX del Arduino UNO/MEGA
// PARA Arduino UNO
//#define EMGING_TX 8    // corresponde al pin TX del Shield Bluetooth y RX del Arduino UNO
// PARA Arduino MEGA
#define EMGING_TX 11    // corresponde al pin TX del Shield Bluetooth y RX del Arduino MEGA
                        // Se DEBERA PUENTEAR pin 8 con el PIN 11

SoftwareSerial mySerial(EMGING_TX, EMGING_RX);

void setup() {
  // Abre puerto serial de comunicación y espera a que se abra el puerto
  Serial.begin(9600);
  while (!Serial) {
    ; // Espera a que se conecte el puerto. Necesita solo del puerto USB nativo
  }


  Serial.println("Hola Mundo!!");

  // Especifica la tasa de transmisión para el Puerto del SoftwareSerial
  mySerial.begin(9600);
  mySerial.println("Hola, Mundo ??");
}

void loop() { // Loop de ejecución de programa
  char c;
  if (mySerial.available()) {
    c=mySerial.read();
    Serial.print(c);
  }
  
  char c1;
  if (Serial.available()) {
    c1=Serial.read();
    mySerial.print(c1);
  }
}
