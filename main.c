/**
 * @file main.c
 * @author luke roland (lukeroland.email@gmail.com)
 * @brief target for compilation
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "src/headers/user.h"
#include "src/headers/interface.h"
#include <stdio.h>


// main function
int main(void)
{
    user default_user = new_user("username", "password", 1);
    print_user(default_user);

    print_line(100, 2);
    load("Updating user.", 3);
    print_line(100, 2);

    update_user(&default_user, "Luke", "Password_😉", 420);
    print_user(default_user);
}