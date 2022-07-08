//
// Created by Luke Roland on 7/8/22.
//
#include <stdbool.h>
#include "config.h"

#ifndef DATA_MANAGEMNT_SYSTEM_USER_H
#define DATA_MANAGEMNT_SYSTEM_USER_H

// strcut for an active or inactive user
typedef struct user
{
    char username[MAX_USER_LEN];
    char password[MAX_HASH_LEN];
    char salt[MAX_SALT_LEN];
    int  user_id;
    int  privileges;
    bool is_new_user;
    bool active;
}   user;

// create a new user
extern user new_user(char username[MAX_USER_LEN], char password[MAX_HASH_LEN], int user_id);

// duplicate an existing user
extern user duplicate_user(user existing_user);

// update an existing user
extern void update_user(struct user *existing_user, char username[MAX_USER_LEN], char password[MAX_HASH_LEN], int nuser_id);

// update ax existing users username
extern void update_username(struct user *existing_user, char username[MAX_USER_LEN]);

// update an existing users password
extern void update_password(struct user *existing_user, char password[MAX_HASH_LEN]);

// write a user into the users file
extern void write_user(struct user *existing_user);

// read an existing user from the users file
extern user read_user(int user_id);

// delete an existing user from the users file
extern void delete_user(int user_id);

// print a user to stdio
extern void print_user(user _user);

#endif //DATA_MANAGEMNT_SYSTEM_USER_H
