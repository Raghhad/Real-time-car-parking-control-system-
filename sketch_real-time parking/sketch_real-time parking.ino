const int TriggerPin = 9; // Trigger Pin
const int echoPin = 8;  // Echo Pin
const int LED1 =4 ; //green
const int LED2 = 3 ; //red

void setup() 
{
  pinMode(TriggerPin , OUTPUT); //Set trigger pin as a output
  pinMode(echoPin , INPUT); //Set echo pin as input
  
  pinMode(LED1 , OUTPUT); //Set pin 4 as a digital output
  pinMode(LED2 , OUTPUT); //Set pin 3 as a digital output
  
  Serial.begin(9600); // initializeing and start serial port 
}

void loop()
{
 digitalWrite(TriggerPin, LOW); //Set pin trigger low
  delay(500); // wait for 0.5 second
  digitalWrite(TriggerPin, HIGH); //Set pin trigger HIGH
  delayMicroseconds(1000); // wait (pause) for 1 second
  digitalWrite(TriggerPin, LOW);  //Set pin trigger low
  int period = pulseIn(echoPin, HIGH); //As long as the wavelength is high, it returns the period value
  int distance = (duration*.0343)/2; //Calculate the distance from the speed of sound 

  if ( distance < 200)  //If distance less than 200 cm 
  {
    digitalWrite(LED1, HIGH); //set green high as an avalible spot 
  }
  else
  { 
    digitalWrite(LED1, LOW); //else set green as low 
  }
  if ( distance >= 200) //If distance greater than or equal to 200 cm 
  {
    digitalWrite(LED2, HIGH); //set red light HIGH as unavalible spot 
  }
  else
  {
    digitalWrite(LED2, LOW); //else set red LOW 
  }
 
  delay(1000); //wait for 1 second 
}