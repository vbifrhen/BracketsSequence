#include <iostream>
#include <stack>

bool bracketChecker(std::string& str, int& index){
    std::stack<std::pair<int, char>> openBrackets;
    int index_first_elem = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            index = i;
            if(openBrackets.empty()) {
                index_first_elem = i;
            }
            openBrackets.emplace(i, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (openBrackets.empty()) {
                index = i;
                return false;
            }
            else if (str[i] == ')' && openBrackets.top().second != '(') {
                index = openBrackets.top().first;
                openBrackets.pop();
                int a = 0;
                while ((!openBrackets.empty()) && (a != 1)) {
                    if (openBrackets.top().second == '(') {
                        a = 1;
                    }
                    openBrackets.pop();
                }
                if (a != 1) {
                    index = i;
                }
                return false;
            }
            else if (str[i] == ']' && openBrackets.top().second != '[') {
                index = openBrackets.top().first;
                openBrackets.pop();
                int a = 0;
                while ((!openBrackets.empty()) && (a != 1)) {
                    if (openBrackets.top().second == '[') {
                        a = 1;
                    }
                    openBrackets.pop();
                }
                if (a != 1) {
                    index = i;
                }
                return false;
            }
            else if (str[i] == '}' && openBrackets.top().second != '{') {
                index = openBrackets.top().first;
                openBrackets.pop();
                int a = 0;
                while ((!openBrackets.empty()) && (a != 1)) {
                    if (openBrackets.top().second == '{') {
                        a = 1;
                    }
                    openBrackets.pop();
                }
                if (a != 1) {
                    index = i;
                }
                return false;
            }
            else {
                openBrackets.pop();
            }
        }
    }
    if(!openBrackets.empty()) {
        index = index_first_elem;
        return false;
    }
    return openBrackets.empty();
}

int main() {
    std::string str;
    std::cout << "Enter a sequence: ";
    std::cin >> str;
    int index;
    if (bracketChecker(str, index)) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << index << std::endl;
    }
    return 0;
}
