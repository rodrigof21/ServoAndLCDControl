#include <LiquidCrystal.h>
#include <Servo.h>

Servo motor;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int angle;
int angle_deg;
int botao = 0;
int certo;
int valor;

void setup() {
  //Para o Random Funcionar 
  randomSeed(analogRead(A1));

  // Setup de LCD e Servo
  lcd.begin(16, 2);
  motor.attach(9);

  //Loop de Menus
  menu();
}

void loop() {
  //resposta certa
  certo = random(0, 179);

  lcd.clear();
  lcd.print("Target: ");
  lcd.print(certo);

  guess(certo);
  delay(500);
}

void menu(){
  //Menu Inicial
  lcd.clear();
  lcd.print("Acerta no");
  lcd.setCursor(0, 1);
  lcd.print("Angulo!");
  //Musica
  tone(7, 440, 300);
  delay(300);
  tone(7, 554.37, 300);
  delay(300);
  tone(7, 660, 300);
  delay(1000);
}

void guess(int c) {

  botao = digitalRead(13);

  while (botao == LOW) {
    //Game Loop

    valor = analogRead(A0);
    botao = digitalRead(13);

    //Passa para angulos
    angle = map(valor, 0, 1023, 0, 155);
    angle_deg = map(angle, 0, 155, 0, 179);

    //Mexe o Servo
    motor.write(angle);

    if (botao == HIGH && abs(angle_deg - c) < 10 && !(abs(angle_deg - c) == 0)){
        tone(7, 440, 20);
        lcd.setCursor(0, 1);
        lcd.print("Guess: ");
        lcd.print(angle_deg);
        delay(1000);
        lcd.clear();
        tone(7, 660, 50);
        lcd.print("Parabens");

    } else if (botao == HIGH && abs(angle_deg - c) > 10){
        tone(7, 440, 20);
        lcd.setCursor(0, 1);
        lcd.print("Guess: ");
        lcd.print(angle_deg);
        delay(1000);
        lcd.clear();
        lcd.print("Tenta outra vez");
    } else if (botao == HIGH && angle_deg == c) {
        tone(7, 440, 20);
        lcd.clear();
        tone(7, 800, 50);
        lcd.print("Perfeito!");
        delay(1000);
    }
  }
}