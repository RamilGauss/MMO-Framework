#pragma once

class BaseMethodCategory
{
public:
    virtual void Override() const = 0;

    virtual void Final() const {}
};

class MethodCategory : public BaseMethodCategory
{
public:
    static void Static() {}
    
    virtual void Virtual() {}

    virtual void VirtualPure() const = 0;

    void Override() const override {}

    void Final() const override final {}

    template<typename T>
    void Template() const {}

    bool operator == (const MethodCategory& other) const { return false; }
};
