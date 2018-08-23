#include <iostream>
#include "calculator.h"

using namespace std;

Operators newOperator(int x, int y) {
    Operators new_op;
    new_op.val1 = x;
    new_op.val2 = y;
    return new_op;
}

int add(Operators num_set) {
    return num_set.val1 + num_set.val2;
}

int subtract(Operators num_set) {
    return num_set.val1 - num_set.val2;
}

int multiply(Operators num_set) {
    return num_set.val1 * num_set.val2;
}

int divide(Operators num_set) {
    return num_set.val1 / num_set.val2;
}