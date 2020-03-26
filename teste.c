#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include "limits.h"
#include <stdio.h>
#include "math.h""

int main()
{
	// os fatores iniciais
	int  maior = 0;
	int i = 0;
	for (int i = 7; i < 10000000; i += 1)
	{
		int smaior = (int)sqrt((double)i);
		for (maior = 1; (maior * maior) < i; maior += 1);
		if(maior*maior != i) maior = maior - 1;
		if (maior != smaior)
		{
			printf("(%d) via sqtr(): %d\n", i, smaior);
			printf("(%d) via   loop: %d\n\n", i, maior);
			break;
		}
		//if (i % 50000 == 0) printf(".");
		//if (i % 1000 == 0) printf(".");
	}
	printf("Encerrando...\n");
};	// main()