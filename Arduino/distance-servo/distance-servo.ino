#include <Servo.h>

#define echoPin 2
#define trigPin 3
#define servoPin 9

long duration;
long distance;
int angle;
Servo servo;

void setup() {
  servo.attach(9);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  /* Clear the trigPin */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  /* Activate trigger for 10 ms */
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  /* Read echoPin */
  duration = pulseIn(echoPin, HIGH);

  /* Calculate the distance */
  distance = duration * 0.034 / 2;

  /* Calculate the angle for servo rotation */
  angle = map(distance, 0, 45, 0, 180);
  /* Rotate the Servo */
  servo.write(constrain(angle, 0, 180));

  Serial.print("cm:");
  Serial.print(distance);
  Serial.print(",");
  Serial.print("deg:");
  Serial.println(constrain(angle, 0, 180));

  delay(15);
}
