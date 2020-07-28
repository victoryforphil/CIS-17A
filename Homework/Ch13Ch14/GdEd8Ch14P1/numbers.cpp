#include "numbers.hpp"

Numbers::Numbers(int num)
{
    m_number = num;
}

void Numbers::print()
{

    while (m_number > 0)
    {
        if (m_number < 9999)
        {
            if (m_number <= 999)
            {
                if (m_number <= 99)
                {
                    if (m_number <= 20)
                    {
                        std::cout << STR_LESS_20[m_number];
                        
                    }
                    else
                    {
                        std::cout << m_number[m_number];
                        m_number -= 20
                    }
                }
                else
                {
                    m_number -= 99;
                }
            }
            else
            {
                m_number -= 999
            }
        }
    }
}