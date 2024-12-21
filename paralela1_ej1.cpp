#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numero;
    #pragma omp parallel num_threads(8) private(numero)
    {
        numero = rand() % 100 + 1;

        printf("Hilo %d: Número aleatorio generado: %d\n", omp_get_thread_num(), numero);
    }

    return 0;
}
