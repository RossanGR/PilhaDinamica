#include<stdio.h>
#include<malloc.h>

// PILHA DINÂMICA

struct elemento {
  int valor;
  struct elemento* prox;
};

typedef struct {
	struct elemento* topo;
} PILHA;

void inicializarPilha(PILHA* pilha);
void limpaPilha(PILHA* pilha);
void imprimirPilha(PILHA pilha);
int push(PILHA* pilha, int valor);
void pop(PILHA* pilha);
int length(PILHA* pilha);

int main () {
	PILHA minhaPilha;

	inicializarPilha(&minhaPilha);
	 
	push(&minhaPilha,5);
  push(&minhaPilha,3);
  push(&minhaPilha,14);
  push(&minhaPilha,8);

  pop(&minhaPilha);
   push(&minhaPilha,3);
    pop(&minhaPilha);
     pop(&minhaPilha);

	imprimirPilha(minhaPilha);


	

	
}

void pop(PILHA* pilha){
	if(pilha->topo != NULL) {
		struct elemento* apagar = pilha->topo;

    // ATUALIZAR TOPO DA PILHA COM O PROX DO TOPO QUE EU VOU TIRAR
    pilha->topo = apagar->prox;

    free(apagar);
	}
}

int push(PILHA* pilha, int valor) {
   struct elemento* novo = (struct elemento*) malloc(sizeof(struct elemento));
	// struct elemento novo;

  novo->valor = valor;
  novo->prox = pilha->topo;

  pilha->topo = novo;

	return 1;
}

void inicializarPilha(PILHA* pilha) {
	pilha->topo = NULL;
}

void limpaPilha(PILHA* pilha) {
	struct elemento* loop = pilha->topo;
  struct elemento* apagar;

  while (loop != NULL) {
    apagar = loop;
    loop = loop->prox;

    free(apagar);
  }

  pilha->topo = NULL;
}

int length(PILHA* pilha) {
	int tamanho = 0;

  struct elemento* loop = pilha->topo;

  while (loop != NULL) {
    tamanho++;
    loop = loop->prox;
  }

  return tamanho;
}

void imprimirPilha(PILHA pilha) {
  struct elemento* loop = pilha.topo;

  printf("MINHA PILHA\n");

  while (loop != NULL) {
    printf("|_%d_| \n", loop->valor);
    loop = loop->prox;
  }

  printf("FIM\n");
}