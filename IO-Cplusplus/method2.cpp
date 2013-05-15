/*
	method 2 - fallback to I/O in C for faster services
*/
/*

source - http://www.codecogs.com/reference/computing/c/stdio.h/

fflush(FILE *stream) - forces a write of all buffered data for the given output or update stream
fpurge(FILE *stream) - erases any input or output buffered in the given \c stream

char fgets (char * restrict str, int size, FILE * restrict stream) - (\n retained)
char gets (char *str) - fgets with infinite size and stream of stdin(\n discarded)

int fputs (const char *str, FILE *stream) - writes str to stream
int puts (const char *str) - otpts str+\n to stdin

int fgetc (FILE *stream) - next input character from stream
int getc (FILE *stream) = fgetc
int getc_unlocked(FILE *stream) = getc + (no locking used - lest overhead)
int getchar() = getc(stdin)
int getchar_unlocked(void) = getc_unlocked(stdin)
int getw (FILE *stream) - gets the next int

int printf (const char * restrict format, ...) - formatted output to stdout
int fprintf (FILE * restrict stream, const char * restrict format, ...) = printf + stream
int sprintf (char * restrict str, const char * restrict format, ...) = write to a string
int snprintf (char * restrict str, size_t size, const char * restrict format, ...) = write to a string without overflow(fixed size)

"put" versions available like "get" family.

"scanf" version available like "printf" family.

// buffer family to set type of buffer for streams
void setbuf (FILE * restrict stream, char * restrict buf)
void setbuffer (FILE *stream, char *buf, int size)
int setlinebuf (FILE *stream)

// push back a character to input stream
int	ungetc (int c, FILE *stream)

*/

#include <cstdio>

int main() {
	
}