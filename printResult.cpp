#include "printResult.h"
#include "Quiz.h"

// Prints the final score along with right and wrong questions
void printResult(int questions, int correct, int wrong)
{
    std::cout << "Number of questions: " << questions << std::endl;
    std::cout << "Number correct answers: " << correct << std::endl;
    std::cout << "Number wrong answers: " << wrong << std::endl;
    std::cout << "Final score: " << Quiz::getScore() << std::endl;
}