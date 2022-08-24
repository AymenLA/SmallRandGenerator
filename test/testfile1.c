
#include <stdio.h>
#include <stdint.h>
#include "SmallRandGenerator.h"

void RunTestCase1(void)
{
    uint32_t testSeed = 0U;
    uint32_t randomValue = 0U;
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase1 : BEGIN -----------\n");
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

    printf("----------- RunTestCase1 : END -----------\n");
}

void RunTestCase2(void)
{
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
    uint32_t testSeed = 0x87526589;
    uint32_t randomValue = 0U;
    
    Init_RandomGen(testSeed);

    printf("----------- RunTestCase4 : BEGIN -----------\n");
    printf("test seed value = %u\n", testSeed);
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