#include <iostream>
#include <vector>

// Created in 02/09/2026

int get_user_input(int min, int max){
    std::cout << "Type your option: ";
    int option;

        while(true){
            std::cin >> option;
            std::cout << "\n";
            if(option < min || option > max){
                std::cout << "\nType a valid option:\n";
                continue;
            }
            else{return option;}
    }
    return option;
}

void view_tasks(std::vector<std::string> tasks){
    if(tasks.size() == 0){
        std::cout << "No tasks, try adding one!\n";
    }
    else{
        // print tasks
        std::cout << "\n\n";
        for(int i = 0; i < tasks.size(); i++){
            std::cout << "Task " << i+1 << ":\n";
            std::cout << tasks[i] << "\n";
            std::cout << "----------------\n\n";
        }
    }
}

std::vector<std::string> add_task(std::vector<std::string> tasks){
    std::cout << "Type the new task you want to add:\n";

    std::string task;
    // when you press enter, it also types a '\n' so this line is to ignore this \n
    std::cin.ignore(); 
    std::getline(std::cin, task);

    tasks.push_back(task);
    return tasks;
}

std::vector<std::string> delete_task(std::vector<std::string> tasks){
    if(tasks.size() == 0){std::cout << "List is already empty!\n";}
    else{
        std::cout << "What task number do you want to remove?\n";
        int task_num = get_user_input(1, tasks.size());

        tasks.erase(tasks.begin() + (task_num-1));
        std::cout << "Removed!\n";
    }
    return tasks;
}

int main(){
    std::vector<std::string> to_do_list = {};

    while(true){
        // intro
        std::cout << "\n--To-do List--\n\n";
        std::cout << "1. Add     2.Delete\n";
        std::cout << "3. View     4. Quit\n";
        // note: change the parameters if you change the number of options
        int option = get_user_input(1, 4);

        if(option == 1){
            to_do_list = add_task(to_do_list);
        }
        else if(option == 2){
            to_do_list = delete_task(to_do_list);
        }
        else if(option == 3){
            view_tasks(to_do_list);
        }
        if(option == 4){
            return 0;
        }
    }

    return 0;
}