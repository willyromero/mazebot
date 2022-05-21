const int pinSensorLeft = 2;
const int pinSensorMiddle = 11;
const int pinSensorRight = 12;
int values[3];

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(pinSensorLeft , INPUT);
  pinMode(pinSensorMiddle , INPUT);
  pinMode(pinSensorRight , INPUT);
}

void loop() {

  values[0] = digitalRead(pinSensorRight);
  values[1] = digitalRead(pinSensorMiddle);
  values[2] = digitalRead(pinSensorLeft);

  if (values[0] != HIGH) {
    Serial.println("Detectado obstaculo -> Izq");
  }
  if (values[1] != HIGH) {
    Serial.println("Detectado obstaculo -> Med");
    Serial.println(" ↑");
  }
  if (values[2] != HIGH) {
    Serial.println("Detectado obstaculo -> Der");
  }

  delay(2000);
}
