const int PWM_M1 = 9;
const int Dir_A_M1 = 10;
const int Dir_B_M1 = 11;
const int PWM_M2 = 3;
const int Dir_A_M2 = 5;
const int Dir_B_M2 = 6;

void setup() {
    pinMode(PWM_M1, OUTPUT);
    pinMode(PWM_M2, OUTPUT);
    pinMode(Dir_A_M1, OUTPUT);
    pinMode(Dir_B_M1, OUTPUT);
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
  forwardMotors();
  delay(30);
  stopMotors();
  delay(1000);
}

void forwardMotors(){
  analogWrite(PWM_M1, 255);
  digitalWrite(Dir_A_M1, HIGH);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 255);
  digitalWrite(Dir_A_M2, HIGH);
  digitalWrite(Dir_B_M2, LOW);
}

void stopMotors(){
  analogWrite(PWM_M1, 0);
  digitalWrite(Dir_A_M1, LOW);
  digitalWrite(Dir_B_M1, LOW);
  analogWrite(PWM_M2, 0);
  digitalWrite(Dir_A_M2, LOW);
  digitalWrite(Dir_B_M2, LOW);
}

/*#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
*/
