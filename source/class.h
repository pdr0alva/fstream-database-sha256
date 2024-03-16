#ifndef CLASS_H
#define CLASS_H

// ------------------------------------------- //

class User
{
private:    
    std::string name_hash, password_hash;

    void convertStrToHash(std::string &name_string, std::string &password_string);
    
public: 
    bool setUserByString(std::string &name_arg, std::string &password_arg);
    bool setUserByHash(std::string &name_hash_arg, std::string &password_hash_arg);
    
    inline std::string getNameHash() { return this -> name_hash; }
    inline std::string getPasswordHash() { return this -> password_hash; }

    User(std::string cons_name = "", std::string cons_password = "")
    {
        convertStrToHash(cons_name, cons_password);
    }
};

bool User::setUserByHash(std::string &name_hash_arg, std::string &password_hash_arg)
{
    /* VERIFY IF IS A REAL HASH */
    this->name_hash = name_hash_arg;
    this->password_hash = password_hash_arg;
    
    return 1;
}

bool User::setUserByString(std::string &name_arg, std::string &password_arg)
{
    convertStrToHash(name_arg, password_arg);
    return true;    
}

void User::convertStrToHash(std::string &name_string, std::string &password_string) 
{
    auto calculateSHA256 = [](const std::string &input) -> std::string 
    {
        SHA256_CTX sha256_context;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        std::stringstream ss;

        SHA256_Init(&sha256_context);
        SHA256_Update(&sha256_context, input.c_str(), input.length());
        SHA256_Final(hash, &sha256_context);

        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) 
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);

        return ss.str();
    };

    this->name_hash = calculateSHA256(name_string); 
    this->password_hash = calculateSHA256(password_string); 

    // name_hash = name_string;
    // password_hash = password_string;

    return;
} 

#endif