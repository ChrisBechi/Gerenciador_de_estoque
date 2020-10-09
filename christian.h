#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dirent.h>
#define UTC (0)

int horas,min,sec,dia,mes,ano,OC=1;

char *concast(char *texto,float num1,float num2){
      char n1[10],n2[10],auxC[200]={' '},teste[100];
      int cont=0,cAux=0,Acont=0,flag=0;
      itoa(num1,n1,10);
      sprintf (n2, "%.2f", num2);
      while(texto[cont] != '\0'){   
           if(texto[cont] == '@'){
               Acont = 0;
               if(flag == 0) strcpy(teste,n1); else strcpy(teste,n2);
			   while(teste[Acont] != '\0'){
			   		auxC[cAux] = teste[Acont];
			   		Acont++;
			   		cAux++;
			   }            
			   cont++; 
			   flag++;             
           }else{
			   auxC[cAux] = texto[cont]; 
               cont++;
               cAux++;
           }
           
      }
      return auxC; 
}


char *concastD(char *men, char *texto,char *texto2){
      char n1[10],n2[10],aux[POS],teste[100];
      int cont=0,cAux=0,Acont=0,flag=0;
      while(men[cont] != '\0'){  
	  	   if(flag == 0) strcpy(teste,texto); else strcpy(teste,texto2);
           if(men[cont] == '@'){
               Acont = 0;
			   while(teste[Acont] != '\0'){
			   		aux[cAux] = teste[Acont];
			   		Acont++;
			   		cAux++;
			   }            
			   cont++; 
			   flag++;             
           }else{
			   aux[cAux] = men[cont]; 
               cont++;
               cAux++;
           }
           
      }
      aux[cAux]='\0';
      return aux; 
}

char* consultaPreco(char *preco){
	int flag=0,c=0;
	char auxP[10];
	while(preco[c]!='\0' && flag < 3){
		if(preco[c] == '.'){
			auxP[c] = ',';
			flag++;
		}else{
			auxP[c] = preco[c];
			if(flag != 0 || preco[c] == ',')flag++;
		}
		c++;
	}
	auxP[c]='\0';
	return auxP; 
}

char *concastI(char *texto,int num1,int num2){
      char n1[10],n2[10],aux[200],teste[100];
      int cont=0,cAux=0,Acont=0,flag=0;
      itoa(num1,n1,10);
      itoa(num2,n2,10);
      while(texto[cont] != '\0'){   
           if(texto[cont] == '@'){
               Acont = 0;
               if(flag == 0) strcpy(teste,n1); else strcpy(teste,n2);
			   while(teste[Acont] != '\0'){
			   		aux[cAux] = teste[Acont];
			   		Acont++;
			   		cAux++;
			   }            
			   cont++; 
			   flag++;             
           }else{
			   aux[cAux] = texto[cont]; 
               cont++;
               cAux++;
           }
           
      }
      return aux; 
}

char *concastM(char *texto,int num1,int num2){
      char n1[10],n2[10],aux[200],teste[100];
      int cont=0,cAux=0,Acont=0,flag=0;
      itoa(num1,n1,10);
      itoa(num2,n2,10);
      while(texto[cont] != '\0'){   
           if(texto[cont] == '@'){
               Acont = 0;
               if(flag == 0) strcpy(teste,n1); else strcpy(teste,n2);
			   while(teste[Acont] != '\0'){
			   		aux[cAux] = teste[Acont];
			   		Acont++;
			   		cAux++;
			   }            
			   cont++; 
			   flag++;             
           }else{
			   aux[cAux] = texto[cont]; 
               cont++;
               cAux++;
           }
           
      }
      return aux; 
}


char *concastF(char *texto,float num1,float num2){
      char n1[10],n2[10],aux[200],teste[100];
      int cont=0,cAux=0,Acont=0,flag=0;
      sprintf (n1, "%.2f", num1);
      sprintf (n2, "%.2f", num2);
      while(texto[cont] != '\0'){   
           if(texto[cont] == '@'){
               Acont = 0;
               if(flag == 0) strcpy(teste,n1); else strcpy(teste,n2);
			   while(teste[Acont] != '\0'){
			   		aux[cAux] = teste[Acont];
			   		Acont++;
			   		cAux++;
			   }            
			   cont++; 
			   flag++;             
           }else{
			   aux[cAux] = texto[cont]; 
               cont++;
               cAux++;
           }
           
      }
      return aux; 
}

gotoxy(int c,int l){
	COORD posicao;
	posicao.Y = c;
	posicao.X = l;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicao);
}


LogAcesso(){
	FILE * arquivo;
	int linha=1;
	CreateDirectory("C:\\TMP",0);
	if((arquivo=fopen("C:\\TMP\\LogAcesso.txt","a"))==NULL)printf("Não foi possivel abrit o arquivo!");
	fprintf(arquivo," Acessado em: %02d/%02d/%02d às %02d:%02d:%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",dia,mes,ano,horas,min,sec);
    fclose(arquivo);
}

