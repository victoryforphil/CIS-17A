#ifndef _ESSAY_H_
#define _ESSAY_H_
#include "graded_activitity.hpp"
class Essay : public GradedActivity
{
private:
    double m_grammer; // Max 30
    double m_spelling; //Max 20
    double m_length; // 20
    double m_content; // 30
public:
    Essay();

    bool SetGrammer(double scoreSet);
    bool SetSpelling(double scoreSet);
    bool SetLength(double scoreSet);
    bool SetContent(double scoreSet);

    double GetGrammerScore();
    double GetSpellingScore();
    double GetLengthScore();
    double GetContentScore();

    
};




#endif