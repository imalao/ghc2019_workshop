# Build With Us: IoT to Keep Your Plants Alive!

Presenters: Ivy Malao, Star Washington, Yanning Qu

# Overview

Tables will work together to build a simple device that tells you when to water a plant. Wiring together and writing code for an Arduino, LEDs, moisture sensor, you will be able to use your device in different potted plants to determine which are over or under-watered. 

These instruction are divided into **two separate modules**: working with the **moisture sensor** and working with the **LEDs**. These two modules can be completed in parallel. The **last step** is to figure out how to use the moisture sensor readings to control the LEDs.

# Materials

-	Arduino Uno
-	Half breadboard
-	Adafruit I2C Capacitive Moisture Sensor
-	4-pin JST-PH cable
-	LEDs
-	Resistors 
-	USB-B cable
-	Jumper wires

Moisture sensors include two styles: resistive sensors and capacitive sensors. 

Resistive style sensors use two probes to pass current through the soil and read the resistance to get the moisture level. Wet soil causes the soil to conduct electricity better (less resistance). Corrosion of the sensor probes limits the lifespan of a resistive sensor.

Capacitive moisture sensors use only one probe and do not have any exposed metal. They work by measuring the “dielectric” that is formed by the soil. Water is the most important factor that affects the dielectric and the sensor measures specifically the dissolved ions (electrically charged molecules). **Capacitive moisture sensors will give you a reading ranging from 200 (very dry) to 2000 (very wet).**

![moisture_sensors](./imgs/moisture_sensors.png)

# Instructions

## Hardware and Arduino Simulator

As each table is provided with only one set of hardware components, you can optionally use Tinkercad to simulate the Arduino and hardware: https://www.tinkercad.com/

## Moisture Sensor 

### Hardware

Connect the moisture sensor to the Arduino using the 4-pin JST-PH cable. JST is just the manufacturer’s name and PH is the series of cable.

 ![moisture_sensors](./imgs/moisture_sensors.png)

Looking at the image above, from top to bottom, the pinout is

1.	**I2C SCL**: Clock Line used to synchronize all data transfers over the I2C bus. 
2.	**I2C SDA**: Data Line
3.	**Vin**: 3-5V DC. Has a regulator which supplies 5V to the 5V pin/node
4.	**GND**: power and logic ground

 ![adafruit_moisture_sensor](./imgs/adafruit_moisture_sensor.png) 

- Connect **Vin Red Wire to the power supply**. Use the same voltage that the microcontroller logic is based off of. For most Arduino's, that is 5V.
- Connect **GND Black Wire to common power/data ground**
- Connect the **SCL Green Wire pin to the I2C clock SCL pin** on your Arduino. On an UNO Arduino, this is also known as A5.
- Connect the **SDA White Wire pin to the I2C data SDA pin** on your Arduino. On an UNO Arduino, this is also known as A4.

### Software

1.	Create an **Online Arduino Web Editor Account** (create.arduino.cc) or download the **Arduino desktop IDE**
2.	Install **Arduino Create Plugin** to upload code to the Arduino
3.	To install the Adafruit libraries
    - Click on Libraries on the left bar
    - Click on Library Manager, the blue button on the top. 
    - Search for Adafruit_seesaw and Star it to download the library. 
    - Go to **Favorites**, mouseover the Adafruit Seesaw Library, and click **Include** to include the Adafruit seesaw libraries.
 
  ![installing_adafruit_lib](./imgs/installing_adafruit_lib.png) 
  
4.	Use the following starter code:

You can also find the starter code here:


1.	#include “Adafruit_seesaw.h”;
2.	Adafruit_seesaw ss;
3.	
4.	uint16 serial_baud = 0; // fill in serial_baud
5.	uint16 seesaw_I2C_address = 0x00; // fill in Adafruit seesaw I2C address
6.	 
7.	// the setup routine runs once when you press reset:
8.	void setup() {                
9.	  // initialize the digital pin as an output.
10.	  Serial.begin(serial_baud);
11.	  Serial.println(''Seesaw Soil Sensor example'');
12.	  if (!ss.begin(seesaw_I2C_address)) {
13.	    Serial.println("ERROR! seesaw not found");
14.	    while (1);
15.	  } else {
16.	    Serial.print("Seesaw started! version: ");
17.	    Serial.println(ss.getVersion(), HEX);
18.	  }
19.	}
20.	
21.	// the loop routine runs over and over again forever:
22.	void loop() {
23.	  float tempC = 0.0; // fill in temperature reading, see
24.	 // https://adafruit.github.io/Adafruit_Seesaw/html/class_adafruit__seesaw.html
25.	  Uint16_t capread = 0; // fill in capacitive reading, note use pin number = 0, see
26.	 // https://adafruit.github.io/Adafruit_Seesaw/html/class_adafruit__seesaw.html
27.	
28.	  Serial.print("Temperature: "); Serial.print(tempC);
29.	  Serial.println("*C");               
30.	  Serial.print("Capacitive: "); Serial.println(capread);
31.	  delay(1000);               // wait for a second
32.	}
5.	Upload your code by connecting your Arduino to your laptop using the USB-B cable.
6.	Open up the serial console at the baud rate you set in serial¬_baud to see the temperature and capacitive reading. Baud is a measurement of bit rate.
7.	Try touching the body of the sensor to make the “moisture” measurement go up. The temperature reading is only on the chip itself but gives you an idea of the room’s temperature.

