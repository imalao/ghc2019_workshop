#include “Adafruit_seesaw.h”;
Adafruit_seesaw ss;

uint16 serial_baud = 0; // fill in serial_baud
uint16 seesaw_I2C_address = 0x36; // Adafruit seesaw I2C address
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(serial_baud);
  Serial.println("Seesaw Soil Sensor example");
  if (!ss.begin(seesaw_I2C_address)) {
    Serial.println("ERROR! seesaw not found");
    while (1);
  } else {
    Serial.print("Seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  float tempC = 0.0; // fill in temperature reading, see
 // https://adafruit.github.io/Adafruit_Seesaw/html/class_adafruit__seesaw.html
  Uint16_t capread = 0; // fill in capacitive reading, note use pin number = 0, see
 // https://adafruit.github.io/Adafruit_Seesaw/html/class_adafruit__seesaw.html

  Serial.print("Temperature: "); Serial.print(tempC);
  Serial.println("*C");               
  Serial.print("Capacitive: "); Serial.println(capread);
  delay(1000);               // wait for a second
}
