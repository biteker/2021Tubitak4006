  //L298N Bağlantısı   
const int motorA1  = 5;  // L298N'in IN3 Girişi
const int motorA2  = 6;  // L298N'in IN1 Girişi
  
int vSpeed=255;     // Standart Hız, 0-255 arası bir değer alabilir

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  
  Serial.begin(9600);
  
  Serial.println("Motor test ediliyor...");
  sagaDon();
  delay(1000);
  solaDon();
  delay(1000);
}

void loop() {
  
  //LDR oku
  int ldrSag = map(analogRead(A0),0,1024,1,4);
  int ldrSol = map(analogRead(A1),0,1024,1,4);
  
  if (ldrSag>ldrSol) {
    sagaDon();
  }
  else if (ldrSol>ldrSag) {
    solaDon();
  }
  else {
    dur();
  }
  
}

void sagaDon(){
  analogWrite(motorA1, vSpeed);
  analogWrite(motorA2, 0);  
}

void solaDon() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, vSpeed);   
}

void dur() {
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
}
