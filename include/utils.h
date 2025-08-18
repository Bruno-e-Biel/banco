#pragma once
#include <stdio.h>
#include "types.h"

void readfile(char *filepath);
void withdraw(Account *account);
void deposit(Account *account);
void view_history(Account *account);
void view_cash(Account *account);
