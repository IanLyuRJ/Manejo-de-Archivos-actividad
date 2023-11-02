#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenarRapido(int *arreglo, int inicio, int fin);
int particionar(int *arreglo, int inicio, int fin);
void intercambiar(int *a, int *b);
double calcularMedia(int *arreglo, int tamano);
double calcularMediana(int *arreglo, int tamano);
int calcularModa(int *arreglo, int tamano);
void imprimirHistograma(int *arreglo, int tamano);

int main() {
    int N;
    printf("Numero de elementos a ordenar:\n");
    scanf("%d", &N);

    int arreglo[N];
    int arregloCopia[N];  

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        arreglo[i] = rand() % 30;  
        arregloCopia[i] = arreglo[i];  
    }

    printf("\nLista sin ordenar:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arregloCopia[i]);
    }
    printf("\n");

    ordenarRapido(arreglo, 0, N - 1);

    printf("\nLista ordenada:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    printf("\nElemento menor: %d\n", arreglo[0]);
    printf("\nElemento mayor: %d\n", arreglo[N - 1]);

    printf("\nMedia de la lista ordenada: %.2f\n", calcularMedia(arreglo, N));
    printf("\nMediana de la lista ordenada: %.2f\n", calcularMediana(arreglo, N));
    printf("\nModa de la lista ordenada: %d\n", calcularModa(arreglo, N));

    imprimirHistograma(arreglo, N);  

    return 0;
}

void ordenarRapido(int *arreglo, int inicio, int fin) {
    if (inicio < fin) {
        int indiceParticion = particionar(arreglo, inicio, fin);
        ordenarRapido(arreglo, inicio, indiceParticion - 1);
        ordenarRapido(arreglo, indiceParticion + 1, fin);
    }
}

int particionar(int *arreglo, int inicio, int fin) {
    int pivote = arreglo[fin];
    int i = (inicio - 1);

    for (int j = inicio; j <= fin - 1; j++) {
        if (arreglo[j] < pivote) {
            i++;
            intercambiar(&arreglo[i], &arreglo[j]);
        }
    }
    intercambiar(&arreglo[i + 1], &arreglo[fin]);
    return (i + 1);
}

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double calcularMedia(int *arreglo, int tamano) {
    double suma = 0;
    for(int i = 0; i < tamano; i++) {
        suma += arreglo[i];
    }
    return suma / tamano;
}

double calcularMediana(int *arreglo, int tamano) {
    if (tamano % 2 == 0) {
        return (arreglo[tamano / 2 - 1] + arreglo[tamano / 2]) / 2.0;
    } else {
        return arreglo[tamano / 2];
    }
}

int calcularModa(int *arreglo, int tamano) {
    int maximaVeces = 0;
    int moda = 0;
    for (int i = 0; i < tamano; ++i) {
        int veces = 0;
        for (int j = 0; j < tamano; ++j) {
            if (arreglo[j] == arreglo[i]) {
                veces++;
            }
        }
        if (veces > maximaVeces) {
            maximaVeces = veces;
            moda = arreglo[i];
        }
    }
    return moda;
}

void imprimirHistograma(int *arreglo, int tamano) {
    int frecuencia[30] = {0};
    int maxFrecuencia = 0;

 
    for (int i = 0; i < tamano; i++) {
        frecuencia[arreglo[i]]++;
        if (frecuencia[arreglo[i]] > maxFrecuencia) {
            maxFrecuencia = frecuencia[arreglo[i]];
        }
    }
    
    printf("\nHistograma de frecuencia:\n");
    for (int i = 0; i < 30; i++) {
        printf("%2d : ", i);
        int longitudBarra = (frecuencia[i] * 30) / maxFrecuencia; 
        for (int j = 0; j < longitudBarra; j++) {
            printf("*");
        }
        printf("\n");
    }
}






