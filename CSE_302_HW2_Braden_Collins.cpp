#include <iostream>

using namespace std;

//ACStack class
class ACStack
{
private:
    char items[100];
    int length;

public:
    //constructor
    ACStack()
    {
        length = -1;
    }

    //returns true if the stack is empty; false otherwise
    bool IsEmpty()
    {
        if(length == -1)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }

    //returns the item at the top of the stack
    char Peek()
    {
        return items[length];
    }

    //return and removes the item at the top of the stack
    char Pop()
    {
        int tempItem = items[length];
        length--;
        return tempItem;
    }

    //adds a new item to the top of the stack
    void Push(char newItem)
    {
        if(length >= 100)
        {
            cout << "Stack is full" << endl;
        }

        else
        {
            length++;
            items[length] = newItem;
        }
    }
};

//function declarations
bool matchedParentheses(string);
bool matchedBrackets(string);

//main
int main()
{
    cout << "matchedParentheses()" << endl;
    cout << matchedParentheses("(())()") << endl;
    cout << matchedParentheses("())(()") << endl;
    cout << matchedParentheses("(())") << endl;
    cout << matchedParentheses(")(") << endl;

    cout << "matchedBrackets()" << endl;
    cout << matchedBrackets("{<[]>()}") << endl;
    cout << matchedBrackets("{<[>()]}") << endl;
    cout << matchedBrackets("{<<[]>>({})}") << endl;
    cout << matchedBrackets("}{][") << endl;


    return 0;
}

//matchedParenthesis() function
bool matchedParentheses(string s)
{
    ACStack list;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            list.Push(s[i]);
        }
        
        else if(s[i] == ')')
        {
            if(list.IsEmpty())
            {
                return false;
            }

            list.Pop();
        }
    }
    
    if(list.IsEmpty())
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

//matchedBrackets() function
bool matchedBrackets(string s)
{
    ACStack list;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<')
        {
            list.Push(s[i]);
        }

        else if(s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>')
        {
            if(list.IsEmpty())
            {
                return false;
            }

            else if(list.Peek() == '(' && s[i] == ')')
            {
                list.Pop();
            }

            else if(list.Peek() == '[' && s[i] == ']')
            {
                list.Pop();
            }

            else if(list.Peek() == '{' && s[i] == '}')
            {
                list.Pop();
            }

            else if(list.Peek() == '<' && s[i] == '>')
            {
                list.Pop();
            }

            else
            {
                return false;
            }
        }
    }
    
    if(list.IsEmpty())
    {
        return true;
    }
    
    else
    {
        return false;
    }
}