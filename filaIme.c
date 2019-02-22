//Fila em vetor
int tiradafila (void) {
   return fila[p++];
}

void colocanafila (int y) {
   fila[u++] = y;
}
///////////////

//fila circular
int tiradafila (void) {
   int x = fila[p++];
   if (p == N) p = 0;
   return x;
}
(desde que a fila não esteja vazia).  A inserção de um objeto y na fila pode ser escrita assim:

void colocanafila (int y) {
   fila[u++] = y;
   if (u == N) u = 0;
}

/////////////////////////////////////////

//fila para o calculo de distancias em Grafos
#define N 100
int fila[N], int p, u;
int dist[N];

void criafila (void) {
   p = u = 0;
}

int filavazia (void) {
   return p >= u;
}

int tiradafila (void) {
   return fila[p++];
}

void colocanafila (int y) {
   fila[u++] = y;
}

// Esta função recebe uma matriz A
// que representa as interligações entre
// cidades 0..N-1 e preenche o vetor dist
// de modo que dist[i] seja a distância
// da cidade c à cidade i, para cada i.

void distancias (int A[][N], int c) {
   for (int j = 0; j < N; ++j)  dist[j] = N;
   dist[c] = 0;
   criafila ();
   colocanafila (c);

   while (! filavazia ()) { 
      int i = tiradafila ();
      for (int j = 0; j < N; ++j)
         if (A[i][j] == 1 && dist[j] >= N) {
            dist[j] = dist[i] + 1;
            colocanafila (j);
         }
   }
}
///////////////////////////////////////////////////


//Implementação circular de uma fila
int tiradafila (void) {
   int x = fila[p++];
   if (p == N) p = 0;
   return x;
}

void colocanafila (int y) {
   fila[u++] = y;
   if (u == N) u = 0;
}
////////////////////////////////////

//Implementação em vetor com redimencionamento
void redimensiona (void) {
   N *= 2;
   fila = realloc (fila, N * sizeof (int));
}
Uma versão ad hoc poderia ser escrita assim sem usar realloc:

void redimensiona (void) {
   N *= 2;
   int *novo;
   novo = malloc (N * sizeof (int));
   for (int i = p; i < u; i++)
      novo[i] = fila[i];
   free (fila);
   fila = novo;
}
////////////////////////////////////////////////////////











//Fila implementada em uma lista encadeada
typedef struct registro{
	int objeto1;
	struct registro *prox;
}

typedef struct registro celula;

//Criação de uma Fila vazia
celula *fi;
fi = malloc (sizeof (celula));
fi->prox = fi;

//Manipulação
// Tira um elemento da fila fi e devolve
// o conteudo do elemento removido.
// Supõe que a fila não está vazia.

int tiradafila (celula *fi) {
   celula *p;
   p = fi->prox;  // o primeiro da fila
   int x = p->conteudo;
   fi->prox = p->prox;
   free (p);
   return x;  
}
A inserção usa um truque sujo:  armazena o novo elemento na célula-cabeça original e cria uma nova célula-cabeça:

// Coloca um novo elemento com conteudo y
// na fila fi. Devolve o endereço da
// cabeça da fila resultante.

celula *colocanafila (int y, celula *fi) { 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->conteudo = y;
   return nova;
}


