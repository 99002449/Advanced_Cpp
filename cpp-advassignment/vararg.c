#include <stdio.h>
#include <stdarg.h>

int vsum(int num,...) {

   va_list valist;
   int sum = 0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int);
   }
	
   /* clean memory reserved for valist */
   va_end(valist);

   return sum;
}

int main() {
   printf("sum of 2, 3, 4, 5 = %d\n", vsum(4, 2,3,4,5));
   printf("sum of 5, 10, 15 = %d\n", vsum(3, 5,10,15));
    printf("sum of 2, 3, = %d\n", vsum(2,2,3));
   printf("sum of 5 = %d\n", vsum(1, 5));
}

