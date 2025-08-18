#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "types.h"

void withdraw(Account *account);
void deposit(Account *account);
void view_history(Account *account);
void view_cash(Account *account);
void login(Account *account, char *in_email, char *in_password, bool *auth, bool *should_close);
