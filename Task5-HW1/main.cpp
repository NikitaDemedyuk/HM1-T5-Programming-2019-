//
//  main.cpp
//  Task5-HW1
//
//  Created by Никита on 3/29/22.
//

#include <iostream>
#include <vector>
#include <cassert>


void printVector(std::vector <int> &array, bool flag) {
    if (flag) {
        std::cout << "\nFinal array:\n";
    } else {
        std::cout << "\nArray\n";
    }
    for (auto element: array) {
        std::cout << element << " ";
    }
    std::cout << "\n\n";
}

bool testFuncDeleteElem(std::vector <int> &array, std::vector <int> &testArray) {
    bool flag = true;
    if (array.size() != testArray.size()) {
        flag = false;
    } else {
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] != testArray[i]) {
                flag = false;
            }
        }
    }
    return flag;
}

void changePlace(std::vector <int> &array, int max) {
    for (int k = 0; k < max; ++k) {
        int tmp {array[0]};
        array[0] = array[array.size() - 1];
        std::swap(array[0], array[array.size() - 1]);
        for (int i = 1; i < array.size(); ++i) {
            array[i - 1] = array[i];
        }
        array[array.size() - 1] = tmp;
    }
}

int main() {
    int size {0};
    std::cout << "Size = ";
    std::cin >> size;
    assert(size >= 0);
    
    int max {0};
    std::cout << "Max = ";
    std::cin >> max;
    assert(max >= 0);
    
    std::vector <int> array;
    
    std::cout << "\nEnter the elements: \n";
    for (int i = 0, value = {}; i < size; i++) {
        std::cout << "array [" << i << "] = ";
        std::cin >> value;
        array.push_back(value);
    }
    
    printVector(array, false);
    
    changePlace(array, max);
    
    printVector(array, true);
    
    std::vector <int> testArray1 = {28, 9, -6, 23, 52, 33, 54, 75, 3, 45, 66, 21, 34, 55, 22, 12, -12, 44};
    changePlace(testArray1, 3);
    
    printVector(testArray1, true);
    
    std::vector <int> testArray2 = {23, 52, 33, 54, 75, 3, 45, 66, 21, 34, 55, 22, 12, -12, 44, 28, 9, -6};
    
    if (testFuncDeleteElem(testArray1, testArray2)) {
        std::cout << "Correct work!\n\n";
    } else {
        std::cout << "Not correct work.\n\n";
    }
    
    return 0;
}
