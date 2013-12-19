/*
  The circuit:
  * A connect to digital 2
  * B connect to digital 3
  * C connect to digital 4
  * D connect to digital 5
  * OE connect to digital 6
  * STB connect to digital 10
  * R1 connect to digital 11
  * CLK connect to digital 13
  * GND connect to GND
*/


#include <SoftwareSerial.h>
#include <SPI.h>
#include "bars.h"
#include "words.h"

#define SOUND_SENSOR A0
#define SOUND_SENSOR_2 A2
#define THRESHOLD_FAIL 200//The threshold to turn the led on 400.00*5/1024 = 1.95v
#define THRESHOLD_GOOD 400
#define THRESHOLD_WIN 600
#define LCD_OUT 8


#define RowA 2
#define RowB 3
#define RowC 4
#define RowD 5
#define OE 6
#define R1 11
#define CLK 13
#define STB 10

byte row=0;

byte *hz;

int sensorValue;

int average;
int counter = 0;
boolean clapMeterOn = false;
double clapMeter = 0;
int sensor = 0;
int sensor_2 = 0;
SoftwareSerial lcd(99, LCD_OUT);


#define DBNORM 140

void setHistogram(int value){

     int normValue = value/DBNORM;
     normValue = min(normValue*2,32);
     if (normValue == 0){
      hz = zero;
     }
     else if (normValue == 1){
      hz = one;
     }
     else if (normValue == 2){
      hz = two;
     }
     else if (normValue == 3){
      hz = three;
     }
     else if (normValue == 4){
      hz = four;
     }
     else if (normValue == 5){
      hz = five;
     }
     else if (normValue == 6){
      hz = six;
     }
     else if (normValue == 7){
      hz = seven;
     }
     else if (normValue == 8){
      hz = eight;
     }
     else if (normValue == 9){
      hz = nine;
     }
     else if (normValue == 10){
      hz = ten;
     }
     else if (normValue == 11){
      hz = eleven;
     }
     else if (normValue == 12){
      hz = twelve;
     }
     else if (normValue == 13){
      hz = thirteen;
     }
     else if (normValue == 14){
      hz = fourteen;
     }
     else if (normValue == 15){
      hz = fifteen;
     }
     else if (normValue == 16){
      hz = sixteen;
     }
     else {
      hz = sixteen;
     }
}
void setup()
{


    Serial.begin(9600);
    pins_init();

    pinMode(LCD_OUT, OUTPUT);
    lcd.begin(9600);
    lcd_init();

    pinMode(RowA, OUTPUT);
    pinMode(RowB, OUTPUT);
    pinMode(RowC, OUTPUT);
    pinMode(RowD, OUTPUT);
    pinMode(OE, OUTPUT);
    pinMode(R1, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(STB, OUTPUT);
    SPI.begin();
    delay(10);

}

void loop()
{

    sensor = analogRead(SOUND_SENSOR);
    sensor_2 = analogRead(SOUND_SENSOR_2);

    if(min(sensor,sensor_2) > 0)
    {
        sensorValue = max(sensor, sensor_2);
        setHistogram(sensorValue);

        for(row=0;row<16;row++){
            for (int i=0;i<2;i++){
                SPI.transfer(~(hz[i*32+row*2]));
                SPI.transfer(~(hz[i*32+row*2+1]));
            }
            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }

        if(sensorValue > THRESHOLD_FAIL)
        {
            clapMeterOn = true;
            clapMeter = clapMeter + sensorValue;
            counter++;
        }
   }
   if (clapMeterOn == true && sensorValue < 50)
   {
        average = clapMeter/counter;
        clapMeterOn = false;
        if (average >= THRESHOLD_WIN)
        {
            Serial.println("WIN");
            for (row=0;row<16;row++){
                for (int i=0;i<2;i++){
                    SPI.transfer(~(win[i*32+row*2]));
                    SPI.transfer(~(win[i*32+row*2+1]));
                }
                digitalWrite(OE,HIGH);
                hc138sacn(row);
                digitalWrite(STB,LOW);
                digitalWrite(STB,HIGH);
                delayMicroseconds(500);
                digitalWrite(OE,LOW);
                delayMicroseconds(500);
            }
        } else if (average >= THRESHOLD_GOOD){
            Serial.println("GOOD");
            for (row=0;row<16;row++){
                for (int i=0;i<2;i++){
                    SPI.transfer(~(good[i*32+row*2]));
                    SPI.transfer(~(good[i*32+row*2+1]));
                }
                digitalWrite(OE,HIGH);
                hc138sacn(row);
                digitalWrite(STB,LOW);
                digitalWrite(STB,HIGH);
                delayMicroseconds(500);
                digitalWrite(OE,LOW);
                delayMicroseconds(500);
            }
         } else {
            Serial.println("FAIL");
            for (row=0;row<16;row++){
                for (int i=0;i<2;i++){
                    SPI.transfer(~(fail[i*32+row*2]));
                    SPI.transfer(~(fail[i*32+row*2+1]));
                }
                digitalWrite(OE,HIGH);
                hc138sacn(row);
                digitalWrite(STB,LOW);
                digitalWrite(STB,HIGH);
                delayMicroseconds(500);
                digitalWrite(OE,LOW);
                delayMicroseconds(500);
            }
        }

        counter = 0;
        clapMeter = 0;
    }

}

void pins_init()
{
    pinMode(SOUND_SENSOR, INPUT);
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
        //delay(200);
        lcd.print(value);
        //delay(200);
    }
}

void hc138sacn(byte r){
  digitalWrite(RowA,(r & 0x01));
  digitalWrite(RowB,(r & 0x02));
  digitalWrite(RowC,(r & 0x04));
  digitalWrite(RowD,(r & 0x08));

}


