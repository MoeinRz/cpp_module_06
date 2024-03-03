#include "../include/Serializer.hpp"

Serializer::Serializer(void)
{
    return;
}

Serializer::~Serializer(void)
{
    return;
}

Serializer &Serializer::operator=(Serializer const &src)
{
    static_cast<void>(src);
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}
