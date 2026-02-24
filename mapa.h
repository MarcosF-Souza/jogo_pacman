#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

typedef struct Mapa {
  char **matriz;  //'ponteiro para ponteiro'
  int linhas;
  int colunas;
} TMapa;

typedef struct Posicao {
  int x;
  int y;
} TPosicao;

void lerMapa(TMapa *m);
void imprimirMapa(TMapa *m);
void liberarMapa(TMapa *m);
void alocarMapa(TMapa *m);
int validarMapa(TMapa *m, int x, int y);  //vê se a posição passou das fronteiras do mapa
int validarPosicao(TMapa *m, int x, int y);  //vê se a posição é vazia
int validarParede(TMapa *m, int x, int y);
int validarPersonagem(TMapa *m, char personagem, int x, int y);
int podeAndar(TMapa *m, char personagem, int x, int y);  //junta as funções 'validarMapa' e 'validarPosicao'
void andarNoMapa(TMapa *m, int xOrigem, int yOrigem, int xDestino, int yDestino);
void copiarMapa(TMapa *origem, TMapa *destino);

int encontrarMapa(TMapa *m, TPosicao *p, char c);  //retorna inteiro para saber se achou ou não o personagem