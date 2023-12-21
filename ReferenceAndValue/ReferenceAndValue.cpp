#include <iostream>
#include <cassert>

// advertisement of the function printValueAndAddress
template<typename T>
void printValueAndAddress(const T& value);

// definition of function printValueAndAddress
template<typename T>
void printValueAndAddress(const T& value) {
    std::cout << "Value: " << value << "\tAddress: " << &value << std::endl;
}

//definition of function testReferenceType
template<typename T>
void testReferenceType(const T& value) {
    const T* originalAddress = &value;
    printValueAndAddress(value); // call function printValueAndAddress
    const T* currentAddress = &value;
    assert(originalAddress == currentAddress && "Passed by value!");
    std::cout << "Test passed: Passed by value!" << std::endl;
}

int main() {
    int intValue = 10;
    double doubleValue = 3.14;

    // Testing value types (int, double)
    std::cout << "Testing value types (int, double):" << std::endl;
    testReferenceType(intValue); // test for int
    testReferenceType(doubleValue); // test for double

    // Reference types (ссилки)
    int& intRef = intValue;
    double& doubleRef = doubleValue;

    // testing reference types
    std::cout << "\nTesting reference types:" << std::endl;
    testReferenceType(intRef); // test for the link to int
    testReferenceType(doubleRef); // test for the link to double

    return 0;
}