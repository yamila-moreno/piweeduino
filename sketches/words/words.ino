/*
  A very simple demo for SeeedStudio ultrathin 16x32 Red LED Matrix to display 2 character of "你好".

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

#include <SPI.h>
#include "proof.h"
#include "bars.h"

#define RowA 2
#define RowB 3
#define RowC 4
#define RowD 5
#define OE 6
#define R1 11
#define CLK 13
#define STB 10

byte row=0;

void hc138sacn(byte r){
  digitalWrite(RowA,(r & 0x01));
  digitalWrite(RowB,(r & 0x02));
  digitalWrite(RowC,(r & 0x04));
  digitalWrite(RowD,(r & 0x08));

}

void setup () {
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

     Serial.begin(9600);
}

void loop(){
    print_phrase();
//    print_bars();
}

int iterations = 3;

void print_bars(){
    int jj = 0;
    while(jj<3000){
        jj++;
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(ten[0+row*4]));
            SPI.transfer(~(ten[1+row*4]));
            SPI.transfer(~(ten[2+row*4]));
            SPI.transfer(~(ten[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            //delayMicroseconds(500);
            digitalWrite(OE,LOW);
            //delayMicroseconds(500);
        }
    }
    /*
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(two[0+row*4]));
            SPI.transfer(~(two[1+row*4]));
            SPI.transfer(~(two[2+row*4]));
            SPI.transfer(~(two[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(three[0+row*4]));
            SPI.transfer(~(three[1+row*4]));
            SPI.transfer(~(three[2+row*4]));
            SPI.transfer(~(three[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(four[0+row*4]));
            SPI.transfer(~(four[1+row*4]));
            SPI.transfer(~(four[2+row*4]));
            SPI.transfer(~(four[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(five[0+row*4]));
            SPI.transfer(~(five[1+row*4]));
            SPI.transfer(~(five[2+row*4]));
            SPI.transfer(~(five[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(six[0+row*4]));
            SPI.transfer(~(six[1+row*4]));
            SPI.transfer(~(six[2+row*4]));
            SPI.transfer(~(six[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(seven[0+row*4]));
            SPI.transfer(~(seven[1+row*4]));
            SPI.transfer(~(seven[2+row*4]));
            SPI.transfer(~(seven[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(eight[0+row*4]));
            SPI.transfer(~(eight[1+row*4]));
            SPI.transfer(~(eight[2+row*4]));
            SPI.transfer(~(eight[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(nine[0+row*4]));
            SPI.transfer(~(nine[1+row*4]));
            SPI.transfer(~(nine[2+row*4]));
            SPI.transfer(~(nine[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }
    for(int h=0;h<iterations;h++){
        for(row=0;row<16;row++){
            // DISPLAY IN COMPLETE ROWS IN LCS
            SPI.transfer(~(ten[0+row*4]));
            SPI.transfer(~(ten[1+row*4]));
            SPI.transfer(~(ten[2+row*4]));
            SPI.transfer(~(ten[3+row*4]));

            digitalWrite(OE,HIGH);
            hc138sacn(row);
            digitalWrite(STB,LOW);
            digitalWrite(STB,HIGH);
            delayMicroseconds(500);
            digitalWrite(OE,LOW);
            delayMicroseconds(500);
        }
    }*/

}


void print_phrase(){
    String phrase = "    ";
    phrase.concat("toma zorra =)");
    phrase.concat("    ");
    String m;
    for(int i=0;i<phrase.length()-3;i++){
        m = phrase.substring(i,i+4);
        Serial.println(m);
        byte won[] =
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
            for(row=0;row<16;row++){
                // DISPLAY IN COMPLETE ROWS IN LCS
                SPI.transfer(~(won[0+row*4]));
                SPI.transfer(~(won[1+row*4]));
                SPI.transfer(~(won[2+row*4]));
                SPI.transfer(~(won[3+row*4]));

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
