//augusto viniucius 12181500756 
//Christian Ferreira Bechi


//constantes
#define VET 6
#define POS 50


//bibliotecas
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include "christian.h"
#include<time.h>
#include "Load.h"
#include<dirent.h>

//cabeçalho de funçoes 
void relatorio2();
void relatorio();
void cadastro();
void auxilio(char tipo[3],char enunciado[50],char erro[100], char vetor[20], int vetorI[],float preco[],int flag);
void consulta();
void compras();
void submenus();
void SSMenu();
void consultar();
void Listar();
void tabulacao(char *descricao,int qtd,char *precoC);
char *verificando(char *valor, int fl);
void alteracao();
void exclusao();
void infor();
void SobreProg();
void LogDoProg();
void LogMenu();
void ExcluirLog();
void MostrarLog(char *arquivo);

//vetores e variaveis globais
 int codigoprod[VET] = {0,0}, qtd[VET] = {0,0}, qtdmin[VET] = {0,0};
 float precototal[VET],precounitario[VET] = {0,0};
 char descricao[VET][POS],precoChar[VET][POS],carregado='n';
 int cod=1;
 int fl=1;
 
 
main(){
	system("title Genrenciamento");
	//Load do programa
	if(carregado == 'n'){
		HANDLE had;
		DWORD algo;
		had = CreateThread(NULL,0,hora,NULL,0,&algo);
		LogAcesso();
		Loading();
		carregado = 's';
	}
	
	//decleraçao de variaveies
	int escolha=0;
	char esc='f';
	DWORD Refresh;
	//inicio do programa
	system("color a");
	system("mode 25,20");
	setlocale(LC_ALL,"portuguese");
	do{
		OC=1;
		esc = ' ';
		system("cls");
		printf(" =======================\n ");
		printf("|         MENU        |\n ");
		printf("=======================\n ");
	    printf("|  [1]-CADASTRO       |\n -----------------------  |  [2]-CONSULTA       |  -----------------------  |  [3]-ALTERAÇÃO      |  -----------------------  |  [4]-EXCLUSÃO       |  -----------------------  |  [5]-RELATORIO      |  -----------------------  |  [6]-INFORMAÇÕES    |  -----------------------  |  [7]-SAIR           |");
		printf("\n -----------------------\n");
		CreateThread(NULL,0,HoraRefresh,NULL,0,&Refresh);
		Sleep(705);
		gotoxy(18,0);
		printf("=========================");
	    printf("=> "); fflush(stdin); scanf("%d",&escolha);
	    OC=0;
	    Sleep(400);
	    switch(escolha){
	    	case 1:
				cadastro();
	    		break;
	    	case 2:
	    		SSMenu();
				break;
	    	case 3:
	    		alteracao();
				break;
	    	case 4:
	    		exclusao();
				break;
	    	case 5:
	    		int esco;
	    		system("cls");
	    		printf(" =======================\n");
				printf(" |      Relatórios     |\n ");
				printf("=======================\n ");
	    		printf("| [1] - Estoque       |\n -----------------------  | [2] - Saldo Estoque |  -----------------------  | [3] - Voltar        |");
	    		printf("\n -----------------------\n\n\n\n\n\n\n\n\n\n");
				printf("=========================");
				printf("=> "); fflush(stdin); scanf("%d",&esco);
				switch(esco){
					case 1:
						relatorio2();
						break;
					case 2:
						relatorio();
						break;
					case 3:
						main();
						break;
					default:
						MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
						submenus();
						break;
				}
				relatorio();
				break;
	    	case 6:
	    		infor();
				break;
			case 7:
	    		exit(0);
				break;
			default:
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
		}
	}while(esc!='s');
}

	int procura(char *compras){
	int n=0,cont=1,flag=0;
	n = atoi(compras);
	if(n==0){
		while(descricao[cont][0] != '\0'){
			if(strcmp(descricao[cont],compras)==0){
				return cont;
			}
			cont++;	
		}
		if(flag == 0){
			MessageBoxA(0,"Não foi possivel localizar esse produto!","Ops",0x30L);
		}
	}else{
		cont = atoi(compras);
		for(int c=1;c <= cod-1;c++){
			if(codigoprod[c] == cont){
				return c;
			}
		}			
		if(flag==0){
			MessageBoxA(0,"Não foi possivel localizar esse produto!","Ops",0x30L);
		}
	}
	return 0;
}

