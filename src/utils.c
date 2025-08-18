#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/utils.h"
#include "../include/types.h"

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

void withdraw(Account *account){
    float value = 0;
    TransactionType type = WITHDRAW;
    printf("Digite o valor do saque: \n");
    scanf("%f", &value);

    account->cash -= value;
    account->history[account->history_length].type = type;
    account->history[account->history_length].value = value;
    account->history_length++;
}

void deposit(Account *account){
    float value = 0;
    TransactionType type = DEPOSIT;
    printf("Digite o valor do deposito: \n");
    scanf("%f", &value);

    account->cash += value;
    account->history[account->history_length].type = type;
    account->history[account->history_length].value = value;
    account->history_length++;
}

void view_history(Account *account){
    printf("Historico: \n");
    for (int i = 0; i < account->history_length; i++){
        Transaction transaction = account->history[i];
        printf("\n[%d]: \n Tipo: %s \n Valor: %.2f \n", i, transaction.type == WITHDRAW ? "Saque" : "Deposito", transaction.value);
    }
}

void view_cash(Account *account){
    printf("Saldo: %.2f", account->cash);
}

void login(Account *account, char *in_email, char *in_password, bool *auth, bool *should_close) {
    if (
        !strcmp(in_email, account->email) && 
        !strcmp(in_password, account->password))
    {
        *auth = true;
    } else if (!strcmp(in_email, "-1")) {
        *should_close = true;
        *auth = false;
    } else {
        *auth = false;
    }
}

