#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string red(const std::string& str)
{
    const char* RED_BEGIN = "\033[1;31m";
    const char* RED_END = "\033[0m";
    return RED_BEGIN + str + RED_END;
}

std::string green(const std::string& str)
{
    const char* GREE_BEGIN = "\033[1;32m";
    const char* GREE_END = "\033[0m";
    return GREE_BEGIN + str + GREE_END;
}

template <typename T>
void print_vector(const std::vector<T>& arr)
{
    std::for_each(arr.begin(), arr.end(), [](const T& i) { std::cout << i << " "; });
    std::cout << std::endl;
}