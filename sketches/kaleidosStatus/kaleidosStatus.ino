#include <SoftwareSerial.h>

#define ITERATIONS 5

//NOISE
#define NOISE_SENSOR_1 A0
#define NOISE_SENSOR_2 A2
#define THRESHOLD_GREEN 200
#define THRESHOLD_RED 500
int noiseAVG = 0;
int noiseMeter = 0;

//LIGTH
#define LIGHT_SENSOR A4
int lightAVG = 0;
int lightMeter = 0;

//LCD
#define LCD_OUT 6
SoftwareSerial lcd(99, LCD_OUT);


void setup()
{
  Serial.begin(9600);
}

void loop()
{
    noiseAVG = check_noise();
    lightAVG = check_light();
    Serial.println("============> NOISE: " + noiseAVG);
    Serial.println("============> LIGHT: " + lightAVG);
    delay(5000);    
   
}

int check_noise()
{
      Serial.println("NOISE");
    noiseMeter = 0;
    for(int i=0; i<=ITERATIONS; i++)
    {
      Serial.println(max(analogRead(NOISE_SENSOR_1), analogRead(NOISE_SENSOR_2)));
      noiseMeter = noiseMeter + max(analogRead(NOISE_SENSOR_1), analogRead(NOISE_SENSOR_2));
    }
    return noiseMeter/ITERATIONS;
}

int check_light()
{
    Serial.println("LIGHT");
    lightMeter = 0;
    for(int i=0; i<=ITERATIONS; i++)
    {
        Serial.println(analogRead(LIGHT_SENSOR));
      lightMeter = lightMeter + analogRead(LIGHT_SENSOR);
    }
  return lightMeter/ITERATIONS;
}
