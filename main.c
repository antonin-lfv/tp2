#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

off_t taille_fichier(char* path) {
    int fd;
    off_t len;

    if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR ))==-1){
        perror("Erreur ouverture ");
        exit(EXIT_FAILURE);
    }

    // Déplacement à la fin du fichier pour avoir la taille
    if((len =lseek(fd, 0, SEEK_END)) == -1) {
        perror("Erreur lors du déplacement dans le fichier ");
        exit(EXIT_FAILURE);
    }
    // printf("Taille %lld", len);

    if (close(fd)==-1){
        perror("Erreur close : ");
        exit(EXIT_FAILURE);
    }
    return len;
}

off_t save_10_first_int(char* path) {
    int fd, i;
    off_t pos;

    if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR ))==-1){
        perror("Erreur ouverture ");
        exit(EXIT_FAILURE);
    }

    // Écriture de 10 entiers
    for(i = 0; i < 10; i++) {
        if(write(fd, &i, sizeof(int)) == -1) {
            perror("Erreur write ");
            exit(EXIT_FAILURE);
        }
    }

    // Position courante
    if((pos =lseek(fd, 0, SEEK_CUR)) == -1) {
        perror("Erreur lors du déplacement dans le fichier ");
        exit(EXIT_FAILURE);
    }

    /*
    // On se déplace à la pos 1024
    if(lseek(fd, 1024, SEEK_SET) == -1) {
        perror("Erreur lors du déplacement dans le fichier ");
        exit(EXIT_FAILURE);
    }
     */

    if (close(fd)==-1){
        perror("Erreur close : ");
        exit(EXIT_FAILURE);
    }

    return pos;
}

int main() {
    printf("Taille fichier : %lld", taille_fichier( "/Users/antoninlefevre/Downloads/Licence info/L3/S6/601 - OS/TP/TP2_file/cmake-build-debug/toto.bin"));
    printf("\nSauvegarde réussi ! Position actuelle : %lld", save_10_first_int("int_10_first.bin"));
    printf("\nTaille fichier : %lld", taille_fichier( "int_10_first.bin"));
    return 0;
}



