

#ifndef _BS_MATH_H_
#define _HS_MATH_H_
#include <iostream>
#include <string>
namespace BSGame
{
    class BSVector2
    {
    private:
        int mX;
        int mY;

    public:
        /**
         * @brief Construct a new BSVector2 object
         * 
         * @param x initial x value
         * @param y initial y value
         */
        BSVector2(int x, int y);

        bool operator==(BSVector2 const &obj);
        bool operator!=(BSVector2 const &obj);
        BSVector2 operator=(BSVector2 const &obj);

        /**
         * @brief Generate a random vector
         * 
         * @return BSVector2 generates a random vector
         */
        BSVector2 random(); 

        int y();
        int x();
        /**
         * @brief Sets the X value of the vector
         * 
         * @param x - int of new x value
         * @return BSVector2 the updated vector (this)
         */
        BSVector2 setX(int x);
        /**
         * @brief Sets the Y value of the vector
         * 
         * @param y - int of new y value
         * @return BSVector2 the updated vector (this)
         */
        BSVector2 setY(int y);

        /**
         * @brief Updates the x and y values of the vector at once
         * 
         * @param x new x value
         * @param y new y value
         * @return BSVector2 updated vector
         */
        BSVector2 update(int x, int y);
        /**
         * @brief Clamps the values of the vector to a minimum
         * for example: clampMin(0) -> x=5 y=-1 -> x=5 y=0
         * 
         * @param min 
         * @return BSVector2 updated vector
         */
        BSVector2 clampMin(int min);
        /**
         * @brief Clamps the values of the vector to a minimum
         * for example: clampMax(4) -> x=5 y=-1 -> x=4 y=-1
         * 
         * @param max 
         * @return BSVector2 updated vector
         */
        BSVector2 clampMax(int max);

  
    };

}; // namespace BSGame

#endif