// Wire Scanner
//
//
// Demonstrates the use of the Wire library
// Ping all valid addresses on the I²C bus
// and get the answer to see if there is a slave
// Print an 8 x 16 array with the results

// Created by fdufnews 2012 december 14th

// This example code is in the public domain.

// I2C definition states that address 0 to 7 and 7C to 7F are reserved ones
// so those addresses are not scanned

#include <Wire.h>

void setup()
{
	 int result;
	 Wire.begin();         // join i2c bus (address optional for master)
	 Serial.begin(9600);   // start serial for output
	 Serial.println();     // Print a banner
	 Serial.println();
	 Serial.println("I2C slave scanner");
	 Serial.println("   reserved address");
	 Serial.println(".  no slave detected");
	 Serial.println("X  slave detected");
	 Serial.println();
	 Serial.println();
	 // print low nibble of address
	 Serial.println("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F");
	 
	 // Scan only valid addresses (8 to 0x7B)
	 // 0-7 and 7C-7F are reserved ones
	 unsigned char devices=0;                  // keep trace of how many devices were found
	 for (unsigned char ad=0; ad<0x7C;ad++){
	   if(ad%16==0){                           // If at start of a row
		 Serial.print(ad>>4,HEX);              // Display high nibble of address
		 Serial.print(" ");
	   }
	   if (ad>7){                              // test if valid address
		 Wire.beginTransmission(ad);           // start transmission
		 result = Wire.endTransmission();      // end transmission and get ACK/NACK
		 if (!result) devices++;               // add a device to the count if ACK
		 Serial.print(" ");
		 Serial.print(result==0?"X ":". ");    // If ACK there is a guy at this address
	   }
	   else{
		 Serial.print("   ");                  // If reserved address
	   }
	   if(ad%16==15) Serial.println();         // if end of the row add a new line
	 }
	 Serial.println();
	 Serial.println();
	 Serial.println();
	 Serial.print(devices, DEC);
	 Serial.print(" device");
	 Serial.print(devices>1?"s":"");
	 Serial.println(" found on the bus");
}

void loop()
{

}
