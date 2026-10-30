
class Solution {
public:
    bool equalFrequency(string word) {
        int array[26] = {0};

        for(int i=0; i<word.size(); i++){
            array[word[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if(array[i]>0){
                array[i]--;

                int prev = 0;
                bool flag = true;

                for(int j=0; j<26; j++){
                    if(array[j]>0){
                        if(prev==0){
                            prev=array[j];
                        }
                        else if(prev!=array[j]){
                            flag=false;
                            break;
                        }
                    }
                }

                if(flag) return true;

                array[i]++;
            }
        }

        return false;
    }
};
