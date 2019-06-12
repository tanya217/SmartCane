
#define echoPin 7 // Echo Pin for uv
#define trigPin 8 // Trigger Pin for uv
#define buzzer 11 //buzzer
#define vib 4
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int maximumRange = 200; // Maximum range needed
int minimumRange = 30; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
  Serial.begin (9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  //pinMode (lightpin,OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   // initialize digital pin 13 as an output.
  pinMode(buzzer, OUTPUT);
  pinMode( vib , OUTPUT);  // Must be a PWM pin
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  //int tilt = digitalRead(buttonPin);
  int sensorvalue=analogRead(A0);
  //Serial.println(sensorvalue);
  if(sensorvalue<600){
  digitalWrite(buzzer,LOW);
  }
  else{
   digitalWrite(buzzer,HIGH); 
  }
  
  if(buttonState==0){
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  //digitalWrite(buzzer,HIGH);
  //igitalWrite(buzzer,HIGH);
  //digitalWrite(buzzer,HIGH);
  }
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, LOW);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, HIGH); 
  }
  
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 

 distance = duration/58.2;  //distance (in cm)
 //Serial.println(distance);
 Serial.println(buttonState);
 if (distance <= minimumRange){
 //Serial.println("-1");
 digitalWrite(vib, HIGH); 
 }
 else {
 
 digitalWrite(vib, LOW);   
 }
 
 delay(50);
 
}








