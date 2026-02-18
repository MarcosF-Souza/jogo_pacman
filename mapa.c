#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapa.h"

void copiaMapa(TMapa *origem, TMapa *destino) {

  destino->linhas = origem->linhas;
  destino->colunas = origem->colunas;

  alocaMapa(destino);
  for(int i=0; i<origem->linhas; i++) {

    strcpy(destino->matriz[i], origem->matriz[i]);
  }
}

void andaNoMapa(TMapa *m, int xOrigem, int yOrigem, int xDestino, int yDestino) {

  char personagem = m->matriz[xOrigem][yOrigem];
  m->matriz[xDestino][yDestino] = personagem;
  m->matriz[xOrigem][yOrigem] = '.'; 
}

int validaMapa(TMapa *m, int x, int y) {

  if(x>=m->linhas || y>=m->colunas)
    return 0;

  return 1;
}

int validaPosicao(TMapa *m, int x, int y) {
  return m->matriz[x][y] == VAZIO;
}

int podeAndar(TMapa *m, int x, int y) {
  return validaMapa(m, x, y) && validaPosicao(m, x, y);
}

int encontraMapa(TMapa *m, TPosicao *p, char c) {

  //sempre tenho que percorrer a matriz inteira pra encontrar o herói, como melhorar isso?
  for(int i=0; i < m->linhas; i++) {
    for(int j=0; j < m->colunas; j++) {

      if(m->matriz[i][j] == c) {  //guardando a posição do PacMan

        p->x = i;
        p->y = j;
        return 1;
      }
    }
  }

  return 0;
}

void liberaMapa(TMapa *m) {

  for(int i=0; i < m->linhas; i++)
    free(m->matriz[i]);

  free(m->matriz);
}

void alocaMapa(TMapa *m) {

  m->matriz = malloc(sizeof(char*) * m->linhas);  //malloc: memory allocation

  for(int i=0; i < m->linhas; i++) 
    m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);  // Aloca colunas (+1 para '\0')
}

void leMapa(TMapa *m) {

  FILE *f; //variável para manipular arquivos
  f = fopen("C:\\Users\\marco\\OneDrive\\Desktop\\Marcos\\alura\\C\\pacMan\\mapa.txt", "r");
  
  if(!f) //verifica se o arquivo foi aberto corretamente 
  {  
    printf("\n\nErro na leitura do mapa");
    exit(1);
  }

  fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
  alocaMapa(m);

  for(int i=0; i < m->linhas; i++) 
    fscanf(f, "%s", m->matriz[i]);

  fclose(f);
}

void imprimeMapa(TMapa *m) { 
  for(int i=0; i < m->linhas; i++)
    printf("%s\n", m->matriz[i]);
}