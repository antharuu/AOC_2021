//
// Created by Antharuu on 06/12/2022.
//

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "Day_2.h"
#include "../../Input.h"

Day_2::Day_2() {
    data_from(2, false);

    int result = get_step_1();

    std::cout << "Result: " << result << std::endl;
}

void Day_2::data_from(int day, bool test) {
    input = Input::get_input(day, test);
}

// Get the result of step 1
int Day_2::get_step_1() {
    for (const std::string &line: input) {
        Instruction instruction = get_instruction(line);

        if (instruction.key == "forward") {
            position += instruction.value;
        } else if (instruction.key == "down") {
            depth += instruction.value;
        } else if (instruction.key == "up") {
            depth -= instruction.value;
        }
    }

    return position * depth;
}

// Transform a string into an instruction (key and value)
Instruction Day_2::get_instruction(const std::string &line) {
    Instruction instruction;

    // use regex to get the 2 parts in "forward 5" and "up 3"
    const std::regex pattern("([a-z]+) ([0-9]+)");
    std::smatch match;

    if (std::regex_match(line, match, pattern)) {
        instruction.key = match[1];
        instruction.value = std::stoi(match[2]);
    }

    return instruction;
}
