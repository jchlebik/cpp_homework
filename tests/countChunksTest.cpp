#include <iostream>
#include <vector>

#include "assignment.h"
#include "common.h"

/**
 * Test cases for countChunks function.
 */


int countChunks_tests() {
    int failed_tests = 0;

    // Basic case with chunks separated by zeroes
    {
        std::vector<int> arr = {5, 4, 0, 0, -1, 0, 2, 0, 0};
        if (countChunks(arr) == 3)
        {
            std::cout << green("\tcountChunks(): Basic case passed") << std::endl;
        }
        else
        {
            std::cout << red("\tcountChunks(): Basic case failed") << std::endl;
            failed_tests++;
        }
    }

    // Single chunk with no zeroes
    {
        std::vector<int> arr = {1, 2, 3, 4};
        if (countChunks(arr) == 1)
        {
            std::cout << green("\tcountChunks(): Single chunk passed") << std::endl;
        }
        else
        {
            std::cout << red("\tcountChunks(): Single chunk failed") << std::endl;
            failed_tests++;
        }
    }

    // All zeroes
    {
        std::vector<int> arr = {0, 0, 0, 0};
        if (countChunks(arr) == 0)
        {
            std::cout << green("\tcountChunks(): All zeroes passed") << std::endl;
        }
        else
        {
            std::cout << red("\tcountChunks(): All zeroes failed") << std::endl;
            failed_tests++;
        }
    }

    // Mixed positive and negative numbers
    {
        std::vector<int> arr = {0, -3, -5, 0, 1, 0, 0, 6, -2, 0};
        if (countChunks(arr) == 3)
        {
            std::cout << green("\tcountChunks(): Mixed positive and negative numbers passed") << std::endl;
        }
        else
        {
            std::cout << red("\tcountChunks(): Mixed positive and negative numbers failed") << std::endl;
            failed_tests++;
        }
    }

    // Leading zeroes
    {
        std::vector<int> arr = {0, 0, 1, 2, 3};
        if (countChunks(arr) == 1)
        {
            std::cout << green("\tcountChunks(): Leading zeroes passed") << std::endl;
        }
        else
        {
            std::cout << red("\tcountChunks(): Leading zeroes failed") << std::endl;
            failed_tests++;
        }
    }

    // Trailing zeroes
    {
        std::vector<int> arr = {1, 2, 3, 0, 0};
        if (countChunks(arr) == 1)
        {
            std::cout << green("\tcountChunks(): Trailing zeroes passed") << std::endl;
        }
        else
        {
            std::cout << red("\tcountChunks(): Trailing zeroes failed") << std::endl;
            failed_tests++;
        }
    }

    // Alternating zeroes and numbers
    {
        std::vector<int> arr = {0, 1, 0, 2, 0, 3, 0, 4, 0};
        if (countChunks(arr) == 4) {
            std::cout << green("\tcountChunks(): Alternating zeroes and numbers passed") << std::endl;
        } else {
            std::cout << red("\tcountChunks(): Alternating zeroes and numbers failed") << std::endl;
            failed_tests++;
        }
    }

    // Empty vector (exception case)
    {
        std::vector<int> arr = {};
        try
        {
            countChunks(arr);
            std::cout << red("\tcountChunks(): Empty vector failed (no exception thrown)") << std::endl;
            failed_tests++;
        }
        catch (const std::invalid_argument& e)
        {
            if (std::string(e.what()) == "Empty vector")
            {
                std::cout << green("\tcountChunks(): Empty vector passed") << std::endl;
            }
            else
            {
                std::cout << red("\tcountChunks(): Empty vector failed (unexpected exception message)") << std::endl;
                failed_tests++;
            }
        }
        catch (...)
        {
            std::cout << red("\tcountChunks(): Empty vector failed (unexpected exception type)") << std::endl;
            failed_tests++;
        }
    }

    // Summary
    if (failed_tests == 0) 
    {
        std::cout << green("countChunks(): All test cases passed!\n\n");
    }
    else 
    {
        std::cout << red("countChunks(): " + std::to_string(failed_tests) + " test(s) failed\n\n");
    }
    return failed_tests;
}

int main()
{
    return countChunks_tests();
}
