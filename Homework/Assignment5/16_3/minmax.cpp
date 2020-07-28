#include "minmax.hpp"

template<typename  T>
T MinMax::GetMax(T a, T b){
    return a>b?a:b;
}

template<typename  T>
T MinMax::GetMin(T a, T b){
    return a<b?a:b;
}