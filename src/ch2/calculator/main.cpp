//
// Created by efuquen on 10/15/22.
//

#include <cstdio>
#include <stdexcept>

struct Calculator {
    enum class Operation {
        Add, Subtract, Multiply, Divide
    };
    Operation op_;

    int calculate(int a, int b) {
        switch(op_) {
            case (Operation::Add): {
                return a + b;
            } break;
            case (Operation::Subtract): {
                return a - b;
            } break;
            case (Operation::Multiply): {
                return a * b;
            } break;
            case (Operation::Divide): {
                return a / b;
            } break;
            default: {
                throw std::invalid_argument("invalid operation");
            }
        }
    }
};

int main() {
    Calculator add_calc {Calculator::Operation::Add};
    Calculator sub_calc { Calculator::Operation::Subtract};
    Calculator mult_calc { Calculator::Operation::Multiply};
    Calculator div_calc { Calculator::Operation::Divide};

    printf("1 + 2 = %d\n", add_calc.calculate(1, 2));
    printf("1 - 2 = %d\n", sub_calc.calculate(1, 2));
    printf("1 * 2 = %d\n", mult_calc.calculate(1, 2));
    printf("1 / 2 = %d\n", div_calc.calculate(1, 2));
}