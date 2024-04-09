#include <Wire.h>
#include <MPU6050.h>
#include <SoftwareSerial.h>
#include <I2Cdev.h>

MPU6050 mpu;
const int MPU_ADDRESS = 0x68; // I2C address of the MPU-6050

int16_t ax, ay, az, gx, gy, gz; // 16-bit integers
SoftwareSerial BTSerial(3, 2); // RX, TX pins of HC-05

const int INDEX_PIN = A3;  
const int MIDDLE_PIN = A2;
const int RING_PIN = A1;
const int PINKY_PIN = A0;

void setup() {
  // Flex sensor pin setup
  pinMode(PINKY_PIN, INPUT); //PINKY
  pinMode(RING_PIN, INPUT); //RING
  pinMode(MIDDLE_PIN, INPUT); //MIDDLE
  pinMode(INDEX_PIN, INPUT); //INDEX
 
  Serial.begin(9600); // Initialize serial communication for debugging
  Wire.begin();
  mpu.initialize();
  BTSerial.begin(9600); // Initialize SoftwareSerial for Bluetooth communication
}

void loop() {
  // Flex sensor readings
  int index = analogRead(INDEX_PIN);
  int middle = analogRead(MIDDLE_PIN);
  int ring = analogRead(RING_PIN);
  int pinky = analogRead(PINKY_PIN);

  // MPU6050 data readings
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  if (index >=0 && middle >= 260 && ring<210 && pinky <210 && ay > 125) {
    BTSerial.println("peace"); // Sends string over bluetooth
    Serial.println("peace");
  } else if (index >=0 && middle >= 260 && ring >=210 && pinky <=210 ) {
    BTSerial.println("i need help");
    Serial.println("i need help");
  } else if (index >=0 && middle >= 260 && ring >=210 && pinky >= 210 && ay >= 125) {
    BTSerial.println("hello");
    Serial.println("hello");
  } else if (index >=0 && middle <= 240 && ring <=210 && pinky <= 210) {
    BTSerial.println("fist bump");
    Serial.println("fist bump");
  } else if (index >=0 && middle <= 240 && ring <=200 && pinky >= 210 && ay >= 130) {
    BTSerial.println("need to go washroom");
    Serial.println("need to go washroom");
  } else if (index >=0 && middle >= 260 && ring >=210 && pinky >= 210 && ax < 100) {
    BTSerial.println("thank you");
    Serial.println("thank you");
  } else {
    BTSerial.println("No sign detected");
    Serial.println("No sign detected");
  }
  delay(2000); 
}