void alteracao(){
	char auxiliar[POS],desc[POS],conti; 
	int flag,esc,qtds,dec;
	float precou;
	do{
		system("mode 59,20");
		do{
			system("cls");
			printf(" =========================================================\n ");
			printf("|                        ALTERAÇÃO                      |\n ");
			printf("=========================================================\n\n ");
			printf("Entre com Codigo/Nome do Produto: "); fflush(stdin); gets(auxiliar);
			if(strcmp(auxiliar,"principal")==0){
				main();	
			}
			flag = procura(auxiliar);
		}while(flag==0);
		printf(" ---------------------------------- \n |  [1]-Descrição: %s      \n ---------------------------------- \n |  [2]-Quantidade: %d        \n ----------------------------------  \n |  [3]-Quantidade Minima: %d       \n ---------------------------------- \n |  [4]-Preço Unitario: %s        \n ---------------------------------- \n |  [5]-Voltar ao menu principal  | \n ----------------------------------  ",descricao[flag],qtd[flag],qtdmin[flag],precoChar[flag]);
	    gotoxy(6,34);printf("|");gotoxy(8,34);printf("|");gotoxy(10,34);printf("|");gotoxy(12,34);printf("|");
		printf("\n\n\n\n\nQual das Especificações Deseja alterar: \n"); 
		printf("===========================================================\n");
		do{
			printf("=> ");
			fflush(stdin);
			scanf("%d",&esc);
			if(esc != 1 && esc != 2 && esc != 3 && esc != 4 && esc != 5)MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
		}while(esc != 1 && esc != 2 && esc != 3 && esc != 4 && esc != 5);
		system("mode 59,18");
	    switch(esc){
	    	case 1:
		    		system("cls");
		    		printf(" =========================================================\n ");
					printf("|                  ALTERAÇÃO DESCRIÇÃO                  |\n ");
					printf("=========================================================\n ");
		    	    printf("\n Deseja alterar a descrição %s para: ",descricao[flag]); fflush(stdin); scanf("%s",&desc);
		    	    printf("\n===========================================================\n\n");
		    	    char mensaD[POS];
		    	    strcpy(mensaD,concastD((char*)"Deseja realmente alterar @ por @",descricao[flag],desc));
		    	    dec = MessageBox(0,mensaD,"Aviso",0x30L | 0x4L);
		    	    if(dec == 6 || dec == 6){
		    	    	LogModificacao("",descricao[flag],desc,'c');
		    	    	strcpy (descricao[flag],desc);
					}
    		break;
    	case 2:
        	system("cls");
		    		printf(" =========================================================\n ");
					printf("|                  ALTERAÇÃO QUANTIDADE                 |\n ");
					printf("=========================================================\n\n");
		    	    printf(" Deseja alterar a quantidade %d para: ",qtd[flag]); 
					while((scanf("%d",&qtds))<=0 || qtds<=0){
						MessageBoxA(0,"VALOR INVALIDO!!","ERROR",0x10);
						printf(" Deseja alterar a quantidade %d para: ",qtd[flag]);	
						fflush(stdin);	
					}
		    	    printf("\n===========================================================\n\n");
		    	    char mensaI[POS];
		    	    strcpy(mensaI,concastI((char*)"Deseja realmente alterar @ por @",qtd[flag],qtds));
		    	    dec = MessageBox(0,mensaI,"Aviso",0x30L | 0x4L);
		    	    if(dec == 6 || dec == 6){
		    	    	char qtd1[10],qtd2[10];
		    	    	itoa(qtd[flag],qtd1,10);
		    	    	itoa(qtds,qtd2,10);
						LogModificacao(descricao[flag],qtd1,qtd2,'m');
		    	    	qtd[flag] = qtds;
					}
					if(qtds<qtdmin[flag]) {
							int SN = MessageBoxA(0,"A QUANTIDADE NO ESTOQUE FICOU ABAIXO DO MINIMO               ESTIPULADO. DESEJA COMPRAR MAIS PRODUTOS?","ERROR",0x4L | 0x40L);
							if(SN== 6)compras();	
							SN = 0;
						}
			break;
    	case 3:
    		system("cls");
		    		printf(" =========================================================\n ");
					printf("|              ALTERAÇÃO QUANTIDADE MINIMA              |\n ");
					printf("=========================================================\n\n ");
		    	    printf("Deseja alterar quantidade minima %d para: ",qtdmin[flag]);
		    	    while((scanf("%d",&qtds))<=0 || qtds<=0){
						MessageBoxA(0,"VALOR INVALIDO!!","ERROR",0x10);
						printf(" Deseja alterar quantidade minima %d para: ",qtdmin[flag]);
						fflush(stdin);	
					}
					printf("\n===========================================================\n\n");
		    	    char mensaM[POS];
		    	    strcpy(mensaM,concastM((char*)"Deseja realmente alterar @ por @",qtdmin[flag],qtds));
		    	    dec = MessageBox(0,mensaM,"Aviso",0x30L | 0x4L);
			    	if(dec == 6 || dec == 6){
		    	    	char qtd1[10],qtd2[10];
		    	    	itoa(qtdmin[flag],qtd1,10);
		    	    	itoa(qtds,qtd2,10);
		    	    	qtdmin[flag] = qtds;
		    	    	LogModificacao(descricao[flag],qtd1,qtd2,'i');
		    	    	if(qtds>qtd[flag]) {
							int SN = MessageBoxA(0,"A QUANTIDADE NO ESTOQUE FICOU ABAIXO DO MINIMO               ESTIPULADO. DESEJA COMPRAR MAIS PRODUTOS?","ERROR",0x4L | 0x40L);
							if(SN== 6)compras();	
							SN = 0;
						}
					}
			break;
    	case 4:
    		system("cls");
		    		printf(" =========================================================\n ");
					printf("|                   ALTERAÇÃO DO PREÇO                  |\n ");
					printf("=========================================================\n\n ");
		    	    printf("Deseja alterar preço %s para: ",precoChar[flag]);
		    	    while((scanf("%f",&precou))<=0 || precou<=0){
						MessageBoxA(0,"VALOR INVALIDO!!","ERROR",0x10);
						printf(" Deseja alterar preço %s para: ",precoChar[flag]);
						fflush(stdin);	
					}
		    	    printf("\n===========================================================\n\n");
		    	    char mensaF[POS];
		    	    strcpy(mensaF,concastF((char*)"Deseja realmente alterar @ por @",atof(precoChar[flag]),precou));
		    	    dec = MessageBox(0,mensaF,"Aviso",0x30L | 0x4L);
		    	    if(dec == 6 || dec == 6){
		    	    	char qtd1[10],qtd2[10];
		    	    	sprintf(qtd2,"%.2f",precou);		    	    	
		    	    	LogModificacao(descricao[flag],precoChar[flag],qtd2,'f');
		    	    	sprintf(precoChar[flag],"%.2f",precou);
					}
			break;
		case 5:
			main();
			break;
		default:
			MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
			alteracao();
	}
	if(dec == 6){
		printf(" *********************************************************\n "); Sleep(250);
    	printf("*           ____      ____ ____ ____ ____ ____          *\n"); Sleep(250);
    	printf(" *           |___ |  | |    |__  |___ |___ |  |          *\n"); Sleep(250);
    	printf(" *           ___| |__| |___ |___ ___| ___| |__|          *\n"); Sleep(250);
    	printf(" *                                                       *\n "); Sleep(250);
    	printf("*********************************************************\n "); Sleep(250);
	}else{
		printf(" *********************************************************\n "); Sleep(250);
    	printf("*      ____  __  _  _ ____ ____      __  ___  ____      *\n"); Sleep(250);
    	printf(" *      |    |__| |\\ | |    |__  |   |__| |  \\ |  |      *\n"); Sleep(250);
    	printf(" *      |___ |  | | \\| |___ |___ |__ |  | |__/ |__|      *\n"); Sleep(250);
    	printf(" *                                                       *\n "); Sleep(250);
    	printf("*********************************************************\n "); Sleep(250);
	}
	printf("\nDeseja Continuar Alterando [S/N]: "); fflush(stdin);
	printf("\n===========================================================");
	
		do{
			printf("=> ");
			fflush(stdin);
			conti = getchar();
			if(conti != 's' && conti != 'S' && conti != 'n' && conti != 'N')MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);;
		}while(conti != 's' && conti != 'S' && conti != 'n' && conti != 'N');
	}while(conti == 's' || conti == 'S');
	dec=0;
	main();
}

