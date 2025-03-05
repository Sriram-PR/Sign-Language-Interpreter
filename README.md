# Sign Language Interpreter

## Overview
The system uses an Arduino microcontroller with flex sensors attached to a glove and an MPU6050 accelerometer to detect hand orientation. Recognized gestures are sent via Bluetooth to a paired device.

## Hardware Components
- Arduino board (e.g., Arduino Uno or Nano)
- MPU6050 accelerometer/gyroscope sensor
- HC-05 Bluetooth module
- 4 flex sensors (one for each finger except thumb)
- Glove to mount sensors
- Resistors for flex sensor circuits
- Connecting wires
- Power supply

## Connections
- Flex sensors connected to analog pins A0-A3:
  - A0: Pinky finger
  - A1: Ring finger
  - A2: Middle finger
  - A3: Index finger
- MPU6050 connected via I2C (SDA, SCL pins)
- HC-05 Bluetooth module:
  - TX connected to Arduino pin 3
  - RX connected to Arduino pin 2

## Recognized Gestures
The current implementation recognizes the following hand gestures:
- Peace sign
- "I need help" gesture
- Hello/greeting
- Fist bump
- "Need to go to washroom" gesture
- "Thank you" gesture

## Software Dependencies
- `Wire.h` library for I2C communication
- `MPU6050.h` library for accelerometer/gyroscope
- `SoftwareSerial.h` library for Bluetooth communication
- `I2Cdev.h` library for enhanced I2C device interface

## How It Works
1. The Arduino reads values from flex sensors to determine finger positions
2. The MPU6050 provides orientation data to enhance gesture recognition
3. The combination of flex sensor and accelerometer data is used to recognize specific gestures
4. When a gesture is recognized, a corresponding text message is sent via Bluetooth
5. The recognized gesture is also output to the Serial Monitor for debugging

## Installation
1. Clone this repository:
   ```
   git clone https://github.com/Sriram-PR/Sign-Language-Interpreter.git
   ```
2. Install required libraries in Arduino IDE:
   - MPU6050 by Electronic Cats
   - I2Cdev
   - Wire (built-in)
   - SoftwareSerial (built-in)

3. Connect the hardware components as described in the Connections section
4. Upload the Arduino sketch to your Arduino board
5. Pair the HC-05 Bluetooth module with your receiving device

## Usage
1. Power on the Arduino with the sensors connected
2. Put on the glove with attached sensors
3. Open your Bluetooth receiver application on the paired device
4. Perform the gestures to see the interpreted text messages
5. The system will send a message every 2 seconds based on the detected gesture

## Customization
The gesture recognition thresholds in the code can be adjusted based on your specific sensor calibration:
- Flex sensor thresholds (e.g., `middle >= 260`)
- Accelerometer thresholds (e.g., `ay > 125`)

## Future Improvements
- Add more gestures to the recognition library
- Implement machine learning for better gesture recognition
- Develop a companion mobile app for easier interaction
- Add text-to-speech functionality for audio output
- Reduce delay time for faster response

## License
This project is open source and available under the [MIT License](https://github.com/Sriram-PR/Sign-Language-Interpreter/blob/main/LICENSE).

## Contributors
- [Sriram-PR](https://github.com/Sriram-PR)
