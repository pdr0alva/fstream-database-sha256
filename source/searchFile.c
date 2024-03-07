inline long int filterId(std::string &line) 
{
    std::string id_str = line.substr(0, line.find(':'));
    return !id_str.empty() ? stoi(id_str) : 0; 
}

inline User filterUser(std::string &line)
{
    User filter_user;

    std::string filter_name = line.substr(line.find(':') + 1, 64);
    std::string filter_password = line.substr(line.find('&') + 1, 64);

    filter_user.setUserHash(filter_name, filter_password);
    return filter_user;
}

long int searchLastIndex(std::string &database_name)
{   
    char endline;
    std::ifstream database;
    std::string file_buf;

    database.open(database_name, std::ios::in | std::ios::app);

    if (database.is_open())
    {
        database.seekg(-1, std::ios_base::end);

        while (1)
        {
            database.get(endline);

            if (int(database.tellg()) <= 1)
            {
                database.seekg(0);
                break;
            }
            else if (endline == '\n')
            {
                break;
            }
            else 
            {
                database.seekg(-2, std::ios_base::cur);
            }
        }

        std::getline(database, file_buf);
        database.close();
    }
    else return -2;

    return filterId(file_buf);
}

User searchUserByIndex(std::string &database_name, long int search_id) 
{
    User index_user;

    std::string file_buf, id_str;
    std::ifstream database;

    database.open(database_name, std::ios::in);

    if (database.is_open())
    {
        while (getline(database, file_buf))
        {
            if (filterId(file_buf) == search_id)
            {
                index_user = filterUser(file_buf);
                break;
            }
        }
        database.close();
    }

    return index_user;
}

User searchUserByName(std::string &database_name, std::string search_name_hash)
{
    User search_user;
    std::string line_buff, name_buff;
    std::ifstream database;

    database.open(database_name, std::ios::in);

    if (database.is_open())
    {
        while (getline(database, line_buff))
        {
            name_buff = line_buff.substr(line_buff.find('&'), 64);
            
            if (name_buff == search_name_hash)
            {
                search_user = filterUser(line_buff);
                break;
            }
        }
        database.close();
    }
    
    return search_user;
}