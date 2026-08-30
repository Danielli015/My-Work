#include <iostream>
#include <cstdlib>
#include <ctime>

// attention: if you want to change the levels values, change the variables
// and the menu in levels_display()
// created in 29-30/08/2026

int input_validation(int min, int max){
    int option;

    while(true){
        // input
        std::cout << "\nSelect your option: ";
        std::cin >> option;
        std::cout << "\n";

        // check if input is between min and max
        if(option < min || option > max){
            std::cout << "Please type a valid number\n";
        }
        else{break;}
    }
    return option;
}

void main_game(int lvlmin, int lvlmax){
    // random number between 0 and lvlmax
    int correct_answer = rand() % (lvlmax - lvlmin +1) + lvlmin;

    std::cout << "Try guessing the random number between " << lvlmin << " and " << lvlmax << "!\n";

    int attempts = 1;
    int guess;
    while(true){
        std::cout << "Attempt " << attempts << ": ";
        std::cin >> guess;

        if(guess == correct_answer){break;}
        else if(guess < correct_answer){
            std::cout << "Try a higher number\n\n";
        }
        else{
            std::cout << "Try a smaller number\n\n";
        }
        attempts++;
    }
    std::cout << "Congratulations! The number was " << correct_answer << "\n";
    std::cout << "You guessed it with " << attempts << " attempts!\n\n";
}

void user_game_create(){
    int min;    
    int max;

    while(true){
        std::cout << "Minimum: ";
        std::cin>>min;
        std::cout << "\n";

        std::cout << "Max: ";
        std::cin>>max;
        std::cout << "\n";

        if(min > max){
            std::cout << "Minimum can't be higher than max\n";
        }
        else if(min == max){
            std::cout << "Minimum and max can't be the same\n";
        }
        else{break;}
    }
    main_game(min, max);
}

void levels(){
    std::cout << "What level do you want to play?\n";

    std::cout << "1 - up to 100\n";
    std::cout << "2 - up to 10.000\n";
    std::cout << "3 - up to 1.000.000\n";
    std::cout << "4 - numbers of your choice!\n";
    int lvl1max = 100; int lvl2max = 10000;
    int lvl3max = 1000000;


    int level = input_validation(1, 4);
    if(level == 1){
        main_game(0, lvl1max);
    }
    else if(level == 2){
        main_game(0, lvl2max);
    }
    else if(level == 3){
        main_game(0, lvl3max);
    }
    else if(level == 4){
        user_game_create();
    }
}

void tutorial(){
    std::cout << "How to play:\n";
    std::cout << "The program will generate a random number\n";
    std::cout << "and you must guess what it is. If you get\n";
    std::cout << "it wrong, the program will print for you\n";
    std::cout << "to try a higher or smaller number.\n";
    std::cout << "You can play the main 3 levels or create your own!\n\n";
}

int main(){
    // set seed for randomness
    srand(time(0));

    while(true){
        std::cout << "\n--Number Guessing Game!--\n\n";

        // first menu, play or tutorial
        std::cout << "1 - Play\n";      // go to levels
        std::cout << "2 - How to play"; // go to text

        int intro_option = input_validation(1, 2);


        // go to option
        if(intro_option == 1){
            // take user to choose level, then to main game
            levels();
        }
        else if(intro_option == 2){
            tutorial();
            levels();
        }

        std::cout << "Play again?\n0 for no, 1 for yes\n";
        int option = input_validation(0, 1);

        if(option == 0){return 0;}
    }
    return 0;

}