#ifndef _tree_h_
#define _tree_h_

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void);
Arvore* constroi_arv (char c, Arvore *e, Arvore *d);
int verifica_arv_vazia (Arvore *a);
void arv_libera (Arvore* a);
void pre_ordem(Arvore *a);
void in_ordem(Arvore *a);
void pos_ordem(Arvore *a);
int pertence_arv (Arvore *a, char c);
int conta_nos (Arvore *a);
int calcula_altura_arvore (Arvore *a);
int conta_nos_folha (Arvore *a);

#endif