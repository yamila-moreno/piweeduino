#include <math.h>
#include <SoftwareSerial.h>

int termReading = 0;
double tempC = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("OpenSegment Example Code");

}

double Thermister(int RawADC) {
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))*Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 return Temp;
}

void loop() 
{
  Serial.println("hola mundo"); 
  termReading = analogRead(A0);
  tempC = Thermister(termReading);
  Serial.println(tempC);
  delay(1000);
  
}
