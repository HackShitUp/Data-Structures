//
//  main.cpp
//  HW2
//
//  Created by Joshua Choi on 3/12/19.
//  Copyright © 2019 Joshua Choi. All rights reserved.
//

#include "AnyObject.cpp"
#include "MinStack.cpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// MARK: - Method Definitions
bool containsCharacter(char array[], int sizeOfArray, char element);
bool containsString(string array[], int size, string element);
bool arePairs(char opening, char closing);
bool isValid(string text);
bool inputStream(string inputA, string inputB);
void demonstrateMinStack();
string simplifyPath(string input);
int evaluatePFE(string input[], int size);
int applyOperator(int a, int b, string operand);

// MARK: - Main
int main() {
    
    // MARK: - Class Vars
    
    /// Used for output
    string headlines = "\n************************************************";
    
    // 1)
    cout << headlines << endl;
    cout << "1.) Determining if \"(){}[]\" is a valid string..." << endl;
    string validResultStatement = (isValid("()[]{}") == true) ? "TRUE" : "FALSE";
    cout << validResultStatement << endl;
    
    // 2)
    cout << headlines << endl;
//    string inputA = "a<<bc", inputB = "abc<";
    string inputA = "abcde<<", inputB = "abcd<e<";
    cout << "2.) Determining if one of the 2 input streams — Input A: \"" << inputA << "\" and Input B: \"" << inputB << "\"  should have backspace..." << endl;
    string isInputStream = (inputStream(inputA, inputB) == true) ? "TRUE" : "FALSE";
    cout << isInputStream << endl;
    
    // 3)
    cout << headlines << endl;
    cout << "3.) Design a min stack that supports push, pop, top, and retrieving the minimum element using two stacks:\n";
    demonstrateMinStack();
    
    // 4)
    cout << headlines << endl;
    string path = "/home/";
//    string path = "/a/./b/../../c/";
//    string path = "./c/../a/./a";
    cout << "4.) Given an absolute path for a file (Unix-style), simplify it. Testing with \"" << path << "\"" << endl;
    string simplifiedResult = simplifyPath(path);
    cout << "• Result: " << simplifiedResult << endl;
    
    // 5)
    cout << headlines << endl;
//    string inputArithmetic[5] = {"2", "1", "+", "3", "*"};
    string inputArithmetic[5] = {"4", "13", "5", "/", "+"};
    cout << "5.) Evaluating the value of the arithmetic expression, in 'Reverse Polish Notation' (ie: postfix expression).\nValues: ";
    for (int i = 0; i < 5; i++) {
        cout << inputArithmetic[i] << " ";
    }
    cout << "\n• Calculation: ";
    int value = evaluatePFE(inputArithmetic, 5);
    cout << value << endl << endl;
    
    
    return 0;
}



/// Determines if the input string is valid (based on "(){}[]").
/// - Parameter text: A String value.
bool isValid(string text) {
    
    // MARK: - Stack
    stack<char> aStack;
    
    /// Initialized Boolean used to determine if the string is valid or not
    bool isValid = true;
    
    // Declared opening valid characters
    char openingValidCharacters[3] = {'(', '{', '['};
    // Declared closing valid characters
    char closingValidCharacters[3] = {')', '}', ']'};
    
    // Loop through the text and determine if the text contains another
    for(int i = 0; i < text.length(); i++) {
        
        /// Determine if the current element contains the opening characters
        bool doesContainOpening = containsCharacter(openingValidCharacters, 3, text[i]);
        /// Determine if the current element contains the closing characters
        bool doesContainClosing = containsCharacter(closingValidCharacters, 3, text[i]);
        
        if (doesContainOpening == true) {
            // Append the element to the top of the stack if the characters
            aStack.push(text[i]);
            
        } else if (doesContainClosing == true) {
            // If the stack is empty or the stack's top element and the current character are NOT valid
            if (aStack.empty() || arePairs(aStack.top(), text[i]) == false) {
                isValid = false;
            } else {
                // Pop the last element in the stack
                aStack.pop();
            }
        }
    }
    
    // Return the Boolean
    return isValid;
}



/// Determines if an element in a vector contains another character element
/// - Parameter array: A character array.
/// - Parameter sizeOfArray: An Int value representing the size of the array.
/// - Parameter element: A character value.
bool containsCharacter(char array[], int sizeOfArray, char element) {
    /// Initialized Boolean
    bool isContained = false;
    
    // Loop through the elements and determine whether the element is contained in an array
    for (int i = 0; i < sizeOfArray; i++) {
        if (array[i] == element) {
            isContained = true;
        }
    }
    
    // Return the isContained Boolean
    return isContained;
}



