/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include <stdio.h>
#include "../../boolean.h"

#define MARK '\r'
/* State Mesin */
extern char currentChar;
extern boolean EOP;
static int retval;

void START(FILE *input);

void ADV();

void ADVFILE();

#endif