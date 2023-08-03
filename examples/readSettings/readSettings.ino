/******************************************************************
  @file       readSettings.ino
  @brief      Read the MPU6050 IMU current settings
  @author     David Such
  @copyright  Please see the accompanying LICENSE file

   Code:        David Such
   Version:     1.0.0
   Date:        31/07/23
 
   1.0.0    Original Release            31/07/23

******************************************************************/

#include <ReefwingMPU6050.h>

ReefwingMPU6050 imu;

void setup() {
  // Initialise the LSM9DS1 IMU
  imu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);

  //  Start Serial and wait for connection
  Serial.begin(115200);
  while (!Serial);

  if (imu.connected()) {
    Serial.println("MPU6050 IMU Connected."); 
  } else {
    Serial.println("MPU6050 IMU Not Detected.");
    while(1);
  }
  
  Serial.print("\n * Sleep Mode:            ");
  Serial.println(imu.getSleepEnabled() ? "Enabled" : "Disabled");
  
  Serial.print(" * Clock Source:          ");
  switch(imu.getClockSource()) {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }
  
  Serial.print(" * Accelerometer:         ");
  switch(imu.getRange()) {
    case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
  }  

  Serial.print(" * Accelerometer offsets: ");
  Serial.print(imu.getAccelOffsetX());
  Serial.print(" / ");
  Serial.print(imu.getAccelOffsetY());
  Serial.print(" / ");
  Serial.println(imu.getAccelOffsetZ());
}

void loop() { }