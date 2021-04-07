#include "Wire.h"

const int MPU_Address = 0x68 ; //I2c address of MPU-6050

int16_t accelerometer_x , accelerometer_y ,accelerometer_z ;
int16_t gyro_x ,gyro_y, gyro_z;
int16_t temp;
int16_t i ;
char str[7]; 

char* convert_int_TO_str(int16_t x )
{
  sprintf(str, "%d" , x);
  return str ;
  }

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_Address); 
  Wire.write(0x6B); 
  Wire.write(0); 
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU_Address);
  Wire.write(0x3B); 
  Wire.endTransmission(false); 
  Wire.requestFrom(MPU_Address , 14 , true); 
  accelerometer_x = Wire.read()<<8 | Wire.read();
  accelerometer_y = Wire.read()<<8 | Wire.read();
  accelerometer_z = Wire.read()<<8 | Wire.read();
  temp = Wire.read()<<8 | Wire.read();
  gyro_x = Wire.read()<<8 | Wire.read();
  gyro_y = Wire.read()<<8 | Wire.read();
  gyro_z = Wire.read()<<8 | Wire.read();
  
  
  //***********************************//

  Serial.print("ACC_x = ");
  Serial.print(convert_int_TO_str(accelerometer_x));
  Serial.print("ACC_y = ");
  Serial.print(convert_int_TO_str(accelerometer_y));
  Serial.print("ACC_z = ");
  Serial.print(convert_int_TO_str(accelerometer_z));
  Serial.print("TEMP = ");
  Serial.print(convert_int_TO_str(temp / 340.00 + 36.53));
  Serial.print("GR_x = ");
  Serial.print(convert_int_TO_str(gyro_x));
  Serial.print("GR_y = ");
  Serial.print(convert_int_TO_str(gyro_y));
  Serial.print("GR_z = ");
  Serial.print(convert_int_TO_str(gyro_z));
  

  delay(2000);
}
