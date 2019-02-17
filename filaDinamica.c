#include <stdlib.h>
#include "filaDinamica.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

//Definição do Nó descritor da fila
struct fila{
	struct elemento *inicio;
	struct elemento *final;
	int qtd;
};

//Criando uma fila
Fila *cria_Fila(){
	Fila *fi = (Fila*) malloc(sizeof(Fila));
	
	if(fi != NULL){
		fi->final = NULL;
		fi->inicio = NULL;
		fi->qtd = 0;
	}
	
	return fi;
}

//Destruindo um fila
void libera_Fila(Fila *fi){
	if(fi != NULL){
		Elem *no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);	
		}
		free(fi);
	}
}

//tamanho da fila
int tamanho_Fila(Fila *fi){
	if(fi == NULL){
		return 0;
	}
	
	return fi->qtd;
}

//Fila cheia;
int Fila_cheia(Fila *fi){
	return 0;
}

//Fila vazia;
int Fila_vazia(Fila *fi){
	if(fi == NULL){
		return 1;
	}
	if(fi->inicio == NULL){
		return 1;
	}
	return 0;
}

//Inserção de um nodo na fila encadeada
int insere_Fila(Fila *fi, struct aluno al){
	if(fi == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	
	if(no == NULL){
		return 0;
	}
	no->dados = al;
	no->prox = NULL;
	
	if(fi->final == NULL){
		fi->inicio = no;
	}else{
		fi->final->prox = no;
	}
	fi->final = no;
	fi->qtd++;
	return 1;
}

//Remoção de um nodo(elemento) de fila encadeada
int remove_Fila(Fila *fi){
	if(fi == NULL){
		return 0;
	}
	if(fi->inicio == NULL){
		return 0;
	}
	Elem *no = fi->inicio;
	
	fi->inicio = fi->inicio->prox;
	
	if(fi->inicio == NULL){
		fi->final = NULL;
	}
	
	free(no);
	fi->qtd--;
	return 1;
}

//Consultando um nodo de fila encadeada

int consulta_Fila(Fila *fi, struct aluno *al){
	if(fi == NULL){
		return 0;
	}
	if(fi->inicio == NULL){
		return 0;
	}
	*al = fi->inicio->dados;
	return 1;
}

//Imprime os elementos de uma fila
void imprime_Fila(Fila *fi){
	if(fi == NULL){
		return;
	}
	Elem *no = fi->inicio;
	
	while(no != NULL){
		printf("Matricula: %d\n", no->dados.matricula);
		printf("Nome: %d\n", no->dados.nome);
		printf("Notas: %f %f %f\n", no->dados.n1,
						    no->dados.n2,
						    no->dados.n3);
		printf("--------------------------------\n");
		no = no->prox;
	}
}

