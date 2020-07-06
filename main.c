#include <stdio.h>
#include <stdlib.h>

int main()
{
   typedef struct {
        long  codigo;
        char  nome[100];
        float preco;
} Produto;

typedef struct {
        long numitem;
        long codigoprod;
        long qtd;
        float precototal;
}  Carrinho;

#define QUANTIDADE_DE_PRODUTOS 2

        Produto produtos[QUANTIDADE_DE_PRODUTOS];

        printf("Informe os produtos disponiveis contendo os seguintes campos: codigo-do-produto nome preco\n");
        for (int i = 0; i < QUANTIDADE_DE_PRODUTOS; i++)
	{
                printf("\nInforme os dados do produto(%i): ", i + 1);
                scanf("%ld %s %f", &produtos[i].codigo, produtos[i].nome, &produtos[i].preco);
        }

        for(int i = 0; i < QUANTIDADE_DE_PRODUTOS; i++)
	{
                printf("\n%ld\t%s\tR$ %1.2f", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
        }

	int qtd_carrin;
	printf("\nQuantos produtos diferentes deseja adicionar ao carrinho? ");
        scanf("%d", &qtd_carrin);
	Carrinho carrin[qtd_carrin];
	for (int i = 0; i < qtd_carrin; i++)
	{
		printf("\nInforme o %dº produto contendo os seguintes campos: codigo-do-produto quantidade\n", i + 1);
        	scanf("%ld %ld", &carrin[i].codigoprod, &carrin[i].qtd);
		carrin[i].numitem = i + 1;
		for (int j = 0; j < QUANTIDADE_DE_PRODUTOS; j++)
		{
			if (carrin[i].codigoprod == produtos[j].codigo)
			{
				carrin[i].precototal = carrin[i].qtd * produtos[j].preco;
				carrin[i].numitem = j;
				break;
			}
		}
	}

	float total_compra;
	printf("\n-- Totais do conteudo do carrinho --");
	printf("\n#\tcodigo-do-produto\tnome\tquantidade\tpreco unid.\ttotal");
        for (int i = 0; i < qtd_carrin; i++)
	{
		printf("\n%ld\t%ld\t%s\t%ld\tR$ %1.2f\tR$ %1.2f", carrin[i].numitem + 1, carrin[i].codigoprod, produtos[carrin[i].numitem].nome, carrin[i].qtd, produtos[carrin[i].numitem].preco, carrin[i].precototal);
		total_compra = total_compra + carrin[i].precototal;
        }
	printf("\nPreco total da compra: R$ %1.2f", total_compra);

        getchar();
        return 0;
}

