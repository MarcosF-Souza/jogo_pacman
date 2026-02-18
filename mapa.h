#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

typedef struct Mapa {
  char **matriz;  //'ponteiro para ponteiro'
  int linhas;
  int colunas;
} TMapa;

typedef struct Posicao {
  int x;
  int y;
} TPosicao;

void leMapa(TMapa *m);
void imprimeMapa(TMapa *m);
void liberaMapa(TMapa *m);
void alocaMapa(TMapa *m);
int validaMapa(TMapa *m, int x, int y);  //vê se a posição passou das fronteiras do mapa
int validaPosicao(TMapa *m, int x, int y);  //vê se a posição é vazia
int validaParede(TMapa *m, int x, int y);
int validaPersonagem(TMapa *m, char personagem, int x, int y);
int podeAndar(TMapa *m, char personagem, int x, int y);  //junta as funções 'validaMapa' e 'validaPosicao'
void andaNoMapa(TMapa *m, int xOrigem, int yOrigem, int xDestino, int yDestino);
void copiaMapa(TMapa *origem, TMapa *destino);

int encontraMapa(TMapa *m, TPosicao *p, char c);  //retorna inteiro para saber se achou ou não o personagem