//#define DEBUG
#include <math.h>

int relay = 8;

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15; 
 return Temp;
}

void setup() {
 Serial.begin(9600);
 pinMode(relay, OUTPUT);
}

void loop() {
  int temp2 = Thermistor(analogRead(0));
  
  if(temp2 > 70)
   digitalWrite(relay, HIGH);
  else
    digitalWrite(relay, LOW);
    
#ifdef DEBUG
  Serial.println(temp2);
#endif

}
