#include <DabbleESP32.h>
// Sumobot 2 Wheels with Esp32 and L298N Motor Driver
// Controller Dabble Apps
// Special Thx to Learning Week Programming
// Author Wilson

// motor kanan
int motor_kanan_maju=18;
int motor_kanan_mundur=19;


// motor kiri
int motor_kiri_maju=32;
int motor_kiri_mundur=33;

void setup() {
  //motor kanan
  pinMode(motor_kanan_maju,OUTPUT);
  pinMode(motor_kanan_mundur,OUTPUT);

  //motor kiri
  pinMode(motor_kiri_maju, OUTPUT);
  pinMode(motor_kiri_mundur, OUTPUT);

  // untuk membaca serial pada monitor
  Serial.begin(115200);
  
  //nama bluetooth
  Dabble.begin("WILSON");
}

void loop() {
  Dabble.processInput();
  if(GamePad.isUpPressed()){
    Serial.println("Maju");
    maju_depan();
  }
  else if(GamePad.isDownPressed()){
    Serial.println("Mundur");
    mundur_belakang();
  }
    else if(GamePad.isCirclePressed()){
    Serial.println("Kanan");
    belok_kanan();
  }
    else if(GamePad.isSquarePressed()){
    Serial.println("Kiri");
    belok_kiri();


  } else {
    Serial.println("diam");
    tidak_bergerak();
  }


}

//untuk maju
void maju_depan(){
  //motor kanan
  analogWrite(motor_kanan_maju, 255);
  analogWrite(motor_kanan_mundur, 0);

  // motor kiri
  analogWrite(motor_kiri_maju, 255);
  analogWrite(motor_kiri_mundur, 0);

}

//untuk mundur
void mundur_belakang(){
  //motor kanan
  analogWrite(motor_kanan_maju, 0);
  analogWrite(motor_kanan_mundur, 255);

  // motor kiri
  analogWrite(motor_kiri_maju, 0);
  analogWrite(motor_kiri_mundur, 255);

}

//untuk belok kanan
void belok_kanan(){
  //motor kanan
  analogWrite(motor_kanan_maju, 0);
  analogWrite(motor_kanan_mundur, 255);

  // motor kiri
  analogWrite(motor_kiri_maju, 255);
  analogWrite(motor_kiri_mundur, 0);

}

//untuk belok kiri
void belok_kiri(){
  //motor kanan
  analogWrite(motor_kanan_maju, 255);
  analogWrite(motor_kanan_mundur, 0);


  // motor kiri
  analogWrite(motor_kiri_maju, 0);
  analogWrite(motor_kiri_mundur, 255);
}

//untuk stop
void tidak_bergerak(){
  //motor kanan
  analogWrite(motor_kanan_maju, 0);
  analogWrite(motor_kanan_mundur, 0);

  // motor kiri
  analogWrite(motor_kiri_maju, 0);
  analogWrite(motor_kiri_mundur, 0);
}