#include <iostream>
#include "Day_1.h"
#include "Input.h"

using namespace std;

Day_1::Day_1() {
    data_from(1, false);

    int result = get_increased_count();
    int result2 = get_measurement_increased_count();

    cout << "Result   : " << result << endl;
    cout << "Result 2 : " << result2 << endl;
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
    vector<vector<int>> measurements;

    for (int i = 0; i < input.size(); i++) {
        vector<int> measurement;

        measurement.push_back(input[i]);
        if (input.size() > i + 1) measurement.push_back(input[i + 1]);
        if (input.size() > i + 2) measurement.push_back(input[i + 2]);

        measurements.push_back(measurement);
    }

    vector<int> sums;
    for (const vector<int> &measurement: measurements) {
        int sum = 0;
        for (int i: measurement) {
            sum += i;
        }
        sums.push_back(sum);
    }


    for (int i: sums) {
        if (lastSum > 0 && i > lastSum) count++;
        lastSum = i;
    }

    return count;
}


void Day_1::data_from(int day, bool test = false) {
    vector<string> tmp_inputs = get_input(day, test);

    for (const auto &tmp_input: tmp_inputs) {
        input.push_back(stoi(tmp_input));
    }
}
