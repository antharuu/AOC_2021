#ifndef AOC_INPUT_H
#define AOC_INPUT_H

class Input {
public:
    static std::vector<std::string> get_input(int day, bool test);

    static std::vector<std::string> split(const std::string &s, char delim);
};

#endif //AOC_INPUT_H
