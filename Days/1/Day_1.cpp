//
// Created by Antharuu on 05/12/2022.
//

#include <iostream>
#include <numeric>
#include "Day_1.h"
#include "../../Input.h"

Day_1::Day_1() {
    data_from(1, false);

    int result = get_increased_count();
    int result2 = get_measurement_increased_count();

    std::cout << "Result   : " << result << std::endl;
    std::cout << "Result 2 : " << result2 << std::endl;
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

int Day_1::get_measurement_increased_count() {
    int count = 0, lastSum = 0;
    std::vector<std::vector<int>> measurements;

    for (int i = 0; i < input.size(); i++) {
        std::vector<int> measurement;

        measurement.push_back(input[i]);
        if (input.size() > i + 1) measurement.push_back(input[i + 1]);
        if (input.size() > i + 2) measurement.push_back(input[i + 2]);

        measurements.push_back(measurement);
    }

    std::vector<int> sums;
    for (const std::vector<int> &measurement: measurements) {
        sums.push_back(std::accumulate(measurement.begin(), measurement.end(), 0));
    }


    for (int i: sums) {
        if (lastSum > 0 && i > lastSum) count++;
        lastSum = i;
    }

    return count;
}


void Day_1::data_from(int day, bool test = false) {
    std::vector<std::string> tmp_inputs = Input::get_input(day, test);
    input.resize(tmp_inputs.size());
    for (const auto &tmp_input: tmp_inputs) {
        input.push_back(stoi(tmp_input));
    }
}
