#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

int main() {
    std::ifstream inFile1, inFile2;
    std::stack<char, std::vector<char>> charStack1, charStack2;
    std::string fileName1, fileName2;

    // Read in and check for validity of first file
    std::cout << "Enter the first file to read from:\n";
    std::cin >> fileName1;
    inFile1.open(fileName1);
    if(!inFile1.is_open()) {
        std::cout << "File not found.\n";
        return 0;
    }

    // Read in and check validity of second file
    std::cout << "Enter the second file to read from:\n";
    std::cin >> fileName2;
    inFile2.open(fileName2);
    if(!inFile2.is_open()) {
        std::cout << "File not found.\n";
        return 0;
    }

    char ch;
    while(inFile1.get(ch)) {
        charStack1.push(ch);
    }
    while(inFile2.get(ch)) {
        charStack2.push(ch);
    }

    bool same = true;
    if(charStack1.size() == charStack2.size()) {
        while(!charStack1.empty() && same) {
            if(charStack1.top() =! charStack2.top()) {
                same = false;
            }
            charStack1.pop();
            charStack2.pop();
        }
    }
    else if(charStack1.empty() && charStack2.empty()) {
        std::cout << "Both files are empty.\n";
    }
    else
        std::cout << "Both files are not the same.\n";

    if(same)
        std::cout << "Both files are the same.\n";
    
    return 0;
}