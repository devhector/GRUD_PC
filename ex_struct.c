#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100
#define LUCROMIN 0.15
#include "minha_bib.h"

/*

Nesse exercício você implementará um programa de computador para gerenciar a compra e
venda de veículos por uma empresa. A empresa vai iniciar suas atividades com
um caixa inicial, comprar e vender veículos para obter lucro (ou prejuízo, afinal nem
todos são bons administradores de negócio).

Verifique as atividades comentadas nesse "esqueleto" do programa
e finalize sua implementação. Verifique sua nota caso esse exercício fosse a avaliação

Boa sorte! Alison

*/


int main()
{

	automovel estoque[MAX];

	int caixa = 0, lucro = 0;
	int escolha;


	cria_lista(estoque);

	caixa_inicial(&caixa);

	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:

			comprar(estoque, &caixa);
			break;
		case 2:

			vender(estoque, &caixa, &lucro);
			break;
		case 3:

			imprime(estoque);
			break;
		case 4:

			system("cls || clear");
			financeiro(caixa, lucro);
			getchar();
			//system("pause");
			break;
		case 5:
			exit(0);
			break;
		}
	}
	return 0;
}
