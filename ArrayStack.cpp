#include "ArrayStack.h"
#include <iostream>
using namespace std;

//Global var to keep track of first unmatched curly bracket.
int indexToBreak;
//Global var to keep track of missingbracket causing runtime error//stackfull//stackempty
char missingBrace;

/*
 * Exception class to handle operations attempted on an empty stack.
 */
class StackEmpty {
public:
    StackEmpty(const string& err) {}
};

/*
 * Exception class to handle operations attempted on a full stack.
 */
class StackFull {
public:
    StackFull(const string& err) {}
};

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1) {
} // constructor

template <typename E>
int ArrayStack<E>::size() const {
    return (t + 1);
} // size

template <typename E>
bool ArrayStack<E>::empty() const {
    return (t < 0);
} //empty

template <typename E>
const E& ArrayStack<E>::top() {
    if (empty()) {
        throw StackEmpty("Stack is empty!");
    } else {
        return S[t];
    }
} // top

template <typename E>
void ArrayStack<E>::push(const E& e) {
    if (size() == capacity) {
        throw StackFull("Stack is full!");
    } else {
    S[++t] = e;
    } 
 } // push

template <typename E>
void ArrayStack<E>::pop() {
    if (empty()) {
        throw StackEmpty("Stack is empty!");
    } else {
        --t;
    }
} // pop

/*
 * Function to compare corresponding curly brackets. If the input
 * array element is a left curly brace we will push it onto the stack.
 * If the next array element is a right curly brace and the stack
 * is not empty, we will pop it off the stack. After traversing through
 * the entire array, if the stack is empty we have proper corresponding
 * brackets and the program will compile correctly. If not, return false
 * indicating that the program would not have compiled.
 */
bool checkBrackets(int size, char * inputArr) {
    ArrayStack<char> A;
    bool bracesGood;
    char temp;
    int prevIndexBreak;
    int indexBreak;
    for (int i = 0; i < size; i++) {
        temp = inputArr[i];
         if (temp == '{') {
//             cout << "pushing on " << temp << endl;
             indexToBreak = i;
            A.push(temp);
        } else if (temp == '}') {
            if (A.empty()) {
                missingBrace = '{';
                indexToBreak = i;
                return false;
            } else {
                A.pop();
            }
         } // else if
    } // for
    if (A.empty()) {
        bracesGood = true;
    } else {
        missingBrace = '}';
        bracesGood = false;
    }
    return bracesGood;
} // checkBrackets

 /*
  * Main function to handle user input and display output via std. Input
  * is stored into an array which is then passed to the checkBrackets function
  * and checked for correctness with an array based stack.
  */
int main() {
     string inputStr;
     cout << "Enter your code:" << endl;
     cin >> inputStr;
    int size = inputStr.length();
    char inputArray[size];
    for (int i = 0; i < size; i++) {
        inputArray[i] = inputStr[i];
    }
    if (checkBrackets(size, inputArray) == false) {
        cout << "Invalid: program stops at ";
        for (int i = 0; i <= indexToBreak; i++) {
            cout << inputArray[i];        }
        cout << ", Missing " << missingBrace  <<  endl;
    } else {
        cout << "Valid." << endl;
    }
    return 0;
} // main
