// Conner Tash
// Program to create a quiz based on a text file that the user
// inputs at run time. The program will read the first question line
// then answer line and ask the user for their answer keeping track 
// of their right and wrong answers.
#include "Quiz.h"
#include "printResult.h"
#include <fstream>      // opens files 
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

// Allows access to files
int main(int argc, char const *argv[])
{
    // Variable declaration
    string question;
    string answer;
    vector<Quiz> quizVector;
    string line;
    string userInput;
    int numOfQuestion {0}, correctQuestions {0}, wrongQuestions {0};

    // Opens the text file for the input
    ifstream file;
    file.open(argv[1], ios::in);

    // Verfication that the file opened
    if(!file.is_open()) 
    {
        cout << "Unable to open file."; 
        return EXIT_FAILURE;
    }
    
    // Gets each of the first lines and stores it in question
    while(getline(file, question))
    {
        // Removes the 'Q: ' from the question
        question.erase(0,3);

        // Gets the other line and stores it in answer
        getline(file, answer);
        // Removes 'A: ' from answer
        answer.erase(0,3);
        
        // Stores question and answer into a vector of class Quiz
        quizVector.push_back(Quiz(question, answer));
    }   
        
    
    // Close input file
    file.close();

    // Intialize the rng to the current runtime value
    srand(unsigned(time(0)));

    // Randomly choses a question from the vector
    random_shuffle (quizVector.begin(), quizVector.end());

    // Prints the question to the user 
    for ( auto & val: quizVector)
    {
        numOfQuestion++;
        cout << val.getQuestion()<<"\n";
        cout << "Type in your answer: ";
        getline(cin, userInput);

        // Checks to see if the user gets the question correct and awards or takes points
        if (userInput == val.getAnswer())
        {
            Quiz::updateScore(1);
            correctQuestions++;
            cout << "Correct!\nCurrent score: " << Quiz::getScore() << endl << endl;
        }
        else 
        {
            Quiz::updateScore(-1);
            wrongQuestions++;
            cout << "Wrong! Correct answer: " << val.getAnswer() << endl;
            cout << "Current score: " << Quiz::getScore() << endl << endl;
        }
    }
    // Prints the final score along with right and wrong questions
    printResult(numOfQuestion, correctQuestions, wrongQuestions);
    return 0;
}