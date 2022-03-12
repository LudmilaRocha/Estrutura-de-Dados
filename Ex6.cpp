/*6. Escreva uma função que copie o conteúdo de um vetor para uma lista encadeada 
preservando a ordem dos elementos.
Autora: Ludmila Rocha Silva
E-mail: ludmila030301@gmail.com
Ano:2022*/
#include <stdio.h>
#include <windows.h>


struct LISTA {
	int num;
	LISTA * prox;
};

// inserir lista
LISTA * insere_inicio(LISTA * inicio) {
	LISTA * novo = new LISTA();
	printf("Infome o seu numero: ");
	scanf("%d", & novo->num);
	// se a lista for vazia, é o primeiro nó
	if(inicio == NULL) {
		inicio = novo;
		
		inicio->prox = NULL;
		
	} else {
		//insere no inicio
		novo->prox = inicio;
		inicio = novo;
	}
	
	return inicio;
}
// imprimir lista

void imprimi_lista(LISTA * inicio) {
	if(inicio == NULL) {
		printf("\nA lista esta vazia...");
	} else {
		LISTA * aux;
		printf("\nLISTA: ");
		aux = inicio;
		while(aux != NULL) {
			printf("%d ", aux-> num);
			aux = aux->prox;
		}
	}
}

int insere_vet(LISTA * inicio, int vet[100]) {
	int i = 0;
	if(inicio == NULL) {
		printf("\nA lista esta vazia...");
	} else {
		LISTA * aux;
		printf("\nLISTA: ");
		aux = inicio;
		
		while(aux != NULL) {
		
			vet[i] = aux->num;
			i++; 
			aux = aux->prox;
		}
	}
	return i;
}

// chamada 

int main () {
	LISTA * inicio = NULL;
	
	int menu, elemento, vet[100];
	
	do {
		system("cls");
		printf("\nMENU DE OPCOES");
		printf("\n1 - inserir no inicio da lista");
		printf("\n2 - consultar toda a lista");
		printf("\n3 - consultar copia vetor");
		scanf("%d", & menu);
		
		switch(menu) {
			case 1:
				inicio = insere_inicio(inicio);
				break;
			case 2:
				imprimi_lista(inicio);
				break;
			case 3: 
				int cont = insere_vet(inicio, vet);
				
				for(int j = 0; j < cont; j++) {
					printf("vetor [%d] ", vet[j]);
				}
				break;
		}
		
	}
	while(menu != 3);
}

