#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <openssl/sha.h>

#include "class.h"
#include "searchFile.c"
#include "modifyFile.c"

int main (int argc, char *argv[])
{
    std::string database_name = "test.txt";

    

    return 0;
}

// g++ -o main main.cpp -lssl -lcrypto

/*
    Critical Functions:
        - filterUser(std::string &line) => searchFile.c 
        - filterId(std::string &line) => searchFile.c

*/