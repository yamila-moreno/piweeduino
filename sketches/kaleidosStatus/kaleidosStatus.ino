#include <SoftwareSerial.h>
#include"AirQuality.h"
#include <stdio.h>
#include <math.h>

#define ITERATIONS 5

char buffer[200];

//NOISE
#define NOISE_SENSOR_1 A2
#define NOISE_SENSOR_2 A4
#define THRESHOLD_GREEN 200
#define THRESHOLD_RED 500
int noiseAVG = 0;
int noiseMeter = 0;

//LIGHT
#define LIGHT_SENSOR A6
int lightAVG = 0;
int lightMeter = 0;

//AIR
AirQuality airqualitysensor;
int current_quality = -1;
int airPol = 0;

//TEMPERATURE
#define TEMP_SENSOR A8
int B = 3975;
float resistance;
float temperature;
int a = 0;

//LCD
#define LCD_OUT 6
SoftwareSerial lcd(99, LCD_OUT);

void setup()
{
    Serial.begin(9600);
    airqualitysensor.init(A1);
}

void loop()
{
    noiseAVG = check_noise();
    lightAVG = check_light();
    airPol = check_air();
    temperature = check_temperature();
    Serial.print("============> NOISE: ");
    Serial.println(noiseAVG);
    Serial.print("============> LIGHT: ");
    Serial.println(lightAVG);
    Serial.print("============> AIR: ");
    Serial.println(airPol);
    
    delay(5000);
}

int check_noise()
{
    noiseMeter = 0;
    for(int i=0; i<=ITERATIONS; i++)
    {
        noiseMeter = noiseMeter + max(analogRead(NOISE_SENSOR_1), analogRead(NOISE_SENSOR_2));
    }
    return noiseMeter/ITERATIONS;
}

int check_light()
{
    lightMeter = 0;
    for(int i=0; i<=ITERATIONS; i++)
    {
        lightMeter = lightMeter + analogRead(LIGHT_SENSOR);
    }
    return lightMeter/ITERATIONS;
}

int check_air()
{
    current_quality=airqualitysensor.slope();    
    return current_quality;
}

ISR(TIMER2_OVF_vect)
{
	if(airqualitysensor.counter==122)//set 2 seconds as a detected duty
	{

			airqualitysensor.last_vol=airqualitysensor.first_vol;
			airqualitysensor.first_vol=analogRead(A0);
			airqualitysensor.counter=0;
			airqualitysensor.timer_index=1;
			PORTB=PORTB^0x20;
	}
	else
	{
		airqualitysensor.counter++;
	}
}

int check_temperature()
{
    a = analogRead(TEMP_SENSOR);
    resistance = (float)(1023-a)*10000/a;
    temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;
    return temperature;
}
