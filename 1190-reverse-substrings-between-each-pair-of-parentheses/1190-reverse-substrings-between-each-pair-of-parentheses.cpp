class Solution {
public:
   void reverse(string &x){
       stack<char>s;
       int n=x.length();
       for( int i=0; i<n; i++){
        s.push(x[i]);
       }
       x="";
      while(!s.empty()){
          x=x+s.top();
          s.pop();
      }


   }
    string reverseParentheses(string s) {
          stack<string> st;
        string x = "";

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '('){

                st.push(x);
                x = "";
            }

            else if(s[i] == ')'){

                reverse(x);

                x = st.top() + x;
                st.pop();
            }

            else{

                x = x + s[i];
            }
        }

        return x;
    }
};