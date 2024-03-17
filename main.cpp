#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <openssl/sha.h>

#include "./source/User.h"
#include "./source/searchFile.c"
#include "./source/modifyFile.c"

int main (void)
{
    User input_user;

	std::string database_name = "test.txt";
    std::string input_name, input_password;

    std::cout << "Input Name....: ";
    std::cin >> input_name;

    std::cout << "Input Password: ";
    std::cin >> input_password;

    input_user.setUserByString(input_name, input_password);

    if (writeNewUser(database_name, &input_user) != -1)
    {
        std::cout << "\nSuccess!";
    }
    else 
    {
        std::cout << "\nError: [ User Already Exists! ]";
    }

	return 0;
}

/** 
    IMPORTANT: Organize the libs in modules (./Search, ./Modify)
    ANALIZE:   Set a class to operate and manage the database file


 -> Features to add (!)
    
    1. Start Database properly (security.h) 
        a. Verify the id sequence (if it's crescent, if not, organize it) => first organize in crescent, after it, set to the {1, 2, 3, ... } pattern
        b. Delete duplicated users (delete the newest one)
        c. Verify if every user has name and password in a valid SHA256 Hash (if not valid, delete it) 
    
    2. Features to add: number of columns defined when starting database
     

 -> Critical Functions:
        - filterUser(std::string &line) => searchFile.c 
        - filterId(std::string &line) => searchFile.c
    .
    compile: g++ -o main main.cpp -lssl -lcrypto
*/