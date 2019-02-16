#include <IRremote.h>

// IR Reciever Set Up
const int recieverPin = 7;
IRrecv irrecv(recieverPin);
decode_results results;

int white_led = 11;
int yellow_led = 10;
int red_led = 9;
int green_led = 6;
int blue_led = 5;

void setup() 
{
  Serial.begin(9600);

  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  irrecv.blink13(true);

  pinMode(white_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);

  digitalWrite(white_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
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
  digitalWrite(white_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
  break;
  
  case 0xFF629D:
  Serial.println("VOL +");
  digitalWrite(white_led, HIGH);
  break;
  
  case 0xFFE21D:
  Serial.println("FUNC/STOP");
  digitalWrite(yellow_led, HIGH);
  break;
  
  case 0xFF22DD:
  Serial.println("REVERSE");  
  digitalWrite(red_led, HIGH);
  break;
  
  case 0xFF02FD:
  Serial.println("PLAY/PAUSE"); 
  digitalWrite(green_led, HIGH); 
  break;
  
  case 0xFFC23D:
  Serial.println("FAST FORWARD");
  digitalWrite(blue_led, HIGH);
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
  digitalWrite(white_led, LOW); 
  break;
  
  case 0xFF18E7:
  Serial.println("2");
  digitalWrite(yellow_led, LOW);
  break;
  
  case 0xFF7A85: 
  Serial.println("3"); 
  digitalWrite(red_led, LOW);  
  break;
  
  case 0xFF10EF:
  Serial.println("4");
  digitalWrite(green_led, LOW);
  break; 
  
  case 0xFF38C7:
  Serial.println("5");  
  digitalWrite(blue_led, LOW);
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
  digitalWrite(white_led, HIGH);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, HIGH);
  digitalWrite(blue_led, HIGH);
  break;
  
  case 0xFFFFFFFF:
  Serial.println("REPEAT");
  break;
  
  default:
  Serial.println("Try another button");
  }
}
