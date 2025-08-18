#pragma once

typedef  enum {
    DEPOSIT,
    WITHDRAW
} TransationType;

typedef struct {
    TransationType type;
    float value;
} Transation;

typedef struct {
    int id;
    char name[50];
    char email[100];
    char password[100];
    float cash;
    Transation history[50];

} Account;
