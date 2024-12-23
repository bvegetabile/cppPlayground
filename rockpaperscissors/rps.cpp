#include <map>
#include <iostream>
#include <string>
#include <cctype>
#include <ctime>

void printBreakStatement(char breakchar = '-', int nchars = 80) {
    for (int i = 0; i < nchars; i++) {
        std::cout << breakchar;
    }
    std::cout << std::endl;
}

void printStatementWithDecoration(
    std::string statement, 
    bool before = false, 
    bool after = false,
    char breakchar = '-',
    int nchars = 80) {
        if (before) printBreakStatement(breakchar, nchars);
        std::cout << statement << std::endl;
        if (after) printBreakStatement(breakchar, nchars);
}

int main () {
    // Get a different random number each time the program runs
    srand(time(0));

    // Initialization of parameters. 
    std::string get_player_choice = "Choose from:\n\t(1) or 'Rock'\n\t(2) or 'Paper'\n\t(3) or 'Scissors'\n<Enter>: ";
    std::string player_choice = "0";
    std::string computer_choice = "0";
    bool is_number_choice; 
    bool is_correct_word_input_choice;


    std::map<std::string, std::string> lookup_rps; 
    lookup_rps["rock"] = "1";
    lookup_rps["paper"] = "2";
    lookup_rps["scissors"] = "3";

    std::map<std::string, std::string> rev_lookup_rps; 
    rev_lookup_rps["1"] = "rock";
    rev_lookup_rps["2"] = "paper";
    rev_lookup_rps["3"] = "scissors";

    std::string welcome_statement = "Welcome to the Game: Rock, Paper, Scissors!";
    std::string tie_statement = "It's a tie! Play again!";
    std::string final_combo; 

    // player:computer
    std::map<std::string, std::string> winning_results;
    winning_results["rock:paper"] = "Player loses! --> Paper beats rock!";
    winning_results["rock:scissors"] = "Player wins! --> Rock beats scissors!";

    winning_results["paper:rock"] = "Player wins! --> Paper beats rock!";
    winning_results["paper:scissors"] = "Player loses! --> Scissors beats paper!";

    winning_results["scissors:rock"] = "Player loses! --> Rock beats scissors!";
    winning_results["scissors:paper"] = "Player wins! --> Scissors beats paper!";

    // header info. 
    printStatementWithDecoration(welcome_statement, true, true, '=');

    do {
        // Get player inputs
        std::cout << get_player_choice;
        std::cin >> player_choice; 
        is_number_choice = (
            player_choice == "1" || 
            player_choice == "2" || 
            player_choice == "3"
        );

        // Generate a random number between 1 and 3 for computer choice. 
        computer_choice = std::to_string((rand() % 3) + 1);

        // Convert player choice to lowercase --> then set to appropriate comparison. 
        if(!is_number_choice){
            // convert to lower case to manage inputs. 
            for (char &c : player_choice){
                c = std::tolower(c);
            }

            is_correct_word_input_choice = (
                player_choice == "rock" || 
                player_choice == "paper" || 
                player_choice == "scissors"
            );

            if (is_correct_word_input_choice) {
                player_choice = lookup_rps[player_choice];
            } else {
                std::cout << "Wrong input for player." << std::endl << std::endl;
                continue;
            }
        }

        std::cout << std::endl << "Player picked    : " << rev_lookup_rps[player_choice] << std::endl;
        std::cout << "Computer picked  : " << rev_lookup_rps[computer_choice] << std::endl;

        if (player_choice == computer_choice) {
            std::cout << std::endl; 
            printStatementWithDecoration(tie_statement, true, true, '*', 65);
            std::cout << std::endl; 
        }

    } while (player_choice == computer_choice);

    final_combo = rev_lookup_rps[player_choice] + ":" + rev_lookup_rps[computer_choice];
    
    std::cout << std::endl; 
    printStatementWithDecoration(winning_results[final_combo], true, true, '*', 65);
    std::cout << std::endl; 

    return 0;
}
