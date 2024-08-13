#include <LiquidCrystal.h>
#include <Servo.h>

Servo meuServo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int angle;
int angle_deg;
int botao = 0;
int escolha = 0;


void setup() {
  // Setup de LCD e Servo
  lcd.begin(16, 2);
  meuServo.attach(9);

  //Loop de Menus
  menu();
  escolha = Menu2();
}

void loop() {

  //Potenciometro
  int valor = analogRead(A0);
  
  //Botao
  botao = digitalRead(13);

  //Passar para angulos
  angle = map(valor, 0, 1023, 0, 155);
  angle_deg = map(angle, 0, 155, 0, 179);

  //Info LCD
  lcd.clear();
  lcd.print("Angulo: ");
  lcd.print(angle_deg);
  lcd.setCursor(0, 1);
  lcd.print("Valor: ");
  lcd.print(valor);

  //Consoante Escolha
  if (escolha == 1) {
    //Direto
    meuServo.write(angle);
  } else if (escolha == 2)
    //Escolher Angulo
  {
    if (botao == HIGH) {
      meuServo.write(angle);
      delay(500);
    }
  } 
  delay(15);
}

void menu(){
  //Menu Inicial
  lcd.clear();
  lcd.print("Escolher Modo");
  delay(3000);
}

int Menu2(){

  int b = 0;
  int v;

  while ( b == LOW) {

    b = digitalRead(13);
    v = analogRead(A0);

    if (v < 200 || 400 < v && v < 600 || 800 < v && v < 1000) {
      lcd.clear();
      lcd.print(">> Direto");
      lcd.setCursor(0, 1);
      lcd.print("Escolher Ang");
      delay(15);
    } else {
      lcd.clear();
      lcd.print("Direto");
      lcd.setCursor(0, 1);
      lcd.print(">> Escolher Ang");
      delay(15);
      }
    if (b == HIGH && (v < 200 || 400 < v && v < 600 || 800 < v && v < 1000)) {
      return 1;
    } else if (b == HIGH && !(v < 200 || 400 < v && v < 600 || 800 < v && v < 1000)) {
      return 2;
    }
  }
}


