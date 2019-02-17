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
  Serial.println("Enter text you would like to translate to brail:\n");                                                  

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


 char rx_byte = 0;
String rx_str = "";

  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    
    if (rx_byte != '\n') {
      // a character of the string was received
      rx_str += rx_byte;
    }
    else {
      // end of string
      Serial.print("Welcome ");
      Serial.println(rx_str);
      rx_str = "";                // clear the string for reuse
      Serial.println("");
      Serial.println("Enter your name.");
    }
  } // end: if (Serial.available() > 0)
}

void translateIR()
{
  switch(results.value)
  {
  case 0xFFA25D:
  Serial.println("POWER; Letter A");
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
  //nextLetter(); 
  break;
  
  case 0xFF629D:
  Serial.println("VOL +; Letter B");
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
  //nextLetter();
  break;
  
  case 0xFFE21D:
  Serial.println("FUNC/STOP; Letter C");
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFF22DD:
  Serial.println("REVERSE; Letter D");
  forward();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
 // nextLetter();
  break;
  
  case 0xFF02FD:
  Serial.println("PLAY/PAUSE; Letter E");
  forward();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFFC23D:
  Serial.println("FAST FORWARD; Letter F");
  forward();
  delay(500);
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
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFFE01F:
  Serial.println("ARROW DOWN; Letter G"); 
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFFA857:
  Serial.println("VOL -; Letter H"); 
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
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFF906F: 
  Serial.println("ARROW UP; Letter I");
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
 // nextLetter();
  break;
  
  case 0xFF9867: 
  Serial.println("EQ; Letter J");
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break; 
   
  case 0xFFB04F: 
  Serial.println("ST/REPT; Letter K");
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
  //nextLetter();
  break;
  
  case 0xFF6897: 
  Serial.println("0; Letter L");
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
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;

  case 0xFF30CF: 
  Serial.println("1; Letter M");
  indent();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent(); 
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFF18E7:
  Serial.println("2; Letter N");
  indent();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500); 
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFF7A85: 
  Serial.println("3; Letter O");
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
  indent(); 
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFF10EF:
  Serial.println("4; Letter P");
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
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break; 
  
  case 0xFF38C7:
  Serial.println("5; Letter Q");
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
  indent();
  delay(500);
  left();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);  
  //nextLetter();
  break;
  
  case 0xFF5AA5:
  Serial.println("6; Letter R");
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
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFF42BD:
  Serial.println("7; Letter S");
  indent();
  delay(500);
  forward();
  delay(500);
  indent();
  delay(500);
  forward();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break; 
  
  case 0xFF4AB5:
  Serial.println("8; Letter T");
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
  indent();
  delay(500);
  left();
  delay(500);
  forward();
  delay(500);
  right();
  delay(500);
  indent();
  delay(500);
  left();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  backwards();
  delay(500);
  //nextLetter();
  break;
  
  case 0xFF52AD:
  Serial.println("9; Letter U");
  indent();
  delay(500);
  forward();
  delay(500);
  right();
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
  //nextLetter();
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
  delay(500);
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
  delay(500);
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
  delay(1000);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  delay(200);
}

void indent(){
  myServo.write(0);
  delay(100);
  myServo.write(90);
  delay(1000);
  myServo.write(0);
}

void nextLetter(){
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
 
