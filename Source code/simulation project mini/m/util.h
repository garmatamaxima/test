#pragma once

namespace util
{   
    template <typename T> T clamp(T value, T min, T max)
    {
        if (value > max) { return max; }
        else if (value < min) { return min; }
        return value;
    }
    template <typename T> T clamp(T value, int min, int max)
    {
        if (value > max) { return max; }
        else if (value < min) { return min; }
        return value;
    }

    template <typename T> T clampmin(T value, T min)
    {
        if (value < min) { return min; }
        return value;
    }
    template <typename T> T clampmin(T value, int min)
    {
        if (value < min) { return min; }
        return value;
    }



};