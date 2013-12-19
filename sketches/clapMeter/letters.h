unsigned char charset[][8] = {
{
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // !
0x04,
0x04,
0x04,
0x04,
0x00,
0x00,
0x04,
0x00
},
{               // "
0x0A,
0x0A,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // #
0x0A,
0x0A,
0x1F,
0x0A,
0x1F,
0x0A,
0x0A,
0x00
},
{               // $
0x04,
0x0F,
0x14,
0x0E,
0x05,
0x1E,
0x04,
0x00
},
{               // %
0x18,
0x19,
0x02,
0x04,
0x08,
0x13,
0x03,
0x00
},
{               // &
0x0C,
0x12,
0x14,
0x08,
0x15,
0x12,
0x0D,
0x00
},
{               // '
0x0C,
0x04,
0x08,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // (
0x02,
0x04,
0x08,
0x08,
0x08,
0x04,
0x02,
0x00
},
{               // )
0x08,
0x04,
0x02,
0x02,
0x02,
0x04,
0x08,
0x00
},
{               // *
0x00,
0x04,
0x15,
0x0E,
0x15,
0x04,
0x00,
0x00
},
{               // +
0x00,
0x04,
0x04,
0x1F,
0x04,
0x04,
0x00,
0x00
},
{               // ,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x04,
0x08,
0x00
},
{               // -
0x00,
0x00,
0x00,
0x1F,
0x00,
0x00,
0x00,
0x00
},
{               // .
0x00,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x0C,
0x00
},
{               // /
0x00,
0x01,
0x02,
0x04,
0x08,
0x10,
0x00,
0x00
},
{               // 0
0x0E,
0x11,
0x13,
0x15,
0x19,
0x11,
0x0E,
0x00
},
{               // 1
0x04,
0x0C,
0x04,
0x04,
0x04,
0x04,
0x0E,
0x00
},
{               // 2
0x0E,
0x11,
0x01,
0x02,
0x04,
0x08,
0x1F,
0x00
},
{               // 3
0x1F,
0x02,
0x04,
0x02,
0x01,
0x11,
0x0E,
0x00
},
{               // 4
0x02,
0x06,
0x0A,
0x12,
0x1F,
0x02,
0x02,
0x00
},
{               // 5
0x1F,
0x10,
0x1E,
0x01,
0x01,
0x11,
0x0E,
0x00
},
{               // 6
0x06,
0x08,
0x10,
0x1E,
0x11,
0x11,
0x0E,
0x00
},
{               // 7
0x1F,
0x01,
0x02,
0x04,
0x04,
0x04,
0x04,
0x00
},
{               // 8
0x1E,
0x11,
0x11,
0x0E,
0x11,
0x11,
0x0E,
0x00
},
{               // 9
0x0E,
0x11,
0x11,
0x0F,
0x01,
0x02,
0x0C,
0x00
},
{               // :
0x00,
0x0C,
0x0C,
0x00,
0x0C,
0x0C,
0x00,
0x00
},
{               // ;
0x00,
0x0C,
0x0C,
0x00,
0x0C,
0x04,
0x08,
0x00
},
{               // <
0x02,
0x04,
0x08,
0x10,
0x08,
0x04,
0x02,
0x00
},
{               // =
0x00,
0x00,
0x1F,
0x00,
0x1F,
0x00,
0x00,
0x00
},
{               // >
0x08,
0x04,
0x02,
0x01,
0x02,
0x04,
0x08,
0x00
},
{               // ?
0x0E,
0x11,
0x01,
0x02,
0x04,
0x00,
0x04,
0x00
},
{               // @
0x0E,
0x11,
0x01,
0x0D,
0x15,
0x15,
0x0E,
0x00
},
{               // A
0x0E,
0x11,
0x11,
0x11,
0x1F,
0x11,
0x11,
0x00
},
{               // B
0x1E,
0x09,
0x09,
0x0E,
0x09,
0x09,
0x1E,
0x00
},
{               // C
0x0E,
0x11,
0x10,
0x10,
0x10,
0x11,
0x0E,
0x00
},
{               // D
0x1E,
0x09,
0x09,
0x09,
0x09,
0x09,
0x1E,
0x00
},
{               // E
0x1F,
0x10,
0x10,
0x1F,
0x10,
0x10,
0x1F,
0x00
},
{               // F
0x1F,
0x10,
0x10,
0x1E,
0x10,
0x10,
0x10,
0x00
},
{               // G
0x0E,
0x11,
0x10,
0x13,
0x11,
0x11,
0x0F,
0x00
},
{               // H
0x11,
0x11,
0x11,
0x1F,
0x11,
0x11,
0x11,
0x00
},
{               // I
0x0E,
0x04,
0x04,
0x04,
0x04,
0x04,
0x0E,
0x00
},
{               // J
0x07,
0x02,
0x02,
0x02,
0x02,
0x12,
0x0C,
0x00
},
{               // K
0x11,
0x12,
0x14,
0x18,
0x14,
0x12,
0x11,
0x00
},
{               // L
0x10,
0x10,
0x10,
0x10,
0x10,
0x10,
0x1F,
0x00
},
{               // M
0x11,
0x1B,
0x15,
0x15,
0x11,
0x11,
0x11,
0x00
},
{               // N
0x11,
0x19,
0x19,
0x15,
0x13,
0x13,
0x11,
0x00
},
{               // O
0x0E,
0x11,
0x11,
0x11,
0x11,
0x11,
0x0E,
0x00
},
{               // P
0x1E,
0x11,
0x11,
0x1E,
0x10,
0x10,
0x10,
0x00
},
{               // Q
0x0E,
0x11,
0x11,
0x11,
0x15,
0x12,
0x1D,
0x00
},
{               // R
0x1E,
0x11,
0x11,
0x1E,
0x14,
0x12,
0x11,
0x00
},
{               // S
0x0E,
0x11,
0x10,
0x0E,
0x01,
0x11,
0x0E,
0x00
},
{               // T
0x1F,
0x04,
0x04,
0x04,
0x04,
0x04,
0x04,
0x00
},
{               // U
0x11,
0x11,
0x11,
0x11,
0x11,
0x11,
0x0E,
0x00
},
{               // V
0x11,
0x11,
0x11,
0x11,
0x11,
0x0A,
0x04,
0x00
},
{               // W
0x11,
0x11,
0x11,
0x15,
0x15,
0x1B,
0x11,
0x00
},
{               // X
0x11,
0x11,
0x0A,
0x04,
0x0A,
0x11,
0x11,
0x00
},
{               // Y
0x11,
0x11,
0x11,
0x0A,
0x04,
0x04,
0x04,
0x00
},
{               // Z
0x1F,
0x01,
0x02,
0x04,
0x08,
0x10,
0x1F,
0x00
},
{               // [
0x0E,
0x08,
0x08,
0x08,
0x08,
0x08,
0x0E,
0x00
},
{               // backslash
0x00,
0x10,
0x08,
0x04,
0x02,
0x01,
0x00,
0x00
},
{               // ]
0x0E,
0x02,
0x02,
0x02,
0x02,
0x02,
0x0E,
0x00
},
{               // ^
0x04,
0x0A,
0x11,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // _
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x1F,
0x00
},
{               // `
0x10,
0x08,
0x04,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // a
0x00,
0x00,
0x0E,
0x01,
0x0F,
0x11,
0x0F,
0x00
},
{               // b
0x10,
0x10,
0x16,
0x19,
0x11,
0x11,
0x1E,
0x00
},
{               // c
0x00,
0x00,
0x0E,
0x11,
0x10,
0x11,
0x0E,
0x00
},
{               // d
0x01,
0x01,
0x0D,
0x13,
0x11,
0x11,
0x0F,
0x00
},
{               // e
0x00,
0x00,
0x0E,
0x11,
0x1F,
0x10,
0x0E,
0x00
},
{               // f
0x02,
0x05,
0x04,
0x0E,
0x04,
0x04,
0x04,
0x00
},
{               // g
0x00,
0x0D,
0x13,
0x13,
0x0D,
0x01,
0x0E,
0x00
},
{               // h
0x10,
0x10,
0x16,
0x19,
0x11,
0x11,
0x11,
0x00
},
{               // i
0x04,
0x00,
0x0C,
0x04,
0x04,
0x04,
0x0E,
0x00
},
{               // j
0x02,
0x00,
0x06,
0x02,
0x02,
0x12,
0x0C,
0x00
},
{               // k
0x08,
0x08,
0x09,
0x0A,
0x0C,
0x0A,
0x09,
0x00
},
{               // l
0x0C,
0x04,
0x04,
0x04,
0x04,
0x04,
0x0E,
0x00
},
{               // m
0x00,
0x00,
0x1A,
0x15,
0x15,
0x15,
0x15,
0x00
},
{               // n
0x00,
0x00,
0x16,
0x19,
0x11,
0x11,
0x11,
0x00
},
{               // o
0x00,
0x00,
0x0E,
0x11,
0x11,
0x11,
0x0E,
0x00
},
{               // p
0x00,
0x16,
0x19,
0x19,
0x16,
0x10,
0x10,
0x00
},
{               // q
0x00,
0x0D,
0x13,
0x13,
0x0D,
0x01,
0x01,
0x00
},
{               // r
0x00,
0x00,
0x16,
0x19,
0x10,
0x10,
0x10,
0x00
},
{               // s
0x00,
0x00,
0x0F,
0x10,
0x1E,
0x01,
0x1F,
0x00
},
{               // t
0x08,
0x08,
0x1C,
0x08,
0x08,
0x09,
0x06,
0x00
},
{               // u
0x00,
0x00,
0x12,
0x12,
0x12,
0x12,
0x0D,
0x00
},
{               // v
0x00,
0x00,
0x11,
0x11,
0x11,
0x0A,
0x04,
0x00
},
{               // w
0x00,
0x00,
0x11,
0x11,
0x15,
0x15,
0x0A,
0x00
},
{               // x
0x00,
0x00,
0x11,
0x0A,
0x04,
0x0A,
0x11,
0x00
},
{               // y
0x00,
0x00,
0x11,
0x11,
0x13,
0x0D,
0x01,
0x0E
},
{               // z
0x00,
0x00,
0x1F,
0x02,
0x04,
0x08,
0x1F,
0x00
},
{               // {
0x02,
0x04,
0x04,
0x08,
0x04,
0x04,
0x02,
0x00
},
{               // |
0x04,
0x04,
0x04,
0x00,
0x04,
0x04,
0x04,
0x00
},
{               // }
0x08,
0x04,
0x04,
0x02,
0x04,
0x04,
0x08,
0x00
},
{               // ~
0x08,
0x15,
0x02,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 5F
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 60
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 61
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 62
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 63
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 64
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 65
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 66
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 67
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 68
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 69
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 6A
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 6B
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 6C
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 6D
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 6E
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 6F
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 70
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 71
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 72
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 73
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 74
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 75
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 76
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 77
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 78
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 79
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 7A
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 7B
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 7C
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 7D
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 7E
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
},
{               // 7F
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00
}}; 
