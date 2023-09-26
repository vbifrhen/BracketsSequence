#include <iostream>
#include <stack>

bool bracketChecker(std::string& str, int& index){
    std::stack<std::pair<int, char>> s;
    int index_first_elem = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            index = i;
            if(s.empty()){
                index_first_elem = i;
            }
            s.emplace(i, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if (s.empty()){
                index = i;
                return false;
            }
            else if (str[i] == ')' && s.top().second != '('){
                index = s.top().first;
                return false;
            }
            else if (str[i] == ']' && s.top().second != '['){
                index = s.top().first;
                return false;
            }
            else if (str[i] == '}' && s.top().second != '{'){
                index = s.top().first;
                return false;
            }
            else{
                s.pop();
            }
        }
    }
    if(!s.empty()){
        index = index_first_elem;
        return false;
    }
    return s.empty();
}

int main() {
    std::string str;
    std::cout << "Enter a sequence: ";
    std::cin >> str;
    int index;
    if (bracketChecker(str, index)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << index << std::endl;
    }
    return 0;
}
