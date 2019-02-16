#include <IRremote.h>
#include <Servo.h>

// IR Reciever Set-Up
const int recieverPin = 7;
IRrecv irrecv(recieverPin);
decode_results results;

// Motor 1 Set-Up
const int PWM_M1 = 5;
const int Dir_A_M1 = 5;
const int Dir_B_M1 = 6;

// Motor 2 Set-Up
const int PWM_M2 = 9;
const int Dir_A_M2 = 10;
const int Dir_B_M2 = 11;

// Servo Set-Up
Servo myServo;

//Variables Set-Up
const int delta_x_within_letter = 5;
const int delta_x_between_letters = 7;
const int delta_y_within_letter = 5;
const int delta_y_between_letters = 9;

void setup() 
{
  Serial.begin(9600);

  //Initializing IR Reciever
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  irrecv.blink13(true);

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

  //Servo Initalizing and Default
  myServo.attach(4);
  myServo.write(0);
}

void loop() {
  if (irrecv.decode(&results)) 
    {
      translateIR();
      irrecv.resume();      
    }
}

void translateIR()
{
  switch(results.value)
  {
  case 0xFFA25D:
  Serial.println("POWER; Letter A");
  forward();
  forward();
  indent();
  backwards();
  backwards();
  break;
  
  case 0xFF629D:
  Serial.println("VOL +; Letter B");
  forward();
  indent();
  forward();
  indent();
  backwards();
  backwards();
  break;
  
  case 0xFFE21D:
  Serial.println("FUNC/STOP; Letter C");
  forward();
  forward();
  indent();
  forward();
  right();
  indent();
  backwards();
  left();
  backwards();
  backwards();
  backwards();
  break;
  
  case 0xFF22DD:
  Serial.println("REVERSE; Letter D");
  forward();
  forward();
  indent();
  forward();
  right();
  indent();
  forward();
  right(); 
  indent(); 
  right();
  forward();
  left();
  forward();
  forward();
  forward();
  flipYAxis(); 
  break;
  
  case 0xFF02FD:
  Serial.println("PLAY/PAUSE; Letter E");
  forward();
  forward();
  indent();
  right();
  indent(); 
  left();
  backwards();
  backwards();
  break;
  
  case 0xFFC23D:
  Serial.println("FAST FORWARD; Letter F");
  forward();
  indent();
  forward();
  indent();
  forward();
  right();
  indent();
  left();
  backwards();
  backwards();
  backwards();
  break;
  
  case 0xFFE01F:
  Serial.println("ARROW DOWN; Letter G"); 
  forward();
  indent();
  forward();
  indent();
  forward();
  right();
  indent();
  forward();
  right();
  indent();
  forward();
  forward();
  forward();
  right();
  forward();
  right(); 
  break;
  
  case 0xFFA857:
  Serial.println("VOL -; Letter H"); 
  forward();
  indent();
  forward();
  indent();
  right();
  indent();
  left();
  backwards();
  backwards();
  break;
  
  case 0xFF906F: 
  Serial.println("ARROW UP; Letter I");
  forward();
  indent();
  forward();
  forward();
  right();
  indent();
  left();
  backwards();
  backwards();
  backwards();
  break;
  
  case 0xFF9867: 
  Serial.println("EQ; Letter J");
  forward();
  indent();
  forward();
  right();
  indent();
  forward();
  left();
  indent();
  backwards();
  backwards();
  backwards();
  right();
  backwards();
  left();
  break; 
   
  case 0xFFB04F: 
  Serial.println("ST/REPT; Letter K");
  indent();
  forward();
  forward();
  indent();
  flipYAxis();
  forward();
  forward();
  flipYAxis();
  break;
  
  case 0xFF6897: 
  Serial.println("0; Letter L");
  indent();
  forward();
  indent();
  forward();
  indent(); 
  flipYAxis();
  forward();
  forward();
  flipYAxis();
  break;

  case 0xFF30CF: 
  Serial.println("1; Letter M");
  indent();
  forward();
  forward();
  indent();
  forward();
  right();
  indent(); 
  break;
  
  case 0xFF18E7:
  Serial.println("2; Letter N");
  indent();
  forward();
  forward();
  indent();
  forward();
  right();
  indent();
  forward();
  right();
  indent();
  break;
  
  case 0xFF7A85: 
  Serial.println("3; Letter O");
  indent();
  forward();
  forward();
  indent();
  right();
  indent(); 
  break;
  
  case 0xFF10EF:
  Serial.println("4; Letter P");
  indent();
  forward();
  forward();
  indent();
  forward();
  right();
  indent();
  break; 
  
  case 0xFF38C7:
  Serial.println("5; Letter Q");
  indent();
  forward();
  indent();
  forward();
  indent();
  forward();
  right();
  indent();
  forward();
  right();
  indent();  
  break;
  
  case 0xFF5AA5:
  Serial.println("6; Letter R");
  indent();
  forward();
  indent();
  forward();
  indent();
  forward();
  right();
  indent();
  break;
  
  case 0xFF42BD:
  Serial.println("7; Letter S");
  indent();
  forward();
  indent();
  forward();
  right();
  forward();
  left();
  indent();
  break; 
  
  case 0xFF4AB5:
  Serial.println("8; Letter T");
  indent();
  forward();
  indent();
  forward();
  right();
  indent();
  forward();
  left();
  indent();
  break;
  
  case 0xFF52AD:
  Serial.println("9; Letter U");
  indent();
  forward();
  right();
  indent();
  left();
  forward();
  indent();
  break;
  
  case 0xFFFFFFFF:
  Serial.println("REPEAT");
  break;
  
  default:
  Serial.println("Try another button");
  }
}

void forward(){
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

void left(){
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, HIGH);
  digitalWrite(Dir_B_M1, LOW);
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

void right(){
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, HIGH);
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

void backwards(){
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

void flipXAxis(){
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

void flipYAxis(){
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, HIGH);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, HIGH);
  digitalWrite(Dir_B_M2, LOW);
  delay(180);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void indent(){
  myServo.write(90);
  delay(100);
  myServo.write(0);
  delay(100);
}

void nextLetter(){
  
}
