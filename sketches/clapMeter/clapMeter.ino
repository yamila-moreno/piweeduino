/*
LCD - no combina bien con pintar tambien en la matrix porque no se refresca bien
MEJORAR PALABRAS - YA SE PUEDE PONER CUALQUIER STRING
SENSORES - los probamos en la ofi por no andar gritando en casa
BARRAS -

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
#include "letters.h"

#define SOUND_SENSOR A0
#define SOUND_SENSOR_2 A2
#define THRESHOLD_EPIC_FAIL 120 //The threshold to turn the led on 400.00*5/1024 = 1.95v
#define THRESHOLD_FAIL 220
#define THRESHOLD_AVERAGE 380
#define THRESHOLD_WIN 450
#define THRESHOLD_EPIC_WIN 550
#define THRESHOLD_GOD 800

#define RowA 2
#define RowB 3
#define RowC 4
#define RowD 5
#define OE 6
#define R1 11
#define CLK 13
#define STB 10
#define DBNORM 150

byte row=0;
byte *hz;
int sensorValue;
int counter = 0;
unsigned long clapMeter = 0;
String clapPoints;
int sensor = 0;
int sensor_2 = 0;
int goodClap = 0;
int badClap = 0;
int result = 0;
boolean scanning = true;

void setup()
{
    Serial.begin(9600);

    // INIT SOUND SENSORS
    pinMode(SOUND_SENSOR, INPUT);
    pinMode(SOUND_SENSOR_2, INPUT);

    // INIT LED MATRIX
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
    if(scanning){
        result = scanClaps();
    }else{
        showResult();
    }
}

void showResult(){
    String phraseResult = "    ";
    if (result >= THRESHOLD_GOD){
        phraseResult.concat("OH GOD! YOU MUST BE NOHAYDUINO TEAM! :P");
    } else if (result >= THRESHOLD_EPIC_WIN){
        phraseResult.concat("FATALITY: EPIC WIN \o/");
    } else if (result >= THRESHOLD_WIN){
        phraseResult.concat("BRUTALITY: WIN :-)");
    } else if (result >= THRESHOLD_AVERAGE){
        phraseResult.concat("AVERAGITY: QUITE NORMAL :-/");        
    } else if (result >= THRESHOLD_FAIL){
        phraseResult.concat("FAIL! DO YOU USE MACOSX, MAYBE? u.u");        
    } else {
        phraseResult.concat("FRAK! EPIC FAIL! FIRED! >_<");
    }
    phraseResult.concat(" POINTS: ");
    clapPoints = String(clapMeter/100);
    phraseResult.concat(clapPoints);
    phraseResult.concat("    ");
    String m;
    for(int i=0;i<phraseResult.length()-3;i++){
        m = phraseResult.substring(i,i+4);
        byte charmap[] =
        {
            0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,
            charset[int(m.charAt(0))-32][0],charset[int(m.charAt(1))-32][0],charset[int(m.charAt(2))-32][0],charset[int(m.charAt(3))-32][0],
            charset[int(m.charAt(0))-32][1],charset[int(m.charAt(1))-32][1],charset[int(m.charAt(2))-32][1],charset[int(m.charAt(3))-32][1],
            charset[int(m.charAt(0))-32][2],charset[int(m.charAt(1))-32][2],charset[int(m.charAt(2))-32][2],charset[int(m.charAt(3))-32][2],
            charset[int(m.charAt(0))-32][3],charset[int(m.charAt(1))-32][3],charset[int(m.charAt(2))-32][3],charset[int(m.charAt(3))-32][3],
            charset[int(m.charAt(0))-32][4],charset[int(m.charAt(1))-32][4],charset[int(m.charAt(2))-32][4],charset[int(m.charAt(3))-32][4],
            charset[int(m.charAt(0))-32][5],charset[int(m.charAt(1))-32][5],charset[int(m.charAt(2))-32][5],charset[int(m.charAt(3))-32][5],
            charset[int(m.charAt(0))-32][6],charset[int(m.charAt(1))-32][6],charset[int(m.charAt(2))-32][6],charset[int(m.charAt(3))-32][6],
            charset[int(m.charAt(0))-32][7],charset[int(m.charAt(1))-32][7],charset[int(m.charAt(2))-32][7],charset[int(m.charAt(3))-32][7],
            0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,
        };
        for(int h=0;h<20;h++){
            for (row=0;row<16;row++){
                // DISPLAY IN COMPLETE ROWS IN LCS
                SPI.transfer(~(charmap[0+row*4]));
                SPI.transfer(~(charmap[1+row*4]));
                SPI.transfer(~(charmap[2+row*4]));
                SPI.transfer(~(charmap[3+row*4]));

                digitalWrite(OE,HIGH);
                hc138sacn(row);
                digitalWrite(STB,LOW);
                digitalWrite(STB,HIGH);
                delayMicroseconds(500);
                digitalWrite(OE,LOW);
                delayMicroseconds(500);
            }
        }
    }
}

int scanClaps(){
    clapMeter = 0;
    boolean keep = true;
    while(keep){
        sensor = 0;
        sensor_2 = 0;
        int tmp1 = 0;
        int tmp2 = 0;
        counter = 0;
        while(counter<5){
            tmp1 = analogRead(SOUND_SENSOR);
            tmp2 = analogRead(SOUND_SENSOR_2);
            if(min(tmp1,tmp2) > 0){
                sensor = sensor + tmp1;
                sensor_2 = sensor_2 + tmp2;
                counter++;
            }
        }
        sensor = sensor/5;
        sensor_2 = sensor_2/5;
        sensorValue = max(sensor, sensor_2);
         if(sensorValue > THRESHOLD_EPIC_FAIL){
            clapMeter = clapMeter + sensorValue;
            goodClap++;
        } else {
            if(badClap<50){
                badClap++;
            } else {
                keep = false;
            }
        }

    }

    result = clapMeter/goodClap;
    goodClap = 0;
    badClap = 0;
    scanning = false;

    return result;
}

void hc138sacn(byte r){
  digitalWrite(RowA,(r & 0x01));
  digitalWrite(RowB,(r & 0x02));
  digitalWrite(RowC,(r & 0x04));
  digitalWrite(RowD,(r & 0x08));

}

void setHistogram(int value){
     int normValue = value/40;
     normValue = min(normValue,16);
     if (normValue == 0){
      hz = zero;
     }
     else if (normValue <= 4){
      hz = four;
     }
     else if (normValue <= 8){
      hz = eight;
     }
     else if (normValue <= 12){
      hz = twelve;
     }
     else if (normValue <= 16){
      hz = sixteen;
     }
     else {
      hz = sixteen;
     }
}
