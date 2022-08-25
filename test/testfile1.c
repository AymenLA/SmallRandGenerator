
#include <stdio.h>
#include <stdint.h>
#include "SmallRandGenerator.h"

void RunTestCase1(void)
{
    /* start with 0 as seed */
    uint32_t testSeed = 0U;
    uint32_t randomValue = 0U;
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase1 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
    randomValue = Get_RandomNumber();
    printf("first Random value = %u\n", randomValue);
    /* the first generated number should be different from 0 */
    if(testSeed == randomValue)
    {
        printf("FAILED !!! first Random value is equal to seed value\n"); 
    }

   
    randomValue = Get_RandomNumber();
    printf("second Random value = %u\n", randomValue); 
    if(testSeed == randomValue)
    {
        printf("FAILED !!! second Random value is equal to seed value\n"); 
    }

    randomValue = Get_RandomNumber();
    printf("Third Random value = %u\n", randomValue); 
    if(testSeed == randomValue)
    {
        printf("FAILED !!! Third Random value is equal to seed value\n"); 
    }

    printf("----------- RunTestCase1 : END -----------\n");
}

void RunTestCase2(void)
{
    /* start with MAX_UIN32_T as seed */
    uint32_t testSeed = 0xFFFFFFFF;
    uint32_t randomValue = 0U;

    Init_RandomGen(testSeed);

    printf("----------- RunTestCase2 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
    randomValue = Get_RandomNumber();
    printf("first Random value = %u\n", randomValue);
    if(testSeed == randomValue)
    {
        printf("FAILED !!! first Random value is equal to seed value\n"); 
    }

   
    randomValue = Get_RandomNumber();
    printf("second Random value = %u\n", randomValue); 
    if(testSeed == randomValue)
    {
        printf("FAILED !!! second Random value is equal to seed value\n"); 
    }

    randomValue = Get_RandomNumber();
    printf("Third Random value = %u\n", randomValue); 
    if(testSeed == randomValue)
    {
        printf("FAILED !!! Third Random value is equal to seed value\n"); 
    }

    printf("----------- RunTestCase2 : END -----------\n");
}

void RunTestCase3(void)
{
    /* start with a random seed */
    uint32_t testSeed = 0xAB12CD34;
    uint32_t randomValue = 0U;
    
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase3 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
    randomValue = Get_RandomNumber();
    printf("first Random value = %u\n", randomValue);
    if(testSeed == randomValue)
    {
        printf("FAILED !!! first Random value is equal to seed value\n"); 
    }

   
    randomValue = Get_RandomNumber();
    printf("second Random value = %u\n", randomValue); 
    if(testSeed == randomValue)
    {
        printf("FAILED !!! second Random value is equal to seed value\n"); 
    }

    randomValue = Get_RandomNumber();
    printf("Third Random value = %u\n", randomValue); 
    if(testSeed == randomValue)
    {
        printf("FAILED !!! Third Random value is equal to seed value\n"); 
    }

    printf("----------- RunTestCase3 : END -----------\n");
}

void RunTestCase4(void)
{
    /* start with a random seed */
    uint32_t testSeed = 0x87526589;
    uint32_t randomValue = 0U;
    
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase4 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
    /* print all 255 first values from the generator */
    for(uint8_t count = 0U; count < 254; count++)
    {
        randomValue = Get_RandomNumber();
        printf(" Random value = %u\n", randomValue);
    }

    printf("----------- RunTestCase4 : END -----------\n");
}

void RunTestCase5(void)
{
    uint32_t testSeed = 0x87526589;
    uint32_t randomValue = 0U;
    
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase5 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
    for(uint8_t count = 0U; count < 254; count++)
    {
        randomValue = Get_RandomNumber();
        printf(" Random value = %u\n", randomValue % 17U);
    }

    printf("----------- RunTestCase5 : END -----------\n");
}

void RunTestCase6(void)
{
    uint32_t testSeed = 0xac25be88;
    uint32_t randomValue = 0U;
    uint32_t upper = 21U;
    uint32_t lower = 15U;
    
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase6 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
    printf("Range = %u - %u\n", lower, upper);
    for(uint8_t count = 0U; count < 254; count++)
    {
        randomValue = Get_RandomNumberFromRange(lower, upper);
        printf(" Random value = %u\n", randomValue);
        if((randomValue < lower) || (randomValue > upper))
        {
            printf("FAILED !!! value out of range\n"); 
        }

    }

    printf("----------- RunTestCase6 : END -----------\n");
}

void RunTestCase7(void)
{
    uint32_t testSeed = 0xac25be88;
    uint32_t randomValue = 0U;
    uint32_t upper = 3U;
    uint32_t lower = 0U;
    
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase7 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
    printf("Range = %u - %u\n", lower, upper);
    for(uint8_t count = 0U; count < 254; count++)
    {
        randomValue = Get_RandomNumberFromRange(lower, upper);
        printf(" Random value = %u\n", randomValue);
        if((randomValue < lower) || (randomValue > upper))
        {
            printf("FAILED !!! value out of range\n"); 
        }

    }

    printf("----------- RunTestCase7 : END -----------\n");
}