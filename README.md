<h2 align=center>Simple C++ Database Project</h2>

<h4 align=center>This project uses the librarys (excluding the essencial)</h4>

- `fstream` to manipulate files, the C FILE was discarted due some inconsistencies
- `openssl/sha.h` to generate the SHA256 Hashes that will be storage
- `iomainp` in this project, it is only used to help generate the Hashes

___

<h2 align=center>How to use it?</h3>

##### You can simply install the "./source" folder and include the following files: 

- `source/class.h` it defines the User class and methods (it does not have access to the database, obviously)
- `source/searchFile.h` defines all the functions that search in the database, using only `std::ifstream`
- `source/modifyFile.h` defines all the functions that modify the database, using only `std::ofstream`
- `source/security.h` defines all the functions that checks the security of the database, using `std::fstream`

<div align=center>

###### The project is current in development. Soon I will add the exact instructions on how to use it.

</div>

<br/>

<h2 align=center>Security</h3>

<p align="justify">
  
The database file is locally storage, so, you maybe asking about the security of the files.
For sure, the program can't prevent the user to **modify** the file, but, the `security.h` provide functions 
to check if the file follows the defined patterns (if not, the program will not work with the file).

The encryptation is SHA256, because of that, it is almost impossible to break the file usernames and passwords,
also, the file provides functions to sum up all the ASCII characters into a defined in-program fixed value. The program will work with
that ASCII summed-up automatically, making the development much easier.

Concluding: It is a good library for simple projects, such as games, portfolio-making, etc. But, thinking about security, It should not 
be used for **really important** data 

</p>

<hr>

### Future of the project

- [ ] `.dbinfo` file to describe the database
- [ ] Create a table with N number of columns, each with T data type
- [ ] Cache for optimizing search
