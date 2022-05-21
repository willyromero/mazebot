//Pines de los motores
const int pinPWMA = 3;
const int pinAIN2 = 4;
const int pinAIN1 = 5;
const int pinMotorA[3] = { pinPWMA, pinAIN2, pinAIN1 };

const int pinBIN1 = 7;
const int pinBIN2 = 8;
const int pinPWMB = 9;
const int pinMotorB[3] = { pinPWMB, pinBIN1, pinBIN2 };

const int pinSTBY = 6;

//Speed y tiempo de espera
const int waitTime = 10000;   //espera entre fases
const int speed = 50;      //velocidad de giro

//Pines de sensores
const int pinSensorLeft = 2;

const int pinSensorMiddle = 11;

const int pinSensorRight = 12;

//Estados de direccion de movimiento
enum moveDirection {
  forward,
  backward
};

int values[3];

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(pinSensorLeft , INPUT);
  pinMode(pinSensorMiddle , INPUT);
  pinMode(pinSensorRight , INPUT);
}

// ←→↑↓↩↪

void loop() {

  values[0] = digitalRead(pinSensorRight);
  values[1] = digitalRead(pinSensorMiddle);
  values[2] = digitalRead(pinSensorLeft);

  Serial.println(analogRead(pinSensorMiddle));
  Serial.println("↑");
  enableMotors();
  move(forward, 50);

  if (values[0] != HIGH) {
    Serial.println("Detectado obstaculo -> Izq");
  }
  if (values[1] != HIGH) {
    //Serial.println("Detectado obstaculo -> Med");
    Serial.println(" ↑");
    fullStop();
  }
  if (values[2] != HIGH) {
    Serial.println("Detectado obstaculo -> Der");
  }
}


//Funciones

//motores
void move(int direction, int speed)
{
  if (direction == forward)
  {
    moveMotorForward(pinMotorA, speed);
    moveMotorForward(pinMotorB, speed);
  }
  else
  {
    moveMotorBackward(pinMotorA, speed);
    moveMotorBackward(pinMotorB, speed);
  }
}

void turn(int direction, int speed)
{
  if (direction == forward)
  {
    moveMotorForward(pinMotorA, speed);
    moveMotorBackward(pinMotorB, speed);
  }
  else
  {
    moveMotorBackward(pinMotorA, speed);
    moveMotorForward(pinMotorB, speed);
  }
}

void fullStop()
{
  disableMotors();
  stopMotor(pinMotorA);
  stopMotor(pinMotorB);
}

//Funciones que controlan los motores
void moveMotorForward(const int pinMotor[3], int speed)
{
  digitalWrite(pinMotor[1], 124);
  digitalWrite(pinMotor[2], LOW);

  analogWrite(pinMotor[0], speed);
}

void moveMotorBackward(const int pinMotor[3], int speed)
{
  digitalWrite(pinMotor[1], LOW);
  digitalWrite(pinMotor[2], 124);

  analogWrite(pinMotor[0], speed);
}

void stopMotor(const int pinMotor[3])
{
  digitalWrite(pinMotor[1], LOW);
  digitalWrite(pinMotor[2], LOW);

  analogWrite(pinMotor[0], 0);
}

void enableMotors()
{
  digitalWrite(pinSTBY, 124);
}

void disableMotors()
{
  digitalWrite(pinSTBY, LOW);
}
