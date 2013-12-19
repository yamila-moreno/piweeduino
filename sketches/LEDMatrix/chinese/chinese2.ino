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

#define DBNORM 40

void setHistogram(int value){

     normValue = value/DBNORM;
     normValue = min(normValue*2,16);
     for (int i=0;i<64;i++){
     	 if (i=<normValue){
     	     hz[i] = 0xFF;
         else if(16<i=<normValue+16){
     	     hz[i] = 0xFF;
	 }
         else{
             hz[i] = 0x00;
         }
	 }
     }


}

int main() {
   int i;
   int array[10];
   for (i = 0; i < 10; i++) {
      array[i] = i;
      printf("%d ", array[i]);
   }
   return 0;

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

  noise = check_noise();
  setHistogram(noise);

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
