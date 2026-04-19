#include <stdio.h>
#include <stdlib.h>     // Para exit()
#include <unistd.h>     // Para fork()
#include <sys/wait.h>   // Para wait()
int main() {
    pid_t pid = fork();
    int status;
    
    if (pid == 0) {
        // --- CÓDIGO DEL PROCESO HIJO ---
        printf("Soy el hijo, trabajando...\n");
        // Hago mi trabajo...
        
        // Termino y comunico mi estado. 
        // Usemos 0 para indicar que todo fue bien.
        printf("Hijo terminando.\n");
        exit(0); // O también podrías usar 'return 0;' aquí.

    } 
    
    else {
        // --- CÓDIGO DEL PROCESO PADRE ---
        printf("Soy el padre, esperando a que mi hijo termine...\n");

        // Pauso mi ejecución hasta que el hijo termine.
        // Esto evita que el hijo se convierta en zombi.
        wait(&status);
    }
}