void submenus(){
	system("mode 25,20");
	int escolha=0;
    system("cls");
    printf(" =======================\n");
	printf(" |    Compras/Vendas   |\n ");
	printf("=======================\n ");
    printf("|  [1] - Compras      |\n -----------------------  |  [2] - Vendas       |  -----------------------  |  [3] - Voltar       |");
    printf("\n -----------------------\n\n\n\n\n\n\n\n\n\n");
	printf("=========================");
	printf("=> "); fflush(stdin); scanf("%d",&escolha);
	switch(escolha){
		case 1:
			compras();
			break;
		case 2:
			consulta();
			break;
		case 3:
			SSMenu();
			break;
		default:
			MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
			submenus();
			break;
	}
	
}

void SSMenu(){
	system("mode 25,20");
	int escolha=0;
    system("cls");
    printf(" =======================\n");
	printf(" |       Consulta      |\n ");
	printf("=======================\n ");
    printf("| [1]-Compras/Vendas  |\n -----------------------  | [2]-Consulta        |  -----------------------  | [3]-Voltar          |");
    printf("\n -----------------------\n\n\n\n\n\n\n\n\n\n");
	printf("=========================");
	printf("=> "); fflush(stdin); scanf("%d",&escolha);
	switch(escolha){
		case 1:
			submenus();
			break;
		case 2:
			Listar();
			break;
		case 3:
			main();
			break;
		default:
			MessageBoxA(0,"CARACTER !!","ERROR",0x10);
			SSMenu();
			break;
	}
}


void compras(){
	char compras[VET],qtd1[POS];
	int flag=0,aux_qtd=0;
	system("mode 49,8");
	do{
		system("cls");
		printf(" ===============================================\n ");
		printf("|                    COMPRAS                  | ");
		printf(" ===============================================\n\n ");
		printf("Entre com Codigo/Nome do Produto: "); fflush(stdin); gets(compras);
		if(strcmp(compras,"principal")==0){
			main();	
		}else if(strcmp(compras,"volta")==0){
			SSMenu();
		}
		flag = procura(compras);
	}while(flag==0);
	printf(" -----------------------------------------------\n");
	do{
		printf(" Quanto deseja adicionar ao estoque: ");
		while((scanf("%d",&aux_qtd))<=0 || aux_qtd<=0){
			MessageBoxA(0,"VALOR INVALIDO!!","ERROR",0x10);
			printf(" Quanto deseja adicionar ao estoque: ");
			fflush(stdin);	
		}
		char cartman[10];
		LogCompras(descricao[flag],qtd[flag],aux_qtd);
		qtd[flag] += aux_qtd;	
		strcpy(qtd1,concast((char*)"Você adquiriu @ novos(as) ",aux_qtd,0));
		strcat(qtd1,descricao[flag]);
		strcat(qtd1,"\n        Seu novo Saldo é de @");
		strcpy(qtd1,concastI(qtd1,qtd[flag],0));
		MessageBoxA(0,qtd1,"Sucesso",0x40);
		SSMenu();
	}while(1);
	printf(" --------------------------------------- ");
}

