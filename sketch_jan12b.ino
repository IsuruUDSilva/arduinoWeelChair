//final
#include <Wire.h>;
const int MPU = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int isObstaclePin1 = 8;
int isObstaclePin2 = 7;
//

//int isObstacle = HIGH;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(8, INPUT);
  pinMode(7, INPUT);


  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  //  digitalWrite(4,HIGH);
  //  digitalWrite(7,HIGH);

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 12, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);


  if (digitalRead(isObstaclePin1) == LOW) {

    Serial.print("object detected infront of chair");

    if (AcX > 5000 ) {
      if (AcY < -4000) {
        analogWrite(10 , 30);
        analogWrite(3 , 60);
      }
      else if (AcY > 4000) {
        analogWrite(10, 60);
        analogWrite(3, 30);
      }
      else {
        analogWrite(5, 50);
        analogWrite(6, 50);
      }

    }
    else {

      if (AcY < -4000) {
        analogWrite(5, 50);
        analogWrite(10, 50);
      }
      else if (AcY > 4000) {
        analogWrite(6, 50);
        analogWrite(3, 50);
      }
      else {
        analogWrite(3, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);
        analogWrite(10, 0);
      }
    }
  }


  else if (digitalRead(isObstaclePin2) == LOW) {

    Serial.print("object detected behind of chair");

    if (AcX < -5000  ) {
      if (AcY < -4000) {
        analogWrite(6 , 30);
        analogWrite(5 , 60);
      }
      else if (AcY > 4000) {
        analogWrite(6, 60);
        analogWrite(5, 30);
      }
      else {
        //        analogWrite(3, 100);
        //        analogWrite(10, 100);
        if (AcX > -7000 && AcX < -6000) {
          analogWrite(3, 70);
          analogWrite(10, 70);
        }
        else if (AcX < -7000) {
          analogWrite(3, 100);
          analogWrite(10, 100);
        }
        else {
          analogWrite(3, 50);
          analogWrite(10, 50);
        }
      }

    }
    else {
      if (AcY < -4000) {
        analogWrite(5, 50);
        analogWrite(10, 50);
      }
      else if (AcY > 4000) {
        analogWrite(6, 50);
        analogWrite(3, 50);
      }
      else {
        analogWrite(3, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);
        analogWrite(10, 0);
      }
    }

  }
  else {
    if (AcX > 5000 ) {
      if (AcY < -4000) {
        analogWrite(6 , 30);
        analogWrite(5 , 60);
      }
      else if (AcY > 4000) {
        analogWrite(6, 60);
        analogWrite(5, 30);
      }
      else {
        analogWrite(5, 50);
        analogWrite(6, 50);
      }
    }
    else if (AcX < -5000  ) {
      if (AcY < -4000) {
        analogWrite(10 , 30);
        analogWrite(3 , 60);
      }
      else if (AcY > 4000) {
        analogWrite(10, 60);
        analogWrite(3, 30);
      }
      else {
        //        analogWrite(3, 100);
        //        analogWrite(10, 100);
        if (AcX > -7000 && AcX < -6000) {
          analogWrite(3, 70);
          analogWrite(10, 70);
        }
        else if (AcX < -7000) {
          analogWrite(3, 100);
          analogWrite(10, 100);
        }
        else {
          analogWrite(3, 50);
          analogWrite(10, 50);
        }
      }

    }

    else {
      if (AcY < -4000) {
        analogWrite(3, 50);
        analogWrite(6, 50);
      }
      else if (AcY > 4000) {
        analogWrite(10, 50);
        analogWrite(5, 50);
      }
      else {
        analogWrite(3, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);
        analogWrite(10, 0);
      }

    }

  }

  delay(200);

}
