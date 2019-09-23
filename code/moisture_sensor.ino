#include “Adafruit_seesaw.h”;
Adafruit_seesaw ss;

// to communicate with the computer, use one of the following rates: 
// 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200.
uint16 serial_baud = 0; // Set the serial_baud rate
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
  // see https://adafruit.github.io/Adafruit_Seesaw/html/class_adafruit__seesaw.html for documentation
  float tempC = ss.getTemp(); // temperature reading
  Uint16_t capread = ss.touchRead(0); // capacitive reading

  Serial.print("Temperature: "); Serial.print(tempC);
  Serial.println("*C");               
  Serial.print("Capacitive: "); Serial.println(capread);
  delay(1000);               // wait for a second
}
