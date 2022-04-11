#include "Quiz.h"
// Static varable to be used everywhere
int Quiz::score = 0;

const std::string Quiz::getQuestion()
{ return question; }

const std::string Quiz::getAnswer()
{ return answer; }

int Quiz::getScore()
{
    return score;
}

// Keeps track of score by adding to the score but stopping 
// from going into the negatives
void Quiz::updateScore(int val)
{
    score += val;
    if (score < 0)
    {
        score = 0;
    }
}