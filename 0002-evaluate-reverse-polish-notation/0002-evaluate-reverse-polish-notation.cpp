class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        
        for(int i=0; i<tokens.size(); i++){
              
            if(tokens[i]=="+"){
                 int x=stoi(st.top());
                st.pop();
                int y=stoi(st.top());
                st.pop();
                string ans=to_string(x+y);
                
                st.push(ans);

            }
            else if(tokens[i]=="-"){
                 int x=stoi(st.top());
                st.pop();
                int y=stoi(st.top());
                st.pop();

                  string ans=to_string(y-x);
                
                st.push(ans);
            }
             else if(tokens[i]=="*"){
                 int x=stoi(st.top());
                st.pop();
                int y=stoi(st.top());
                st.pop();

                  string ans=to_string(x*y);
                
                st.push(ans);
            }
             else if(tokens[i]=="/"){
                 int x=stoi(st.top());
                st.pop();
                int y=stoi(st.top());
                st.pop();

                  string ans=to_string(y/x);
                
                st.push(ans);
            }
            else{
                st.push(tokens[i]);
            }
        }


        return stoi(st.top());
    }
};