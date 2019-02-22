struct dados{
	int objeto1;
	char objeto2[30];
	float objeto3, objeto4, objeto5;
};

struct registro{
	struct dados Dados;
	struct registro *prox;
};
//parte superior semelhante a lista encadeada
typedef struct registro celula;

struct fila{
	struct celula *inicio;
	struct celula *final;
	int qtde;
};

typedef struct fila Fila;

//Cria uma fila
Fila *cria_Fila(){
	Fila *fi = (Fila*) malloc(sizeof(Fila));
	
	if(fi != NULL){
		fi->final = NULL;
		fi->inicio = NULL;
		fi->qtde = 0;
	}
	
	return fi;
}

//Destruindo uma fila
void libera_Fila(Fila *fi){
	if(fi != NULL){
		celula *no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}

//Tamanho da Fila;
int tamanho_Fila(Fila *fi){
	if(fi == NULL){
		return 0;
	}
	
	return fi->qtde;
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
int insere_Fila(Fila *fi, struct dados Dados){
	if(fi == NULL){
		return 0;
	}
	celula *no = (celula*) malloc(sizeof(celula));
	
	if(no == NULL){
		return 0;
	}
	no->Dados = Dados;
	no->prox = NULL;

	if(fi->final == NULL){
		fi->inicio = no;
	}else{
		fi->final->prox = no;
	}
	fi->final = no;
	fi->qtde++;
	
	return 1;
}

//Remoção de um nodo(elemento) de uma fila encadeada
int remove_Fila(Fila *fi){
	if(fi == NULL){
		return 0;
	}
	if(fi->inicio == NULL){
		return 0;
	}
	
	celula *no = fi->inicio;
	fi->inicio = fi->inicio->prox;
	
	if(fi->inicio == NULL){
		fi->final = NULL;
	}
	
	free(no);
	fi->qtde--;
	return 1;
}

//Consultando um nodo de fila encadeada
int consulta_Fila(Fila *fi, struct dados Dados){
	if(fi == NULL){
		return 0;
	}
	if(fi->inicio == NULL){
		return 0;
	}
	
	*Dados = fi->inicio->Dados;
	
	return 1;
}

//Imprime os elementos de uma fila
void imprime_Fila(Fila *fi){
	if(fi == NULL){
		return;
	}
	
	celula *no = fi->inicio;
	
	while(no != NULL){
		printf("%Dados\n", no->Dados.objeto1);
		printf("%s\n", no->Dados.objeto2);//...
	}
}
	
	
