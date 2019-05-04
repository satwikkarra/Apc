#include "apc.h"


long int my_atoi(const char *s1)
{
	long int sum =0;
	if (*s1 == '-')
	{
		int sign = -1;
		s1++;
		for ( ;(*s1 > 47  && *s1 < 58); s1++)
		{
			sum = sum * 10 + (*s1 - '0');
		}
		return sign * sum;
	}
	else
	{
		for ( ;((*s1 > 47 && *s1 < 58) || (*s1 == '+')); s1++)
		{
			if (*s1 == '+')
			{
				s1++;
			}
			sum = sum * 10 + (*s1 - '0');
		}
		return sum;
	}
}
