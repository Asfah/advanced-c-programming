/* Hello World in C, the hard way, just for fun.... */
/***************************/

#include<stdio.h>
#include<stdlib.h> /* stdlib for malloc() function */

/* macro to declare the constant EXIT_SUCCESS which is 0, used as the return
value when exiting without any errors */
#define EXIT_SUCCESS 0

/* defining types, int as WORD, char as BYTE */
typedef unsigned int WORD;
typedef char BYTE;

/* function prototypes */
void putn();  /* prints a newline to screen */
void putb();  /* prints an array of characters/bytes to screen */
void (*pn)(); /* a function pointer */

int main()
{
/* _LEN: a constant int having 12 as the value */
const WORD _LEN = 12;

/* allocating memory for 12 bytes/characters using malloc() function
   so it creates a C string of 12 characters */
BYTE *phl= (BYTE*)malloc(_LEN * sizeof(BYTE));

/* assigning values to individual bytes/indexes using pointers
   *(phl+1) is same as phl[1] using array indexing
   and 0x20 is the hexadecimal value of \n (newline) */
*(phl)='H';   *(phl+1)='e'; *(phl+2)='l';
*(phl+3)='l'; *(phl+4)='o'; *(phl+5)=0x20;
*(phl+6)='W'; *(phl+7)='o'; *(phl+8)='r';
*(phl+9)='l'; *(phl+10)='d';

/* prints the string in phl to screen */
putb (phl);

/* function pointer pointing to the function putn() */
pn= &putn;

/* prints a newline to screen */
pn();

/* free the memory which was dynamically allocated by malloc() function */
free (phl);

/* function pointer pn is pointing to nothing */
pn = NULL;

/* return with exit code 0 */
return EXIT_SUCCESS;

}

/* prints an array of characters/bytes to screen */
void putb(BYTE *s)
{
  /* while the char pointed by *s has a byte/character */
 while (*s)
 {
   /* prints the character to screen */
  putchar(*s);

   /* increment the address so it points to the next byte/char */
  s++;
 }
}

/* prints a newline to screen */
void putn()
 {
  putchar(0xa);
 }
 
 
