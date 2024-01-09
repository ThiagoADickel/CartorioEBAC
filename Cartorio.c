#include <stdio.h> //Biblioteca de comunica��o com o usuario
#include <stdlib.h>//Biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//Biblioteca de aloca��es de texto por regi�o
#include <string.h>//Biblioteca respons�vel por cuidar das strings

int registro()// Fun��o responsavel por cadastrar os usuarios no sistema
{
	//Inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings
	
	//Coletando informa��o do usu�rio
	printf("\nDigite o CPF a ser cadastrado: \n");
	printf("> ");
	scanf("%s", cpf);//%s refere-se a strings
	getchar();
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file;// Cria o arquivo
	file = fopen(arquivo, "w");// Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);// Salvo o valor da variavel
	fclose(file);// Fecha o arquivo
	
	file = fopen(arquivo, "a");// "a" atualiza o arquivo
	fprintf(file, ",");// Adiciona uma virgula
	fclose(file);// Fecha o arquivo
	
	printf("\nDigite o nome a ser cadastrado: \n");
	printf("> ");
	scanf("%s", nome);
	getchar();
	
	file= fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");// Atualiza o arquivo
	fprintf(file, ",");// Adiciona uma virgula
	fclose(file);// Fecha o arquivo
	
	printf("\nDigite o sobrenome a ser cadastrado: \n");
	printf("> ");
	scanf("%s",sobrenome);
	getchar();
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");// Atualiza o arquivo
	fprintf(file, ",");// Adiciona uma virgula
	fclose(file);// Fecha o arquivo
	
	printf("\nDigite o cargo a ser cadastrado: \n");
	printf("> ");
	scanf("%s",cargo);
	getchar();
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("\nDigite o CPF a ser consultado: \n");
	printf("> ");
	scanf("%s", cpf);
	getchar();
	
	FILE *file;
	file = fopen(cpf, "r");// O "r" l� o arquivo
	
	if(file == NULL)
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf(" %s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("\nDigite o CPF do usu�rio a ser deletado: \n");
	printf("> ");
	scanf("%s",cpf);
	getchar();
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!. \n");
		system("pause");
		
	}
	
	else
	{
		remove(cpf);
		printf("\nO usu�rio foi deletado com sucesso! \n");
		system("pause");
	}

	
}

int main()
{
	int opcao=0;//Definindo as variaveis 
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		system("cls");
		
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("\t[Cart�rio da EBAC]\n\n");//Inicio menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t[1] - Registrar nomes\n");
		printf("\t[2] - Consultar nomes\n");
		printf("\t[3] - Deletar nomes\n\n");
		printf("Op��o > ");//Fim do menu
	
		scanf("%d", &opcao);//Ler a op��o
		getchar();//Ler o enter
		
		system("cls");//Deletar as mensagens superiores 
		
		switch(opcao)//Inicio sele��o
		{
			case 1://Op��o escolhida
				registro();
				break;
				
			case 2://Op��o escolhida
				consulta();
				break;
				
			case 3://Op��o escolhida
				deletar();
				break;
				
			default://Op��o escolhida
				printf("\t\nEssa op��o n�o esta disponivel\n");
				system("pause");
				break;
		}//Fim da sele��o
	
		printf("\nEsse software pertence a ...\n");
	}
	
	
}

