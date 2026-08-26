#include <iostream>
#include <vector>
#include <cmath>

// Small Project: Quadratic Equations Solver/Analyzer

int input_validation(float min, float max){
    int input;
    while(true){
        std::cin >> input;

        // check if input is between min and max
        if(input < min || input > max){
            std::cout << "Insert a valid number\n";
        }
        else{break;}
    }
    return input;
}

float calculate_discriminant(float a, float b, float c, bool print){
    // certain functions use this function without the intent to
    // print anything, so it only prints the discriminant informations
    // if the user ask for it
    if(print == true){
        if(b*b - 4*a*c > 0){
            std::cout << "The equation has 2 roots\n";
        }
        else if(b*b - 4*a*c == 0){
            std::cout << "The equation has one root\n";
        }
        else{
            std::cout << "The equation has no real roots\n";
        }
    }
    return b*b - 4*a*c;
}

std::vector<float> apply_quadratic_formula(float a, float b, float c, float discriminant){
    // solutions
    std::vector<float> solutions;

    // discriminant cannot be under 0, or else there would
    // not have real solutions
    if(discriminant>=0){
        if(discriminant == 0){
            solutions.push_back(-b/(2*a));
        } 
        else{
            solutions.push_back((-b+std::sqrt(discriminant))/(2*a));
            solutions.push_back((-b-std::sqrt(discriminant))/(2*a));
        }
    }
    return solutions;
}

std::vector<float> calculate_vertex_position(float a, float b, float c, float discriminant){
    float x = -b/(2*a);
    float y = -discriminant/(4*a);
    std::vector<float> coordinates_x_y = {x, y};
    return coordinates_x_y;
}

int main(){
    std::cout << "\n--Quadratic formula solver--\n\n";
    
    while(true){
        float a; float b; float c;
        // --TERMS INPUT--
        while(true){
            std::cout<< "Input the terms:\n";
            // a
            std::cout << "Coeficient 'a': ";
            // reject a = 0
            while(true){
                std::cin >> a; // variable and input
                std::cout << "\n";
                if(a == 0){std::cout << "a cannot be 0, Type again:\n"; continue;}
                else{break;}
            }

            // b
            std::cout << "Coeficient 'b': ";
            std::cin >> b; // variable and input
            std::cout << "\n";

            // c
            std::cout << "Constant 'c': ";
            std::cin >> c; // variable and input
            std::cout << "\n";

            // equation print
            std::cout << "Your equation is: " << a << "x^2 + " << b << "x + " << c << "\n";
            std::cout << "Proceed? 1 for yes, 0 for no.\n";
            if(input_validation(0, 1) == 0){
                continue;
            }
            else{
                break;
            }
        }


        // --ACTION INPUT--
        std::cout << "Select what you want to get:\n";
        // --MENU--
        std::cout << "1. Discriminant \n2. Roots \n3. Vertex position\n4. Quit\n";
        int action = input_validation(1, 4);

        // --ACTIONS--
        // discriminant
        if(action == 1){
            std::cout << "\n";
            float disc = calculate_discriminant(a, b, c, true);
            std::cout << "Discriminant: " << disc << "\n";
        }
        
        // equation solver
        else if(action == 2){
            std::vector<float> sols = apply_quadratic_formula(a, b, c, calculate_discriminant(a, b, c, false));

            if(sols.empty()){std::cout << "No real roots\n";}

            else{
                std::cout << "The roots are: ";
                for(int i = 0; i < sols.size(); i++){
                    std::cout << sols[i] << "   ";
                }
                std::cout << "\n";
            }
        }

        // vertex
        else if(action == 3){
        std::cout << "The vertex coordinates, in (x,y) order, is:\n";
        std::vector<float> coordinates_x_y = calculate_vertex_position(a, b, c, calculate_discriminant(a, b, c, false));
        for(int i = 0; i < coordinates_x_y.size(); i++){
            std::cout << coordinates_x_y[i] << "  ";
        }
        std::cout << "\n";
    }
        
        // quit
        else if(action == 4){
            std::cout<< "Quitting...\n\n\n";
            return 0;
        }
        std::cout << "\n\n\n";

    }
    return 0;
}