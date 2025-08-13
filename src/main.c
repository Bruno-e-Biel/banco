#include "../include/utils.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void login(char *in_email, char *in_password);
void menu(float *cash);
void withdraw(float *cash);
void deposit(float *cash);

const char *email = "usermail@gmail.com";
const char *password = "000";
bool auth = false;
bool should_close = false;

int main(void){
    // readfile("data/login.json"); // apenas umas ideia

    char in_email[255];
    char in_password[255];
    float cash = 0;
    printf("Informe o email e senha: \n(Email: -1 para sair)\n");

    while (auth == 0 && should_close == 0){
        fgets(in_email, sizeof(in_email), stdin);
        fgets(in_password, sizeof(in_password), stdin);
        in_email[strcspn(in_email, "\n")] = 0;
        in_password[strcspn(in_password, "\n")] = 0;
        login(in_email, in_password);
    }

    while (auth == 1 && should_close == 0) {
        menu(&cash);
    }

    return 0;
}

void login(char *in_email, char *in_password) {
    if (
        !strcmp(in_email, email) && 
        !strcmp(in_password, password))
    {
        auth = true;
    } else if (!strcmp(in_email, "-1")) {
        should_close = true;
        auth = false;
    } else {
        auth = false;
    }
}

void menu(float *cash) {
    unsigned int operation;
    printf("Bem vindo! Selecione uma operação: \n0-Sair | 1-Depositar | 2-Sacar\n");
    fflush(stdin);
    scanf("%d%*c\n", &operation);

    switch (operation) {
        case 0:
            should_close = true;
        break;
        case 1:
            printf("OK DEPOSIT\n");
            deposit(cash);
        break;
        case 2:
            printf("OK WITHDRAW\n");
        break;
        default:
            printf("Escolha uma opção válida!\n");
        break;
    }
}


void withdraw(float *cash){

}

void deposit(float *cash){

}
