#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<cstdlib>
#include<stdlib.h>
char t;
int  matriz[100];
char nome [100][100], cep[100][100], cpf[100][100],email[100][100],tel[100][100];  //V�RIAVES GLOBAIS QUE DECLAREI POIS USO NAS FUN��ES E NO MAIN
FILE*pont_arq;
int i=0;


int menuopcao(){
int opcaomenu;
printf("-----------MENU-----------\n");
printf("\nESCOLHA UMA DAS OPCOES\n\n");
printf("[1] CADASTRAR CLIENTE\n");
printf("[2] CONSULTAR CADASTRO\n");
printf("[3] ALTERAR MEU CADASTRO\n");              //FUN��O PARA EXIBIR O MENU PRINCIPAL NO MAIN ONDE RETORNA UM VALOR QUE SERA LIDO NO MENU PRINCIPAL
printf("[4] EXCLUIR CADASTRO\n");
printf("[5] SAIR\n");
printf("\nOp��o escolhida: ");
scanf("%d",&opcaomenu);
return (opcaomenu);
}


void lercadastro(){
	fflush(stdin);
    system("cls");
    printf("-------PAINEL DE CADASTRO-------\n\n");
    printf("C�digo do cliente: %d", i);
	printf("\n\nDigite seu nome: ");
	fgets(nome[i], 100, stdin);
	fputs(nome[i],pont_arq);
	printf("\nDigite seu telefone: ");
	fgets(tel[i],100,stdin);
	fputs(tel[i],pont_arq);
	printf("\nDigite seu CPF: ");                            //FUN��O PARA LER O CADASTRO DOS CLIENTES (NO CASE 1)
	fgets(cpf[i],100,stdin);
	fputs(cpf[i],pont_arq);
	printf("\nDigite seu CEP: ");
	fgets(cep[i],100,stdin);
	fputs(cep[i],pont_arq);
	printf("\nDigite seu E-mail: ");
	fgets(email[i],100,stdin);
	fputs(email[i],pont_arq);
	
	fprintf(pont_arq,"\n %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",t,t,t,t,t,t,t,t,t,t,t,t,t,t,t);	
}

int mostrarcadastro(){
	system("cls");
	printf("Digite o c�digo do cliente para consulta: ");
	scanf("%d",&i);
	if(i==matriz[i] & matriz[i]!=0){
	system("cls");
	printf("DADOS DE CADASTRO\n\n");
	printf("NOME: %s",nome[i]);                   //FUN��O PARA EXIBIR O CADASTRO DO CLIENTE DESEJADO NA TELA (NO CASE 2)
	printf("TELEFONE: %s",tel[i]);
	printf("CPF: %s",cpf[i]);
	printf("CEP: %s",cep[i]);
	printf("E-MAIL: %s",email[i]);
	}
	else{
			printf("\nC�digo n�o cadastrado!!!\n");
	}
}


int menuopcaob(){
	int opcaomenuB;
	printf("ESCOLHA A OP��O QUE DESEJA ALTERAR\n\n");
	printf("[1] ALTERAR NOME\n");
	printf("[2] ALTERAR TELEFONE\n");
    printf("[3] ALTERAR CPF\n");
    printf("[4] ALTERAR CEP\n");               //FUN��O PARA EXIBIR O MENU DE ALTERA��O NO MAIN ONDE RETORNA UM VALOR QUE SERA LIDO NO CASE 3
    printf("[5] ALTERAR E-MAIL\n");
    printf("\nOp��o escolhida: ");
	
	scanf("%d",&opcaomenuB);
	return(opcaomenuB);
}
void excluir(){
	char excluir;
	system("cls");
	printf("------------EXCLUSAO DE CADASTRO-------------\n\n");
	printf("Digite o c�digo do cliente para ser exclu�do:  ");
	scanf("%d",&i);
	if(i==matriz[i] && matriz[i]!=0){
	printf("\n\n Tem certeza que deseja excluir?s/n\n");             //FUN��O PARA EXCLUIR O CADASTRO DESEJADO 
	if(excluir=='s'||excluir=='S'){
	scanf(" %c",&excluir);
	matriz[i]=0;
	printf("\n\nEXCLUS�O BEM SUCEDIDA!!!\n\n");			
	}
	}
	else{
		printf("\n\nC�DIGO N�O CADASTRADO\n\n");
	}
}


