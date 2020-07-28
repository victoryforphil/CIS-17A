#ifndef _NUM_DAYS_H_
#define _NUM_DAYS_H_

class NumDays
{
private:
    int m_hours;

public:
    NumDays();
    NumDays(int hours);

    double GetDays();
    int GetHours();
    void SetHours(int hours);
    NumDays &operator++();   // Prefix increment operator.
    NumDays operator++(int); // Postfix increment operator.

    // Declare prefix and postfix decrement operators.
    NumDays &operator--();   // Prefix decrement operator.
    NumDays operator--(int); // Postfix decrement operator.

    NumDays operator + (NumDays const &obj);
    NumDays operator - (NumDays const &obj);

    ~NumDays();
};

#endif;