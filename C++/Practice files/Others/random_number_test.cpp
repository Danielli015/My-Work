#include <iostream>
#include <cstdlib>
#include <ctime>

// learning about random numbers in C++

int main(){

    // rand() generates a random number, using it alone does not give
    // you too much control about it
    int randomN1 = rand();
    std::cout << "This is a random number: " << randomN1 << "\n";

    // srand() can be used along with rand() to generate a new random
    // number each execution, giving it a seed (a number to start the
    // random formula). But it would generate the same sequence, so
    // you can use the current time
    srand(time(NULL)); // giving the formula a seed
    int randomN2 = rand();
    std::cout << "This is a different random number each execution: " << randomN2 << "\n";

    // you can also make the random numbers be between two other numbers
    // the formula is: rand() % (max - min + 1) + min
    int randomN3 = rand() % 101;
    std::cout << "This is a random number between 0 and 100: " << randomN3 << "\n";
    std::cout << "Also different each execution because the seed was already set!";

    // between 50 and 100
    int randomN4 = rand() % 51 + 50;
    std::cout << "This is a random number between 50 and 100: " << randomN4 << "\n";

    return 0;
}