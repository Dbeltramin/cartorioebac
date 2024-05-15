#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> // boblioteca responsável por cuidar das string
 
int registro() // Fnnção responsavel por cadastrar os usuários no sistema 
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string


	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário 
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
	
	
	printf("Digite o sobrenome a ser cadastrado:"); // mensagem para o usuário 
	scanf("%s", sobrenome); // salava a variavel sobrenome / armazena a informação inserida pelo usuário 
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,sobrenome);// salva a variavel
	fclose(file); //Fecha arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); // adiciona a virgula
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // mensagem usuário 
	scanf("%s", cargo); // salva a variavel cargo/ armazena a informação recebida 
	
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
    	printf("Não foi possivel abrir o arquivo, usuário não cadastrado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informaçãoes do usuário");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
    
}

int deletar()
{ // inicio de inserção das variaveis
	char cpf[40];
	
	    printf("Digite o CPF do usuário a ser deletado:");
	    scanf("%s" ,cpf);
	
	    remove(cpf);
	
	    FILE *file;
	    file = fopen(cpf , "r");
	
	if(file == NULL)
	{
		printf("Usuário deletado com sucesso!:\n");
	    printf("O usuário não se encontra no sistema!.\n");
	     
	    system("pause");
		 	
	}
} // fim da inserção



int main()
   {
   int opcao=0; //Definindo variáveis
   int laco=1;
   
   for(laco=1;laco=1;)
   {
   	
   	    system("cls"); //Responsavel por limpoar a tela
   	    


        setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
  
  
        printf("### Cartório da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("opcao: "); //Fim do menu
   
        scanf("%d", &opcao); //armazenando escolha do usuáro
   
        system("cls");
        
        
        switch(opcao) //inicio da seleção do menu 
        {
        	case 1:
            registro(); // chamada das funçãoes 
   	        break;
   	        
   	        case 2:
   	        consulta();
			break;
			
			case 3:
		    deletar();
			break;
			
			
			default:
			printf("Essa opcao não esta disponivel!\n");
   	        system("pause");
		    break;	
		}
        
   

   }
} 

