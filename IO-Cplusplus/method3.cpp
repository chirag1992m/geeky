/*
	method 3 - fallback to unlocked I/O in C for much faster services

	Can be used in performance intensive I/O.
	These are NOT multi-thread safe. Should be used in caution.
	But, in competetive programming platforms, one program is already
	separated from others, so can easily be used for better I/O in competetive
	programming.

	I've used register variables to make the I/O even faster (as they reside in registers).
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

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    
    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }
    
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
    
    if(neg)
    	x = -x;
}
 
inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
 
    str[i] = '\0';
}
 
 
int main()
{
 
  int n;
  char s[100];

  fastRead_int(n);
  	printf("%d\n", n);

  fastRead_string(s);
  	printf("%s\n", s);
  return 0;
}