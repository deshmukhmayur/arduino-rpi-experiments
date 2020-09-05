#define echoPin 2
#define trigPin 3
#define RED 11
#define GREEN 10
#define BLUE 9

long duration;
long distance;
int dangerThreshold = 10;         // threshold in cm
int closeThreshold = 20;         // threshold in cm
int activeThreshold = 45;         // threshold in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ultrasonic Senson HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}

void loop() {
  /* Clears the trigPin */
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

  /* Display the distance on the Serial Monitor */
  Serial.println("Distance: " + String(distance) + " cm");

  showIndicator(distance);
}

void showIndicator(long distance) {
  if (distance < dangerThreshold) {
    RGBColor(255, 0, 0);
  } else if (distance < closeThreshold) {
    RGBColor(255, 165, 0);
  } else if (distance < activeThreshold) {
    RGBColor(0, 255, 0);
  } else {
    RGBColor(0, 0, 0);
  }
}

void RGBColor(int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}