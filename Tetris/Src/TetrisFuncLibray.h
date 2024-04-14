#pragma once

#include <random>

namespace tetris
{
template <typename T>
T clamp(T value, T min, T max)
{
    if (value < min)
    {
        return min;
    }
    if (value > max)
    {
        return max;
    }
    return value;
}

inline int get_random_int(const int min, const int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

inline double get_time_milliseconds()
{
    using namespace std::chrono;
    const high_resolution_clock::time_point now = high_resolution_clock::now();
    const duration<double, std::milli> time_span = duration_cast<duration<double, std::milli>>(now.time_since_epoch());
    return time_span.count();
}

template <typename T>
inline void add_unique(const T& new_item, std::vector<T>& array)
{
    if (!std::any_of(array.begin(), array.end(), [new_item](const T& elem) { return new_item == elem; }))
    {
        array.push_back(new_item);
    }
}

inline void sort_vec2_y(std::vector<vec2<int>>& array)
{
    std::sort(array.begin(), array.end(), [](const vec2<int>& a, const vec2<int>& b) { return a.y > b.y; });
}

template <typename T>
int find_first_index(const std::vector<T>& array, const T& value)
{
    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] == value) return i;
    }
    return -1;
}

}  // namespace tetris