/// Determines if two characters match the valid parameters.
/// - Parameter opening: An opening character value.
/// - Parameter closing: A closing character value.
bool arePairs(char opening, char closing) {
    bool arePairs = (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
    return arePairs;
}



/// Method used to determine which of the two input streams should have backspace.
/// - Parameter inputA: The first input stream as a string value.
/// - Parameter inputB: The second input stream as a string value.
bool inputStream(string inputA, string inputB) {
    // MARK: - Stack
    stack<char> firstStack, secondStack;
    
    // MARK: - Iterator
    string::iterator firstIterator, secondIterator;
    
    // Loop through the first iterator and remove or append to the first stack
    for (firstIterator = inputA.begin(); firstIterator < inputA.end(); ++firstIterator) {
        if (*firstIterator == '<') {
            if (!firstStack.empty()) {
                firstStack.pop();
            } else {
                firstStack.push(*firstIterator);
            }
        }
    }
    
    // Loop through the second interator
    for (secondIterator = inputB.begin(); secondIterator < inputB.end(); ++secondIterator) {
        if (*secondIterator == '<') {
            if (!secondStack.empty()) {
                secondStack.pop();
            } else {
                secondStack.push(*secondIterator);
            }
        }
    }
    
    
    return (firstStack == secondStack);
}


/**
 Method used to demonstrate the MinStack class implementation. Expected behavior logs:
 -2
 0
 -1
 */
void demonstrateMinStack() {
    // MARK: - MinStack
    MinStack minStack;
    minStack.push(-1);
    minStack.push(0);
    minStack.push(-2);
    cout << "• The minimum value after pushing -1, 0, and 2" << " is..." << minStack.getMin() << endl;
    minStack.pop();
    cout << "• The top element after popping 2 off the stack" << " is..." << minStack.top() << endl;
    cout << "• The minimum value after popping 2 off the " << "stack is..." << minStack.getMin() << endl;
}


/// Simplifies a given String value repesenting a file path in Unix.
/// - Parameter input: A String value of the supposed directory.
string simplifyPath(string input) {
    // MARK: - Stack (used to store the file's name)
    stack<string> fileNameStack;
    
    // MARK: - Stack (Representation of 'fileNameStack', reversed. Used to compare with the original absolute path)
    stack<string> fileNameStackReversed;
    
    /// Temporary string storing the extracted directory name or commands. In otherwords, this value will store the 'split up' string representation of the absolute path when iterated.
    string directory;
    
    /// The final, simplified path initialized with "/" (root directory)
    string result = "/";
    
    // Get the length of the string
    int inputLength = input.length();
    
    // Loop through the string value
    for (int i = 0; i < inputLength; i++) {
        // De-allcoate the original value
        directory.clear();
        
        // Skip multiple/consecutive '/'s
        while (input[i] == '/') {
            i++;
        }
        
        /// Store the temporary value of the split string
        while (i < inputLength && input[i] != '/') {
            directory.push_back(input[i]);
            i++;
        }
        
        // If the directory has ".." and the stack is NOT empty, pop the top most value
        if (directory.compare("..") == 0 && fileNameStack.empty() == false) {
            fileNameStack.pop();
        } else if (directory.compare(".") == 0) {
            continue;
        } else if (directory.length() != 0) {
            // Append the temporary value to the stack if it's the file's absolute path (name)
            fileNameStack.push(directory);
        }
    }
    
    while (!fileNameStack.empty()) {
        // Append the top value of the fileNameStack
        fileNameStackReversed.push(fileNameStack.top());
        // Then remove it from the original stack
        fileNameStack.pop();
    }
    
    while (!fileNameStackReversed.empty()) {
        /// Get the current top value
        string temp = fileNameStackReversed.top();
        
        // If the reversed stack's size isn't empty or greater than 1, append the "/"
        result.append((fileNameStackReversed.size() != 1) == true ? (temp + "/") : temp);
        
        // Pop the top most stack
        fileNameStackReversed.pop();
    }
    
    return result;
}



/// Returns the value of a postfix expression.
/// - Parameter input: A string array.
/// - Parameter size: An Int of the size of the array.
int evaluatePFE(string input[], int size) {
    
    // MARK: - MinStack
    MinStack stack;
    
    /// Declared Array of String operators used to identify
    string operators[4] = {"+", "-", "*", "/"};
    
    // Loop through the input
    for (int i = 0; i < size; i++) {
        
        // Determine if the character is an operator
        bool isContained = containsString(operators, 4, input[i]);
        
        if (isContained == false) {
            // Get the integer value of the string element
            int valueFromString = stoi(input[i]);
            
            // Append the item to the stack
            stack.push(valueFromString);
            
        } else {
            // Here, we discover that an operator was found. We need to first calculate its value between its preceding stack and the top value after removing the top-most value thereafter.
            
            // Store the temporary value.
            int temporaryTopValue = stack.top();
            
            // Remove the last value
            stack.pop();
            
            // Get the value of the last 2 elements
            int precedingValues = applyOperator(stack.top(), temporaryTopValue, input[i]);
            
            // Remove the last value again
            stack.pop();
            
            // Append the calculated value
            stack.push(precedingValues);
        }
    }
    
    
    return stack.top();
}


/// Determines if an array of String values contains a String element.
/// - Parameter array: A String array.
/// - Parameter size: An Int value representing the size of the String array.
/// - Parameter element: A String value representing the element to check for.
bool containsString(string array[], int size, string element) {
    /// Initialized Boolean
    bool isContained = false;
    
    // Loop through the elements and determine whether the element is contained in an array
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            isContained = true;
        }
    }
    
    // Return the isContained Boolean
    return isContained;
}


/// Calculates the value of two integers based on the limited possible operations +, -, *, and /.
/// - Parameter a: An Int value (first).
/// - Parameter b: An Int value (second).
/// - Parameter operand: A string value of the operation to perform.
int applyOperator(int a, int b, string operand) {
    if (operand == "+") {
        return a+b;
    } else if (operand == "-") {
        return a-b;
    } else if (operand == "*") {
        return a*b;
    } else if (operand == "/") {
        return a/b;
    }
    return 0;
}


