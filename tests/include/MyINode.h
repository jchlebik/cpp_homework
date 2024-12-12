#pragma once

#include <vector>
#include <memory>

#include "INode.h"

/**
 * Node interface class. Please do not change this interface.
 */ 
class MyINode: public INode
{
private:
    int value_;
    std::vector<std::unique_ptr<INode>> children_;

public:
    virtual ~MyINode() = default;

    // Copy 
    MyINode(const INode&) = delete;
    MyINode& operator=(const MyINode&) = delete;

    // Move
    MyINode(MyINode&&) noexcept = default;
    MyINode& operator=(MyINode&&) noexcept = default;

    /** 
     * Returns the value of the node.
     */
    [[nodiscard]] virtual int value() const override
    {
        return this->value_;
    }

    /** 
     * Returns a vector of all the children of the node.
     */
    [[nodiscard]] virtual const std::vector<std::unique_ptr<INode>>& children() const override
    {
        return this->children_;
    }

    MyINode(int value):
        value_{value}
    {
    }

    MyINode(int value, std::vector<std::unique_ptr<INode>>&& children):
        value_{value},
        children_{std::move(children)}
    {
    }

    void addChild(std::unique_ptr<INode>&& child)
    {
        this->children_.push_back(std::move(child));
    }
};
