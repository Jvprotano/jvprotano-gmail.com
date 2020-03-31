#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tipoElemento
{
	int valor;
	struct tipoElemento *proximo;
}TElemento;

typedef struct tipoLista
{
	TElemento *inicio;
	TElemento *fim;
}TLista;

void inicializar(TLista tabela[])
{
	int i;
	for (i=0; i<10; i++)
	{
		tabela[i].inicio = NULL;
		tabela[i].fim = NULL;
	}
}

int hash (int valor)
{
	int indice;
	indice = valor % 10;
	return indice;
}

void inserir (TLista tabela[])
{
	int x,valor;
	 srand(time(NULL));
	printf("\n Valores para armazenar na tabela: ");
 	for(x=0; x<10;x++)
 	{
 		 
    valor = rand()%100;

	
	
	int indice;
	indice = hash(valor);
	
	TElemento *novo;
	novo = new TElemento;
	
	novo->valor = valor;
	novo->proximo = NULL;
	
	//if (p->inicio == NULL)
	//{
	//	p->inicio = novo;
	//	p->fim = novo;
	//}
	
	if (tabela[indice].inicio == NULL)
	{
		tabela[indice].inicio = novo;
		tabela[indice].fim = novo;
	}
	else
	{
		tabela[indice].fim->proximo = novo;
		tabela[indice].fim = novo;
	}
	}
}

void apresentar (TLista tabela[])
{
	float ocupacao;
	int i;
	int vazio=0;
	for (i=0; i<10; i++)
	{
		
		if (tabela[i].inicio != NULL)
		{
			printf("\n Indice [%d]: ", i);
			TElemento *aux = tabela[i].inicio;
			while (aux != NULL)
			{
				printf("%d //", aux->valor);
				aux = aux->proximo;
			}
		}
		else
		{
			printf("\n Indice: %d: //", i);
		}
		if(tabela[i].inicio== NULL)
		{
			vazio++;
		
		}
	
	}
	printf("\n Numero de vazios: %d",vazio);
			ocupacao=(float)vazio /10*100;
		 
				printf("\n Taxa de ocupacao: %.2f%%",ocupacao);
}

int verificarValorNaTabela(TLista tabela[], int valorPesquisado)
{
	int indice;
	indice = hash(valorPesquisado);
	
	TElemento *aux;
	aux = tabela[indice].inicio;
	while (aux != NULL)
	{
		if (aux->valor == valorPesquisado)
		{
			return 1;
		}
		else
		{
			aux = aux->proximo;
		}
	}
	return 0;
}

void consultar (TLista tabela[])
{
	int valorPesquisado;
	
	printf("\n Informe valor para busca: ");
	scanf("%d", &valorPesquisado);
	
	if (verificarValorNaTabela(tabela, valorPesquisado) == 1)
	{
		printf("\n Valor Encontrado!");
	}
	else
	{
		printf("\n Valor nao Encontrado!");
	}
}

int main()
{
	int opcao;
	
	TLista tabelaHashing[10];
	
	inicializar(tabelaHashing);
	
	do
	{
		printf("\n 1 - Inserir");
		printf("\n 2 - Consultar");
		printf("\n 3 - Apresentar");
		printf("\n 0 - Sair");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 1: inserir(tabelaHashing); break;
			case 2: consultar(tabelaHashing); break;
			case 3: apresentar(tabelaHashing); break;
		}
	}while (opcao != 0);
}