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
	std::string database_name = "test.txt";

	User user("Pedro", "pedro__123456");
	writeNewUser(database_name, &user);

	return 0;
}

/** Tests
	test: Pass class User as reference instead of pointer

*/

/** Features to add (!)

	modifyFile.c -> writeNewUser(param): 
		- verify if user already exists before adding it
*/

// g++ -o main main.cpp -lssl -lcrypto

/*
    Critical Functions:
        - filterUser(std::string &line) => searchFile.c 
        - filterId(std::string &line) => searchFile.c

*/