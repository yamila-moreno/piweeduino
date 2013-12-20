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
#define THRESHOLD_FAIL 200 //The threshold to turn the led on 400.00*5/1024 = 1.95v
#define THRESHOLD_GOOD 400
#define THRESHOLD_WIN 600

#define RowA 2
#define RowB 3
#define RowC 4
#define RowD 5
#define OE 6
#define R1 11
#define CLK 13
#define STB 10
#define DBNORM 80

byte row=0;
byte *hz;
int sensorValue;
int counter = 0;
double clapMeter = 0;
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
    phraseResult.concat(result);
    phraseResult.concat(": ");
    if (result >= THRESHOLD_WIN){
        phraseResult.concat("YOU ARE A TOTAL WINNER");
    } else if (result >= THRESHOLD_GOOD){
        phraseResult.concat("YOU DID IT QUITE WELL");
    } else {
        phraseResult.concat("FRAK! YOU LOST!");
    }
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
        for(int h=0;h<10;h++){
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
    boolean keep = true;
    while(keep){
        sensor = analogRead(SOUND_SENSOR);
        sensor_2 = analogRead(SOUND_SENSOR_2);
        if(min(sensor,sensor_2) > 0){
            sensorValue = max(sensor, sensor_2);
            if(sensorValue > THRESHOLD_FAIL){
                clapMeter = clapMeter + sensorValue;
                goodClap++;
                /*
                setHistogram(sensorValue);
                for(row=0;row<16;row++){
                    SPI.transfer(~(hz[0+row*4]));
                    SPI.transfer(~(hz[1+row*4]));
                    SPI.transfer(~(hz[2+row*4]));
                    SPI.transfer(~(hz[3+row*4]));

                    digitalWrite(OE,HIGH);
                    hc138sacn(row);
                    digitalWrite(STB,LOW);
                    digitalWrite(STB,HIGH);
                    delayMicroseconds(500);
                    digitalWrite(OE,LOW);
                    delayMicroseconds(500);
                }
                */
            } else {
                if(badClap<5){
                    badClap++;
                } else {
                    keep = false;
                }
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
     int normValue = value/DBNORM;
     normValue = min(normValue*2,32);
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
