

#ifndef _BS_MATH_H_
#define _HS_MATH_H_
#include <iostream>
#include <string>
namespace BSGame
{
    template <class T>
    class BSVector2
    {
    private:
        T mX;
        T mY;

    public:
        /**
         * @brief Construct a new BSVector2 object
         * 
         * @param x initial x value
         * @param y initial y value
         */
        BSVector2(T x, T y)
        {
           
            update(x, y);
        }
        BSVector2(BSVector2 &old)
        {
            update(old.x(), old.y());
        }

        bool operator==(BSVector2 const &obj)
        {
            return (obj.mX == mX) && (obj.mY == mY);
        }
        bool operator!=(BSVector2 const &obj)
        {
            return (obj.mX != mX) || (obj.mY != mY);
        }
        BSVector2 operator=(BSVector2 const &obj)
        {
            mY = obj.mY;
            mX = obj.mX;
            return *this;
        }

        T y(){return mY;} 
        
        T x(){return mX;}
        /**
         * @brief Sets the X value of the vector
         * 
         * @param x - int of new x value
         * @return BSVector2 the updated vector (this)
         */
        void setX(T x)
        {
            mX = x;
           
        }
        /**
         * @brief Sets the Y value of the vector
         * 
         * @param y - int of new y value
         * @return BSVector2 the updated vector (this)
         */
        void setY(T y)
        {
            mY = y;
            
        }

        /**
         * @brief Updates the x and y values of the vector at once
         * 
         * @param x new x value
         * @param y new y value
         * @return BSVector2 updated vector
         */
        void update(T x, T y)
        {
            
           setX(x);
           setY(y);
         
        }
        /**
         * @brief Clamps the values of the vector to a minimum
         * for example: clampMin(0) -> x=5 y=-1 -> x=5 y=0
         * 
         * @param min 
         * @return BSVector2 updated vector
         */
        BSVector2 clampMin(int min)
        {
            setX(std::max(min, x()));
            setY(std::max(min, y()));
            return *this;
        }
        /**
         * @brief Clamps the values of the vector to a minimum
         * for example: clampMax(4) -> x=5 y=-1 -> x=4 y=-1
         * 
         * @param max 
         * @return BSVector2 updated vector
         */
        BSVector2 clampMax(int max)
        {
            setX(std::min(max, x()));
            setY(std::min(max, y()));
            return *this;
        }
    };

}; // namespace BSGame

#endif