void consulta(){
	system("mode 49,8");
    char auxiliar[VET];
    int aux_qtd,flag=0;
    char achei='n';
    char qtd1[100];
    do{
		system("cls");
		printf(" ===============================================\n ");
    	printf("|                    Vendas                   |\n ");
    	printf("===============================================\n\n");
		printf(" Entre com Codigo/Nome do Produto: "); fflush(stdin); gets(auxiliar);
		if(strcmp(auxiliar,"principal")==0){
			main();	
		}else if(strcmp(auxiliar,"volta")==0){
			SSMenu();
		}
		flag = procura(auxiliar);
	}while(flag==0);
	printf(" -----------------------------------------------\n");
	printf(" Entre Com a Quantidade De Produtos: ");
	while((scanf(" %d",&aux_qtd))<=0){
		fflush(stdin);
		printf(" Entre Com a Quantidade De Produtos: "); 
		MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
	}
	printf(" -----------------------------------------------\n");
	               
	if(aux_qtd <= 0)MessageBoxA(0,"Não pode colocar valores nulos (0)","ERROR",0x10L);
	else if(qtd[flag]<aux_qtd) {
			MessageBoxA(0,"QUANTIDADE INVALIDA!!  QUANTIDADE SUPERIOR AO ESTOQUE","ERROR",0x10);
			consulta();
	    }else{
	    	LogVendas(descricao[flag],qtd[flag],aux_qtd,aux_qtd*atof(precoChar[flag]));
	       	qtd[flag] -=aux_qtd;
			precototal[flag] += precounitario[flag]*aux_qtd;
			if(qtdmin[flag]>qtd[flag]) {
				strcpy(qtd1,concast((char*)" A SUA COMPRA FOI REALIZADA COM SUCESSO!!\nQUANTIDADE ADQUIRIDA @, VALOR FINAL R$@",aux_qtd,aux_qtd*atof(precoChar[flag])));
				MessageBoxA(0,qtd1,"SUCESSO",0x40L);
				int SN = MessageBoxA(0,"O ESTOQUE ULTRAPASSOU O LIMITE MINIMO ESTIPULADO! \n DESEJA COMPRAR MAIS PRODUTOS?","ERROR",0x4L | 0x40L);
				if(SN== 6)compras();	
				SN = 0;
			}else if(aux_qtd > 0){
				strcpy(qtd1,concast((char*)" A SUA COMPRA FOI REALIZADA COM SUCESSO!!\nQUANTIDADE ADQUIRIDA @, VALOR FINAL R$@",aux_qtd,aux_qtd*atof(precoChar[flag])));
				MessageBoxA(0,qtd1,"SUCESSO",0x40L);	
			}
		}
	SSMenu();	
}


void auxilio(char tipo[3],char enunciado[50],char erro[100], char vetor[20], int vetorI[],float preco[],int flag){
	if(strcmp("%s",tipo)==0){
		int fg;
		do{
			fg=0;
			printf("%s %d: ",enunciado,cod); fflush(stdin); gets(vetor);
			if(strcmp(vetor,"principal")==0){
				main();
			}
			if(vetor[0] == '\0'){
					MessageBoxA(0,erro,"ERROR",0x10L);
					cadastro();
			}else{if(vetor[0] > 96 && vetor[0] < 123); else if(vetor[0] > 64 && vetor[0] < 91);else{MessageBoxA(0,"O primeiro caractere não pode ser numero, nem caractere especial","Aviso",0x40);cadastro();}}
		}while(vetor[0] == '\0');
	}else if(strcmp("%d",tipo)==0){
		do{
			printf(" %s ",enunciado,cod); fflush(stdin); scanf(tipo,&vetorI[cod]);
			if(vetorI[cod]==0 || vetorI[cod] <= flag){
					MessageBoxA(0,erro,"ERROR",0x10);
			}
		}while(vetorI[cod] <= flag);
	}else{
		char aux[20];
		float dinheiro;
		do{
			printf(" %s ",enunciado,cod); fflush(stdin); scanf("%s",&aux);
			dinheiro = atof(aux);
			if(dinheiro==0 || dinheiro <= flag){
					MessageBoxA(0,erro,"ERROR",0x10);
			}
		}while(dinheiro <= flag);
		dinheiro = atof(consultaPreco(aux));
		preco[cod] = dinheiro;
		char auxilio[POS];
		strcpy(auxilio,consultaPreco(aux));
		strcpy(precoChar[flag],verificando(auxilio,cod));		
	}
}

