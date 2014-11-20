#ifndef PA3_H
#define PA3_H

/* TODO #define flag bitmasks and constants for min/max/default bases */
#define H_FLAG_MASK 128
#define READ_FILE_MASK 64
#define PRINT_ENGLISH_MASK 32
#define PRINT_FLOAT_MASK 16
#define INPUT_MASK 8
#define OUTPUT_MASK 4
#define BASE_TEN 10
#define BASE_MIN 2
#define BASE_MAX 36
#define PA3 "pa3"
#define BASE_MASK(ob) (((long long) 0x1) << (ob))

struct argsInfo {
  unsigned char mode;
  unsigned int inputBase;
  unsigned long long outputBases;
  char* inFileStr;
};

void printEnglish( long num );
void printIntBinary( long num );
void printFPBinary( float num );
void printBase( long num, int base );
long strToLong( const char* str, const int base );
int checkRange( long value, long minRange, long maxRange );
void processIntToken( char* inStr, struct argsInfo info );
void processFPToken( char* inStr, struct argsInfo info );
struct argsInfo setFlags( int argc, char* argv[] );
void printChar(char ch);
#endif /* PA3_H */
