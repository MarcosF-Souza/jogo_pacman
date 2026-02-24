#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogeFoge.h"
#include "mapa.c"

//definição de variáveis globais
TMapa m;
TPosicao heroi;
int temPipula = 0;

int main(void) {

  leMapa(&m);
  encontraMapa(&m, &heroi, HEROI);  //encontra a posição do herói

  do
  {
    printf("Tem pilula: %s\n", (temPipula ? "SIM" : "NAO"));
    imprimeMapa(&m);

    char comando;
    scanf(" %c", &comando);
    
    move(comando);
    if(comando == BOMBA) explodePilula();

    fantasmas();

  } while(!acabou());

  liberaMapa(&m);
}

//*************** FUNÇÕES ***************
void explodePilula() {
  printf("EXPLODIU");
}

int validarDirecao(char direcao) {
  return (direcao==ESQUERDA || direcao==CIMA || direcao==BAIXO || direcao==DIREITA); 
}

void move(char direcao) {

  int proximoX = heroi.x;
  int proximoY = heroi.y;

  //começando a validar a entrada do usuário
  if(!validarDirecao(direcao)) 
    return;

  switch (direcao) 
  {
    case ESQUERDA:
      proximoY--;
      break;
    case CIMA:
      proximoX--;
      break;
    case BAIXO:
      proximoX++;
      break;
    case DIREITA:
      proximoY++;
      break;
  }

  if(!podeAndar(&m, HEROI, proximoX, proximoY))
    return;

  if (validaPersonagem(&m, PILULA, proximoX, proximoY))
  {
    temPipula = 1; //verdadeiro
  }
  
  andaNoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);
  heroi.x = proximoX;
  heroi.y = proximoY;
}

void fantasmas() {

  TMapa copia;
  copiaMapa(&m, &copia);

  for(int i=0; i<m.linhas; i++) 
  {
    for(int j=0; j<m.colunas; j++) 
    {

      if(copia.matriz[i][j] == FANTASMA) 
      {
        int xDestino, yDestino;
        int encontrou = praOndeFantasmaVai(i, j, &xDestino, &yDestino);

        if(encontrou) 
          andaNoMapa(&m, i, j, xDestino, yDestino);
      }
    }
  }

  liberaMapa(&copia);
}

int praOndeFantasmaVai(int xOrigem, int yOrigem, int *xDestino, int *yDestino) {

  int opcoes[4][2] = 
  {
    {xOrigem, yOrigem+1},
    {xOrigem+1, yOrigem},
    {xOrigem, yOrigem-1},
    {xOrigem-1, yOrigem}
  };

  srand(time(0));
  for(int i=0; i<10; i++) 
  {
    int posicao = rand()%4;
    if(podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) 
    {
      *xDestino = opcoes[posicao][0];
      *yDestino = opcoes[posicao][1];

      return 1;
    }
  }

  return 0;
}

int acabou() {

  TPosicao pos;
  int pacMan = encontraMapa(&m, &pos, HEROI);

  return !pacMan;
}