char *verificando(char *valor,int fl){
	int cont=0,flag=0,flag2=0,decisao=0;
	char aux[10];
	strcpy(precoChar[fl],valor);
	while(precoChar[fl][cont] != '\0'){
		if(precoChar[fl][cont] == ',')flag++;
		cont++;
	}
	if(flag == 0){
		strcat(precoChar[fl],",00");
	}
	cont=0;
	if(flag != 0){
		while(precoChar[fl][cont]!='\0'){
			if(precoChar[fl][cont] == ',' || flag2!=0){
				flag2++;
			}
			if(flag2 > 3){
				precoChar[fl][cont] = '\0';	
			}
			cont++;
		}
	}
	return precoChar[fl];
}

void cadastro(){
    //variavel local
	char deseja;
	system("mode 41,18");
	do{
		system("cls");
		if(fl != 7)
					fl = MessageBoxA(0,"Caso não queira cadastrar um produto, no rotulo \"nome do produto\" digite \"principal\" e aperte <ENTER>, voce voltará ao menu principal. \n\n  OBS: para não visualizar mais esssa janela, clique em não.","AVISO",0x4L | 0x40);
	// Titulo
   	    printf(" =======================================\n ");
		printf("|               CADASTRO              |\n ");
		printf("=======================================\n\n ");
	// função que faz as devidas verificações. Exemplo se o numero é negativo ou nulo.
    //parametros - tipo da variavel, rotulo a se escrever na tela, mensagem de erro, vetor de string, vetor de inteiro, vetor float, flag para fazer comparação entre qtd minima e atual
		auxilio((char*)"%s",(char*)"Nome do produto",(char*)"Não é permitido deixar o nome do produto em branco!",descricao[cod],0,0,0);
		puts(" ---------------------------------------");
		auxilio((char*)"%d",(char*)"quantidade minima:",(char*)"A quantidade minima não pode ser menor ou igual a 0",(char*)"",qtdmin,0,0);
		puts(" ---------------------------------------");	
		auxilio((char*)"%d",(char*)"quantidade:",(char*)"A quantidade não pode ser menor ou igual a zero, nem menor que ou igual ao minimo!",(char*)"",qtd,0,qtdmin[cod]-1);
		puts(" ---------------------------------------");
		auxilio((char*)"%f",(char*)"preço por unidade:",(char*)"O preço não pode ser igual ou menor que zero.",(char*)"",0,precounitario,0);	
		printf(" ---------------------------------------\n\n\n\n");
		printf("Deseja continuar? [S/N]\n=========================================");
		do{
			printf("=> ");
			fflush(stdin);
			deseja = getchar();
			if(deseja != 's' && deseja != 'S' && deseja != 'n' && deseja != 'N')MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);;
		}while(deseja != 's' && deseja != 'S' && deseja != 'n' && deseja != 'N');
		codigoprod[cod] = cod;
		LogCadastro(descricao[cod],qtd[cod],qtdmin[cod],precoChar[cod]);
		cod++;
	}while(deseja=='s'|| deseja =='S');	
	main();
}

void Listar(){
	char deci[POS],deseja;
	do{
		system("mode 41,18");
		system("cls");
		int flag=0;
		char auxiliar[POS];
		do{
			system("cls");
			printf(" =======================================\n ");
    		printf("|        Listagem de produtos         |\n ");
    		printf("=======================================\n\n");
			printf(" Entre com Codigo/Nome do Produto: "); fflush(stdin); gets(auxiliar);
			if(strcmp(auxiliar,"principal")==0){
				main();	
			}else if(strcmp(auxiliar,"volta")==0){
				SSMenu();
			}
			flag = procura(auxiliar);
		}while(flag==0);
		printf("\n +-------------+-------------+---------+");
		printf("\n |   Produto   | Quantidades |  Preço  |");
		printf("\n +-------------+-------------+---------+");
		tabulacao(descricao[flag],qtd[flag],precoChar[flag]);
		printf("\n +-------------+-------------+---------+\n\n\n\n\n");
		puts("  Deseja consultar outro produto: [S/N]");
		printf("=========================================");
		do{
			printf("=> ");
			fflush(stdin);
			deseja = getchar();
			if(deseja != 's' && deseja != 'S' && deseja != 'n' && deseja != 'N')MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);;
		}while(deseja != 's' && deseja != 'S' && deseja != 'n' && deseja != 'N');
	}while(deseja != 'n' && deseja != 'N');
	SSMenu();
}

void tabulacao(char *descricao,int qtd,char *precoC){
	char aux[POS];
	char quantidade[VET];
	int cont=0,flag=0;
	itoa(qtd,quantidade,10);
	printf("  | %s",descricao);
	for(int c=strlen(descricao);c<=11;c++){
		printf(" ");
	}
	printf("| %d",qtd);
	for(int c=strlen(quantidade);c<=11;c++){
		printf(" ");
	}
	printf("| %s",precoC);
	for(int c=strlen(precoC);c<=7;c++){
		printf(" ");
	}
	printf("|");
}

