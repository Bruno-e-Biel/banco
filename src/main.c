#include "../include/utils.h" // Transactions operations
#include "../include/types.h" // def types to Account
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void menu(Account *account, bool *should_close);

int main(void){
    // readfile("data/login.json"); // apenas umas ideia
    Account account;

    account.id = 1;
    strcpy(account.name, "User");
    strcpy(account.email, "usermail@gmail.com");
    strcpy(account.password, "000");
    account.cash = 0;
    account.history_length = 0;

    char in_email[255];
    char in_password[255];
    bool auth = false;
    bool should_close = false;

    printf("Informe o email e senha: \n(Email: -1 para sair)\n");

    while (auth == 0 && should_close == 0){
        fgets(in_email, sizeof(in_email), stdin);
        fgets(in_password, sizeof(in_password), stdin);
        fflush(stdin);
        in_email[strcspn(in_email, "\n")] = 0;
        in_password[strcspn(in_password, "\n")] = 0;
        login(&account, in_email, in_password, &auth, &should_close);
    }

    while (auth == 1 && should_close == 0) {
        menu(&account, &should_close);
    }

    return 0;
}

void menu(Account *account, bool *should_close) {
    unsigned int operation;
    printf("\nBem vindo! Selecione uma operação: \n0-Sair | 1-Depositar | 2-Sacar | 3-Ver Historico | 4-Ver Saldo \n");
    scanf("%d%*c", &operation);

    switch (operation) {
        case 0:
            *should_close = true;
        break;
        case 1:
            deposit(account);
        break;
        case 2:
            withdraw(account);
        break;
        case 3:
            view_history(account);
        break;
        case 4:
            view_cash(account);
        break;
        default:
            printf("\nEscolha uma opção válida!\n");
        break;
    }
}

