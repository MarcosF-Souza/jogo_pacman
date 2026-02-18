# jogo_pacman

Este é um projeto de um jogo inspirado no clássico Pac-Man, desenvolvido em linguagem C como parte de estudos de programação. O herói (`@`) deve coletar itens enquanto foge dos fantasmas (`F`) em um labirinto.

## 🎮 Funcionalidades

- Labirinto carregado de arquivo (mapa)
- Movimentação do herói com as teclas `WASD`:
  - `W` = CIMA
  - `S` = BAIXO
  - `A` = ESQUERDA
  - `D` = DIREITA
- Fantasmas que se movem aleatoriamente
- Coleta de pontos (itens representados por `·`)
- Interface textual no terminal

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Bibliotecas padrão: `stdio.h`, `stdlib.h`, `string.h`, `time.h`
- Arquivos de cabeçalho próprios: `fogeFoge.h`, `mapa.h`

## 📦 Como Compilar e Executar

1. Clone o repositório:
    ```bash
    git clone https://github.com/MarcosF-Souza/jogo_pacman.git

    Acesse a pasta do projeto: cd jogo_pacman

    Compile com o GCC: gcc *.c -o pacman

    Execute: ./pacman

Observação: Certifique-se de que os arquivos de mapa (ex: mapa.txt) estejam no mesmo diretório do executável.

## 🧩 Estrutura do Código

  **mapa.h / mapa.c** – funções para carregar, alocar e liberar o mapa.

  **fogeFoge.h** – cabeçalho com as constantes e declarações principais.

  **Constantes definidas:**

    #define ESQUERDA 'a'
    #define CIMA 'w'
    #define BAIXO 's'
    #define DIREITA 'd'
    #define HEROI '@'
    #define FANTASMA 'F'
    #define VAZIO '.'
    #define PAREDE_VERTICAL '|'
    #define PAREDE_HORIZONTAL '-'

## 📬 Contato

  **GitHub:** MarcosF-Souza
  **E-mail:** marcosfsouza.dev@gmail.com

Divirta-se jogando e contribuindo! 😄