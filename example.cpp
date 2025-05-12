#include "csv_to_json.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#define MISSING_ERR "Missing file_path"
#define INVALID_FILE_ERR "Invalid file format its must be .csv"
#define MISSING_COMMA_COMMAND "Missing -seperator command"
#define MISSING_COMMAND "Missing command"

int main (int argc, char* argv[])
{
    std::string file_path = static_cast<std::string>(argv[1]);
    std::string command = static_cast<std::string> (argv[2]);
    char* seperator = argv[3];

    if (argc < 2) {
        std::cout << MISSING_ERR << std::endl;
        return -1;
    }

    if (file_path.find(".csv") == std::string::npos) {
        std::cout << INVALID_FILE_ERR << std::endl;
        return -1;
    }
    if (command.find("-seperator") == std::string::npos) {
        std::cerr << MISSING_COMMA_COMMAND << std::endl;
        return -1;
    }
    if (!seperator) {
        std::cerr << MISSING_COMMAND << std::endl;
        return -1;
    }


    std::vector<std::vector<std::string>> rows_vector;
    std::vector<std::string> head;

    std::string line;
    std::fstream file(file_path);


    if (!file.is_open())
    {
        std::cerr << "couldn't open this file" << std::endl;
    }

    CsvToJson::CtJ ctj;

    if (std::getline(file, line)) 
    {
        ctj.ExtractHeaders(line, head,  seperator);
    }

    while (std::getline(file, line)) 
    {
            std::vector<std::string> row;
            ctj.ExtractWords(line, row,  seperator);
            rows_vector.push_back(row);
    }

    /*
        for (auto& item : words)
    {
           ctj.PrintOut(head, item);
    }
    */

    ctj.SaveAsJson(head, rows_vector);


    file.close();
    return 0;
}
