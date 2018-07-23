#include <Servo.h>
 
Servo esc;              //create variable esc of type servo
int throttlePin = 3;    //analog input pin 3
 
void setup()
{
esc.attach(6);          //attach servo variable to pwm pin 6
}
 
void loop()
{
int throttle = analogRead(throttlePin);     //read potentiometer position
throttle = map(throttle, 0, 1023, 0, 179);  //map pot value to servo value
                                            //ex: half value of pot: 512 
                                            //would give half value of servo: 90
esc.write(throttle);                        //writes value to servo
}
