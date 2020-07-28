#include "math.hpp"
#include <algorithm>
using namespace BSGame;

BSVector2::BSVector2(int x, int y){
    update(x,y);
}


bool BSVector2::operator == (BSVector2 const &obj){
    return (obj.mX == mX) && (obj.mY == mY);
}
bool BSVector2::operator != (BSVector2 const &obj){
    return (obj.mX != mX) || (obj.mY != mY);
}
BSVector2 BSVector2::operator = (BSVector2 const &obj){
    mY = obj.mY;
    mX = obj.mX;
}
BSVector2 BSVector2::random(){
    return *this;
}

BSVector2 BSVector2::setX(int x){
    mX = x;
}
BSVector2 BSVector2::setY(int y){
    mY = y;
}
BSVector2 BSVector2::update(int x, int y){
    setX(x);
    setY(x);
}
BSVector2 BSVector2::clampMin(int min){
    setX(std::max(min,x()));
    setY(std::max(min, y()));
}
BSVector2 BSVector2::clampMax(int max){
    setY(std::min(max,x()));
    setY(std::min(max, y()));
}

int BSVector2::y(){
    return mY;
}

int BSVector2::x(){
    return mX;
}