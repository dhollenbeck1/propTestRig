int propPin = 9;      // prop connected to digital pin 9
int analogPin = 3;   // potentiometer connected to analog pin 3
int val = 0;         // variable to store the read value

void setup()
{
  pinMode(propPin, OUTPUT);   // sets the pin as output
  Serial.begin(9600); 
}

void loop()
{
  val = analogRead(analogPin);   // read the input pin
  Serial.println(val);
  
  analogWrite(propPin, val);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  delay(1);
}
