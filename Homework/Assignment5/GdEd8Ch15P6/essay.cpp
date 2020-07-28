#include "essay.hpp"

Essay::Essay() {}
bool Essay::SetGrammer(double scoreSet)
{
    if (scoreSet > 30)
    {
        return false;
    }

    m_grammer = scoreSet;

    setScore(m_grammer + getScore());
}
bool Essay::SetSpelling(double scoreSet)
{
    if (scoreSet > 20)
    {
        return false;
    }

    m_spelling = scoreSet;
    setScore(m_spelling + getScore());
}
bool Essay::SetLength(double scoreSet)
{
    if (scoreSet > 20)
    {
        return false;
    }

    m_length = scoreSet;
    setScore(m_length + getScore());
}
bool Essay::SetContent(double scoreSet)
{
    if (scoreSet > 30)
    {
        return false;
    }

    m_content = scoreSet;
    setScore(m_content + getScore());
}

double Essay::GetGrammerScore()
{
    return m_spelling;
}
double Essay::GetSpellingScore()
{
    return m_spelling;
}
double Essay::GetLengthScore()
{
    return m_length;
}
double Essay::GetContentScore()
{
    return m_content;
}

char GradedActivity::getLetterGrade() const{
    return 'a';
}