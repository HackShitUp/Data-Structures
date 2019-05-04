//
//  main.cpp
//  Mini-Project-2
//
//  Created by Joshua Choi on 5/3/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <limits>
using namespace std;

/// Used to represent the operands on the lhs or rhs of the operator (only applicable to single-digit operands).
using ValueType = int;

/**
 * @class IllegalExpressException
 * Abstract: Exception class thron by an illegal infix expression
 */
class IllegalExpressException : public runtime_error {
    
};

/**
 * @class ZeroDivideException
 * Exception class thrown by zero divide exception
 */
class ZeroDivideException : public runtime_error {
    
};

/**
 * Determine the value of an infix expression
 *
 * @param expr a string, supposedly representing an infix expression
 * @return the value of <code>expr</code>
 * @throw IllegalExpressException if <code>expr</code> is not a legal infix
 * expression
 * @throw ZeroDivideException if <code>expr</code> involves a division
 * by zero
 */
ValueType processExpression(const string& expr) throw (IllegalExpressException, ZeroDivideException);

bool isValidResponse(char response);
bool isYesResponse(char response);
int precedence(char op);
void provideHelpIfNecessary(void);
void execute(stack<ValueType>& valstack, stack<char>& opStack)
throw (IllegalExpressException, ZeroDivideException);
ValueType doOperation(ValueType operandL, char operation, ValueType operandR)
throw (IllegalExpressException, ZeroDivideException);



// MARK: - Main
int main(void) {
    
    // Log the initial statements
    provideHelpIfNecessary();
    
    // Execute reading the expressions until the program was terminated
    while (true) {
        cout << "Expression? " ;
        
        /// Initialized String used to store the input
        string expression;
        // Get the input
        getline(cin, expression);
        
        // Terminate the program if the input was a simple return key
        if (expression.length() == 0) {
            break;
        } else {
            // Attempt to process the input expression
            
            try {
                // MARK: - ValueType
                ValueType result = processExpression(expression);
                cout << result << endl;
            } catch (exception& ex) {
                // Log the error
                cerr << "Illegal expression: " << ex.what() << endl;
            }
        }
    }
    cout << endl;
}

/// Log the statements for the user to begin inputting arithemtic expressions.
void provideHelpIfNecessary() {
    /// Initialized character value used to store the
    char response;
    
    cout <<"Do you need help (Y/N)? ";
    cin >> response;
    cin.ignore();

    /// Determine if the input value was valid or not
    bool isValid = isValidResponse(response);
    
    // Delegate the validity
    if (isValid == true) {
        //
        // Valid Response
        //
        if (isYesResponse(response) == true) {
            cout << "Enter an infix expression at the prompt." << endl;
            cout << "The program will tell you its value." << endl;
            cout << "To stop the program, just hit 'return' at the prompt." << endl;
        } else {
            return;
        }
        
    } else if (isValid == false) {
        //
        // Invalid Response
        //
        cout << "Reponse must be 'Y' or 'N'." << endl;
        provideHelpIfNecessary();
    }
}

/// Boolean method used to determine if a character is either 'Y' or 'N' (lowercased or capitalized).
/// \param response Character value used to determine if it's valid or not.
bool isValidResponse(char response) {
    return (response == 'Y' || response == 'N') || (response == 'y' || response == 'n');
}

/// Boolean method used to determine if the response was yes ('y', lowercased or capitalized) via its character.
/// \param response Character value used to determine if it's valid or not.
bool isYesResponse(char response) {
    return (response == 'Y' || response == 'y');
}

/// Method used to manipulate the expression to perform calculations
ValueType processExpression(const string& expr) throw (IllegalExpressException, ZeroDivideException) {
    
    // MARK: - Stack
    /// Initialized stack used to store the values in the input expression
    stack<ValueType> valueStack;
    /// Initialized stack used to store the operators in the input expression
    stack<char> operatorStack;

    /// Loop through the string expression's characters
    for (int i = 0; i < expr.length(); i++) {
        
        // Append the value to its stack if it's a valid integer
        if (expr[i] >= '0'&& expr[i] <= '9') {
            // MARK: - ValueType
            ValueType num = expr[i] - '0';
            valueStack.push(num);
        }
        
        // If the expression is starting an operation...
        if (expr[i] == '(')
            operatorStack.push(expr[i]);
            
            // Attempt to calculate the operation
            if (expr[i] == '*'|| expr[i] == '+'|| expr[i] == '-'|| expr[i] == '/') {
                // If it's empty we append the expression
                if(operatorStack.empty()) {
                    operatorStack.push(expr[i]);
                } else if (precedence(expr[i]) > precedence(operatorStack.top())) {
                // Otherwise, if the expression is greater than the top of the operand stack we append the expression
                    operatorStack.push(expr[i]);
                } else {
                    // Otherwise, we calculate the expression
                    while (!operatorStack.empty() && precedence(expr[i]) <= precedence(operatorStack.top())) {
                        execute(valueStack, operatorStack);
                    }
                }
                operatorStack.push(expr[i]);
            }
        
        // If the expression is ending an operation...
        if (expr[i] == ')') {
            while (operatorStack.top() != '(')
                execute(valueStack, operatorStack);
                operatorStack.pop();
        }
    }

    if (!operatorStack.empty()) {
        execute(valueStack, operatorStack);
    }

    // MARK: - ValueType
    ValueType result = valueStack.top();
    return result;
}

/// Return the ranking of an operation.
/// @param op Character representing an operator.
int precedence(char op) {
    if (op == '*' || op == '/')
        op = 3;
    if (op == '+' || op == '-')
        op = 2;
    if (op == '(')
        op = 0;
    else
        op = -1;
    return op;
}

/// Calculates the expression using the order of operations by
/// @param valStack Stack storing all the ValueType values
/// @param opStack Stack storing all the operators in the expression
void execute(stack<ValueType>& valStack, stack<char>& opStack)
throw (IllegalExpressException, ZeroDivideException) {
    ValueType result;
    ValueType operand1 = valStack.top();
    valStack.pop();
    ValueType operand2 = valStack.top();
    valStack.pop();
    char op = opStack.top();
    opStack.pop();
    result = doOperation(operand2, op, operand1);
    valStack.push(result);
}

/// Perform the operation between the lhs and rhs values.
/// @param operandL The lhs value
/// @param operation A character representing the supported operations to calcualte the lhs and rhs expression
/// @param operandR the rhs value
ValueType doOperation(ValueType operandL, char operation, ValueType operandR)
throw (IllegalExpressException, ZeroDivideException) {
    ValueType answer = 0;
    if (operation == '*') {
        answer = operandL * operandR;
    }
    if (operation == '/') {
        answer = operandL / operandR;
    }
    if (operation == '+') {
        answer = operandL + operandR;
    }
    if (operation == '-') {
        answer = operandL - operandR;
    }
    return answer;
}
