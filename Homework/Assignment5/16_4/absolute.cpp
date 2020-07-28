#include "absolute.hpp"


template<typename  T>
T Abs(T a){
    return a < 0 : a * -1 ? a;
}