void exclusao(){
	char deseja='n';
	char auxiliar[POS],escolha,qtd1[POS];
	int flag;
	system("mode 66,18");
	do{
	
	 do{
		system("cls");
		printf(" ================================================================\n ");
    	printf("|                           Exclusão                           |\n ");
    	printf("================================================================\n\n");
		printf(" Entre com Codigo/Nome do Produto Que Deseja Excluir: "); fflush(stdin); gets(auxiliar);
		printf("\n==================================================================\n\n");
		if(strcmp(auxiliar,"principal")==0){
			main();	
		}
		flag = procura(auxiliar);
	}while(flag==0);
	strcpy(qtd1,concastD((char*)"Você realmente deseja Excluir @",descricao[flag],(char*)""));
	int SN = MessageBoxA(0,qtd1,"Atenção",0x4L | 0x30L);
	if(descricao[flag][0] == '\0' ){
		MessageBoxA(0,"ESSE USUARIO JÁ FOI EXCLUIDO","ERROR",0x10);
	}else if(SN == 6){
		LogExclusao(descricao[flag],qtd[flag],qtdmin[flag],atof(precoChar[flag]));
		descricao[flag][0] = '\0';
		codigoprod[flag] = 0;
	}
	if(SN == 6){
		printf("    *********************************************************\n "); Sleep(250);	
    	printf("   *           ____      ____ ____ ____ ____ ____          *\n"); Sleep(250);
    	printf("    *           |___ |  | |    |__  |___ |___ |  |          *\n"); Sleep(250);
    	printf("    *           ___| |__| |___ |___ ___| ___| |__|          *\n"); Sleep(250);
    	printf("    *                                                       *\n "); Sleep(250);
    	printf("   *********************************************************\n "); Sleep(250);
	}else{
		printf("    *********************************************************\n "); Sleep(250);
    	printf("   *      ____  __  _  _ ____ ____      __  ___  ____      *\n"); Sleep(250);
    	printf("    *      |    |__| |\\ | |    |__  |   |__| |  \\ |  |      *\n"); Sleep(250);
    	printf("    *      |___ |  | | \\| |___ |___ |__ |  | |__/ |__|      *\n"); Sleep(250);
    	printf("    *                                                       *\n "); Sleep(250);
    	printf("   *********************************************************\n "); Sleep(250);
	}
	printf("\nDeseja Continuar com a Exclusão [S/N]: ");
	printf("\n==================================================================\n");
	
	do{
		printf("=> ");
		fflush(stdin);
		deseja = getchar();
		if(deseja != 's' && deseja != 'S' && deseja != 'n' && deseja != 'N')MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
	}while(deseja != 's' && deseja != 'S' && deseja != 'n' && deseja != 'N');
}while(deseja == 's'|| deseja == 'S');
main();
}

void relatorio(){
	char c[VET];
	float guarda;
	int car=4;
	system("mode 67,30");
	printf("\n +----+-----------+-------------+---------------+----------------+");
	printf("\n | ID | Descrição | Quantidades | Quant. Minima | Preço Unitário |");
	printf("\n +----+-----------+-------------+---------------+----------------+");
	for(int cont = 1;cont<=cod-1;cont++,car++, cont+1){
		gotoxy(car,1);
		printf("| %d  | %s ",cont,descricao[cont]);
		gotoxy(car,18);
		printf("|"); 
		itoa(qtd[cont],c,10);
		printf(" %d ",qtd[cont]);
		gotoxy(car,32);
		printf("|");
		itoa(qtdmin[cont],c,10);
		printf(" %d ",qtdmin[cont]);
		gotoxy(car,48);
		printf("|");
		printf(" %s",precoChar[cont]);
		gotoxy(car,65);
		printf("|");
		gotoxy(car+1,1);
		printf("+----+-----------+-------------+---------------+----------------+");
		car++;
		guarda+=qtd[cont]*atof(precoChar[cont]);
		Sleep(1000);
	}
	gotoxy(car,32);
	printf("|     TOTAL:    | %.2f",guarda);
	sprintf(c,"%.2f",guarda);
	gotoxy(car,65);
	printf("|");
	gotoxy(car+1,32);
	printf("+---------------+----------------+");
	Sleep(1000);
	printf("\n\n             ");
	system("pause");
	main();
}

void relatorio2(){
  char deseja;
	char c[VET];
	system("mode 50,30");
	printf("\n +----+-----------+-------------+---------------+");
	printf("\n | ID | Descrição | Quantidades | Quant. Minima |");
	printf("\n +----+-----------+-------------+---------------+");
	for(int cont = 1;cont<=cod-1;cont++){
		if(qtd[cont] < qtdmin[cont]){
			printf("\n | %d  | %s ",cont,descricao[cont]);
			for(int c=strlen(descricao[cont]);c<=8;c++)printf(" ");
			printf("|"); 
			itoa(qtd[cont],c,10);
			printf(" %d",qtd[cont]);
			for(int i=strlen(c);i<=11;i++)printf(" ");
			printf("|");
			itoa(qtdmin[cont],c,10);
			printf(" %d",qtdmin[cont]);
			for(int i=strlen(c);i<=13;i++)printf(" ");
			printf("|");
			printf("\n +----+-----------+-------------+---------------+");
		}
	}
	printf("\n\n   ");
	system("pause");
	main();
}

