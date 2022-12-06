//
// Created by Antharuu on 06/12/2022.
//

#ifndef AOC_DAY_2_H
#define AOC_DAY_2_H

#include <vector>

struct Instruction {
    std::string key;
    int value;
};

class Day_2 {
public:
    Day_2();

    std::vector<std::string> input;

    void data_from(int day, bool test);
private:
    int position = 0;
    int depth = 0;
    int aim = 0;

    int get_step_1();
    int get_step_2();

    static Instruction get_instruction(const std::string& basicString);
};

#endif //AOC_DAY_2_H
