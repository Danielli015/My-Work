#include <iostream>

// challenge: find the sum of all multiples of 3 and 5 below 1000

int get_sum(int maxi){
    int sum = 0;

    for(int i = 1; i< maxi; i++){
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    return sum;
}


int main(){
    int final_sum = get_sum(1000);
    std::cout << "\nThe sum is: " << final_sum << "\n";

    return 0;
}