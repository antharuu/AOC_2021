#ifndef AOC_DAY_1_H
#define AOC_DAY_1_H


#include <vector>

class Day_1 {
public:
    Day_1();

    std::vector<int> input;

    int get_increased_count() const;

    void data_from(int day, bool test);

    int get_measurement_increased_count();
};


#endif //AOC_DAY_1_H
