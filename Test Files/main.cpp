#include <iostream>
#include "stack.h"

using namespace std;

int main() {

    Stack abc (10);

    char ch;

    cout << "Enter a bunch of characters: ";

    while ((ch = cin.get()) != '\n')
        if (!abc.full()) abc.push(ch);

    while (!abc.empty()) cout << abc.pop();

    cout << endl;

    return 0;

}
