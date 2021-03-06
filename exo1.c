#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// I)
// Faites un programme qui demande à l'utilisateur de saisir un entier et qui le sauvegarde dans le fichier toto.bin

int main() {
    int mon_entier;
    char *ma_chaine = malloc(sizeof(char*));
    int fd;
    printf("Saisissez un entier : ");

    if (scanf("%d", &mon_entier)!=1){
        fprintf(stderr, "erreur saisi entier : ");
        exit(EXIT_FAILURE);
    }

    printf("Saisissez une chaine : ");

    if (scanf("%s", ma_chaine)!=1){
        fprintf(stderr, "erreur saisi chaine : ");
        exit(EXIT_FAILURE);
    }

    if ((fd = open("toto.bin", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR ))==-1){
        perror("Erreur ouverture : ");
        exit(EXIT_FAILURE);
    }

    if(write(fd, &mon_entier, sizeof(int)) == -1) {
        perror("Erreur write : ");
        exit(EXIT_FAILURE);
    }

    if(write(fd, &ma_chaine, sizeof(char*)) == -1) {
        perror("Erreur write : ");
        exit(EXIT_FAILURE);
    }

    if (close(fd)==-1){
        perror("Erreur close : ");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

// Faites un programme qui demande à l'utilisateur de saisir un entier et qui le sauvegarde dans le fichier toto.bin

// Sortie :
// 0000000    08  00  00  00
// 0000004

// Que se passe-t-il si vous ouvrez le fichier avec un éditeur de code classique ?
// C'est pas beau :    

// Modifiez votre programme et écrivez maintenant une chaîne de caractères (lue au clavier) après l'entier.
// Observez le contenu du 􏰁chier avec od et votre éditeur de code.

