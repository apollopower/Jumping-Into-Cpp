#ifndef CALC_H
#define CALC_H

struct Operators {
    int val1;
    int val2;
};

Operators newOperator(int x, int y);
int add(Operators num_set);
int subtract(Operators num_set);
int multiply(Operators num_set);
int divide(Operators num_set);

#endif