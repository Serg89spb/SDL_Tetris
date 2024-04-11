#pragma once

namespace Tetris
{

template <typename T>
struct vec2
{
    vec2<T>();
    vec2<T>(T _x, T _y);

    vec2<T> operator+(const vec2<T>& v) const;
    vec2<T> operator-(const vec2<T>& v) const;
    vec2<T> operator*(const T& s) const;
    vec2<T> operator/(const T& s) const;

    T x, y;
};

template <typename T>
vec2<T>::vec2() : x{}, y{}
{
}

template <typename T>
vec2<T>::vec2(T _x, T _y) : x(_x), y(_y)
{
}

template <typename T>
vec2<T> vec2<T>::operator+(const vec2<T>& v) const
{
    return {x + v.x, y + v.y};
}

template <typename T>
vec2<T> vec2<T>::operator-(const vec2<T>& v) const
{
    return {x - v.x, y - v.y};
}

template <typename T>
vec2<T> vec2<T>::operator*(const T& s) const
{
    return {x * s, y * s};
}

template <typename T>
vec2<T> vec2<T>::operator/(const T& s) const
{
    const T rs = 1.f / s;
    return {x * rs, y * rs};
};

}  // namespace Tetris
