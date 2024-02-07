#include <iostream>
#include <cstdlib>

int main() {
        //Define lower and upper bounds for play area
    int maxValue = 100;
    int minValue = 0;
        
        //Ensure that the guess will never already equal a valid option
    int guess = maxValue + 1;


        //Choose a random number, and ensure that it is within the range of values
    srand(time(0));
    const int CORRECT = rand() % maxValue+1;

        //Gameplay loop
    while(guess != CORRECT) {
        std::cout << "Please choose a number between: " + std::to_string(minValue) + " And " + std::to_string(maxValue) << std::endl;

        std::cin >> guess;

        if(guess == CORRECT) {
            std::cout << "YOU WON!! CONGRATULATIONS!";
            return 1;
        }


        if(guess > CORRECT && guess <= maxValue) {
            maxValue = guess;
        } else if (guess < CORRECT && guess >= minValue) {
            minValue = guess;
        }

        std::cout << "You were incorrect, please guess again" << std::endl;
    }
    
    return 0;
}