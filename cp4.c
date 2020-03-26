#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include "limits.h"
#include <stdio.h>
int main()
{
	// os fatores iniciais
	int  next = 0;
	int  N = 0;;
	int  p1 = 2, p2 = 3, p3 = 5, p4 = 7;
		do
	{
		p1 = 2, p2 = 3, p3 = 5, p4 = 7;
		printf("[Max 8 digitos] Entre com N: ");
		int q = scanf("%d", &N);
		//printf("[Aguarde...] Calculando para N = %d\n\n", N);

		if ((q == 1) && (N!=0))
		{
			int processado = FALSE;
			do
			{
				int prd = (p1 * p1) + (p2 * p2) + (p3 * p3) + (p4 * p4);
				//printf("p=[%d,%d,%d,%d] Produto = %d N = %d\n",
				//	p1, p2, p3, p4, prd, N);
				if (prd == N)
				{	// achou a combinacao
					printf("%d^2 + %d^2 + %d^2 + %d^2\n", p1, p2, p3, p4);
					processado = TRUE;
				}
				else
				{
					if (prd < N)
					{
						// p4 e o ultimo primo
						// nas proximas linhas vamos definir next como
						// sendo... o proximo primo depois de p4
						int achou_proximo = FALSE;
						next = 0;
						for (int i = p4 + 2; !achou_proximo; i = i + 2)
						{
							//int smaior = (int)sqrt((double)i); era isso
							int  maior = 0;
							for (maior = 7; (maior * maior) < i; maior += 1);
							// passou 1 da conta se nao for um quadrado perfeito
							if (maior * maior != i) maior = maior - 1;
							int  fator = 3;
							while (fator <= maior)
							{
								if (i % fator == 0)
								{	// entao 'i' nao e primo
									// forca sair do loop
									fator = 100000000L; // tanto faz
								}
								else
								{
									fator = fator + 2;
								}
							}	// end while
							if (fator != (100000000L))
							{
								next = i;
								achou_proximo = TRUE;
							};	// if()
						};	// for()
						// saindo daqui temos o primo depois de p4 em next
						if (next > N)
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
						}
					}
					else
					{
						printf("Nao e possivel a representacao\n");
						processado = TRUE;
					};	// if()
				};	// if()
			} while (processado == FALSE);
		};	// if()
	} while (N != 0);
	printf("Encerrando...\n");
};	// main()