#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

// Code BY PRAVEEN on 2024-08-31

std::vector<int> findPair(std::vector<int>& numbers, int desiredSum) {
    std::unordered_map<int, int> indexMap;
    int i = 0;
    while (i < numbers.size()) {
        int requiredValue = desiredSum - numbers[i];
        if (indexMap.find(requiredValue) != indexMap.end()) {
            std::vector<int> result;
            result.push_back(indexMap[requiredValue]);
            result.push_back(i);
            return result;
        }
        indexMap[numbers[i]] = i;
        ++i;
    }
    return std::vector<int>();
}

int main() {
    int arraySize, sumGoal;
    
    // Loop for input validation for the number of elements
    while (true) {
        std::cout << "Provide total elements (2 <= count <= 104): ";
        std::cin >> arraySize;
        if (std::cin.fail() || arraySize < 2 || arraySize > 104) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    std::vector<int> elements(arraySize);
    
    // Loop for input validation for array elements
    int j = 0;
    while (j < arraySize) {
        std::cout << "Provide element (" << j+1 << " of " << arraySize << ") in range -10^9 to 10^9: ";
        std::cin >> elements[j];
        if (std::cin.fail() || elements[j] < -1000000000 || elements[j] > 1000000000) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            ++j;
        }
    }
    
    // Loop for input validation for the desired sum
    while (true) {
        std::cout << "Provide desired sum (-10^9 <= sum <= 10^9): ";
        std::cin >> sumGoal;
        if (std::cin.fail() || sumGoal < -1000000000 || sumGoal > 1000000000) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    
    std::vector<int> solution = findPair(elements, sumGoal);
    
    if (!solution.empty()) {
        std::cout << "Positions of the pair are: [" << solution[0] << ", " << solution[1] << "]" << std::endl;
    } else {
        std::cout << "No matching pair found for the provided input." << std::endl;
    }
    
    return 0;
}
