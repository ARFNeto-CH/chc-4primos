#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include <stdio.h>
int main()
{
	// os fatores iniciais
	long int next = 0;
	long int n = 0;;
	long int p1 = 2, p2 = 3, p3 = 5, p4 = 7;

	do
	{
		p1 = 2, p2 = 3, p3 = 5, p4 = 7;
		printf("[Max 8 digitos] Entre com N: ");
		int q = scanf("%ld", &n);
		if ((q == 1) && (n!=0))
		{
			int processado = FALSE;
			do
			{
				if (((p1 * p1) + (p2 * p2) + (p3 * p3) + (p4 * p4)) == n)
				{	// achou a combinacao
					printf("%ld^2 + %ld^2 + %ld^2 + %ld^2\n", p1, p2, p3, p4);
					processado = TRUE;
				}
				else
				{
					// p4 e o ultimo primo
					// nas proximas linhas vamos definir next como
					// sendo... o proximo primo depois de p4
					int achou_proximo = FALSE;
					next = 0;
					for (long int i = p4 + 2; !achou_proximo; i = i + 2)
					{
						long int maior = 0;
						for (maior = 7; (maior * maior) < i; maior += 1);
						maior = maior - 1; // passou 1 da conta no for
						long int fator = 3;
						while (fator <= maior)
						{
							if (i % fator == 0)
							{	// entao 'i' nao e primo
								// forca sair do loop
								fator = 100000000; // tanto faz
							}
							else
							{
								fator = fator + 2;
							}
						}	// end while
						if (fator != (100000000))
						{
							next = i;
							achou_proximo = TRUE;
						};	// if()
					};	// for()
					// saindo daqui temos o primo depois de p4 em next
					if (next > n)
					{
						printf("Nao e possivel a representacao\n");
						processado = TRUE;
					}
					else
					{
						// se ainda da, rodamos a tabela de primos
						p1 = p2;
						p2 = p3;
						p3 = p4;
						p4 = next;
						// e continuamos
					};	// if()
				};	// if()
			} while (processado == FALSE);
		};	// if()
	} while (n != 0);
	printf("Encerrando...\n");
};	// main()