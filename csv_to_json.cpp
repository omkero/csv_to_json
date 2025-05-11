#include <cstddef>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "csv_to_json.h"

using namespace CsvToJson;

CtJ::CtJ() {};

void CtJ::ExtractWords(std::string line, std::vector<std::string> &words,char* seperator) {
    std::stringstream ss(line);
    std::string key;

    while (std::getline(ss, key, *seperator)) 
    {
        words.push_back(key);
    }
}

void CtJ::ExtractHeaders(std::string line, std::vector<std::string> &head, char* seperator) {
    std::stringstream ss(line);
    std::string key;

    while (std::getline(ss, key, *seperator)) 
    {
        head.push_back(key);
    }
}


void CtJ::PrintOut(std::vector<std::string> &head, std::vector<std::string> &words) {

    for (size_t i = 0; i < head.size(); ++i) {
        std::cout << head[i];
        if (i != head.size() - 1) { 
            std::cout << ",";
        }
    }

    std::cout << std::endl;

    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << words[i];
        if (i != words.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;

    
    std::cout << "----------------------------------------------------------" << std::endl;
}


void CtJ::SaveAsJson() {

}