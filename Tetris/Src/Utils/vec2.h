#pragma once

namespace tetris
{

template <typename T>
struct vec2
{
    vec2<T>();
    vec2<T>(T x, T y);

    vec2<T> operator+(const vec2<T>& v) const;
    vec2<T> operator-(const vec2<T>& v) const;
    vec2<T> operator*(const T& s) const;
    vec2<T> operator/(const T& s) const;
    bool operator==(const vec2<T>& v) const;

    T x, y;
};

template <typename T>
vec2<T>::vec2() : x{}, y{}
{
}

template <typename T>
vec2<T>::vec2(T x, T y) : x(x), y(y)
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

template <typename T>
bool vec2<T>::operator==(const vec2<T>& v) const
{
    return x == v.x && y == v.y;
};

}  // namespace tetris
