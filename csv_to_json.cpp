#include <cstddef>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "csv_to_json.h"
#include "json.hpp"
#include <fstream>


using json = nlohmann::json;
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


void CtJ::PrintOut(std::vector<std::string> &head, std::vector<std::string> &rows) {
    for (size_t i = 0; i < head.size(); ++i) {
        std::cout << head[i];
        if (i != head.size() - 1) { 
            std::cout << ",";
        }
    }

    std::cout << std::endl;

    for (size_t i = 0; i < rows.size(); ++i) {
        std::cout << rows[i];
        if (i != rows.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
    
    std::cout << "----------------------------------------------------------" << std::endl;
}


void CtJ::SaveAsJson(const std::vector<std::string>& head, const std::vector<std::vector<std::string>>& rows_vector) {
    std::ofstream file("output.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    json array = json::array();

    std::cout << "proccessing..." << std::endl;
    for (const auto& row : rows_vector) {
        json obj;
        for (size_t i = 0; i < head.size(); ++i) {
            std::string key = head[i];
            std::string value = row[i];

            key.erase(std::remove(key.begin(), key.end(), '\r'), key.end());
            value.erase(std::remove(value.begin(), value.end(), '\r'), value.end());

            obj[key] = value;
        }
        array.push_back(obj);
    }

    file << array.dump(4);
    file.close();
    std::cout << "Saved " << array.size() << " rows to output.json" << std::endl;
}
