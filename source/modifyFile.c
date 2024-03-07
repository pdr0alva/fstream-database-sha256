bool writeNewUser(std::string database_name, User *new_user)
{
    long int new_id;
    std::ofstream database;

    database.open(database_name, std::ios::out | std::ios::app);

    if (database.is_open())
    {
        new_id = searchLastIndex(database_name) + 1;

        if (new_id > 1)
            database << "\n";
        
        database <<  new_id << ':' <<  new_user->getNameHash() << '&' << new_user->getPasswordHash();
        database.close();
    }
    else
    {
        return -2;
    }

    return 0;
}