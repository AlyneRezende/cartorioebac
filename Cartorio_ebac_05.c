#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

// \n � para saltar linhas
// \t funciona como espa�amento no �nicio do texto
// = atribui��o e == compara��o != diferen�a

int registrar() // n�o tem ; porque � uma fun��o.
{
	//inicio de cria��o das vari�veis/string (string � um conjunto de v�riavel)
	char arquivo[40];
	char cpf[40]; // char tipo string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); // salvar dentro da string - %s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string, ou seja, ta criando o nome do arquivo igual ao cpf
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // abre a vari�vel arquivo e escreva (w, write) o que tem l�
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo j� existente e salva (a, append) mais dados dentro do mesmo arquivo
	fprintf(file,"-");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // abre o arquivo j� existente e salva (a, append) mais dados dentro do mesmo arquivo
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // abre o arquivo j� existente e salva (a, append) mais dados dentro do mesmo arquivo
	fprintf(file,"-");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf); // salvar dentro da variavel cpf
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}


int main()
{
	int opcao=0;  // = atribuido
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t### Cart�rio da EBAC ###\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese");
	
			printf("\t### Cart�rio da EBAC ###\n\n"); // in�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 -  Registrar nomes\n");
			printf("\t2 -  Consultar nomes\n");
			printf("\t3 -  Deletar nomes\n");
			printf("\t4 -  Sair do sistema\n\n");
			printf("Op��o:"); // fim do menu
	
			scanf("%d", &opcao); // %d armazenar a vari�vel tipo inteiro (armazenando a escolha do usu�rio)
	
			system("cls"); // fun��o de deletar as mensagens anteriores
		
			switch(opcao) // inicio da selecao do menu
			{
				case 1:
					registrar(); // chamada de fun��es
					break;
				
				case 2:
					consultar();
					break;
				
				case 3:
					deletar();
					break;
					
				case 4:
					printf("Obrigado por utilizar o sistema!\n\n");
					return 0;
					break;
			
				default:
					printf("Essa op��o n�o est� dispon�vel!\n\n");
					system("pause");
					break;
					// fim da sele��o
		
			}
		}
	}
	
	else
		printf("\nSenha incorreta!\n\n");
		printf("Esse software � de livre uso dos alunos\n");
	
}
