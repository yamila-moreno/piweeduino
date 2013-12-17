#include <SoftwareSerial.h>

#define SOUND_SENSOR A0
#define SOUND_SENSOR_2 A2
#define GREEN 2      // the number of the LED pin
#define RED 3
#define THRESHOLD_GREEN 200//The threshold to turn the led on 400.00*5/1024 = 1.95v
#define THRESHOLD_RED 500
#define LCD_OUT 6

int sensorValue;
int average;
int counter = 0;
boolean clapMeterOn = false;
double clapMeter = 0;
int sensor = 0;
int sensor_2 = 0;
SoftwareSerial lcd(99, LCD_OUT);

void setup()
{
    Serial.begin(9600);
    pins_init();

    pinMode(LCD_OUT, OUTPUT);
    lcd.begin(9600);

    lcd_init();

}

void loop()
{

    sensor = analogRead(SOUND_SENSOR);
    sensor_2 = analogRead(SOUND_SENSOR_2);
    if(min(sensor,sensor_2) > 0)
    {
        sensorValue = max(sensor, sensor_2);
        Serial.print("sensorValue ");
        Serial.println(sensorValue);
        if(sensorValue > THRESHOLD_GREEN)
        {
            turnOnLED(GREEN);

            if(counter==0){
                Serial.println("********************* INICIO APLAUSOMETRO");
            }
            clapMeterOn = true;
            clapMeter = clapMeter + sensorValue;
            counter++;
        }
        if(sensorValue > THRESHOLD_RED)
        {
            turnOnLED(RED);
        }
        delay(500);
        turnOffLEDS();
    }
    if (clapMeterOn == true && sensorValue < 50)
    {
        average = clapMeter/counter;
        clapMeterOn = false;
        Serial.println("HA SALIDO ===============> ");
        Serial.println(average);
        lcd_blink(average);
        counter = 0;
        clapMeter = 0;
        delay(1000);
    }
}

void pins_init()
{
    pinMode(GREEN, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(SOUND_SENSOR, INPUT);
}

void turnOnLED(int led)
{
    digitalWrite(led,HIGH);
}

void turnOffLEDS()
{
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
}

void lcd_init()
{
    lcd.write(0XFE);
    lcd.write(0X01);

}

void lcd_blink(int value)
{
    for(int i=0; i<=10; i++){
        lcd_init();
        delay(200);
        lcd.print(value);
        delay(200);
    }
}
