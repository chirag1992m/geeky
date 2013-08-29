#include <cstdio>
#include <cstdlib>
#include <climits>
 
int main() {
	int c;
	double n;

	printf("1000\n");
  for (c = 1; c <= 1000; c++) {
    n = ((double)(rand()%10000000))/1000;
    printf("%.2f\n", n);
  }
 
  return 0;
}