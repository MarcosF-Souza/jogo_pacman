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

  lerMapa(&m);
  encontrarMapa(&m, &heroi, HEROI);  //encontra a posição do herói

  do
  {
    printf("Tem pilula: %s\n", (temPipula ? "SIM" : "NAO"));
    imprimirMapa(&m);

    char comando;
    scanf(" %c", &comando);
    move(comando);

    if(comando == BOMBA) 
      explodePilula();

    fantasmas();

  } while(!acabou());

  liberarMapa(&m);
}

//*************** FUNÇÕES ***************
void explodePilula() {

  if(!temPipula) return;

  explodePilula2(heroi.x, heroi.y, 0, 1, 3);
  explodePilula2(heroi.x, heroi.y, 0, -1, 3);
  explodePilula2(heroi.x, heroi.y, 1, 0, 3);
  explodePilula2(heroi.x, heroi.y, -1, 0, 3);

  temPipula = 0;
}

void explodePilula2(int x, int y, int somaX, int somaY, int qtd) {

  if(qtd==0) return;

  int novoX = x + somaX;
  int novoY = y + somaY;

  if(!validarMapa(&m, novoX, novoY)) return;
  if(validarParede(&m, novoX, novoY)) return; 

  m.matriz[novoX][novoY] = VAZIO;
  explodePilula2(novoX, novoY, somaX, somaY, qtd-1);
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

  if (validarPersonagem(&m, PILULA, proximoX, proximoY))
  {
    temPipula = 1; //verdadeiro
  }
  
  andarNoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);
  heroi.x = proximoX;
  heroi.y = proximoY;
}

void fantasmas() {

  TMapa copia;
  copiarMapa(&m, &copia);

  for(int i=0; i<m.linhas; i++) 
  {
    for(int j=0; j<m.colunas; j++) 
    {

      if(copia.matriz[i][j] == FANTASMA) 
      {
        int xDestino, yDestino;
        int encontrou = praOndeFantasmaVai(i, j, &xDestino, &yDestino);

        if(encontrou) 
          andarNoMapa(&m, i, j, xDestino, yDestino);
      }
    }
  }

  liberarMapa(&copia);
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
  int pacMan = encontrarMapa(&m, &pos, HEROI);

  return !pacMan;
}