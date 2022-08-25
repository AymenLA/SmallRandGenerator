#ifndef _MY_LIB_H_
#define _MY_LIB_H_

#include <stdint.h>
#ifdef	__cplusplus
extern "C" {
#endif

void Init_RandomGen(uint32_t seed);

uint32_t Get_RandomNumber(void);

uint32_t Get_RandomNumberFromRange(uint32_t lower, uint32_t upper);

#ifdef	__cplusplus
}
#endif

#endif // _MY_LIB_H_