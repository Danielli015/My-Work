#include <iostream>
#include <vector>

// given a value of n, find the nth prime number

bool is_prime(int n){
    if (n < 2){return false;}
    // the square root of n is where its factor pairs meet (start reversing)
    // so if you checked everything before sqrt of n, you wont find factors after it
    for(int i = 2; i*i <= n; i++){
        // check if n has divisors, if it has, then its not a prime
        if(n%i == 0){return false;}
    }
    return true;
}

int nth_prime(int index){
    int number{0};
    int count{0};

    // executes until finding the index prime
    while(count < index){
        number++;
        if(is_prime(number)){
            // when finding a prime, add 1 to the counting
            count++;
        }
    }
    return number;
}

int main(){
    std::cout << "\n\n--Type a number to know the prime number in its position!--\n";
    std::cout << "Example: 10 prints 29 because 29 is the 10th prime number\n";
    std::cout << "Position: ";
    int p;
    while(true){
        std::cin >> p;
        if(p <= 0){std::cout << "\nInvalid. Type again\n";}
        else{break;}
    }

    int prime = nth_prime(p);
    std::cout << "The " << p << "th prime number is: " << prime << "\n\n";
    
    
    return 0;
}