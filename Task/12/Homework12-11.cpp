#include<math.h>
#include <stdio.h>

/* prototypes */
unsigned reverseBits(unsigned value);
void displayBits(unsigned value);

int main(void)
{
	unsigned a; /* unsigned integer from user */

				/* prompt user and read value */
				// printf( "Enter an unsigned integer: " );
	scanf("%u", &a);

	/* display bits of a before reversed */
	printf("\nBefore bits are reversed:\n");
	displayBits(a);

	/* reverse bits and display results */
	a = reverseBits(a);
	printf("\nAfter bits are reversed:\n");
	displayBits(a);

	return 0; /* indicate successful termination */

} /* end main */

unsigned reverseBits(unsigned value)
{
	unsigned y = value;
	unsigned fake, real;
	unsigned displaymask = 1 << 15;
	int c, n;
	for (c = 1; c <= 16; c++)
	{
		value <<= 1;
		value &= ~1;
		if (y & 1)
			value |= 1;
		y >>= 1;
	}
	fake = value;
	real = 0;
	n = pow(2, 15);
	printf("\n");
	for (c = 1; c <= 16; c++)
	{
		real += ((fake&displaymask ? '1' : '0') - '0')*n;
		fake <<= 1;
		n /= 2;
	}
	return real;
}

void displayBits(unsigned value)
{
	int c;
	unsigned displaymask = 1 << 15;
	printf("%10u = ", value);
	for (c = 1; c <= 16; c++)
	{
		putchar(value&displaymask ? '1' : '0');
		value <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
}