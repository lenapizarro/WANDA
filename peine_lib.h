/*
PEINE_BLOCK_SAMPLES = 64 samples

*/

#ifndef peine_lib_h
#define peine_lib_h

#ifndef __ASSEMBLER__
#include <stdio.h>  // for NULL
#include <string.h> // for memcpy
#include "kinetis.h"
#endif

#ifndef PEINE_BLOCK_SAMPLES
#if defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__MK64FX512__) || defined(__MK66FX1M0__)
#define PEINE_BLOCK_SAMPLES  64

#ifndef __ASSEMBLER__
class AudioStream;
class AudioConnection;

//typedef bitset<8> BYTE;

typedef struct peine_block_struct
{
  unsigned char ref_count;
	unsigned char memory_pool_index;
	unsigned char reserved1;
	unsigned char reserved2;
  uint8_t data[PEINE_BLOCK_SAMPLES];
}
