#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <algorithm>

#include "assignment.h"
#include "common.h"

int getClosestToZero_tests() 
{
    int failed_tests = 0;

    // Basic test with positive and negative numbers
    {
        std::vector<int> arr = {3, -1, -4, 2, -2, 1};
        if (getClosestToZero(arr) == 1) {
            std::cout << green("\tgetClosestToZero(): Basic test passed") << std::endl;
        }
        else 
        {
            std::cout << red("\tgetClosestToZero(): Basic test failed") << std::endl;
            failed_tests++;
        }
    }

    // Negative number
    {
        std::vector<int> arr = {-5};
        if (getClosestToZero(arr) == -5)
        {
            std::cout << green("\tgetClosestToZero(): Single negative number passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetClosestToZero(): Single negative number failed") << std::endl;
            failed_tests++;
        }
    }

    // Positive preference
    {
        std::vector<int> arr = {2, -2};
        if (getClosestToZero(arr) == 2)
        {
            std::cout << green("\tgetClosestToZero(): Positive preference passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetClosestToZero(): Positive preference failed") << std::endl;
            failed_tests++;
        }
    }

    // Mixed with duplicates
    {
        std::vector<int> arr = {5, -5, -1, -1, 1, 0, 10};
        if (getClosestToZero(arr) == 0) 
        {
            std::cout << green("\tgetClosestToZero(): Mixed with duplicates passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetClosestToZero(): Mixed with duplicates failed") << std::endl;
            failed_tests++;
        }
    }

    // Only negative
    {
        std::vector<int> arr = {-10, -5, -1, -3, -7};
        if (getClosestToZero(arr) == -1)
        {
            std::cout << green("\tgetClosestToZero(): Only negative passed") << std::endl;
        }
        else 
        {
            std::cout << red("\tgetClosestToZero(): Only negative failed") << std::endl;
            failed_tests++;
        }
    }

    // Zero
    {
        std::vector<int> arr = {-3, 3, -1, 1, 0};
        if (getClosestToZero(arr) == 0)
        {
            std::cout << green("\tgetClosestToZero(): Zero in array passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetClosestToZero(): Zero in array failed") << std::endl;
            failed_tests++;
        }
    }

    // Empty (exception case)
    {
        std::vector<int> arr = {};
        try 
        {
            getClosestToZero(arr);
            std::cout << red("\tgetClosestToZero(): Empty array failed (no exception thrown)") << std::endl;
            failed_tests++;
        } 
        catch (const std::invalid_argument& e) 
        {
            if (std::string(e.what()) == "Empty vector") 
            {
                std::cout << green("\tgetClosestToZero(): Empty array passed") << std::endl;
            } 
            else 
            {
                std::cout << red("\tgetClosestToZero(): Empty array failed (unexpected exception message)") << std::endl;
                failed_tests++;
            }
        } 
        catch (...) 
        {
            std::cout << red("\tgetClosestToZero(): Empty array failed (unexpected exception type)") << std::endl;
            failed_tests++;
        }
    }

    // Summary
    if (failed_tests == 0) 
    {
        std::cout << green("getClosestToZero(): All test cases passed!\n\n");
    } 
    else 
    {
        std::cout << red("getClosestToZero(): " + std::to_string(failed_tests) + " test(s) failed\n\n");
    }
    return failed_tests;
}

int main()
{
    return getClosestToZero_tests();
}