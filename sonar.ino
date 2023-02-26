const int TRIG = 7;
const int ECHO = 2;

void setup(){
   //Instructions to serial monitor
   Serial.begin(9600);

   //Pin modes
   pinMode(TRIG, OUTPUT);
   pinMode(ECHO, INPUT);
}

void loop(){
  //Set trigger to 1
  digitalWrite(TRIG, HIGH);
  //Square wave of 10 micros
  delayMicroseconds(10);
  //Set trigger to 0
  digitalWrite(TRIG, LOW);
  
  //Get the time
  unsigned long t0=micros();
  unsigned long tau=pulseIn(ECHO, HIGH);
  unsigned long t1=micros();

  //Print on serial monitor
  Serial.print((t1+t0)/2);
  Serial.print(",");
  Serial.println(tau);
}
