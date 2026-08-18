#include <iostream>

// challenge: find the sum of all even Fibonacci numbers under 4 million

long long get_sum(int limit){
    long long sum = 0;

    long long current = 1; // last number on sequence
    long long previous = 0; // to be summed with current

    // loop from current number to limit
    while(current < limit){
        // the current variable will change, but it still needs its original
        // value to be used, so I use a temporary variable to hold it.
        long long store = current;
        current = previous + current;
        previous = store; // turn previous into the current number
        
        if(current % 2 == 0){sum += current;} // even check
    }
    return sum;
}



int main(){
    long long sum = get_sum(4000000);
    std::cout << sum;

    return 0;
}