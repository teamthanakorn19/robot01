/*-------definning Inputs------*/
int LS = 2;     // เซ็นเซอร์ซ้าย
int RS  = 3;      // เซ็นเซอร์ขวา

/*-------definning Outputs------*/
int LM1 = 4;      // มอเตอร์ซ้าย
int LM2 =  5;       // มอเตอร์ซ้าย
int RM1 =  6;       // มอเตอร์ขวา
int RM2 =  7;       // มอเตอร์ขวา

/*-------PWM ควบคุมความเร็วมอเตอร์-----*/
int PWM1 = 10;    // มอเตอร์ซ้าย
int PWM2 = 11;    // มอเตอร์ขวา
int SPEED = 90;  // ความเร็วมอเตอร์ สามารถปรับความเร็วได้ถึง 255

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void loop()
{

  if (!(digitalRead(LS)) && !(digitalRead(RS)))    // เดินหน้า
  {
    analogWrite(PWM1, SPEED);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }


  if (!(digitalRead(LS)) && digitalRead(RS))    // เลี้ยวขวา
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(PWM2, SPEED);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  if (digitalRead(LS) && !(digitalRead(RS)))    // เลี้ยวซ้าย
  {
    analogWrite(PWM1, SPEED);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }

 if (digitalRead(LS) && digitalRead(RS))    // หยุด
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }

}

