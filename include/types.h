#pragma once

typedef  enum {
    DEPOSIT,
    WITHDRAW
} TransactionType;

typedef struct {
    TransactionType type;
    float value;
    char date[50];
} Transaction;

typedef struct {
    int id;
    char name[50];
    char email[100];
    char password[100];
    float cash;
    Transaction history[100];
    int history_length;
} Account;