int main(){

setlocale(LC_ALL,"Portuguese");
char repeticao,repeticaob;              //v�riaveis que irei usar para fazer o la�o de repeti��o do menu principal e do menu de altera��o
int menu, opcaomenualt;                //v�riaveis que irei usar para atribuir o valor retornado das fun�oes de exibir o menu de altera��o e o principal

t='_';
do{
menu=menuopcao();
pont_arq=fopen("clientes.txt","a");


 switch (menu){
 	case 1:
 	i++;
 	matriz[i]=i;
 	lercadastro();
 	//chamado da fun��o ler cadastro para receber os dados digitados
 	
	fclose(pont_arq);
	
	// aqui foi aberto o arquivo para receber os valores digitados em uma arquivo txt
	// os valores de i ser�o gravados na variavel matriz, sempre adicionando mais um ao i onde sera utilizado como c�digo do cliente 
	break;
	
	case 2:
		//chamado da fun��o mostrar cadastro para exibir os dados digitados
	mostrarcadastro();
	break;	
	
	case 3:
	system("cls");
	do{
		opcaomenualt=menuopcaob();
	
	//para alterar o cadastro ele faz uma pergunta qual o codigo que deseja alterar e vai puxar os daods armazenados na matriz na posi��o i para fazer a altera��o corretamente o mesmo vale para o restante das fun��es do c�digo 
	
	switch (opcaomenualt){
		case 1:
		system("cls");
		printf("--------------ALTERA��O DE NOME---------------\n\n");
		printf("Digite o c�digo do cliente para ser alterado:  ");
		scanf("%d",&i);
		if(i==matriz[i] && matriz[i]!=0){
			fflush(stdin);
			printf("\nDigite o novo nome: ");
			fgets(nome[i],100,stdin);
			printf("\n\nALTERA��O BEM SUCEDIDA!!\n\n");
		}
		else{
		printf("\n\nc�digo inv�lido");
		}
		break;
		
		case 2:
		system("cls");
		printf("-----------------ALTERA��O DE TELEFONE------------------\n\n");
		printf("Digite o c�digo do cliente para ser alterado:  ");
		scanf("%d",&i);
		if(i==matriz[i] && matriz[i]!=0){
		fflush(stdin);
		printf("\nDigite o novo telefone: ");
		fgets(tel[i],100,stdin);
		printf("\n\nALTERA��O BEM SUCEDIDA!!\n\n");
		}
		else{
		printf("\n\nc�digo inv�lido");
		}
		break;
		
		case 3:
		system("cls");
		printf("------------------ALTERA��O DE CPF-------------------\n\n");
		printf("Digite o c�digo do cliente para ser alterado:  ");
		scanf("%d",&i);
		if(i==matriz[i] && matriz[i]!=0){
		fflush(stdin);
		printf("\nDigite o novo CPF: ");
		fgets(cpf[i],100,stdin);
		printf("\n\nALTERA��O BEM SUCEDIDA!!\n\n");
		}
		else{
		printf("\n\nc�digo inv�lido");
		}
		break;
		
		case 4:
		system("cls");
		printf("------------------ALTERA��O DE CEP--------------------\n\n");
		printf("Digite o c�digo do cliente para ser alterado:  ");
		scanf("%d",&i);
		if(i==matriz[i] && matriz[i]!=0){
		fflush(stdin);
		printf("\nDigite o novo CEP: ");
		fgets(cep[i],100,stdin);
		printf("\n\nALTERA��O BEM SUCEDIDA!!\n\n");
		}
		else{
		printf("\n\nc�digo inv�lido");
		}
		break;
		
		case 5:
		system("cls");
		printf("------------------ALTERA��O DE E-MAIL-------------------\n\n");
		printf("Digite o c�digo do cliente para ser alterado:  ");
		scanf("%d",&i);
		if(i==matriz[i] && matriz[i]!=0){
		fflush(stdin);
		printf("\nDigite o novo E-MAIL: ");
		fgets(email[i],100,stdin);
		printf("\n\nALTERA��O BEM SUCEDIDA!!\n\n");
		}
		else{
		printf("\n\nc�digo inv�lido");
		}
		break;
	
		
		default:
		printf("\nOp��o Inv�lida!!");
	}
	
	printf("\n\n\nDeseja voltar ao menu de altera��o? s/n\n");
	scanf(" %c",&repeticaob);
	system("cls");
	  //la�o de repeti��o do menu de altera��o
	}while(repeticaob=='s' || repeticaob=='S');
	break;
	case 4:
		//chamado da fun��o excluir para excluir o cadastro do cliente desejado
		excluir();

	break;
	
	default:
	printf("\nEscolha uma op��o v�lida\n");
 }

 printf("\nDESEJA VOLTAR AO MENU s/n\n");
 scanf(" %c",&repeticao);
 system("cls");
  //la�o de repeti��o pincipal
}while(repeticao=='S'|| repeticao=='s');
}
