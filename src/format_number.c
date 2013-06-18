#include <math.h>
#include <string.h>

#include <stdio.h>

#include "format_number.h"

/*
   format input with comma as thousand separator.
   returns a new character array, or NULL if insufficient memory
*/
char* format_number(uint32_t n) {
    char zero[] = "0";

    /* a 32 bit unsigned int is 10 digits long at most; with 3 separators
       and 1 null terminator, 14 characters are enough for all input
    */
    char buf[14];
    buf[13] = 0;

    if (!n) {
	return strdup(zero);
    } else {
	char*p = &buf[12];
	int i = 1;
	while (n) {
	    *p-- = '0' + (n%10);
	    n /= 10;
	    if (i % 3 == 0 && n) {
		*p-- = ',';
	    }
	    ++i;
	}

	return strdup(p+1);
    }
}
