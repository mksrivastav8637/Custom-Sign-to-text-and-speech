#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

#define FLEX_SENSOR_1_PIN A0
#define FLEX_SENSOR_2_PIN A1
#define FLEX_SENSOR_3_PIN A2
#define FLEX_SENSOR_4_PIN A3
#define THRESHOLD 70

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD address may vary, check your module
SoftwareSerial mySoftwareSerial(10, 11);  // RX, TX for DFPlayer
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin DFPlayer"));
    while(true);
  }

  myDFPlayer.setTimeOut(500);  // Set serial communication timeout to 500ms
 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sign Language to");
  lcd.setCursor(0, 1);
  lcd.print("Speech");
  myDFPlayer.play(1);  // Play audio file 001.mp3
  delay(3000);
  lcd.clear();
}

void loop() {
  int flexValue1 = analogRead(FLEX_SENSOR_1_PIN);
  int flexValue2 = analogRead(FLEX_SENSOR_2_PIN);
  int flexValue3 = analogRead(FLEX_SENSOR_3_PIN);
  int flexValue4 = analogRead(FLEX_SENSOR_4_PIN);
//Serial.println(flexValue1);
delay(300);
//Serial.println(flexValue2);
delay(300);
//Serial.println(flexValue3);
delay(300);
Serial.println(flexValue4);
  if (flexValue1 > 80) {
    lcd.setCursor(0, 0);
    lcd.print("Flex Sensors:");
    lcd.print(flexValue1);
    lcd.setCursor(0, 1);
    lcd.print("I Need Water");
    myDFPlayer.play(2);  // Play audio file 001.mp3
 delay(3000);  // Allow time for audio playback
    lcd.clear();
  }
else if (flexValue2 > 60) {
    lcd.setCursor(0, 0);
    lcd.print("Flex Sensors:");
    lcd.print(flexValue2);
    lcd.setCursor(0, 1);    
    lcd.print("I Need Food");
    myDFPlayer.play(3);  // Play audio file 001.mp3
 delay(3000);  // Allow time for audio playback
    lcd.clear();
  } 
  else if (flexValue3 > 60) {
    lcd.setCursor(0, 0);
    lcd.print("Flex Sensors:");
    lcd.print(flexValue3);
    lcd.setCursor(0, 1);    
    lcd.print("I Need Food");
    myDFPlayer.play(4);  // Play audio file 001.mp3
 delay(3000);  // Allow time for audio playback
    lcd.clear();
  }
  else if (flexValue4 > 160) {
    lcd.setCursor(0, 0);
    lcd.print("Flex Sensors:");
    lcd.print(flexValue4);
    lcd.setCursor(0, 1);    
    lcd.print("I Need Food");
    myDFPlayer.play(5);  // Play audio file 001.mp3
 delay(3000);  // Allow time for audio playback
    lcd.clear();
  }  
  else if (flexValue1 > 80 && flexValue2 > 60) {
    lcd.setCursor(0, 0);
    lcd.print("Flex Sensors:");
    lcd.print(flexValue3);
    lcd.setCursor(0, 1);    
    lcd.print("I Need Food");
    myDFPlayer.play(6);  // Play audio file 001.mp3
 delay(3000);  // Allow time for audio playback
    lcd.clear();
  }
  else if (flexValue3 > 60 && flexValue4 > 160) {
    lcd.setCursor(0, 0);
    lcd.print("Flex Sensors:");
    lcd.print(flexValue3);
    lcd.setCursor(0, 1);    
    lcd.print("I Need Food");
    myDFPlayer.play(7);  // Play audio file 001.mp3
 delay(3000);  // Allow time for audio playback
    lcd.clear();
  }
  else
  { lcd.clear();}       
}
