#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHA 10
#define MAX_COLUNA 20
#define MIN_COLUNA 1
#define MIN_LINHA 1

int main() {
    srand(time(NULL));
    int ox = MAX_COLUNA - 2 , oy = MAX_LINHA - 2;
    int px = 1, py = 1;
    int tx = (int)(MAX_COLUNA * 0.4), ty = (int)(MAX_LINHA * 0.6);
    int mx = (int)(MAX_COLUNA * 0.7), my = (int)(MAX_LINHA * 0.7);
    int x, y;
    char comando;
    int movimentoRealizado;
    int dificuldade = 1;

    for (;;){

        system("CLS");

        printf("\n\t- Viagem a Ilha do Medo -\n\n");
        printf("\t    Setor %d - Dungeon\n\n", dificuldade);
        for (y = 0; y < MAX_LINHA; y++){
            for (x = 0; x < MAX_COLUNA; x++){
                if (y == 0 || x == 0 || x == MAX_COLUNA - 1 || y == MAX_LINHA - 1)
                    printf("=");
                else if (x == px && y == py)
                    printf("J");
                else if (x == mx && y == my)
                    printf("Z");
                else if (x == ox && y == oy)
                    printf("@");
                else
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");

        printf("Guia: \tJ - Jogador\tZ - Zumbi\t@ - Saida\n\n");
        printf("Comandos: \tW - Cima\tA - Esquerda\tS - Baixo\tD - Direita\n\n");
        printf("Sua vez! Movimente-se: ");
        fflush(stdin);
        scanf(" %c", &comando);

        movimentoRealizado = 1;
        switch(comando){
            case 'w':
                py -= 1;
                if (py < 1){
                    py = 1;
                    movimentoRealizado = 0;
                }
                break;

            case 's':
                py += 1;
                if (py >= MAX_LINHA - 1){
                    py = MAX_LINHA - 2;
                    movimentoRealizado = 0;
                }
                break;

            case 'a':
                px -= 1;
                if (px < 1){
                    px = 1;
                    movimentoRealizado = 0;
                }
                break;

            case 'd':
                px += 1;
                if (px >= MAX_COLUNA - 1){
                    px = MAX_COLUNA - 2;
                    movimentoRealizado = 0;
                }
                break;

            default:
                movimentoRealizado = 0;
                printf("\nComando invalido!\n\nPor favor selecione um dos comandos listados acima.\n\n");
                system("PAUSE");
        }

        if (movimentoRealizado == 1){
            int direcao = rand() % 4;
            switch(direcao){
                case 0:
                    my -= dificuldade;
                    if (my < 1){
                        my = 1;
                    }
                    break;

                case 1:
                    my += dificuldade;
                    if (my >= MAX_LINHA - 1){
                        my = MAX_LINHA - 2;
                    }
                    break;

                case 2:
                    mx -= dificuldade;
                    if (mx < 1){
                        mx = 1;
                    }
                    break;

                case 3:
                    mx += dificuldade;
                    if (mx >= MAX_COLUNA - 1){
                        mx = MAX_COLUNA - 2;
                    }
                    break;
            }
        }

        if (px == mx && py == my){
            printf("\n\t       FIM DE JOGO!\n\tVoce foi morto pelo zumbi.\n\n");
            break;
        }

        else if (px == ox && py == oy){
            printf("\n                   VOCE CONSEGUIU!\n\tVoce prosseguiu para a proxima caverna.\n\n");
            system("PAUSE");

            dificuldade++;

            px = 1;
            py = 1;
            tx = 1;
            ty = 1;
            mx = (int)(MAX_COLUNA * 0.7);
            my = (int)(MAX_LINHA * 0.7);

        }
    }

    system("PAUSE");
    return 0;
}

