#ifndef CSV_TO_JSON_H
#define CSV_TO_JSON_H

#include <vector>
#include <string>

namespace CsvToJson {
    class CtJ {
        public:
        CtJ();
        void ExtractWords(std::string line, std::vector<std::string> &words, char* seperator);
        void ExtractHeaders(std::string line, std::vector<std::string> &head, char* seperator);
        void PrintOut(std::vector<std::string> &head, std::vector<std::string> &words);
        void SaveAsJson();
    };
}

#endif