#include <stdio.h>
#include <stdlib.h>

int numNotas;
int maxNotas = 10;
int notas[10];
int length = sizeof(notas) / sizeof(notas[0]); // Tamanho do array

int isEmpty() {
    if (notas[numNotas - 1] <= 0) {
        printf("\nNotas nao registadas\n");
        return 0;
    }

    return 1;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void registarNotas(){
    int tempNota;
    int i;

    printf("Numero de notas: ");
    scanf("%d", &numNotas);
    
    if (numNotas > maxNotas || numNotas <= 0) {
        printf("MAXIMO 10 NOTAS!\n");
    }
    else{
        for (i = 0; i < numNotas; i++){
            
            printf("Nota: ");
            scanf("%d", &tempNota);

            if(tempNota < 0 || tempNota > 20){
                printf("NOT VALID!\n");
                break;
            }

            notas[i] = tempNota;
        }
    }
}

void calcMedia(){
    int soma = 0;
    float media = 0;

    if (isEmpty() != 0) {
        for (int i = 0; i < numNotas; i++) {
            soma += notas[i];
        }

        media = soma/numNotas;
        printf("Media %f", media);
    }
}

void mostrarNotas(){
    if (isEmpty() != 0) {
        for (int i = 0; i < numNotas; i++) {
            printf("%d", notas[i], "\n");
        }
    }
    
}


void menu() {
    int opt;

    while(opt != 7){
        printf("1 - Registar Notas.\n2 - Mostrar todas as notas.\n3- Calcular e mostrar a média da turma.\n4- Indicar a melhor nota e a pior nota.\n5- Mostrar as notas ordenadas de forma crescente (usar um algoritmo de ordenacao estudado).\n6 - Contar quantos alunos tiveram nota >= 10 (aprovados) e quantos tiveram nota < 10 (reprovados).\n7- Sair do programa.\n");
        printf("Option: ");
        scanf("%d", &opt);

        switch (opt) {
        case  1:
            registarNotas();
            break;
        case  2:
            mostrarNotas();
            break;
        case  3:
            calcMedia();
            break;
        case  4:
            printf("%d", opt);
            break;
        case  5:
            printf("%d", opt);
            break;
        case  6:
            printf("%d", opt);
            break;
        case  7:
            printf("%d", opt);
            break;
        
        default:
            printf("Choose a valid option!\n");
        }
    }
}

int main() {
    menu();

    return 0;
}   