#include <iostream>
#include <vector>

#include "assignment.h"

#include "common.h"


int getReversalsToSort_tests() 
{
    int failed_tests = 0;
    auto verify = [](const std::vector<int>& input, const std::vector<std::size_t>& reversals) 
    {
        std::vector<int> input_cpy = input;
        for (std::size_t reversal : reversals) 
        {
            std::reverse(input_cpy.begin(), input_cpy.begin() + reversal);
        }
        // Check if the array is sorted
        return std::is_sorted(input_cpy.begin(), input_cpy.end());
    };


    // Basic case
    {
        std::vector<int> arr = {12, 13, 11, 14};
        std::vector<std::size_t> expected = {2, 3};
        std::vector<std::size_t> reversals = getReversalsToSort(arr);
        if (reversals == expected && verify(arr, reversals)) 
        {
            std::cout << green("\tgetReversalsToSort(): Basic case passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetReversalsToSort(): Basic case failed") << std::endl;
            failed_tests++;
        }
    }

    // Already sorted
    {
        std::vector<int> arr = {1, 2, 3, 4};
        std::vector<std::size_t> expected = {};
        std::vector<std::size_t> reversals = getReversalsToSort(arr);
        if (reversals == expected && verify(arr, reversals)) 
        {
            std::cout << green("\tgetReversalsToSort(): Already sorted passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetReversalsToSort(): Already sorted failed") << std::endl;
            failed_tests++;
        }
    }

    // Reverse sorted
    {
        std::vector<int> arr = {4, 3, 2, 1};
        std::vector<std::size_t> expected = {4};
        std::vector<std::size_t> reversals = getReversalsToSort(arr);

        if (reversals == expected && verify(arr, reversals))
        {
            std::cout << green("\tgetReversalsToSort(): Reverse sorted passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetReversalsToSort(): Reverse sorted failed") << std::endl;
            failed_tests++;
        }
    }

    // Single element
    {
        std::vector<int> arr = {42};
        std::vector<std::size_t> expected = {0};
        std::vector<std::size_t> reversals = getReversalsToSort(arr);
        
        if (reversals == expected && verify(arr, reversals))
        {
            std::cout << green("\tgetReversalsToSort(): Single element passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetReversalsToSort(): Single element failed") << std::endl;
            failed_tests++;
        }
    }

    // Empty vector
    {
        std::vector<int> arr = {};
        std::vector<std::size_t> expected = {};
        std::vector<std::size_t> reversals = getReversalsToSort(arr);

        if (reversals == expected && verify(arr, reversals))
        {
            std::cout << green("\tgetReversalsToSort(): Empty vector passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetReversalsToSort(): Empty vector failed") << std::endl;
            ++failed_tests;
        }
    }

    //Random order
    {
        std::vector<int> arr = {3, 1, 4, 2};
        std::vector<std::size_t> expected = {3, 4, 2, 3};
        std::vector<std::size_t> reversals = getReversalsToSort(arr);

        if (reversals == expected && verify(arr, reversals))
        {
            std::cout << green("\tgetReversalsToSort(): Random order passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetReversalsToSort(): Random order failed") << std::endl;
            failed_tests++;
        }
    }

    // Test: Duplicates in array
    {
        std::vector<int> arr = {4, 4, 3, 2};
        std::vector<std::size_t> expected = {4};
        std::vector<std::size_t> reversals = getReversalsToSort(arr);

        if (reversals == expected && verify(arr, reversals))
        {
            std::cout << green("\tgetReversalsToSort(): Duplicates in array passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetReversalsToSort(): Duplicates in array failed") << std::endl;
            failed_tests++;
        }
    }

    // Summary
    if (failed_tests == 0) 
    {
        std::cout << green("getReversalsToSort(): All test cases passed!\n\n");
    }
    else
    {
        std::cout << red("getReversalsToSort(): " + std::to_string(failed_tests) + " test(s) failed\n\n");
    }
    return failed_tests;
}

int main()
{
    return getReversalsToSort_tests();
}