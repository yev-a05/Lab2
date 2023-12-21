#include <iostream>
#include "pch.h"
#include <vector>
#include <chrono>
#include <cstdlib>
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MemoryTests
{
    TEST_CLASS(MemoryTests)
    {
    public:
        // A test for creating objects with a large amount of memory
        TEST_METHOD(HeavyMemoryConsumption)
        {
            std::vector<int*> largeObjects;

            const int numObjects = 10000; // Number of objects to create

            for (int i = 0; i < numObjects; ++i)
            {
                // Creating objects with a large amount of memory (for example, 10 megabytes)
                int* bigObject = new int[10 * 1024 * 1024]; // 10 MB of memory
                largeObjects.push_back(bigObject);
            }

            // Checking whether all objects were successfully created
            Assert::AreEqual(numObjects, static_cast<int>(largeObjects.size()));

            // Freeing memory to avoid memory leaks
            for (int i = 0; i < numObjects; ++i)
            {
                delete[] largeObjects[i];
            }
            largeObjects.clear();
        }
    };
}

