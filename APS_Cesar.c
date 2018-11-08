



#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define V_SIZE 1000000

void ins_direta(int *v, int tam) {
    int aux, i, j;
    for (i = 1; i < tam; i++) {
        aux = v[i];
        j = i - 1;
        while ((j >= 0) && (aux < v[j])) {
            v[j + 1] = v[j]; //deslocando
            j--;
        }
        v[j + 1] = aux;
    }
}


void bubbleSort(int *v, int tam) {

  int i, j, temp, cont = 0, comp = 0;

  for (i = 0; i < tam-1; i++) {
        cont++;
    for (j = (i+1); j < tam; j++) {
        cont++;
      if (v[j] < v[i]) {
            comp++;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }
  printf("Comparações: %d\n",cont);
  printf("Trocas: %d\n",comp);
}

void selectionSort(int *v, int tam) {

  int i, j, min, temp;
  int comp = 0;
  int troca = 0;

  for (i = 0; i < tam-1; i++) {
    min = i;
    comp++;
    for (j = i+1; j < tam; j++) {
      comp++;
      if (v[j] < v[min])
        min = j;
        troca++;
    }
    if (v[i] != v[min]) {
      temp = v[i];
      v[i] = v[min];
      v[min] = temp;

    }
  }
  printf("Comparações: %d\n",comp);
  printf("Trocas: %d\n",troca);
}
void bubleSort( int vetorDesordenado[], int tamanhoVetor )
{
   int i, j, troca=0, cont=0;
   for( i = 0; i < ( tamanhoVetor -1 );  i++ )
   {
       cont++;
      for( j=0; j <( tamanhoVetor -( i +1 ) ); j++ )
      {
          cont++;
         if( vetorDesordenado[j] > vetorDesordenado[j+1] )
         {
             troca++;
            trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] );
         }
      }
   }
   printf("Passadas: %d\nTrocas: %d\n\n",cont,troca);
}

void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;
}

void selecao(int *v, int tam) {
  int i, j, min, aux, cont=0;
  for (i = 0; i < (tam-1); i++)
  {
    cont++;
     min = i;
     for (j = (i+1); j < tam; j++) {
        cont++;
       if(v[j] < v[min])
         min = j;

     }
     if (v[i] != v[min]) {
       aux = v[i];
       v[i] = v[min];
       v[min] = aux;
     }

  }
  printf("Números de LOOP: %d\n\n",cont);;
}

void shakesort(int *v, int tam) {
    int j, k, l, r, aux;

    l = 1;
    r = k = tam - 1;

    do {
        for (j = r; j >= l; j--) {
            if (v[j - 1] > v[j]) {
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
                k = j;
            }
        }
        l = k + 1;
        for (j = l; j <= r; j++) {
            if (v[j - 1] > v[j]) {
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
                k = j;
            }
            r = k - 1;
        }
    } while (l <= r);
}

void gerar_vetor(int *vetor, int tam) {
    int i;
    srand((unsigned) time(NULL));
    printf("Vetor:  ");
    for (i = 0; i < tam; i++) {
        vetor[i] = rand() % 50;
        //printf("%d  ", vetor[i]);
    }
    printf("\n  ");
}

void gerarV(int *v, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        v[i] = i;
    }
}

void main() {
    setlocale(LC_ALL, "Portuguese");
    int e, vet[V_SIZE];

    e = 1;
    do {
        printf("\n_________________________________\n");
        printf("|\tMENU DE OPÇÕES:\t\t|\n");
        printf("|\t1- Bolha\t\t|\n");
        printf("|\t2- Seleção Direta\t|\n");
        printf("|\t3- Inserção Direta\t|\n");
        printf("|\t4- Shakesort\t\t|\n");
        printf("|\t0- Sair\t\t\t|");
        printf("\n_________________________________\n");
        printf("Escolha uma opção: ");
        scanf("%d", &e);

        switch (e) {
            case 1:
                system("cls");
                printf("Método de ordenação: Bolha\n\n");
                gerar_vetor(vet, V_SIZE);
                printf("\n");
                bubbleSort(vet, V_SIZE);
                printf("Vetor ordenado: ");
                //for (int i=0; i <V_SIZE; i++) {
                //    printf("%d   ", vet[i]);
               // }
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Método de ordenação: Seleção Direta\n\n");
                gerar_vetor(vet, V_SIZE);
                printf("\n");
                selectionSort(vet, V_SIZE);
                printf("Vetor ordenado: ");
                for (int i=0; i <V_SIZE; i++) {
                    printf("%d   ", vet[i]);
                }
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Método de ordenação: Inserção Direta\n\n");
                gerar_vetor(vet, V_SIZE);
                printf("\n");
                ins_direta(vet, V_SIZE);
                printf("Vetor ordenado: ");
                for (int i=0; i <V_SIZE; i++) {
                    printf("%d   ", vet[i]);
                }
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Método de ordenação: Shakesort\n\n");
                gerar_vetor(vet, V_SIZE);
                printf("\n");
                shakesort(vet, V_SIZE);
                printf("Vetor ordenado: ");
                for (int i=0; i <V_SIZE; i++) {
                    printf("%d   ", vet[i]);
                }
                getch();
                system("cls");
                break;
            case 0:
                system("cls");
                printf("Pressione qualquer tecla para continuar...\n\n");
                getch();
                exit(0);
                break;
            default:
                system("cls");
                printf("Opção inválida!!!");
                break;
        }
    } while (e);


}