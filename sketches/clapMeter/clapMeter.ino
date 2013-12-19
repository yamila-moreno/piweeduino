#include <SoftwareSerial.h>
#include "words.h"

#define SOUND_SENSOR A0
#define SOUND_SENSOR_2 A2
#define GREEN 2      // the number of the LED pin
#define RED 3
#define THRESHOLD_GREEN 200//The threshold to turn the led on 400.00*5/1024 = 1.95v
#define THRESHOLD_RED 500
#define LCD_OUT 8

#include <SPI.h>

#define RowA 2
#define RowB 3
#define RowC 4
#define RowD 5
#define OE 6
#define R1 11
#define CLK 13
#define STB 10

byte row=0;

byte hz1[] =
{
  //[16*16]
0x00,0x00,
0x00,0x00,
0x00,0x00,
0xFF,0xFF,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
  //[16*16]
0x00,0x00,
0x00,0x00,
0x00,0x00,
0xFF,0xFF,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
0x00,0x00,
};


byte hz2[] =
{
  //[16*16]
0x00,0x00,
0x04,0x80,
0x04,0x80,
0x05,0xFE,
0x09,0x02,
0x0A,0x04,
0x18,0x20,
0x28,0x20,
0x08,0xA8,
0x08,0xA4,
0x09,0x24,
0x09,0x22,
0x0A,0x22,
0x08,0x20,
0x08,0xE0,
0x00,0x00,
  //[16*16]
0x00,0x00,0x10,0x00,0x11,0xF8,0x10,0x08,0x7C,0x10,0x24,0x20,0x24,0x20,0x25,0xFC,
0x44,0x20,0x24,0x20,0x18,0x20,0x08,0x20,0x14,0x20,0x24,0x20,0x40,0xE0,0x00,0x00
};

byte hz[] =
{
  //[16*16]
0x00,0x00,
0x04,0x80,
0x04,0x80,
0x05,0xFE,
0x09,0x02,
0x0A,0x04,
0x18,0x20,
0x28,0x20,
0x08,0xA8,
0x08,0xA4,
0x09,0x24,
0x09,0x22,
0x0A,0x22,
0x08,0x20,
0x08,0xE0,
0x00,0x00,
  //[16*16]
0x00,0x00,0x10,0x00,0x11,0xF8,0x10,0x08,0x7C,0x10,0x24,0x20,0x24,0x20,0x25,0xFC,
0x44,0x20,0x24,0x20,0x18,0x20,0x08,0x20,0x14,0x20,0x24,0x20,0x40,0xE0,0x00,0x00
};


int sensorValue;

int average;
int counter = 0;
boolean clapMeterOn = false;
double clapMeter = 0;
int sensor = 0;
int sensor_2 = 0;
SoftwareSerial lcd(99, LCD_OUT);


#define DBNORM 70

void setHistogram(int value){

     int normValue = value/DBNORM;
     normValue = min(normValue*2,32);
     //Serial.println(hz.size);
     
     for (int i=0;i<64;i++){
         hz1[i] = 0x00; 
     }
     
     for (int i=0;i<64;i++){
     	 if (i<normValue){
     	     hz1[i] = 0xFF;
     }
         else if(i>32 && i<normValue+32){
     	     hz1[i] = 0xFF;
     	 }
         else{
             hz1[i] = 0x00;
         }
	 }
     

     for (int i=0;i<64;i++){
      Serial.print(hz1[i],HEX); 
     }
}
void setup()
{

  
    Serial.begin(9600);
    pins_init();
    //Serial.println("HHHA");
    pinMode(LCD_OUT, OUTPUT);
    lcd.begin(9600);
  
    lcd_init();
    lcd.print("HOLA");

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
//    sensor_2 = analogRead(SOUND_SENSOR_2);

//    sensor = 300;
    sensor_2 = 300;
    if(min(sensor,sensor_2) > 0)
    {
        sensorValue = max(sensor, sensor_2);
        setHistogram(sensorValue);
  //SPI.begin();
  //delay(100);

  for(row=0;row<16;row++){
       for (int i=0;i<2;i++){
         SPI.transfer(~(hz1[i*32+row*2]));
         SPI.transfer(~(hz1[i*32+row*2+1]));
  }
  digitalWrite(OE,HIGH);
  hc138sacn(row);
  digitalWrite(STB,LOW);
  digitalWrite(STB,HIGH);
  delayMicroseconds(500);
  digitalWrite(OE,LOW);
  delayMicroseconds(500);
  
  }
  
  Serial.print("sensorValue ");
  Serial.println(sensorValue);
       
    if(sensorValue > THRESHOLD_GREEN)
        {
            turnOnLED(GREEN);

            if(counter==0){
                //Serial.println("********************* INICIO APLAUSOMETRO");
            }
            clapMeterOn = true;
            clapMeter = clapMeter + sensorValue;
            counter++;
        }
        if(sensorValue > THRESHOLD_RED)
        {
            turnOnLED(RED);
        }
        //delay(500);
        turnOffLEDS();
    
    if (clapMeterOn == true && sensorValue < 50)
    {
        average = clapMeter/counter;
        clapMeterOn = false;
        //Serial.println("HA SALIDO ===============> ");
        //Serial.println(average);
        lcd_blink(average);
        counter = 0;
        clapMeter = 0;
        //delay(1000);
    }
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


