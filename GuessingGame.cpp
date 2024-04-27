#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdexcept>

int main() {
        //Define lower and upper bounds for play area
    int maxValue = 100;
    int minValue = 0;
    bool isNumber = false;
        
        //Ensure that the guess will never already equal a valid option
    int guess = maxValue + 1;


        //Choose a random number, and ensure that it is within the range of values
    srand(time(0));
    const int SECRET_NUMBER = rand() % maxValue+1;

        //Gameplay loop
    while(guess != SECRET_NUMBER) {
        std::cout << "Please choose a number between: " << minValue << " And " << maxValue << std::endl;

        std::string input;
        do {
            std::getline(std::cin, input);
            try {
                guess = std::stoi(input);
                isNumber = true;
            } catch (const std::invalid_argument& e) {
                std::cout << "The Number was not valid, choose another!" << std::endl;
            }
        } while (!isNumber);

        if(guess == SECRET_NUMBER) {
            std::cout << "YOU WON!! CONGRATULATIONS!";
            return 1;
        }

        if(guess > SECRET_NUMBER && guess <= maxValue) {
            maxValue = guess;
        } else if (guess < SECRET_NUMBER && guess >= minValue) {
            minValue = guess;
        }

        std::cout << "You were incorrect, please guess again" << std::endl;
    }
    
    return 0;
}
