const int sensorPinIzq = 2; //derecha
const int sensorPinMed = 11; //medio
const int sensorPinDer = 12; //derecho

void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPinIzq , INPUT);  //definir pin como entrada
  pinMode(sensorPinMed , INPUT);  //definir pin como entrada
  pinMode(sensorPinDer , INPUT);  //definir pin como entrada
}
 
void loop(){
  int values[3] = {HIGH,HIGH,HIGH};

  values[2] = digitalRead(sensorPinIzq );  //lectura digital de pin
  values[1] = digitalRead(sensorPinMed );  //lectura digital de pin
  values[0] = digitalRead(sensorPinDer );  //lectura digital de pin

  if (values[0] != HIGH) {
      Serial.println("Detectado obstaculo -> Izq");
  }
  if (values[1] != HIGH) {
      Serial.println("Detectado obstaculo -> Med");
  }
  if (values[2] != HIGH) {
      Serial.println("Detectado obstaculo -> Der");
  }
  delay(1000);
}
