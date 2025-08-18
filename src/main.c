#include "../include/utils.h"
#include "../include/types.h" // def types to Account
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool auth = false;
bool should_close = false;

void login(Account *account, char *in_email, char *in_password);
void menu(Account *account, float *cash);
void withdraw(Account *account, float *cash);
void deposit(Account *account, float *cash);

int main(void){
    // readfile("data/login.json"); // apenas umas ideia
    Account account;
    account.id = 1;
    strcpy(account.name, "User");
    strcpy(account.email, "usermail@gmail.com");
    strcpy(account.password, "000");
    char in_email[255];
    char in_password[255];
    float cash = 0;

    printf("Informe o email e senha: \n(Email: -1 para sair)\n");

    while (auth == 0 && should_close == 0){
        fgets(in_email, sizeof(in_email), stdin);
        fgets(in_password, sizeof(in_password), stdin);
        fflush(stdin);
        in_email[strcspn(in_email, "\n")] = 0;
        in_password[strcspn(in_password, "\n")] = 0;
        login(&account, in_email, in_password);
    }

    while (auth == 1 && should_close == 0) {
        menu(&account, &cash);
    }

    return 0;
}

void login(Account *account, char *in_email, char *in_password) {
    if (
        !strcmp(in_email, account->email) && 
        !strcmp(in_password, account->password))
    {
        auth = true;
    } else if (!strcmp(in_email, "-1")) {
        should_close = true;
        auth = false;
    } else {
        auth = false;
    }
}

void menu(Account *account, float *cash) {
    unsigned int operation;
    printf("Bem vindo! Selecione uma operação: \n0-Sair | 1-Depositar | 2-Sacar\n");
    scanf("%d%*c\n", &operation);

    switch (operation) {
        case 0:
            should_close = true;
        break;
        case 1:
            printf("OK DEPOSIT\n");
            deposit(account, cash);
        break;
        case 2:
            printf("OK WITHDRAW\n");
        break;
        default:
            printf("Escolha uma opção válida!\n");
        break;
    }
}

void withdraw(Account *account, float *cash){

}

void deposit(Account *account, float *cash){

}
