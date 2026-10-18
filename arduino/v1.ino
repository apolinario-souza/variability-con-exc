void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  
  Serial.print(analogRead(A0));
  Serial.println(',');
  delay(5);
  
  // put your main code here, to run repeatedly:

}
