const unsigned char sfx_accept_psg[] = {
0xc5,0x4d,0xd0,0x3b,0xce,0x48,0x3b,0xc7,0x44,0xd5,0x3a,0xca,0x46,0x3b,0xc5,0x4d,
0xda,0x3a,0x09,0x04,0x00,0xdb,0x3b,0xca,0x46,0xdd,0x3a,0xc0,0x40,0xdf,0x38,0x00};

const unsigned char sfx_death_psg[] = {
0x8c,0x44,0x9f,0xae,0x61,0xb5,0xc0,0x40,0xdf,0xe4,0xfa,0x38,0xff,0x39,0x80,0x40,
0xaf,0x7f,0xb9,0xe4,0xf6,0x38,0x81,0xb6,0xfa,0x38,0xb4,0xff,0x39,0xb5,0x39,0xb6,
0xe4,0xf6,0x38,0xfa,0x38,0xff,0x39,0xb7,0x38,0x80,0x38,0xe4,0xf6,0x38,0x81,0xfa,
0x38,0xb8,0xff,0x3b,0x81,0x50,0x97,0xad,0x75,0xb9,0xc0,0x48,0xd9,0xe5,0xf3,0x38,
0x94,0xb6,0xd6,0xf4,0x38,0x92,0xb4,0xd4,0xf5,0x38,0xf7,0x38,0x93,0xb5,0xd5,0xf8,
0x38,0xf9,0x38,0x88,0x4d,0x97,0xb6,0xc0,0x49,0xd9,0xe4,0xf6,0x38,0x94,0xd6,0xfa,
0x38,0x92,0xd4,0xff,0x39,0x93,0xb7,0xd5,0x39,0x81,0x4c,0x97,0xcb,0x4a,0xd9,0xe4,
0xf6,0x38,0x94,0xd6,0xfa,0x38,0x92,0xb8,0xd4,0xff,0x39,0x93,0xd5,0x39,0x86,0x4b,
0x97,0xaf,0x6f,0xb9,0xc5,0x4b,0xd9,0xe4,0xf6,0x38,0x94,0xb6,0xd6,0xfa,0x38,0x92,
0xb4,0xd4,0xff,0x39,0x93,0xb5,0xd5,0x39,0x94,0xb6,0xd6,0xe4,0xf6,0x38,0xfa,0x38,
0xff,0x39,0x85,0x95,0xb7,0xd7,0x39,0x81,0x4c,0x97,0xc0,0x4c,0xd9,0xe4,0xf6,0x38,
0x94,0xd6,0xfa,0x38,0x92,0xb8,0xd4,0xff,0x39,0x93,0xd5,0x39,0x88,0x4d,0x97,0xa4,
0x6d,0xb9,0xc7,0x4d,0xd9,0xe5,0xf3,0x38,0x94,0xb6,0xd6,0xf4,0x38,0x92,0xb4,0xd4,
0xf5,0x38,0xf7,0x38,0x93,0xb5,0xd5,0xf8,0x38,0xf9,0x38,0x94,0xb6,0xd6,0xe4,0xf6,
0x38,0xfa,0x38,0xff,0x39,0x87,0x95,0xb7,0xd7,0x39,0x81,0x50,0x97,0xc0,0x50,0xd9,
0xe4,0xf6,0x38,0x94,0xd6,0xfa,0x38,0x92,0xb8,0xd4,0xff,0x39,0x93,0xd5,0x39,0x80,
0x52,0x97,0xaf,0x6f,0xb9,0xcf,0x51,0xd9,0xe4,0xf6,0x38,0x94,0xb6,0xd6,0xfa,0x38,
0x92,0xb4,0xd4,0xff,0x39,0x93,0xb5,0xd5,0x39,0x94,0xb6,0xd6,0xe4,0xf6,0x38,0xfa,
0x38,0xff,0x39,0x8f,0x51,0x95,0xb7,0xd7,0x39,0x87,0x55,0x97,0xad,0x75,0xb9,0xc6,
0x55,0xd9,0xe4,0xf6,0x38,0x94,0xb6,0xd6,0xfa,0x38,0x92,0xb4,0xd4,0xff,0x39,0x93,
0xb5,0xd5,0x39,0x80,0x52,0x97,0xb9,0xcf,0x5a,0xd9,0xe5,0xf3,0x38,0x94,0xb6,0xd6,
0xe7,0xf4,0x38,0x92,0xb4,0xd4,0xe7,0xf5,0x38,0xe7,0xf7,0x38,0x93,0xb5,0xd5,0xe7,
0xf8,0x38,0xe7,0xf9,0x38,0x94,0xb6,0xd6,0xe4,0xf6,0x38,0xe7,0xfa,0x38,0xe7,0xff,
0x38,0xe7,0x38,0x8f,0x51,0x95,0xb7,0xd7,0xe7,0x38,0xe7,0x38,0x81,0x50,0x97,0xaf,
0x7f,0xb9,0xc0,0x60,0xd9,0xe5,0xf3,0x38,0x94,0xb6,0xd6,0xf4,0x38,0x92,0xb4,0xd4,
0xf5,0x38,0xf7,0x38,0x93,0xb5,0xd5,0xf8,0x38,0xf9,0x38,0x9f,0xbf,0xdf,0xe4,0xf6,
0x38,0xfa,0x38,0xff,0x3b,0xe4,0xf6,0x38,0xfa,0x38,0xff,0x3b,0x97,0xb9,0xc6,0x55,
0xd9,0x38,0x94,0xb6,0xd6,0x38,0x92,0xb4,0xd4,0x39,0x93,0xb5,0xd5,0x39,0x94,0xb6,
0xd6,0x3b,0x80,0x95,0xb7,0xd7,0x39,0x81,0x39,0x96,0xb8,0xd8,0x3b,0x80,0x97,0xbf,
0xd9,0x39,0x81,0x38,0x80,0x38,0x81,0x98,0xda,0x39,0x9f,0xdf,0x3b,0x00};

const unsigned char sfx_power_psg[] = {
0xce,0x4b,0xd0,0x3b,0xd1,0x38,0xcf,0x47,0x08,0x02,0x00,0xc7,0x49,0x0a,0x02,0x00,
0x09,0x02,0x00,0x45,0xd0,0x3b,0xd1,0x3b,0xd2,0x3a,0xd3,0x39,0xd4,0x39,0xc3,0x55,
0xdf,0x3c,0x00};

const unsigned char sfx_reset_psg[] = {
0xc5,0x4d,0xd0,0x3b,0xc0,0x4a,0x3b,0xc7,0x49,0x3b,0xce,0x48,0xd5,0x3b,0xc5,0x4d,
0x3b,0xc0,0x4a,0x3b,0xc7,0x49,0xda,0x3b,0xce,0x48,0x3b,0xc0,0x49,0x3b,0xc0,0x40,
0xdf,0x3b,0x00};

