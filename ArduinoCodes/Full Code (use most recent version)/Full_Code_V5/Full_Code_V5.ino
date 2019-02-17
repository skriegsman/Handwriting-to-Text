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
}


void translateIR(){
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

void letterA(){
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

void letterB(){
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

void letterC(){
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

void letterD(){
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

void letterE(){
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

void letterF(){
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

void letterG(){
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

void letterH(){
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

void letterI(){
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

void letterJ(){
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

void letterK(){
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

void letterL(){
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

void letterM(){
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

void letterN(){
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

void letterO(){
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

void letterP(){
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

void letterQ(){
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

void letterR(){
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

void letterS(){
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

void letterT(){
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

void letterU(){
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

void letterV(){
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

void letterW(){
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

void letterX(){
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

void letterY(){
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

void letterZ(){
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
