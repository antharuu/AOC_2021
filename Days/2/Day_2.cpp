//
// Created by Antharuu on 06/12/2022.
//

#include <vector>
#include <string>
#include <iostream>
#include "Day_2.h"
#include "../../Input.h"

Day_2::Day_2() {
    data_from(2, true);

    // print input
    for (auto &i: input) {
        std::cout << i << std::endl;
    }
}

void Day_2::data_from(int day, bool test) {
    input = Input::get_input(day, test);
}
