#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

///Função pre-ordem compactada
void pre_ordem(Arvore *a) {
if(verifica_arv_vazia(a)) {return;}

printf("%c ", a->info); //Visita a raiz
pre_ordem(a->esq); //Percorre a subárvore esquerda
pre_ordem(a->dir); //Percorre a subárvore direita
}

///Função pre-ordem extensa
/*
void pre_ordem(Arvore *a, Arvore *e, Arvore *d) {
//Percurso: R,E,D
if(verifica_arv_vazia(a) == 0) {printf("%c ", a->info);} //Visita a raiz
if(verifica_arv_vazia(e) == 0) {pre_ordem(a->esq, a->esq->esq, a->esq->dir);} //Percorre a subárvore esquerda
if(verifica_arv_vazia(d) == 0) {pre_ordem(a->dir, a->dir->esq, a->dir->dir);} //Percorre a subárvore direita
}
*/

///Função in_ordem compactada
void in_ordem(Arvore *a) {
if(verifica_arv_vazia(a)) {return;}

in_ordem(a->esq); //Percorre a subárvore esquerda
printf("%c ", a->info); //Visita a raiz
in_ordem(a->dir); //Percorre a subárvore direita
}

///Função in_ordem extensa
/*
void in_ordem(Arvore *a, Arvore *e, Arvore *d) {

if(verifica_arv_vazia(e) == 0) {in_ordem(a->esq, a->esq->esq, a->esq->dir);} //Percorre a subárvore esquerda
if(verifica_arv_vazia(a) == 0) {printf("%c ", a->info);} //Visita a raiz
if(verifica_arv_vazia(d) == 0) {in_ordem(a->dir, a->dir->esq, a->dir->dir);} //Percorre a subárvore direita
}
*/

///Função in_ordem compactada
void pos_ordem(Arvore *a) {
if(verifica_arv_vazia(a)) {return;}

pos_ordem(a->esq); //Percorre a subárvore esquerda
pos_ordem(a->dir); //Percorre a subárvore direita
printf("%c ", a->info); //Visita a raiz
}

///Função in_ordem extensa
/*
void pos_ordem(Arvore *a, Arvore *e, Arvore *d) {

if(verifica_arv_vazia(e) == 0) {pos_ordem(a->esq, a->esq->esq, a->esq->dir);} //Percorre a subárvore esquerda
if(verifica_arv_vazia(d) == 0) {pos_ordem(a->dir, a->dir->esq, a->dir->dir);} //Percorre a subárvore direita
if(verifica_arv_vazia(a) == 0) {printf("%c ", a->info);} //Visita a raiz
}
*/

int pertence_arv (Arvore *a, char c) {
int esq, dir;

if(verifica_arv_vazia(a)) {return 0;} //Árvore sem nós, impossível que o elemento pertença à árvore!

if(a->info == c) {return 1;} //Elemento pertence à arvore

//Utilizando a pesquisa binária para facilitar a busca:
if (c < a->info) {esq = pertence_arv(a->esq, c);}
else {dir = pertence_arv(a->dir, c);}

return esq + dir;
}

int conta_nos (Arvore *a) {

//Nó: Subárvore (pode ser um nó pai ou filho de graus 1 ou 2 ou nó de grau 0 / sem filhos)

//Se encontrar um nó, continua a busca p/ esquerda e p/ direita, incrementando o somatório de nós recursivamente
if(!verifica_arv_vazia(a)) {return 1 + conta_nos(a->esq) + conta_nos(a->dir);} 
else {return 0;} //Árvore sem nós
}

int calcula_altura_arvore (Arvore *a) {
int altura_esq, altura_dir;

//Altura: Comprimento do caminho mais longo da raiz até uma das folhas

if (verifica_arv_vazia(a)) {return -1;}
else
{
   altura_esq = (calcula_altura_arvore(a->esq)); 
   altura_dir = (calcula_altura_arvore(a->dir)); 

   //Verificamos e retornamos o maior dos caminhos (esquerda ou direita) recursivamente 
   return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}
}

int conta_nos_folha (Arvore *a) {

if (verifica_arv_vazia(a)) {return 0;} //Arvore sem nós, portanto, sem folhas
else 
{
   if (verifica_arv_vazia(a->esq) && verifica_arv_vazia (a->dir)) //Caso não tenha filhos (nó de grau)
   {
      //Encontrou uma folha, incrementa-se o somatório de nós e continua a busca p/ esquerda e p/ direita recursivamente (outros ramos)
      return 1 + conta_nos_folha(a->esq) + conta_nos_folha(a->dir);
   }
   else {return conta_nos_folha(a->esq) + conta_nos_folha(a->dir);} //Continua a busca
}
}

int main (int argc, char *argv[]) {

            /*RAMOS DA SUBÁRVORE DA ESQUERDA*/
Arvore *a = constroi_arv ('a', //RAIZ PRINCIPAL 
         constroi_arv('b',
   cria_arv_vazia(), constroi_arv('d',
               cria_arv_vazia(), cria_arv_vazia())),
            /*RAMOS DA SUBÁRVORE DA DIREITA*/
         constroi_arv('c',
         //ESQUERDA DE 'c'
         constroi_arv('e',
   cria_arv_vazia(), cria_arv_vazia()),
         //DIREITA DE 'c'
         constroi_arv('f',
   cria_arv_vazia(),cria_arv_vazia())));	

printf("\n       | Percursos |\n\n");
printf("Pre-ordem (R,E,D): ");
pre_ordem (a);

printf("\n");

printf("In-ordem  (E,R,D): ");
in_ordem (a);

printf("\n");

printf("Pos-ordem (E,D,R): ");
pos_ordem (a);

printf("\n\n");

printf("Entre com o caractere a ser pesquisado na arvore: ");
char c;
scanf(" %c", &c);

int pertence = 0;
pertence = pertence_arv(a, c);

if (pertence) {printf("\nO caractere '%c' pertence a arvore!\n", c);}
else {printf ("\n\aO caractere '%c' nao pertence a arvore!\n", c);}

printf("\n    | Caracteristicas |\n\n");

int nos = 0;
nos = conta_nos (a);
printf("NOS: %d\n", nos);

int altura = 0;
altura = calcula_altura_arvore(a);
printf("ALTURA: %d\n", altura);

int folhas = 0;
folhas = conta_nos_folha(a);
printf("FOLHAS: %d\n\n", folhas);

arv_libera (a);
return 0;
}
