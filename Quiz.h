#ifndef QUIZ_H_
#define QUIZ_H_
#include <iostream>
#include <string>
#include <fstream>

class Quiz
{
    private:
        std::string question {""};
        std::string answer {""};
    public:
        int static score;
        Quiz() = default;
        Quiz(std::string q, std::string a) : question{q}, answer{a} {}

        const std::string getQuestion();
        const std::string getAnswer();
        
        static int getScore();
        // Keeps track of score
        static void updateScore(int val);
        
        // Prints the final score along with right and wrong questions
        friend void printResult(int questions, int correct, int wrong);

};

#endif