typedef struct{
	char nome[100];
	char marca[100];
	char modelo[100];
	int ano;
	int km;
	int valor_compra;
	int valor_venda;
} automovel;

void caixa_inicial(int *c_init){
	system("cls || clear");
	printf("\n --Qual o valor inicial do caixa? \n");
	printf("\tValor: ");
	scanf("%d", c_init);
}

int menu(void)
{
	system("cls || clear");
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Comprar um automovel\n");
		printf("\t 2. Vender um automovel\n");
		printf("\t 3. Listar Estoque\n");
		printf("\t 4. Mostrar Financeiro\n");
		printf("\t 5. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 5);
	getchar();
	return c;
}

void ler_string(char palavra[100], int tamanho)
{
	int i = 0;
	char c;

	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';

	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}

}

void cria_lista(automovel *p)
{
	int i;
	for (i = 0; i < MAX; i++)
		p[i].nome[0] = '\0';
}

int livre(automovel p[100])
{
	int i;
	for (i = 0; p[i].nome[0] && i < MAX; i++) ;
	if (i == MAX)
		return -1;
	return i;
}


void imprime(automovel *p)
{
	system("cls || clear");
	int contador = 0;

for(int i = 0; i < MAX; i++){
	if (p[i].nome[0] != '\0'){
		printf("\n-- Registro %d\n", i);
		printf("\t Nome: %s", p[i].nome);
		printf("\t Marca: %s", p[i].marca);
		printf("\t Modelo: %s", p[i].modelo);
		printf("\t Ano: %d", p[i].ano);
		printf("\n");
		printf("\n");
		printf("\t Km: %d", p[i].km);
		printf("\t Valor da compra: %d", p[i].valor_compra);
		printf("\t Valor da venda: %d\n", p[i].valor_venda);
		printf("\n");
		contador ++;
	}
}
if(contador == 0) printf("\n -- ESTOQUE VAZIO -- \n");
  getchar();
	//system("pause");
}

void sugestao(automovel *p, int compra, int posicao){
	int venda = (compra * (1 + LUCROMIN)), escolha;
	printf("\n-- O valor minimo de venda para obter lucro e de R$ %d\n", venda);
	printf("\t(1) Manter esse valor.");
	printf("\t(2) Alterar o valor.\n");
	do{
		printf("\tDigite: ");
		scanf("%d", &escolha);
	if (escolha != 2 && escolha != 1) printf("Escolha uma opcao valida.\n");
	}while (escolha != 2 && escolha != 1);

	if(escolha == 1) p[posicao].valor_venda = venda;
	if (escolha == 2){
		printf("\n-- Novo valor: ");
		scanf("%d", &p[posicao].valor_venda);
	}
}


void comprar(automovel *p, int *caixa)
{
	system("cls || clear");

	int posicao;
	posicao = livre(p);
	if (posicao == -1) {
		printf("\nEstrutura Cheia!!");
		return;
	}


	printf("\n-- Registro %d\n", posicao);
	printf("\tNome do veiculo: ");
	ler_string(p[posicao].nome, MAX);
	printf("\tMarca: ");
	ler_string(p[posicao].marca, MAX);
	printf("\tModelo: ");
	ler_string(p[posicao].modelo, MAX);
	printf("\tAno do veiculo: ");
	scanf("%d", &p[posicao].ano);
	printf("\tKM do carro: ");
	scanf("%d", &p[posicao].km);
	printf("\tValor de compra: ");
	scanf("%d", &p[posicao].valor_compra);

	if (*caixa < p[posicao].valor_compra){

		printf("\n-- Impossivel completar a compra, saldo abaixo do valor do veiculo --\n");
		p[posicao].nome[0] = '\0';
		getchar();
	}else{
		*caixa = *caixa - p[posicao].valor_compra;
		sugestao(p, p[posicao].valor_compra, posicao);
	}

  getchar();
	//system("pause");
}


void vender(automovel *p, int *caixa, int *lucro)
{
	system("cls || clear");
	int posicao, escolha, novo_valor;

	printf("-- Digite o numero do registro: ");
	scanf("%d", &posicao);

	if(p[posicao].nome[0] != '\0'){
		printf("\n -- Vender o %s por R$ %d?\n", p[posicao].nome, p[posicao].valor_venda);
		printf(" (1) Vender.");
		printf("\t (2) Alterar valor.");
		do{

			printf("\n -- Digite: ");
			scanf("%d", &escolha);
			if(escolha != 1 && escolha != 2) printf("\n-- Escolha uma opcao valida");

		}while (escolha != 1 && escolha != 2);

	}else{
		printf("\n-- Nenhum automovel neste registro, verifique o estoque. --\n");
		getchar();
	}

	if (escolha == 1){
		p[posicao].nome[0] = '\0';
		*caixa = *caixa + (p[posicao].valor_venda);
		*lucro = *lucro + (p[posicao].valor_venda - p[posicao].valor_compra);
	}

	if(escolha == 2){
		printf("\n-- Digite o novo valor: ");
		scanf("%d", &novo_valor);
		p[posicao].nome[0] = '\0';
		*caixa = *caixa + novo_valor;
		*lucro = *lucro + (novo_valor - p[posicao].valor_compra);

	}


  getchar();
  //system("pause");
  //sleep(10);


}


void financeiro(int caixa, int lucro){
	system("cls || clear");

	printf("\n-- Dados financeiros:\n");
	printf("\n-- Saldo: R$ %d\n", caixa);
	printf("\n-- Lucro total: R$ %d\n", lucro);

  //getchar();
  //sleep(10);
  //system("pause");

}