## LEDs

 


1.	Connect your stripboard as shown above using the jumper wires, resistor(s), and LED(s). The Arduino can provide power if you plug it in with the USB-B cable. LEDs have a positive and negative leads and will not light if they are the wrong way around. The positive lead is longer.
2.	With the 270 Ohm resistor, the LED should be quite bright. You can use any of the provided resistors.
3.	Now attach the LED to a digital output pin of the Arduino so that you can control the LED with code. Based on the diagram, move the red jumper wire from the 5V pin to one of the digital pins (e.g. 13).
4.	Modify your code to control your LEDs based on the moisture or temperature reading following this sample:
33.	/*
34.	  Blink
35.	  Turns on an LED on for one second, then off for one second, repeatedly.
36.	 
37.	  This example code is in the public domain.
38.	 */
39.	 
40.	// Pin 13 has an LED connected on most Arduino boards.
41.	// give it a name:
42.	int led = 13;
43.	 
44.	// the setup routine runs once when you press reset:
45.	void setup() {                
46.	  // initialize the digital pin as an output.
47.	  pinMode(led, OUTPUT);     
48.	}
49.	 
50.	// the loop routine runs over and over again forever:
51.	void loop() {
52.	  // initialize the digital pin as an output.
53.	  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
54.	  delay(1000);               // wait for a second
55.	  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
56.	  delay(1000);               // wait for a second
57.	}
Next Steps!

If you have a general interest in electronics and IoT, start with Arduinos!
•	An open-source electronics prototyping platform where each of their boards has a microcontroller that let you program to do things and can interact with the world. 
•	Most of their projects are open source, meaning they provide you with schematics, printed circuit board design, and bill of materials (BOM) 
•	See ”getting started” page under resource on Arduino website.
•	https://www.makeuseof.com/tag/arduino-technology-explained/

If you are really interested in making electronic gadgets and doing embedded programming: 
1.	Have a basic understanding of voltage, current, power, resistance, etc.
2.	Learn by building circuits on a breadboard from any circuit diagrams you can find online or in books
3.	Have a basic understanding of electronic components: resistor, diode, LED, capacitor, inductor, transistor
•	Try to build a switch with transistor! This is not easy but very useful
4.	Learn how to solder -- you don't want to use breadboard forever. Soldering is very fun, and not hard to learn. All you need to do is practice.
5.	Build circuits using integrated circuit (aka IC or a chip) -- basically any type of circuit that is made to fit onto a single chip.
6.	Design your own circuit
•	Autodesk Eagle PCB design software is free if you are not designing very complex circuits. You can learn how to create a schematic and PCB layout, and then how to order cheap PCB prototypes (1-day or 2-day turn, how many layers and size, use of vias, polygon pour)
7.	Learn to use a microcontroller. Embedded programming is not running on an operating system but directly interfacing with hardware
8.	Learn C and assembly. The majority of embedded toolchains are designed to support C
9.	Get basic equipment: meters (DMM, scope), debugger, logic analyzer (convert captured data into timing diagrams)
10.	Choose a microcontroller and toolchain...
11.	Be prepared to dig into datasheets! You will spend a lot of time on reading datasheets.
12.	Have fun!


# Useful References

Books
•	Practical Electronics for Inventors by Paul Scherz & Simon Monk
•	The Art of Electronics by Paul Horowitz & Winfield Hill
•	Fundamentals of Analog and Digital Electronic Circuits, by Anant Agarwal
•	Beginning C From Novice to Professional by Ivor Horton
Websites
•	https://www.allaboutcircuits.com/textbook/
Videos
•	Coursera
•	Udemy
•	YouTube
Games
•	Shenzhen I/O: Build circuits and write code on Steam!


# Works Cited

https://www.switchdoc.com/2018/11/tutorial-capacitive-moisture-sensor-grove/

