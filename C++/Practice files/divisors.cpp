#include <iostream>
#include <vector>

// program to check how many divisors a number has and if it is a prime or not

std::vector<int> get_divisors(int number){
    std::vector<int> divisors;    

    for(int i = 1; i <= number; i++){
        if(number % i == 0){
            divisors.push_back(i);
        }
    }
    return divisors;
}

int main (){
    // introduction and input
    std::cout << "\n-- Divisors counter --\n\n";

    int number;
    while(true){
        std::cout << "Insert a number above 0: ";
        std::cin >> number;
        // check for no negatives
        if(number <= 0){
            continue;
        }
        else{break;}
    }

    std::cout << "Calculating...\n\n";

    // divisors vector
    std::vector<int> divisors = get_divisors(number);

    // prime check
    if(divisors.size() == 2){
        std::cout << "The number " << number << " has " << divisors.size() << " divisors, meaning it is a prime!\n";
        std::cout << "Its divisors are 1 and itself.\n";
    }
    else{
        std::cout << "The number " << number << " has " << divisors.size() << " divisors,\nwhich are:\n";
        // vector print
        for(int i = 0; i <= divisors.size() -1; i++){
            std::cout << divisors[i] << "   ";
        }
    }

}