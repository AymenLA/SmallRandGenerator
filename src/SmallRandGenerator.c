#include <stdint.h>
#include <stdio.h>
#include "SmallRandGenerator.h"

/** Local defines          ***************************************************/

/** Privat functions prototypes  *********************************************/
static uint32_t GetNextSeed(uint32_t currentSeed);

/** Local variables        ***************************************************/
static uint32_t digestedSeed = 0U;

/** Local enumerations     ***************************************************/

/** Local types            ***************************************************/

/** Function definitions   ***************************************************/

/*****************************************************************************/
/* the idea is to read the seed value, get four bytes out of it, apply those 
/* bytes to a math equation and use the resulting value as next seed
/* 
/*****************************************************************************/
void Init_RandomGen(uint32_t seed)
{
    digestedSeed = GetNextSeed(seed);
}

uint32_t Get_RandomNumber(void)
{
    uint32_t randomToReturn = digestedSeed;
    digestedSeed = GetNextSeed(digestedSeed);
    return randomToReturn;
}

uint32_t Get_RandomNumberFromRange(uint32_t lower, uint32_t upper)
{
    uint32_t randomToReturn = digestedSeed;
    uint32_t finalRandomToReturn = digestedSeed;

    /* not allowed cases */
    if((upper == 0U) || (upper == lower) || (upper < lower))
    {
        finalRandomToReturn = 0U;
    }

    if(finalRandomToReturn != 0U)
    {
        /* first thing, update the digested seed, needed for futur calls */
        digestedSeed = GetNextSeed(digestedSeed);
        /* upper range should be included, add + 1*/
        /* methode 1 : get the rest of integer devision by the high limit */
        finalRandomToReturn = (randomToReturn % (upper + 1U));
        /* if the result is lower than the low limit, try method 2*/
        if(finalRandomToReturn < lower)
        {
            //printf("#srglib print : %u\n", finalRandomToReturn);
            finalRandomToReturn = lower + (finalRandomToReturn % ((upper - lower) + 1U));
        }
    }

    return finalRandomToReturn;
}

static uint32_t GetNextSeed(uint32_t currentSeed)
{
    uint8_t seedBytes[4] = {0U};
    uint8_t countSeedBytes = 0U;
    uint8_t nextHalfBytePosition = 0U;
    uint32_t seedToReturn = digestedSeed;
    for(uint8_t countSeedBytes = 0U; countSeedBytes < 4U; countSeedBytes++) 
    {
        /* save seed bytes in a table of size 4 */
        seedBytes[countSeedBytes] = (currentSeed >> (countSeedBytes * 8U)) & 0xFF;
        if(seedBytes[countSeedBytes] == 0U)
        {
            seedBytes[countSeedBytes] = ((countSeedBytes * (13U)) * 7U) & 0xFF;
        }

        /* this is needed in order to always read bytes from the tabe of size 4 */
        nextHalfBytePosition = countSeedBytes + 1U;
        if(nextHalfBytePosition == 4U)
        {
            nextHalfBytePosition = 0U;
        }
        /* just some bytes operation ... */
        seedToReturn += (seedToReturn >> (countSeedBytes * 8U)) + 
                        ( 
                            ((seedBytes[countSeedBytes] & 0x0F) - (seedBytes[nextHalfBytePosition] & 0x0F)) * 
                            (((seedBytes[countSeedBytes] & 0xF0) >> 4) + ((seedBytes[nextHalfBytePosition] & 0xF0) >> 4))
                        ) << (countSeedBytes * 8U);
    }

    /* return the calculated seed value + the rest of integer devision by 3 
       (smallest odd number different than 1) */
    return (seedToReturn + (seedToReturn % 3U));
}

/** End of file            ***************************************************/