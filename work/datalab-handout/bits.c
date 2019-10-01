/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
/* simple  construction of XOR using DeMorgan's Law for OR*/
  return ~(~x & ~y) & ~(x & y) ;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
/* construct two's complement representation of largest negative using << */
  return (1 << 31);

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
/* btest is strange in handling of ! operator and overflow
 * This solution clears the overflowed bits
 */
  int xOverflow = x + x + 2;
  return (!xOverflow) & ~xOverflow & !!(x+1); 
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
/* fold iput in half 4 times, then check second bit using >> */
  int x16 = x & (x >> 16);
  int x8 = x16 & (x16 >> 8);
  int x4 = x8 & (x8 >> 4);
  int x2 = x4 & (x4 >> 2);

  return (x2 >> 1) & 1;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
/*exploit invert bits and add one property of 2's complement */
  return (~x + 1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
/* check for upper and lower bit limitations, then screen out certain
 * combinations of bits positions 3, 4, and 5.
 */
  int lessThan64 = !(~63 & x);
  int atLeast48 = (x >> 4) & (x >> 5);
  int screen = ~((x >> 3) & ((x >> 1) | (x >> 2)));
  return lessThan64 & atLeast48 & screen;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
/* create bit masks for 0 and non-zero x, then conjunct with y and z  */
  int xTrue = (((!!x) << 31) >> 31);
  int xFalse = ~(xTrue);
  return (xTrue & y) | (xFalse & z); 
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
/* performs disjunction with automatic truth conditions and conjunction
 * with negated automatic false conditions, and a simple comparison
 */
  int Tmin = (1<<31);
  int minusX = (~x) + 1;
  int ySign = (y>>31);
  int xSign = (x>>31);
  int simpleComp = !((y + minusX) >> 31);
  int xNegYPos = xSign & (!ySign);
  int yNegXPos = ySign & (!xSign);
  int xTmin = (!(x ^ Tmin));
  int yTmin = (!(y ^ Tmin));
  return (xTmin | xNegYPos | ((!yTmin) & simpleComp)) & (!yNegXPos);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
/* checks for any 1 bits by folding x in half and using | */
  int x16 = x | (x >> 16);
  int x8 = x16 | (x16 >> 8);
  int x4 = x8 | (x8 >> 4);
  int x2 = x4 | (x4 >> 2);
  int x1 = x2 | (x2 >> 1);
  return (~x1 & 1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
/*progressively ID's and counts exact position of MSB using masks*/
  int highHalf = (255<<24) | (255<<16);
  int lowHalf = ~highHalf; 
  
  int highByte = (255<<24) | (255<<8);
  int lowByte = ~highByte;
  /* 8 ops*/
  int highNyb = (240<<24) | (240<<16) | (240<<8) | 240;
  int lowNyb = ~highNyb;

  int highPair = (204<<24) | (204<<16) | (204<<8) | 204;
  int lowPair = ~highPair;

  int highBit = (170<<24) | (170<<16) | (170<<8) | 170;
  int lowBit = ~highBit;
  /* 29 ops */
  int signX = x>>31;
  int xPos = x ^ signX;
  /* 31 ops */
  int halfCheck = !!(xPos & highHalf);
  int hMask = (halfCheck<<31)>>31;
  int half = xPos & ((highHalf & hMask) | (lowHalf & ~hMask));
  int halfPlus = halfCheck<<4;
  /* 42 ops */
  int byteCheck = !!(half & highByte);
  int byMask = (byteCheck<<31)>>31;
  int byte = half & ((highByte & byMask) | (lowByte & ~byMask));
  int bytePlus = byteCheck<<3;
  /* 53 ops */
  int nybCheck = !!(byte & highNyb);
  int nMask = (nybCheck<<31)>>31;
  int nyb = byte & ((highNyb & nMask) | (lowNyb & ~nMask));
  int nybPlus = nybCheck<<2;
  /* 64 ops */
  int pairCheck = !!(nyb & highPair);
  int pMask = (pairCheck<<31)>>31;
  int pair = nyb & ((highPair & pMask) | (lowPair & ~pMask));
  int pairPlus = pairCheck<<1;
  /* 75 ops */
  int lBit = !(pair & highBit);
  int bitH = (!lBit)<<1;
  int bitL = (!!(pair & lowBit)) & lBit;
  /* 84 ops */
  

  return halfPlus+bytePlus+nybPlus+pairPlus+bitH+bitL+1;
}
//float = (1 << 29);
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
/*defaults to uf when NaN, otherwise constructs 2*uf from components*/
  int exponent = (uf>>23) & 255;
  int sign = (uf>>31)<<31;
  int frac = uf & ~(511<<23);
  
  if (exponent<255){
    if (exponent==0){
      return (2*uf) | sign;
    }
    return sign | ((exponent+1)<<23) | frac;
  }
  return uf;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
/*eliminates out of bound values, then constructs int based on parts of float*/
  int exponent = (uf>>23) & 255;
  int isNegative = (uf>>31);
  int frac = uf & ~(511<<23);
  int wholeFrac = frac | (1<<23);
  int uExp = exponent - 127;

  if (uExp<0){
    return 0;
  }
  if (uExp>31){
    return (1<<31);
  }
  if (uExp<23){
    wholeFrac = (wholeFrac>>(23-uExp));
  
    if (isNegative){
       return (0 - wholeFrac);
    }
    return wholeFrac;
  }
  if (uExp>=23){
    wholeFrac = wholeFrac<<(uExp-23);
    if (isNegative){
       return (0- wholeFrac);
    }
  }
  return 0;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
/*tests limits, and provides for very small denormalized*/
  int ux = x+127;

  if (ux>254){
    return (255<<23);
  }
  if(ux<1){
    if (ux<-22){
      return 0;
    }
    return ((ux)<<23) | (1<<(ux+22));
  }
  return ((ux)<<23);
}
