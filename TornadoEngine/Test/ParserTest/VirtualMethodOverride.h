#pragma once

class Y
{
    virtual void Foo() {}
};

class X : Y
{
    virtual void Foo() override;
};