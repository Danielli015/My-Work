#include <iostream>

// Challenge: get the sum of all odd perfect squares under 348000

long long get_sum(){
    // variable to hold the sum of the perfect squares
    long long perf_squares_sum = 0;

    // even though i won't be too much, if i is int, i*i=int*int, which results in int
    // to fix this, make i long long too
    for(long long i = 1; i < 348000; i = i+2){
        perf_squares_sum += i*i;
    }

    return perf_squares_sum;
}

int main(){
    long long sum = get_sum();
    std::cout << sum;
}