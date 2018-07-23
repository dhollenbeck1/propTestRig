int i = 1;
int estop;
int switchPin = 8;
int irPin = 1;
int irVal;
int loadAnalog;
float loadLbs;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;


/*
Using the SEN-00241 infrared emitter and detector and the FC2231 load cell

for the load cell
theoretical min value of 0.5 V (digital) for 0 lbf
actual min value of 117 (analog in) @ 0.571289 V (digital) for 0 lbf
theoretical max value of 4.5 V (digital) for 10 lbf
actual max value of 980 (analog in) @ 4.785156 V (digital) for 10 lbf

for the IRs
emitter has the yellow dot
detector has the red dot
*/

void setup() 
{
pinMode(switchPin, INPUT);
pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);
Serial.begin(9600); 
}

void loop() 
{
while (1==1)
  {
    
  digitalWrite(RED_PIN, LOW);             //show green on led
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  
  delay(1000);                            //time delay
  Serial.print(i);
  Serial.print(": irVal value is ");
  i = i + 1;                               //increase counter
  estop = digitalRead(switchPin);
  irVal = analogRead(irPin);
  loadAnalog = analogRead(2);
  loadLbs = (loadAnalog -117) * 0.011587;  //formula derivation on excel
  Serial.println(irVal);
  Serial.print(" load value is ");
  Serial.print(loadLbs);
  Serial.println(" lbf ");
  
  if (estop == HIGH)                      //if button is pressed (and held)
    while (1)                             //do nothing loop
      {
      digitalWrite(RED_PIN, HIGH);    //show red on led
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      }
  //Serial.println("if you see this, it didnt break");
  
  }
}
