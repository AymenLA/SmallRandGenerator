# SmallRandGenerator
A simple and small random number generator

## Introduction

This small code repo aims to create a Random Number Generator based on initial seed value and some bytes operations, no extra expensive math or dependencies to system clock or systicks. The inconvinient of this srng is that it returns always the same values if it is given the same initial conditions (initial seed) but this is a small rng and it is not made to be used for cyphering or salting digests, this is made for a home project where I needed random numbers generated from a library.

## Building libsrng as a stand alone :

It is possible to build only the libsrng.a without an application to test it, however for the moment, make install is not working properly : it only copy libsrng.a to the lib directory and does not create an include directory and puts on it the lib header. this needs to be addressed.

## For native mqchine :

```
cmake ../ -DCMAKE_BUILD_TYPE="Debug" -DCMAKE_INSTALL_PREFIX=../
make
make install
```

### For cortex-m0plus :

```
cmake ../ -DCMAKE_TOOLCHAIN_FILE="arm-gcc-cortex-m0plus.cmake" -DCMAKE_BUILD_TYPE="Debug" -DCMAKE_INSTALL_PREFIX=../
make
make install
```

## Usage and testing

The source code offers 3 public APIs : 

```
void Init_RandomGen(uint32_t seed);
uint32_t Get_RandomNumber(void);
uint32_t Get_RandomNumberFromRange(uint32_t lower, uint32_t upper);
```
those APIs are self explanatory 

To test the code, you need to get into *test* directory and run the following commands :

```
make libsrng
make
./testlibsrng
```
## test cases description
I've written few tests to see how the srng works and generates random numbers in some senarios :

**1- initial seed is 0, print first 3 generated numbers**

**2- initial seed is 0xFFFFFFFF, print first 3 generated numbers**

**3- initial seed is any uint32_t number, print first 3 generated numbers**

**4- initial seed is any uint32_t number, print all 255 first random generated numbers**

**5- initial seed is any uint32_t number, print all 255 first random the rest of integer devision by 16**

**6- initial seed is any uint32_t number, print all 255 first random generated numbers in range 15 to 21**

**7- initial seed is any uint32_t number, print all 255 first random generated numbers in range 0 to 3**

## future evolutions

**1- remove all constants from source code**

**2- add a configuration file**

**3- analyse the enthropy of the rng for various scenarios**

**4- find a limit to the random generation**

**5- use this lib with embedded devices (PIC18F)**
