#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

#define ESQUERDA 'a'
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char direcao);

int validarDirecao(char direcao);
void fantasmas();
void explodePilula();
void explodePilula2(int x, int y, int somaX, int somaY, int qtd);

#endif