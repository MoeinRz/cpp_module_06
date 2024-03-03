#include "../include/Serializer.hpp"

int main()
{
    Data myData = {"Test.", 5};
    Data* myPtr = &myData;

    std::cout <<  "Data: " <<  myPtr->n << ", " << myPtr->s1 << "\n\n";

    uintptr_t serialized = Serializer::serialize(myPtr);
    std::cout << "Serialized Data finished." << "\n\n";
    Data* newDeserializedData = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data finished." << "\n\n";
    if (newDeserializedData == myPtr)
    {
        std::cout << "Post-Deserialization Data: "  << newDeserializedData->n << ", " << newDeserializedData->s1 << "\n";
    }
    return 0;
}
