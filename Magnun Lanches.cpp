#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <windows.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	printf("Olá, seja bem vindo. Tecle [ENTER] para começarmos\n");
	getchar();
	system("color 2f");
	
	int cod, qtd, novoPedido, novoLanche, codInvalido, qtdInvalida;
	char nome[20];
	float saldoDia=0, totalPedido;
	
	do{ // Estrutura de repetição para controlar a quantidade de pedidos em um determinado dia
	
	printf("=======================================================================================================================\n");	
		printf("\t\t\tMagnun Lanches\n\n");
		printf("\tNOVO PEDIDO\n\n");
		
		totalPedido=0; // Sempre que um novo pedido se inicia -> precisamos zerar o valor total do mesmo
		
		printf("Nome e sobrenome do cliente: ");
		scanf("%[^\n]c", nome); // Recebe uma string composta, ou seja, juntamente com espaço. Por exemplo: Daniel Brito
		printf("=======================================================================================================================\n");
		do{ // Laço de repetição para controlar os lanches desejados por um determinado cliente
			
			do{ // Laço de repetição para verificar uma possível entrada inválida referente ao código do lanche

                printf("\n\tTABELA DE PRECOS\n\n");
                printf("Codigo   Lanche             Preco\n");
                printf("1        X-Salada           20,00\n");
                printf("2        Cheddar Cream      22,50\n");
                printf("3        Chicken Barbecue   24,00\n");
                printf("4        London Melt        33,50\n");
                printf("5        American Crispy    33,00\n\n");
				
				printf("Codigo do lanche: ");
				scanf("%d", &cod);
				printf("=======================================================================================================================\n");
				
				if(cod!=1 && cod!=2 && cod!=3 && cod!=4 && cod!=5){
					
					codInvalido = 1;
					printf("\nCodigo invalido!\n\n");
				}
				else{
					
					codInvalido = 0;
				}
				
			}while(codInvalido==1);
			
			do{ // Estrutura de repetição para verificar uma possível entrada inválida referente à quantidade

				printf("Digite a quantidade: ");
				scanf("%i", &qtd);
				
				if(qtd<1){
					
					qtdInvalida = 1;
					printf("\nQuantidade invalida!\n\n");
				}
				else{
					
					qtdInvalida = 0;
				}
				
			}while(qtdInvalida==1);

            // Indexando o código do pedido do cliente para realizar o cálculo do total baseado na tabela de preços:
						
			switch(cod){
				
				case 1: totalPedido = totalPedido + (20.00*qtd);
				 break;
				case 2: totalPedido = totalPedido + (22.50*qtd); 
				 break;
				case 3: totalPedido = totalPedido + (24.00*qtd); 
				 break;
				case 4: totalPedido = totalPedido + (33.50*qtd); 
				 break;
				case 5: totalPedido = totalPedido + (33.00*qtd);
				 break;
			}
			
			printf("\n");
			
			do{ // Laço de repetição para controlar a quantidade de diferentes lanches que um cliente pode pedir
				
				printf("Deseja pedir outro lanche?\n");
				printf("1 - Sim\n");
				printf("0 - Nao\n\n");
				
				printf("Opcao: ");
				scanf("%i", &novoLanche);
				
				if(novoLanche!=0 && novoLanche!=1){
					
					printf("\nOpcao invalida!\n\n");
				}
				
			}while(novoLanche!=0 && novoLanche!=1);

			printf("\n");
			
		}while(novoLanche==1);

        // Exibição do recibo de um determinado cliente após ele fechar sua conta, ou seja, não desejar mais nenhum lanche:
		
		printf("RECIBO\n");
		printf("Nome do cliente: %c\n", nome);
		printf("Total a pagar: R$ %.2f\n", totalPedido);
		
		saldoDia += totalPedido; // Adicionando o valor total de cada pedido ao saldo do dia
		
		printf("\n");

		do{ // Estrutura de repetição para verificar se o administrador deseja atender outro cliente ou sair do sistema
			
			printf("O que deseja fazer?\n");
			printf("1 - Atender novo cliente\n");
			printf("0 - Sair do sistema\n\n");
			
			printf("Opcao: ");
			scanf("%d", &novoPedido);
			
			if(novoPedido!=0 && novoPedido!=1){
				
				printf("\nOpcao invalida!\n\n");
			}
			
		}while(novoPedido!=0 && novoPedido!=1);
		
		printf("\n");
		
	}while(novoPedido==1);
	
	printf("SALDO DO DIA:\nR$ %.2f\n", saldoDia); // Exibição do somatório de todos os pedidos realizados no dia
		
}
