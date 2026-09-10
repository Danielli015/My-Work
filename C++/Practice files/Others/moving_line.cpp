#include <iostream>

// a small experiment with code to create the effect of movement

int main(){
    // the max amount of spaces it will print
    int line_max_distance = 20;
    // the character the line is made of
    std::string line_char = ".\n";

    int spaces = 0;


    while(true){
        // add 1 to spaces 100 times
        // move right
        for(int i = 0; i < line_max_distance; i++){
            spaces++;
            // print the amount of spaces
            for(int i = 0; i < spaces; i++){
                std::cout << " ";
            }
            std::cout << line_char;
        }

        // remove 1 from space 100 times
        // move left
        for(int i = 0; i < line_max_distance; i++){
            spaces--;
            // print the amount of spaces
            for(int i = 0; i < spaces; i++){
                std::cout << " ";
            }
            std::cout << line_char;
        }
    }

    return 0;
}