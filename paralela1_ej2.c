#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <stdbool.h>
#include <time.h>

int main() {
    int numero_objetivo;
    bool encontrado = false;

    srand(time(NULL));

    printf("Introduce un número entre 1 y 10000: ");
    scanf("%d", &numero_objetivo);

    #pragma omp parallel num_threads(8) shared(encontrado)
    {
        int intento;
        while (!encontrado) {
            intento = rand() % 10000 + 1;

            #pragma omp critical
            {
                if (!encontrado && intento == numero_objetivo) {
                    encontrado = true;
                    printf("Hilo %d acertó el número: %d\n", omp_get_thread_num(), intento);
                }
            }
        }
    }

    printf("Todos los hilos han terminado.\n");
    return 0;
}
