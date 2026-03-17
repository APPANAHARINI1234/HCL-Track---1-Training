#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'areBracketsProperlyMatched' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING code_snippet as parameter.
 */

bool areBracketsProperlyMatched(string code_snippet) {
   stack<char>st;
   for(int i = 0; i < code_snippet.length(); i ++){
     char ch = code_snippet[i];
     if(ch == '(' || ch == '{' || ch == '['){
        st.push(ch);
     }
     else if(ch == ')' || ch == '}' || ch == ']'){
        if(st.empty())
         return false;
        if(ch == ')'){
            if(st.top() != '(')
              return false;
            st.pop();
        }
        else if(ch == ']'){
            if(st.top() != '[')
              return false;
              st.pop();
        }
        else if(ch == '}'){
            if(st.top() != '{')
              return false;
              st.pop();
        }
     }
   }
   return st.empty();
}

int main()
{
    string code_snippet;
    getline(cin, code_snippet);

    bool result = areBracketsProperlyMatched(code_snippet);

    cout << result << "\n";

    return 0;
}
