#include <Servo.h>

char receivedChar;
String receivedString[] = "";
int i;
String text[] = "hello world";

Servo myServo;

// Motor 1 Set-Up
const int PWM_M1 = 5;
const int Dir_A_M1 = 5;
const int Dir_B_M1 = 6;

// Motor 2 Set-Up
const int PWM_M2 = 9;
const int Dir_A_M2 = 10;
const int Dir_B_M2 = 11;

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");

  myServo.attach(4);
  myServo.write(0);

  // Motor 1 Pin Set-Up
  pinMode(PWM_M1, OUTPUT);
  pinMode(Dir_A_M1, OUTPUT);
  pinMode(Dir_B_M1, OUTPUT);

  // Motor 2 Pin Set-Up
  pinMode(PWM_M2, OUTPUT);
  pinMode(Dir_A_M2, OUTPUT);
  pinMode(Dir_B_M2, OUTPUT);

  // Motor 1 Default
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);

  // Motor 2 Default
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
}



void loop() {
    
    //receivedChar = Serial.read();
    Serial.println(text[0]);
    Serial.println("hello");

    
  for (i = 0; i < sizeof(text); i++) {
    char temp = text[i];
    sortString(temp);

};


  
}




void sortString(char letter) {

  if (letter == 'a' || letter == 'A') {
    letterA();
  } else if (letter == 'b' || letter == 'B') {
    letterB();
  } else if (letter == 'c' || letter == 'C') {
    letterC();
  } else if (letter == 'd' || letter == 'D') {
    letterD();
  } else if (letter == 'e' || letter == 'E') {
    letterE();
  } else if (letter == 'f' || letter == 'F') {
    letterF();
  } else if (letter == 'g' || letter == 'G') {
    letterG();
  } else if(letter == 'h' || letter == 'H') {
    letterH();
  } else if(letter == 'i' || letter == 'I') {
    letterI();
  } else if(letter == 'j' || letter == 'J') {
    letterJ();
  } else if(letter == 'k' || letter == 'K') {
    letterK();
  } else if(letter == 'l' || letter == 'L') {
    letterL();
  } else if(letter == 'm' || letter == 'M') {
    letterN();
  } else if(letter == 'o' || letter == 'O') {
    letterO();
  } else if(letter == 'p' || letter == 'P') {
    letterP();
  } else if(letter == 'q' || letter == 'Q') {
    letterQ();
  } else if(letter == 'r' || letter == 'R') {
    letterR();
  } else if(letter == 's' || letter == 'S') {
    letterS();
  } else if(letter == 't' || letter == 'T') {
    letterT();
  } else if(letter == 'u' || letter == 'U') {
    letterU();
  } else if(letter == 'v' || letter == 'V') {
    letterV();
  } else if(letter == 'w' || letter == 'W') {
    letterW();
  } else if(letter == 'x' || letter == 'X') {
    letterX();
  } else if(letter == 'y' || letter == 'Y') {
    letterY();
  } else if(letter == 'z' || letter == 'Z') {
    letterZ();
  } else if(letter == '#') {
    hashTagSign();
  } else if(letter == '0') {
    numberZERO();
  } else if(letter == '1') {
    numberONE();
  } else if(letter == '2') {
    numberTWO();
  } else if(letter == '3') {
    numberTHREE();
  } else if(letter == '4') {
    numberFOUR();
  } else if(letter == '5') {
    numberFIVE();
  } else if(letter == '6') {
    numberSIX();
  } else if(letter == '7') {
    numberSEVEN();
  } else if(letter == '8') {
    numberEIGHT();
  } else if(letter == '9') {
    numberNINE();
  };




  /* string = serial.read;
      method RandomName (){

  */




}


void forward() {
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, HIGH);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, HIGH);
  digitalWrite(Dir_B_M2, LOW);
  delay(95);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void left() {
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, HIGH);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, HIGH);
  delay(500);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void right() {
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, HIGH);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, HIGH);
  digitalWrite(Dir_B_M2, LOW);
  delay(500);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void backwards() {
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, HIGH);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, HIGH);
  delay(95);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void flipXAxis() {
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, HIGH);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, HIGH);
  delay(190);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void flipYAxis() {
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, HIGH);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, HIGH);
  digitalWrite(Dir_B_M2, LOW);
  delay(1000);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void indent() {
  myServo.write(0);
  delay(100);
  myServo.write(90);
  delay(1000);
  myServo.write(0);
}

void nextLetter() {
  right();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
}

void letterA() {
  forward();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterB() {
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterC() {
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterD() {
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterE() {
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterF() {
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterG() {
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterH() {
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterI() {
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterJ() {
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterK() {
  indent();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  nextLetter();
  delay(500);
}

void letterL() {
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterM() {
  indent();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterN() {
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterO() {
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterP() {
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterQ() {
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterR() {
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterS() {
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterT() {
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
}

void letterU() {
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterV() {
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterW() {
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
}

void letterX() {
  indent();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  left();
}

void letterY() {
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void letterZ() {
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void hashTagSign() {
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
}

void numberONE() {
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberTWO() {
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberTHREE() {
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberFOUR() {
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberFIVE() {
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberSIX() {
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberSEVEN() {
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberEIGHT() {
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberNINE() {
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}

void numberZERO() {
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  right();
  delay(500);
  backwards();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
}
