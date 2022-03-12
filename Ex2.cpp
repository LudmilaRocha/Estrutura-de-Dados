/*2. Faça um programa contendo as seguintes operações referentes à lista ligada: criar
lista, inserir elemento no início da lista, inserir elemento no fim da lista, remover
item da lista e buscar elemento na lista.
Autora:Ludmila Rocha Silva
E-mail: ludmila030301@gmail.com
Ano:2022*/
#include <stdio.h>
#include <windows.h>

//registro com cada elemento da lista

struct LISTA{
int num;
LISTA * prox;
};

//método para inserir na cabeça da lista (no início)
LISTA * insere_inicio(LISTA * inicio)
{
LISTA * novo = new LISTA();
printf("Informe um elemento a ser inserido:");
scanf("%d", & novo->num);
//se a lista for vazia, é o primeiro nó
if(inicio == NULL){
inicio  = novo;
inicio->prox=NULL;
}else{//insere no inicio
novo->prox = inicio;
inicio = novo;

}
return inicio;
}
//método para inserir no fim da lista
LISTA * insere_fim(LISTA * inicio)
{
LISTA  * aux;
LISTA  * novo = new LISTA();
printf("Informe um numero:");
scanf("%d", & novo->num);
if(inicio == NULL){//se a lista for vazia
inicio  = novo;
inicio->prox=NULL;
}else{
aux  = inicio;
while(aux->prox != NULL)
{
aux = aux->prox;
}
aux->prox = novo;
novo->prox = NULL;
}
return inicio;
}

//método para remoçãp de um elemento da lista

LISTA * remove_lista(LISTA*inicio)
{
int numero, achou=0;
LISTA * aux;
LISTA * anterior;
printf("Informe um numero que deseja remover:");
scanf("%d", & numero);
if(inicio == NULL){
printf("A lista esta vazia");

} else{
aux = inicio;
anterior =  inicio;
while(aux != NULL){
if(numero == aux->num){//se achou, remove
if(aux  == inicio){//se for o primeiro
inicio = aux->prox;
delete(aux);
aux = inicio;
} else{
anterior->prox = aux->prox;
delete(aux);
aux = anterior->prox;
}
achou = achou +  1;
} else{
anterior = aux;
aux = aux->prox;
}
}
if(achou == 0){
printf("\nNumero nao encontrado");
} else{
printf("\nNumero removido com sucesso %d vezes", achou);
}
}
return inicio;
}
//método para impressao da lista

void imprime_lista(LISTA * inicio)
{
if(inicio == NULL){
printf("\nA lista esta vazia");
}else{
LISTA * aux;
printf("\nLista:");
aux = inicio;
while(aux !=  NULL)
{
printf("%d", aux->num);
aux = aux->prox;
}
}
}
void busca_lista(LISTA * inicio, int elemento)
{
int achou = 0;//suponha que o elemento não esta na lista
if(inicio == NULL){
printf("\nA lista esta vazia");

}else{
LISTA * aux;
printf("\nLista");
aux  = inicio;
while(aux  != NULL)
{
if (elemento == aux -> num){
achou  = 1;
break;
}
aux = aux->prox;
}
}

if(achou == 1){
printf("O elemento esta na lista");
}else{
printf("O elemento nao esta na lista");

}
}

//função main
int main()
{
LISTA * inicio = NULL;
int menu, elemento;
do{

printf("\nMenu de opcoes");
printf("\n1 -Inserir no inicio da lista");
printf("\n2 -Inserir no final da lista");
printf("\n3 -Consultar toda a lista");
printf("\n4 -Remover da lista");
printf("\n5 -Busca de um elemento na lista");
printf("\n6 -Sair");
printf("\nDigite a opcao desejada:");
scanf("%d", & menu);
switch(menu){

case  1:
inicio = insere_inicio(inicio);
break;
case 2:
inicio = insere_fim(inicio);
break;
case 3:
imprime_lista(inicio);
break;
case 4:
inicio = remove_lista(inicio);
break;
case 5:
printf("Informe o elemento que deseja buscar:");
scanf("%d", & elemento);
busca_lista(inicio, elemento);

}
}while(menu!=6);
}


