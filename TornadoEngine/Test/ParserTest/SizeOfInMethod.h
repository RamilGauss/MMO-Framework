#pragma once

namespace X
{
    class Y
    {
        void Foo();
    };
    void Y::Foo()
    {
        const int headerSize = sizeof(int);
    }
}