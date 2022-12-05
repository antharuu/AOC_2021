#include <iostream>
#include "Day_1.h"
#include "Input.h"

using namespace std;

Day_1::Day_1() {
    data_from(1, true);

    int result = get_increased_count();

    cout << "Result: " << result << endl;
}

int Day_1::get_increased_count() const {
    int count = 0;
    int lastInput = -1;

    for (int i: input) {
        if (lastInput > 0 && i > lastInput) count++;
        lastInput = i;
    }

    return count;
}

void Day_1::data_from(int day, bool test = false) {
    vector<string> tmp_inputs = get_input(day, test);

    for (const auto &tmp_input: tmp_inputs) {
        input.push_back(stoi(tmp_input));
    }
}