void infor(){
	int esc;
	system("mode 41,18");
		system("cls");
		printf(" =======================================\n ");
    	printf("|       Informações do Programa       |\n ");
    	printf("=======================================\n\n");
    	printf(" ---------------------------------------\n");
    	printf(" | [1] - Sobre o programa              |\n ---------------------------------------  | [2] - Logs do sistema               |  ---------------------------------------  | [3] - Voltar                        |");
    	printf("\n ---------------------------------------\n\n\n\n\n");
    	printf("\n=========================================");
    	do{
			printf("=> ");
			fflush(stdin);
			scanf("%d",&esc);
			if(esc != 0 && esc != 1 && esc != 2 && esc != 3 && esc != 4 && esc != 5 && esc != 6)MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);;
		}while(esc != 0 && esc != 1 && esc != 2 && esc != 3 && esc != 4 && esc != 5 && esc != 6);
    	switch(esc){
	    	case 1:
	    		SobreProg();
    			break;
    		case 2:
    			LogDoProg();
				break;
    		case 3:
    			main();
				break;
			default:
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				infor();
				break;
	}
}



void SobreProg(){
	system("cls");
	printf(" =======================================\n ");
    printf("|       Informações do Programa       |\n ");
    printf("=======================================\n\n");
    printf("   V. 1.0.3");
    printf("\n\n 1- Quando entrar em uma tela e estiver   escrito \"Entre com Codigo/Nome do Prod   uto\" digite \"volta\" para voltar a pagi   na anterior ou digite \"principal\" para   voltar a pagina principal.");
    printf("\n\n 2 - ");
	getch();
    infor();
}

void LogDoProg(){
	int esc;
	system("cls");
	system("mode 25,18");
	printf(" =======================\n ");
    printf("|  Logs do Programa   |\n ");
    printf("=======================\n");
    printf(" | [1]-Visualizar      | ");
    printf(" =======================\n");
    printf(" | [2]-Excluir         | ");
    printf(" =======================\n");
    printf(" | [3]-Voltar          | ");
    printf(" =======================\n\n\n\n\n\n\n\n");
    printf("=========================\n");
    do{
			printf("=> ");
			fflush(stdin);
			scanf("%d",&esc);
			if(esc != 0 && esc != 1 && esc != 2 && esc != 3 && esc != 4 && esc != 5 && esc != 6)MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);;
	}while(esc != 0 && esc != 1 && esc != 2 && esc != 3 && esc != 4 && esc != 5 && esc != 6);
    switch(esc){
	    	case 1:
	    		LogMenu();
    			break;
    		case 2:
    			ExcluirLog();
				break;
    		case 3:
    			infor();
				break;
			default:
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				infor();
				break;
	}
}

