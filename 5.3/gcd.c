#include <stdio.h>
#include <stdlib.h>

#define GCD_DEBUG 1

int non_recusion_gcd(int m,int n)
{
	int tmp;
	while (n != 0) {
#ifdef GCD_DEBUG
	printf("gcd(%d,%d)\n",m,n);
#endif
		tmp = m % n;
		m = n;
		n = tmp;
	}
	return m;
}

int gcd(int m, int n)
{
#ifdef GCD_DEBUG
	printf("gcd(%d,%d)\n",m,n);
#endif
	if (n == 0) return m;
	return gcd(n,m%n);
}

void swap(int *var1, int *var2)
{
	int tmp;
	if (*var1 < *var2) {
		tmp = *var2;
		*var2 = *var1;
		*var1 = tmp;
	}
}

int main(int argc, char *argv[])
{
	int var1,var2;
	int gcd_res = 0;
	if(argc != 3) return;

	var1 = atoi(argv[1]);
	var2 = atoi(argv[2]);

	if (var1 < var2) swap(&var1,&var2);
	printf("recusion gcd:\n");
	gcd_res = gcd(var1,var2);
	printf("%d is gcd  of %d and %d.\n",gcd_res,var1,var2);	

	printf("non recusion gcd:\n");
	gcd_res = non_recusion_gcd(var1,var2);
	printf("%d is gcd  of %d and %d.\n",gcd_res,var1,var2);	
}


