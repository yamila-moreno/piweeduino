

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
byte hz[] =
{
  //[16*16]
0x41,0x7F,
0x41,0x08,
0x41,0x08,
0x41,0x08,
0x49,0x08,
0x49,0x08,
0x36,0x7F,
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
0x00,0x00,
0x00,0x00,
};

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
}

void loop(){
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
}