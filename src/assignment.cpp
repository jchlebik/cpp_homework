#include <vector>
#include <cstdint>
#include <stdexcept>

#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>

#include "INode.h"

/*
 * General rules:
 * - You can use modern C++ features (anything that is supported by modern compilers)
 * - Try to validate input parameters if it makes sense, throw exceptions if needed
 * - You are allowed to use STL (so adding includes is allowed)
 */

/**
 * Implement a method that returns number that is closest to zero in a given vector.
 * If there are two equally close to zero elements like 2 and -2,
 * then consider the positive element to be "closer" to zero.
 */
int getClosestToZero(const std::vector<int>& arr) 
{
    if (arr.empty()) 
    {
        // return -1;
        throw std::invalid_argument("Empty vector"); // "throw exceptions if needed"
    }

    // find the element with the smallest absolute value, if two elements have the same absolute value, return the positive one
    std::function<bool(int, int)> closest_to_zero_comparator = [](int a, int b) {
        return std::abs(a) < std::abs(b) || (std::abs(a) == std::abs(b) && a > 0);
    };

    auto it = std::min_element(arr.begin(), arr.end(), closest_to_zero_comparator);
    return *it;

}

/**
 * Please implement this method to return count of chunks in given array.
 *
 * Chunk is defined as continuous sequence of one or more non-zero numbers separated by one or more zeroes.
 * Input can contain leading and trailing zeroes.
 *
 * Example: [5, 4, 0, 0, -1, 0, 2, 0, 0] contains 3 chunks
 */
std::size_t countChunks(const std::vector<int>& arr) 
{
    if (arr.empty()) 
    {
        // return -1;       // -1 is not a valid size_t value
        throw std::invalid_argument("Empty vector"); // "throw exceptions if needed"
    }

    // while 'here' is not end
        //from 'here' find the first non_zero item  (find the start of next chunk)
        // if not found 
            //return counter
        //else 
            //increase counter
            //from the first non_zero find the first zero (skip past the end of this chunk)
            //set 'here' to this point
    //return counter

    int counter = 0;
    auto here = arr.cbegin();
    while(here != arr.cend())
    {
        auto non_zero_it = std::find_if_not(here, arr.cend(), [](int i) { return i == 0; });
        if (non_zero_it == arr.cend()) 
        {
            return counter;
        }
        
        counter++;
        here = std::find(non_zero_it, arr.cend(), 0);
    }

    return counter;
}

/**
 * Open INode.h to see the INode interface.
 *
 * Implement following function that shall traverse the tree,
 * and return the sum of the values (INode.value()) of all nodes
 * at the level 'n' in the tree.
 * 
 * Node root is assumed to be at the level 0. All its children are level 1, etc.
 */
int getLevelSum(const INode& root, std::size_t n) 
{
    if (n == 0) 
    {
        return root.value();
    }

    //DFS traversal to the n-th level, when at the level, sum the values and backtrack
    int sum = 0;
    std::size_t deepest_level = 0;

    std::stack<std::pair<const INode*, std::size_t>> stack;
    stack.push({&root, 0});

    while(!stack.empty())
    {
        auto [node, level] = stack.top();
        stack.pop();
        
        deepest_level = std::max(deepest_level, level);
        if (level == n) 
        {
            sum += node->value();
        }
        else        // is there a way for level to be greater than n 
        {
            for (const auto& child : node->children()) 
            {
                if (child) 
                {
                    stack.push({child.get(), level + 1});
                }
            }
        }
    }

    if (n > deepest_level) 
    {
        // what is the expected return value?
        // return std::numeric_limits<int>::min(); // need a non-valid integer value or mby std::optional
        throw std::invalid_argument("Level does not exist"); 
    }

    return sum;
}

/**
 * Imagine a sort algorithm, that sorts array of integers by repeatedly reversing
 * the order of the first several elements of it.
 *
 * For example, to sort [12,13,11,14], you need to reverse the order of the first two (2)
 * elements. You will get [13,12,11,14].
 * Then you shall reverse the order of the first three (3) elements,
 * and you will get [11,12,13,14]
 *
 * For this assignment you shall implement function
 * that returns list of integers corresponding to the required reversals.
 * E.g. for given vector [12,13,11,14]
 * the function should return [2, 3].
 */
std::vector<std::size_t> getReversalsToSort(const std::vector<int>& arr)       //Pancake sort, n^2 and not optimal, see http://arxiv.org/pdf/1111.0434v1 and its references
{
    if (arr.empty()) 
    {
        return {};       // is an empty vector a valid input?
        // throw std::invalid_argument("Empty vector"); 
    }
    if (arr.size() == 1) 
    {
        return {0};       // no need to sort a single element
    }

    std::vector<int> arr_copy(arr);    // need to copy the input anyway to sort it
    std::vector<std::size_t> reversals;

    // going from the back, find the max element in the array. 
    // if its out of order, reverse so its at the front and then reverse again to put it in the correct position
    // n^2
    for (std::size_t i = arr_copy.size(); i > 1; i--) 
    {
        auto max_it = std::max_element(arr_copy.begin(), arr_copy.begin() + i);
        if (max_it != arr_copy.begin() + i - 1) // if the max element is not already in place
        {
            if (max_it != arr_copy.begin())     // if the max element is not at the front already
            {
                std::reverse(arr_copy.begin(), max_it + 1);
                reversals.push_back(std::distance(arr_copy.begin(), max_it) + 1);
            }
            std::reverse(arr_copy.begin(), arr_copy.begin() + i);
            reversals.push_back(i);
        }
    }
    return reversals;
}