void LogMenu(){
	system("mode 25,18");
	system("cls");
	printf(" =======================\n");
    printf(" |  Logs do Programa   |\n");
    printf(" =======================\n");
	int cont=0,quant=0;
	char dire[] = {"C:\\TMP"};
	DIR * pasta;
	char arquivos[10][255];
	struct dirent * arq;
	if(pasta=opendir(dire)){
		while(arq=readdir(pasta)){
			strcpy(arquivos[cont++],arq->d_name);
			if(cont==10)break;
		}
		closedir(pasta);
	}
	for(cont=0;cont<10;cont++){
		if(arquivos[cont][0]=='L'){
			int cc=0;
			printf(" | [%d]-",cont-1);
			while(arquivos[cont][cc]!='.'){
				printf("%c",arquivos[cont][cc++]);				
			}
			for(int con=strlen(arquivos[cont]);con<=19;con++)printf(" ");
			printf("|\n");
			printf(" =======================\n");
			quant++;
		}
	}        
	printf(" | [0]-Sair            |");
	if(quant<6){
		printf("  =======================\n");
		gotoxy(15,0);
	}
	int esco=0;
	printf("\n=========================");
	do{
			printf("=> ");
			fflush(stdin);
			scanf("%d",&esco);
			if(esco != 0 && esco != 1 && esco != 2 && esco != 3 && esco != 4 && esco != 5 && esco != 6)MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);;
	}while(esco != 0 && esco != 1 && esco != 2 && esco != 3 && esco != 4 && esco != 5 && esco != 6);
	int cc=0;
	switch(esco){
		case 1:
			if(quant<1){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			system("cls");
			system("mode 145,25");
			printf(" ===============================================================================================================================================\n");
			printf(" |                                                               ");
			do{
				printf("%c",arquivos[2][cc++]);
			}while(arquivos[2][cc]!='.');
			gotoxy(1,143);printf("|");
			printf("\n ===============================================================================================================================================\n");
			MostrarLog(arquivos[2]);
			break;
		case 2:
			if(quant<2){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			system("cls");
			system("mode 145,25");
			printf(" ===============================================================================================================================================\n");
			printf(" |                                                               ");
			do{
				printf("%c",arquivos[3][cc++]);
			}while(arquivos[3][cc]!='.');
			gotoxy(1,143);printf("|");
			printf("\n ===============================================================================================================================================\n");
			MostrarLog(arquivos[3]);
			break;
		case 3:
			if(quant<3){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			system("cls");
			system("mode 145,25");
			printf(" ===============================================================================================================================================\n");
			printf(" |                                                               ");
			do{
				printf("%c",arquivos[4][cc++]);
			}while(arquivos[4][cc]!='.');
			gotoxy(1,143);printf("|");
			printf("\n ===============================================================================================================================================\n");
			MostrarLog(arquivos[4]);
			break;
		case 4:
			if(quant<4){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			system("cls");
			system("mode 145,25");
			printf(" ===============================================================================================================================================\n");
			printf(" |                                                               ");
			do{
				printf("%c",arquivos[5][cc++]);
			}while(arquivos[5][cc]!='.');
			gotoxy(1,143);printf("|");
			printf("\n ===============================================================================================================================================\n");
			MostrarLog(arquivos[5]);
			break;
		case 5:
			if(quant<5){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			system("cls");
			system("mode 145,25");
			printf(" ===============================================================================================================================================\n");
			printf(" |                                                               ");
			do{
				printf("%c",arquivos[6][cc++]);
			}while(arquivos[6][cc]!='.');
			gotoxy(1,143);printf("|");
			printf("\n ===============================================================================================================================================\n");
			MostrarLog(arquivos[6]);
			break;
		case 6:
			if(quant<6){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			system("cls");
			system("mode 145,25");
			printf(" ===============================================================================================================================================\n");
			printf(" |                                                               ");
			do{
				printf("%c",arquivos[7][cc++]);
			}while(arquivos[7][cc]!='.');
			gotoxy(1,143);printf("|");
			printf("\n ===============================================================================================================================================\n");
			MostrarLog(arquivos[7]);
			break;
		case 0:
			LogDoProg();
			break;
		default:
			MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
			LogMenu();
			break;
	}
}

void ExcluirLog(){
	system("cls");
	printf(" =======================\n");
    printf(" |     Excluir logs    |\n");
    printf(" =======================\n");
	int cont=0,quant=0;
	char dire[] = {"C:\\TMP"};
	DIR * pasta;
	char arquivos[10][255],cami[]={"C:\\TMP\\"};;
	struct dirent * arq;
	if(pasta=opendir(dire)){
		while(arq=readdir(pasta)){
			strcpy(arquivos[cont++],arq->d_name);
			if(cont==10)break;
		}
		closedir(pasta);
	}
	for(cont=0;cont<10;cont++){
		if(arquivos[cont][0]=='L'){
			int cc=0;
			printf(" | [%d]-",cont-1);
			while(arquivos[cont][cc]!='.'){
				printf("%c",arquivos[cont][cc++]);				
			}
			for(int con=strlen(arquivos[cont]);con<=19;con++)printf(" ");
			printf("|\n");
			printf(" =======================\n");
			quant++;
		}
	}        
	printf(" | [0]-Sair            |");
	if(quant<6){
		printf("  =======================\n");
		gotoxy(15,0);
	}
	int esco=0;
	printf("\n=========================");
	do{
			printf("=> ");
			fflush(stdin);
			scanf("%d",&esco);
			if(esco != 0 && esco != 1 && esco != 2 && esco != 3 && esco != 4 && esco != 5 && esco != 6 && esco != 100)MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);;
	}while(esco != 0 && esco != 1 && esco != 2 && esco != 3 && esco != 4 && esco != 5 && esco != 6 && esco != 100);
	switch(esco){
		case 1:
			if(quant<1){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			strcat(cami,arquivos[2]);
			remove(cami);
			break;
		case 2:
			if(quant<2){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			strcat(cami,arquivos[3]);
			remove(cami);
			break;
		case 3:
			if(quant<3){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			strcat(cami,arquivos[4]);
			remove(cami);
			break;
		case 4:
			if(quant<4){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			strcat(cami,arquivos[5]);
			remove(cami);
			break;
		case 5:
			if(quant<5){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			strcat(cami,arquivos[6]);
			remove(cami);
			break;
		case 6:
			if(quant<6){
				MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
				LogMenu();
			}
			strcat(cami,arquivos[7]);
			remove(cami);
			break;
		case 100:
			remove("C:\\TMP\\LogAcesso.txt");
			remove("C:\\TMP\\LogExclusao.txt");
			remove("C:\\TMP\\LogVendas.txt");
			remove("C:\\TMP\\LogCadastro.txt");
			remove("C:\\TMP\\LogCompras.txt");
			remove("C:\\TMP\\LogDeAlterações.txt");
			break;
		case 0:
			LogDoProg();
			break;
		default:
			MessageBoxA(0,"CARACTER INVALIDO!!","ERROR",0x10);
			ExcluirLog();
			break;
	}
	ExcluirLog();
} 

void MostrarLog(char *arquivo){
	FILE * arq;
	int linha=100;
	char buffer[255],dire[]={"C:\\TMP\\"};
	strcat(dire,arquivo);
	if((arq=fopen(dire,"r"))==NULL)printf("Não foi possivel abrir o arquivo %s",arquivo);
	while((fgets(buffer,linha,arq))){
		printf("%s",buffer);
	}
	fclose(arq);
	getch();
	LogMenu();
}