LogModificacao(char *Nome,char *prod,char *NProd,char tipo){
	FILE * altera;
	if((altera=fopen("C:\\TMP\\LogDeAlterações.txt","a"))==NULL)printf("Não foi possivel abrit o arquivo!");
	switch(tipo){
		case 'c':
			fprintf(altera," %s foi modificado por %s - às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",prod,NProd,horas,min,sec,dia,mes,ano);
			break;
		case 'i':
			fprintf(altera," %s - quantidade minima %s foi modificado por %s - às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",Nome,prod,NProd,horas,min,sec,dia,mes,ano);
			break;
		case 'm':
			fprintf(altera," %s - quantidade %s foi modificado por %s - às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",Nome,prod,NProd,horas,min,sec,dia,mes,ano);
			break;
		case 'f':
			fprintf(altera," %s - preço Unitario %s foi modificado por %.2f - às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",Nome,prod,atof(NProd),horas,min,sec,dia,mes,ano);
			break;
	}
	fclose(altera);
};

DWORD WINAPI hora(LPVOID lol){
	while(1){
		time_t h;
		struct tm*hms;
		time(&h);
		hms=gmtime(&h);
		switch(hms->tm_hour){
			case 00:
				horas=21;
				min = hms->tm_min;
				sec = hms->tm_sec;
				dia = hms->tm_mday-1; 
				mes = hms->tm_mon+1;
				ano = hms->tm_year+1900;
				break;
			case 01:
				horas=22;
				min = hms->tm_min;
				sec = hms->tm_sec;
				dia = hms->tm_mday; 
				mes = hms->tm_mon+1;
				ano = hms->tm_year+1900-1;
				min = hms->tm_min;
				sec = hms->tm_sec;	
				break;
			case 02:
				horas=23;
				min = hms->tm_min;
				sec = hms->tm_sec;
				dia = hms->tm_mday-1; 
				mes = hms->tm_mon+1;
				ano = hms->tm_year+1900;
				min = hms->tm_min;
				sec = hms->tm_sec;
				break;
			default:
				horas = (hms->tm_hour)-3;
				min = hms->tm_min;
				sec = hms->tm_sec;
				dia = hms->tm_mday; 
				mes = hms->tm_mon+1;
				ano = hms->tm_year+1900;
				break;
		}
	}
}

LogCadastro(char *Nome,int qtd,int qtdmin,char *preco){
	FILE * cad;
	if((cad=fopen("C:\\TMP\\LogCadastro.txt","a"))==NULL)printf("Não foi possivel abrit o arquivo!");
	fprintf(cad," Prod:%s | Qtd:%d | QtdMin:%d | precoUnitario: %s | Cadastrado às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",Nome,qtd,qtdmin,preco,horas,min,sec,dia,mes,ano);
	fclose(cad);
}

LogCompras(char *Prod,int qtdV,int qtdN){
	FILE * Compra;
	if((Compra=fopen("C:\\TMP\\LogCompras.txt","a"))==NULL);
	fprintf(Compra," Adicionado a(o) %s: %d unidades | Quantidade anterior: %d | Quantidade Atual %d | Comprado às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",Prod,qtdN,qtdV,qtdV+qtdN,horas,min,sec,dia,mes,ano);
	fclose(Compra);
}

LogVendas(char *Prod,int qtdV,int qtdN,float arrecadado){
	FILE * Venda;
	if((Venda=fopen("C:\\TMP\\LogVendas.txt","a"))==NULL);
	fprintf(Venda," Foi vendido: %d %s | Arrecadado: %.2f | Quantidade Anterior: %d | Quantidade Atual: %d | Comprado às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",qtdN,Prod,arrecadado,qtdV,qtdV-qtdN,horas,min,sec,dia,mes,ano);
	fclose(Venda);
}

LogExclusao(char *Prod,int qtd,int qtdMinima,float precoUnitario){
	FILE * Venda;
	if((Venda=fopen("C:\\TMP\\LogExclusao.txt","a"))==NULL);
	fprintf(Venda," Excluido o produto: %s | Quantidade: %d | Quantidade Minima: %d | Preço Unitario: %.2f | Comprado às %02d:%02d:%02d na data %02d/%02d/%02d\n-------------------------------------------------------------------------------------------------------------------------------------------------\n",Prod,qtd,qtdMinima,precoUnitario,horas,min,sec,dia,mes,ano);
	fclose(Venda);
}

DWORD WINAPI HoraRefresh(LPVOID lpParam){
	while(OC){
		gotoxy(17,0);
		printf(" %02d:%02d:%02d  |  %02d/%02d/%d ",horas,min,sec,dia,mes,ano);
		gotoxy(19,3);
		Sleep(600);
	}
}
