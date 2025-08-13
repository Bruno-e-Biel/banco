#include <stdio.h>
#include "../include/utils.h"

void readfile(char *filepath){

    FILE *fileptr;
    char file_buffer[255];

    fileptr = fopen(filepath, "r");

    if (fileptr == NULL){
        printf("Error to open file.\n");
    }

    while(fgets(file_buffer, 255, fileptr) != NULL){
        printf("%s", file_buffer);
    }

    fclose(fileptr);

}
