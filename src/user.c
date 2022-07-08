/**
 * @file user.c
 * @author luke roland
 * @brief deals the the current user. Allows for the creation of a user, modification of a user,
 * and the destruction of a user from either the program memory, or the database where the user
 * stored
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 * @note this file doesn't need to be secure because it only deals with encrypted data
 */
#include "headers/config.h"
#include "headers/user.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// create a new user
user new_user(char username[MAX_USER_LEN], char password[MAX_HASH_LEN], int user_id) // todo: needs to check is username is taken
{
    // initialize a new current_user with default values
    user nuser =
            {
                    "username", // username
                    "password", // password
                    0,          // user id
                    0,          // privileges
                    true,       // is new user
                    false,      // is active user
            };
    if (user_id != 0) // check that user id isn't zero. If the user id is zero the program will simply return the default user
    {
        // update the current_user fields
        strcpy(nuser.username, username);
        strcpy(nuser.password, password);
        nuser.user_id = user_id;
        nuser.privileges = 0; // default privileges for all new users
        nuser.is_new_user = true; // default for a user not read from and archive
        nuser.active = false; // new users are inactive by default
    }
    return nuser;
}

// duplicate an existing user
user duplicate_user(user existing_user)
{
    user current_user = new_user(existing_user.username, existing_user.password, existing_user.user_id);
    return current_user;
}

// update an existing user
void update_user(struct user *existing_user, char username[MAX_USER_LEN], char password[MAX_HASH_LEN], int nuser_id) // todo: needs to check if username is taken
{
    if (nuser_id != 0) // check the current_user isn't being reassigned to a default user
    {
        strcpy(((existing_user)->username), username);
        strcpy(((existing_user)->password), password);
        (existing_user)->user_id = nuser_id;
    }
    else               // throw error telling user the problem
    {
        printf("attempting to assign existing user to the default user ID");
    }
}

// update ax existing users username
void update_username(struct user *existing_user, char username[MAX_USER_LEN])
{
    strcpy((existing_user -> username), username);
}

// update an existing user's password. note: only encrypted passwords should be passed into this function
void update_password(struct user *existing_user, char password[MAX_HASH_LEN])
{
    strcpy((existing_user -> password), password);
}

// write a user into the users file
void write_user(struct user *existing_user)
{
    // open file
    // if is_new_user
    // crete a new field and set its id to "user.user_id"
    // change user.is_new_user to "false"
    // else
    // find user by user id
    // update user fields
    // close file
}

// read an existing user from the users file
user read_user(int user_id)
{
    // open users file
    // look for user id in file
    // if user id doesn't exit throw an error
    // else scan the username and password of the user
    // and write them into current user
    return new_user("", "", 0);
}

// delete an existing user from the users file
void delete_user(int user_id) // todo: think about changing return type to int for error handling
{
    // open users file
    // look for user id in file
    // if user id doesn't exit throw an error
    // else delete the user
}

// print a user to stdio
void print_user(user _user)
{
    printf("Username: %s\n", _user.username);
    printf("Password: %s\n", _user.password);
    printf("User ID: %d\n",  _user.user_id);
}