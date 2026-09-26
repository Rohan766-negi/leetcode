class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        map<string,string> mp;

        for(int i=0; i<knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;

        while(i < s.length()){

            if(s[i] == '('){

                int st = i;
                string x = "";

                i++;

                while(s[i] != ')'){
                    x = x + s[i];
                    i++;
                }

                int end = i;

                if(mp.find(x) != mp.end())
                    s.replace(st, end-st+1, mp[x]);
                else
                    s.replace(st, end-st+1, "?");

                i = st + (mp.find(x) != mp.end() ? mp[x].length() : 1);
            }
            else{
                i++;
            }
        }

        return s;
    }
};