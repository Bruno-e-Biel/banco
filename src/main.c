#include "../include/utils.h"
#include <stdio.h>

int main(void){
    welcome();

    FILE *fileptr;
    char file_buffer[255];

    fileptr = fopen("data/login.json", "r");

    if (fileptr == NULL){
        printf("Error to open file.\n");
        return -1;
    }

    while(fgets(file_buffer, 255, fileptr) != NULL){
        printf("%s", file_buffer);
    }

    fclose(fileptr);

    return 0;
}
