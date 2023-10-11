// LUISA LIZETH ZEREGA SOTO 
// MAT:356491
// FECHA: 10-OCT-2023
// DESCRIP: Menu de vectores y matrices.
// ZSL_ACT9.CPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenarVector(int vector[], int tam);
void llenarMatriz(int matriz[][4]);
void imprimirVector(int vector[], int tam, char nombre[]);
void imprimirMatriz(int matriz[][4], int filas, int columnas, char nombre[]);
void ordenarVector(int vector[], int tam);
int buscarValorEnVector(int vector[], int tam, int valor);

int main() {
    int opcion;
    int vector[15];
    int matriz[4][4];
    int valor;

    do {
        printf("\nMENÚ\n");
        printf("1.- LLENAR VECTOR\n");
        printf("2.- LLENAR MATRIZ\n");
        printf("3.- IMPRIMIR VECTOR\n");
        printf("4.- IMPRIMIR MATRIZ\n");
        printf("5.- ORDENAR VECTOR\n");
        printf("6.- BUSCAR VALOR EN VECTOR\n");
        printf("0.- SALIR\n");

        printf("\nIngrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                llenarVector(vector, 15);
                break;
            case 2:
                llenarMatriz(matriz);
                break;
            case 3:
                imprimirVector(vector, 15, "vector");
                break;
            case 4:
                imprimirMatriz(matriz, 4, 4, "matriz");
                break;
            case 5:
                ordenarVector(vector, 15);
                break;
            case 6:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                buscarValorEnVector(vector, 15, valor);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

void llenarVector(int vector[], int tam) {
    srand(time(NULL));

    for (int i = 0; i < tam; i++) {
        vector[i] = rand() % 101 + 100;
    }

    printf("Vector llenado exitosamente.\n");
}

void llenarMatriz(int matriz[][4]) {
    srand(time(NULL));

    int numeros[16] = {0};
    int num;
    int fila, columna;

    for (int i = 0; i < 16; i++) {
        do {
            num = rand() % 16 + 1;
        } while (numeros[num - 1] != 0);

        numeros[num - 1] = 1;
        fila = i / 4;
        columna = i % 4;
        matriz[fila][columna] = num;
    }

    printf("Matriz llenada exitosamente.\n");
}

void imprimirVector(int vector[], int tam, char nombre[]) {
    printf("%s: ", nombre);
    for (int i = 0; i < tam; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void imprimirMatriz(int matriz[][4], int filas, int columnas, char nombre[]) {
    printf("%s:\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ordenarVector(int vector[], int tam) {
    int temp;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    printf("Vector ordenado exitosamente.\n");
}

int buscarValorEnVector(int vector[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (vector[i] == valor) {
            printf("El valor %d se encuentra en la posición %d del vector.\n", valor, i);
            return i;
        }
    }
    printf("El valor %d no se encuentra en el vector.\n", valor);
    return -1;
}