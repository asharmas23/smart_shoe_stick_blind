//Distance
int d=20;

//Ultrasonic Pins Defined
//L
const int trigPin1 = 12;
const int echoPin1 = 13;
//F
const int trigPin2 = 8;
const int echoPin2 = 9;
//R
const int trigPin3 = 4;
const int echoPin3 = 5;

//Vibration Motors Pins Defined
//L
const int g1 = 11;
const int v1 = 10;
//R
const int v2 = 6;
const int g2 = 7;
//F
const int v3 = 3;
const int g3 = 2;

//Function for returning Distance in cms.
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

//Function for Activating vibration motors
void activatemotors(int cm1,int cm2,int cm3)
{
   if(cm1<d)
   {
      analogWrite(v1, 150);
   }
   if(cm2<d)
   {
      analogWrite(v2, 150);
   }
   if(cm3<d)
   {
      analogWrite(v3, 150);
   }
   delay(250);
   analogWrite(v1, 0);
   analogWrite(v2, 0);
   analogWrite(v3, 0);
   
}



void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  //Defining Pins for Ultrasonic sensors
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);

  //Defining pins for Vibration motors
  pinMode(v1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(v2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(v3, OUTPUT);
  pinMode(g3, OUTPUT);

  //Turning vibration Motors OFF initially
  analogWrite(v1, 0);
  digitalWrite(g1, LOW);
  analogWrite(v2, 0);
  digitalWrite(g2, LOW);
  analogWrite(v3, 0);
  digitalWrite(g3, LOW);
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration1,duration2,duration3, cm1,cm2,cm3;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  duration1 = pulseIn(echoPin1, HIGH);
  cm1 = microsecondsToCentimeters(duration1);

  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  duration2 = pulseIn(echoPin2, HIGH);
  cm2 = microsecondsToCentimeters(duration2);

  
  
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  duration3 = pulseIn(echoPin3, HIGH);
  cm3 = microsecondsToCentimeters(duration3);
 

  /*digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  
  
  
  
  // convert the time into a distance
  
  */
  
  Serial.print(cm1);
  Serial.print("cm\t");
  Serial.print(cm2);
  Serial.print("cm\t");
  Serial.print(cm3);
  Serial.print("cm\t");
  Serial.println();
  
  activatemotors(cm1,cm2,cm3);
}

