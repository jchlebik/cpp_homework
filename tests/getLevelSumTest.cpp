#include <iostream>
#include <vector>
#include <format>

#include "assignment.h"
#include "INode.h"

#include "common.h"
#include "MyINode.h"

int getLevelSum_Test() {
    int failed_tests = 0;

    // Simple tree with children at level 1
    {
        std::vector<std::unique_ptr<INode>> children;
        children.push_back(std::make_unique<MyINode>(1));
        children.push_back(std::make_unique<MyINode>(2));
        children.push_back(std::make_unique<MyINode>(3));
        MyINode root(1, std::move(children));

        int sum = getLevelSum(root, 1);
        int expected = 6;
        if (sum == expected)
        {
            std::cout << green("\tgetLevelSum(): Level 1 passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetLevelSum(): Level 1 failed: Expected 6, got " + std::to_string(sum)) << std::endl;
            ++failed_tests;
        }
    }

    // Tree with grandchildren (level 2)
    {
        std::vector<std::unique_ptr<INode>> children;
        children.push_back(std::make_unique<MyINode>(1));
        children.push_back(std::make_unique<MyINode>(2));
        children.push_back(std::make_unique<MyINode>(3));
        MyINode root(1, std::move(children));

        for (auto& child : root.children()) 
        {
            if (child) 
            {
                MyINode* casted_child = dynamic_cast<MyINode*>(child.get());
                casted_child->addChild(std::make_unique<MyINode>(1));
                casted_child->addChild(std::make_unique<MyINode>(2));
                casted_child->addChild(std::make_unique<MyINode>(3));
            }
        }

        int sum = getLevelSum(root, 2);
        int expected = 18;
        if (sum == expected)
        {
            std::cout << green("\tgetLevelSum(): Level 2 passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetLevelSum(): Level 2 failed: Expected 18, got " + std::to_string(sum)) << std::endl;
            failed_tests++;
        }
    }

    // Root only
    {
        MyINode root(10);

        int sum = getLevelSum(root, 0);
        int expected = 10;
        if (sum == expected)
        {
            std::cout << green("\tgetLevelSum(): Level 0 passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetLevelSum(): Level 0 failed: Expected 10, got " + std::to_string(sum)) << std::endl;
            failed_tests++;
        }
    }

    // Requesting a non-existent level (exception)
    {
        std::vector<std::unique_ptr<INode>> children;
        children.push_back(std::make_unique<MyINode>(1));
        children.push_back(std::make_unique<MyINode>(2));
        MyINode root(1, std::move(children));

        try
        {
            int sum = getLevelSum(root, 3); // Level 3 does not exist
            std::cout << red("\tgetLevelSum(): Non-existent level failed: Expected an exception, got " + std::to_string(sum)) << std::endl;
            failed_tests++;
        }
        catch (const std::invalid_argument& e)
        {
            if (std::string(e.what()) == "Level does not exist")
            {
                std::cout << green("\tgetLevelSum(): Non-existent level passed") << std::endl;
            }
            else
            {
                std::cout << red("\tgetLevelSum(): Non-existent level failed (unexpected exception message)") << std::endl;
                failed_tests++;
            }
        }
        catch (...)
        {
            std::cout << red("\tgetLevelSum(): Non-existent level failed (unexpected exception type)") << std::endl;
            failed_tests++;
        }
    }

    // Large tree
    {
        MyINode root(0);
        for (int i = 0; i < 10; ++i)
        {
            auto child = std::make_unique<MyINode>(i + 1);
            for (int j = 0; j < 10; j++)
            {
                child->addChild(std::make_unique<MyINode>(j + 1));
            }
            root.addChild(std::move(child));
        }

        int sum = getLevelSum(root, 1); // Should sum up 1 to 10
        int expected = 55;
        if (sum == expected)
        {
            std::cout << green("\tgetLevelSum(): Large tree test 1 passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetLevelSum(): Large tree test 1 failed: Expected 55, got " + std::to_string(sum)) << std::endl;
            failed_tests++;
        }

        sum = getLevelSum(root, 2); // Should sum up (1 to 10) * 10
        expected = 550;
        if (sum == expected)
        {
            std::cout << green("\tgetLevelSum(): Large tree test 2 passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetLevelSum(): Large tree test 2 failed: Expected 550, got " + std::to_string(sum)) << std::endl;
            failed_tests++;
        }
    }

    // Unbalanced tree
    {
        MyINode root(0);
        
        // Create a deep tree by adding children to one branch only.
        MyINode* current_node = &root;
        for (int i = 1; i < 100; i++) 
        {
            auto child = std::make_unique<MyINode>(i);
            current_node->addChild(std::move(child));
            current_node = dynamic_cast<MyINode*>(current_node->children().back().get());
        }

        // Requesting sum at a middle level (e.g., level 50)
        int sum = getLevelSum(root, 50); // Should sum up 50
        int expected = 50;
        if (sum == expected)
        {
            std::cout << green("\tgetLevelSum(): Unbalanced tree test 1 passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetLevelSum(): Unbalanced tree test failed: Expected 50, got " + std::to_string(sum)) << std::endl;
            failed_tests++;
        }

        // Requesting sum at the last level (level 99)
        sum = getLevelSum(root, 99); // Should sum up 99
        expected = 99;
        if (sum == 99) 
        {
            std::cout << green("\tgetLevelSum(): Unbalanced tree test 2 passed") << std::endl;
        }
        else
        {
            std::cout << red("\tgetLevelSum(): Unbalanced tree test 2 failed: Expected 99, got " + std::to_string(sum)) << std::endl;
            failed_tests++;
        }
    }

    // Summary
    if (failed_tests == 0)
    {
        std::cout << green("test_getLevelSum(): All test cases passed!\n\n");
    }
    else
    {
        std::cout << red("test_getLevelSum(): " + std::to_string(failed_tests) + " test(s) failed\n\n");
    }
    return failed_tests;
}

int main()
{
    return getLevelSum_Test();
}