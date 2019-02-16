#include <IRremote.h>

// IR Reciever Set Up
const int recieverPin = 7;
IRrecv irrecv(recieverPin);
decode_results results;

//Motor 1 Set-Up
const int PWM_M1 = 5;
const int Dir_A_M1 = 5;
const int Dir_B_M1 = 6;

//Motor 2 Set-Up
const int PWM_M2 = 9;
const int Dir_A_M2 = 10;
const int Dir_B_M2 = 11;

const int delta_x_within_letter = 5;
const int delta_x_between_letters = 7;
const int delta_y_within_letter = 5;
const int delta_y_between_letters = 9;

void setup() 
{
  Serial.begin(9600);

  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  irrecv.blink13(true);

  pinMode(PWM_M1, OUTPUT);
  pinMode(Dir_A_M1, OUTPUT);
  pinMode(Dir_B_M1, OUTPUT);
  
  
  pinMode(PWM_M2, OUTPUT);
  pinMode(Dir_A_M2, OUTPUT);
  pinMode(Dir_B_M2, OUTPUT);

  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);

  
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
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
  Serial.println("POWER");
  break;
  
  case 0xFF629D:
  Serial.println("VOL +");
  break;
  
  case 0xFFE21D:
  Serial.println("FUNC/STOP");
  break;
  
  case 0xFF22DD:
  Serial.println("REVERSE; PREVIOUS COLUMN");  
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, HIGH);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, HIGH);
  delay(delta_x_within_letter);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  break;
  
  case 0xFF02FD:
  Serial.println("PLAY/PAUSE");  
  break;
  
  case 0xFFC23D:
  Serial.println("FAST FORWARD; NEXT COLUMN");
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, HIGH);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, HIGH);
  digitalWrite(Dir_B_M2, LOW);
  delay(delta_x_within_letter);
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
  break;
  
  case 0xFFE01F:
  Serial.println("ARROW DOWN");  
  break;
  
  case 0xFFA857:
  Serial.println("VOL -");  
  break;
  
  case 0xFF906F: 
  Serial.println("ARROW UP"); 
  break;
  
  case 0xFF9867: 
  Serial.println("EQ");
  break; 
   
  case 0xFFB04F: 
  Serial.println("ST/REPT");
  break;
  
  case 0xFF6897: 
  Serial.println("0"); 
  break;

  case 0xFF30CF: 
  Serial.println("1"); 
  break;
  
  case 0xFF18E7:
  Serial.println("2");
  break;
  
  case 0xFF7A85: 
  Serial.println("3"); 
  break;
  
  case 0xFF10EF:
  Serial.println("4");
  break; 
  
  case 0xFF38C7:
  Serial.println("5");  
  break;
  
  case 0xFF5AA5:
  Serial.println("6");
  break;
  
  case 0xFF42BD:
  Serial.println("7");
  break; 
  
  case 0xFF4AB5:
  Serial.println("8");
  break;
  
  case 0xFF52AD:
  Serial.println("9");
  break;
  
  case 0xFFFFFFFF:
  Serial.println("REPEAT");
  break;
  
  default:
  Serial.println("Try another button");
  }
}
