#pragma once

template<typename _Ty, size_t SIZE>
class VectorStatic : public std::vector<_Ty>
{
    _Ty _array[SIZE];
    size_t _count;
public:

};
