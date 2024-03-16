#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <openssl/sha.h>

#include "./source/class.h"
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
        std::cout << "\ nError: [ User Already Exists! ]";
    }

	return 0;
}

/** 
    IMPORTANT: Organize the libs in modules (./Search, ./Modify)
    *!USER -> NAME IS CASE SENSITIVE -- NEED TO FIX THAT --

    Test: Pass class User as reference instead of pointer

 -> Features to add (!)

	modifyFile.c -> writeNewUser(param): 
		- verify if user already exists before adding it

 -> Critical Functions:
        - filterUser(std::string &line) => searchFile.c 
        - filterId(std::string &line) => searchFile.c
    .
    compile: g++ -o main main.cpp -lssl -lcrypto
*/