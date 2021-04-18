#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> bra;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
          struct Bracket temp(next, position);
          bra.push(temp);
            // Process opening bracket, write your code here
        }

        if (next == ')' || next == ']' || next == '}') {
          if(!bra.empty())
          {
            if((bra.top()).Matchc(next)) bra.pop();
            else
            {
              cout<<position+1<<endl;
              return 0;
            }
          }
          else {cout<<position+1<<endl; return 0;}
 // Process closing bracket, write your code here
        }
        // cout<<bra.top().type<<endl;

    }
        // cout<<bra.top().type<<endl;
        // cout<<bra.empty()<<endl;
    // Printing answer, write your code here
    if(bra.empty())
    {cout<<"Success"<<endl; return 0;}
    cout<<bra.top().position + 1<<endl;
    return 0;

}
