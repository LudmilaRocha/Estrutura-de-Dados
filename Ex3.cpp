/*3. Fa�a um programa contendo uma fun��o para retornar o tamanho de uma lista
ligada.
Autora:Ludmila Rocha Silva
E-mail:ludmila030301@gmail.com
Ano:2022*/
#include <stdio.h>
#include <windows.h>


//registro com cada elemento da lista

struct LISTA{
int num;
LISTA * prox;
};
//met�do para inserir na cabe�a da lista(no in�cio)

LISTA  * insere_inicio(LISTA * inicio)
{
LISTA * novo = new LISTA();
printf("Informe um numero a ser inserido:");
scanf("%d", & novo->num);
//se a lista for vazia, � o primeiro n�
if(inicio == NULL){
inicio= novo;
inicio->prox=NULL;
} else{//insere no inicio
novo->prox=inicio;
inicio= novo;
}
return inicio;
}

//impress�o da lista

void imprime_lista(LISTA * inicio)
{
if(inicio == NULL){
printf("\nA lista esta vazia");
} else{
LISTA  * aux;
printf("\nLista:");
aux = inicio;
while(aux != NULL)
{
printf("%d", aux->num);
aux = aux->prox;
}
}



}

int tamanho_lista(LISTA*inicio){
int cont=0;	
if(inicio == NULL){
printf("\nA lista esta vazia");
} else{
LISTA  * aux;
printf("\nTamanho:");
aux = inicio;

while(aux != NULL)
{
cont++;
aux = aux->prox;
}


}
 return  printf("Tamanho da lista:%d", cont);

}
//fun��o main
int main(){
LISTA * inicio = NULL;
int menu, elemento;
do{

printf("\nMenu de Opcoes:");
printf("\n1- Lista Impressa.");
printf("\n2- Inserir novo elemento da lista.");
printf("\n3- Verificar tamanho da lista");
printf("\n4- Sair");
printf("\nDigite a opcao desejada:");
scanf("%d", & menu);
switch(menu){
case 1:
imprime_lista(inicio);
break;

case 2:
inicio = insere_inicio(inicio);
break;

case 3:
	tamanho_lista(inicio);
break;

}

} while(menu != 4);
}
