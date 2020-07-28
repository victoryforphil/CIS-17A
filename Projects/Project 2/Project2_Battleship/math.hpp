#ifndef _BS_MATH_H_
#define _HS_MATH_H_

namespace BSGame{
    class BSVector2
    {
    private:
        int mX;
        int mY;
    public:
        BSVector2(int x, int y);
        
        bool operator == (BSVector2 const &obj);
        bool operator != (BSVector2 const &obj);
        BSVector2 operator = (BSVector2 const &obj);

        BSVector2 random(); //Generates a random vector (this class)

        int y();
        int x();
        BSVector2 setX(int x);
        BSVector2 setY(int y);
        BSVector2 update(int x, int y);
    };
    
};


#endif