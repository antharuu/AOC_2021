//
// Created by Antharuu on 06/12/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Input.h"

// Function get_input take a int as a parameter, which is the day number. It then
// opens the file "inputs/[number].txt" and return the content of the file as a string.
std::vector<std::string> Input::get_input(int day, bool test = false) {
    std::string input;
    std::string line;

    std::string path = "../inputs/";
    if (test) path += "test_";
    path += std::to_string(day) + ".txt";

    std::ifstream file(path);

    if (file.is_open()) {
        while (getline(file, line)) {
            input += line + std::string("\n");
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }

    return split(input, '\n');
}

std::vector<std::string> Input::split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}