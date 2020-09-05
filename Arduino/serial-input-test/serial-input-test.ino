int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(LED, HIGH);
 delay(1000);
 digitalWrite(LED, LOW);
 delay(1000);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == 'h') {
      digitalWrite(LED, HIGH);
      Serial.println("Turning LED on");
    } else if (inChar == 'l') {
      digitalWrite(LED, LOW);
      Serial.println("Turning LED off");
    }
  }
}