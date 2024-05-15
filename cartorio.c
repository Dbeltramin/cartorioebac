#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> // boblioteca respons�vel por cuidar das string
 
int registro() // Fnn��o responsavel por cadastrar os usu�rios no sistema 
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string


	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio 
	scanf("%s" , cpf); //%s usado pra salvar string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria arquivo 
	file = fopen(arquivo, "w"); // cria arquivo "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" adcionando novos dados, atualiza arquivo exitente
	fprintf(file,","); //Adiciona virgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // abri arquivo e atualiza 
	fprintf(file,nome); // salva a variavel nome no arquivo 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado:"); // mensagem para o usu�rio 
	scanf("%s", sobrenome); // salava a variavel sobrenome / armazena a informa��o inserida pelo usu�rio 
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,sobrenome);// salva a variavel
	fclose(file); //Fecha arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); // adiciona a virgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // mensagem usu�rio 
	scanf("%s", cargo); // salva a variavel cargo/ armazena a informa��o recebida 
	
	file = fopen(arquivo, "a"); // abre arquivo
	fprintf(file,cargo); // salva a variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	system("pause");
	
	
	
}

int consulta() 
{
    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    char *tokem;
    
    printf("Digite o cpf a ser consultado:");
    scanf("%s" ,cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file ==NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, usu�rio n�o cadastrado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��oes do usu�rio");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
    
}

int deletar()
{ // inicio de inser��o das variaveis
	char cpf[40];
	
	    printf("Digite o CPF do usu�rio a ser deletado:");
	    scanf("%s" ,cpf);
	
	    remove(cpf);
	
	    FILE *file;
	    file = fopen(cpf , "r");
	
	if(file == NULL)
	{
		printf("Usu�rio deletado com sucesso!:\n");
	    printf("O usu�rio n�o se encontra no sistema!.\n");
	     
	    system("pause");
		 	
	}
} // fim da inser��o



int main()
   {
   int opcao=0; //Definindo vari�veis
   int laco=1;
   
   for(laco=1;laco=1;)
   {
   	
   	    system("cls"); //Responsavel por limpoar a tela
   	    


        setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
  
  
        printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("opcao: "); //Fim do menu
   
        scanf("%d", &opcao); //armazenando escolha do usu�ro
   
        system("cls");
        
        
        switch(opcao) //inicio da sele��o do menu 
        {
        	case 1:
            registro(); // chamada das fun��oes 
   	        break;
   	        
   	        case 2:
   	        consulta();
			break;
			
			case 3:
		    deletar();
			break;
			
			
			default:
			printf("Essa opcao n�o esta disponivel!\n");
   	        system("pause");
		    break;	
		}
        
   

   }
} 

