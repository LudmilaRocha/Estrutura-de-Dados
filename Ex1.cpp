/*1. Implemente um programa em C que utiliza a estrutura apresentada para
implementar uma lista. O programa deve mostrar ao usuário duas opções. Se o
usuário escolher 1, a lista deve ser impressa; se escolher 2, ele deve entrar com o
valor do conteúdo do novo elemento da lista.
Autora:Ludmila Rocha Silva
e-mail: ludmila030301@gmail.com
Ano:2022*/
#include <stdio.h>
#include <windows.h>


//registro com cada elemento da lista

struct LISTA{
int num;
LISTA * prox;
};
//metódo para inserir na cabeça da lista(no início)

LISTA  * insere_inicio(LISTA * inicio)
{
LISTA * novo = new LISTA();
printf("Informe um numero a ser inserido:");
scanf("%d", & novo->num);
//se a lista for vazia, é o primeiro nó
if(inicio == NULL){
inicio= novo;
inicio->prox=NULL;
} else{//insere no inicio
novo->prox=inicio;
inicio= novo;
}
return inicio;
}

//impressão da lista

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

//função main
int main(){
LISTA * inicio = NULL;
int menu, elemento;
do{

printf("\nMenu de Opcoes:");
printf("\n1- Lista Impressa.");
printf("\n2- Inserir novo elemento da lista.");
printf("\n3- Sair");
printf("\nDigite a opcao desejada:");
scanf("%d", & menu);
switch(menu){
case 1:
imprime_lista(inicio);
break;

case 2:
inicio = insere_inicio(inicio);
break;

}

} while(menu != 3);
}

