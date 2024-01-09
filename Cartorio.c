#include <stdio.h> //Biblioteca de comunicação com o usuario
#include <stdlib.h>//Biblioteca de alocação de espaço em memoria
#include <locale.h>//Biblioteca de alocações de texto por região
#include <string.h>//Biblioteca responsável por cuidar das strings

int registro()// Função responsavel por cadastrar os usuarios no sistema
{
	//Inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings
	
	//Coletando informação do usuário
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
	file = fopen(cpf, "r");// O "r" lê o arquivo
	
	if(file == NULL)
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n");
		printf(" %s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("\nDigite o CPF do usuário a ser deletado: \n");
	printf("> ");
	scanf("%s",cpf);
	getchar();
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!. \n");
		system("pause");
		
	}
	
	else
	{
		remove(cpf);
		printf("\nO usuário foi deletado com sucesso! \n");
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
	
		printf("\t[Cartório da EBAC]\n\n");//Inicio menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t[1] - Registrar nomes\n");
		printf("\t[2] - Consultar nomes\n");
		printf("\t[3] - Deletar nomes\n\n");
		printf("Opção > ");//Fim do menu
	
		scanf("%d", &opcao);//Ler a opção
		getchar();//Ler o enter
		
		system("cls");//Deletar as mensagens superiores 
		
		switch(opcao)//Inicio seleção
		{
			case 1://Opção escolhida
				registro();
				break;
				
			case 2://Opção escolhida
				consulta();
				break;
				
			case 3://Opção escolhida
				deletar();
				break;
				
			default://Opção escolhida
				printf("\t\nEssa opção não esta disponivel\n");
				system("pause");
				break;
		}//Fim da seleção
	
		printf("\nEsse software pertence a ...\n");
	}
	
	
}

