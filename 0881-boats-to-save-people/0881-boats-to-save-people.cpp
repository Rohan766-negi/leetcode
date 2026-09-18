class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      int n= people.size(); int sum=0; int c=0; int r=n-1; int l=0;
      sort(people.begin(), people.end());
     while(l<=r){
       if(people[l]+ people[r]<=limit){ l++;}
       r--; c++;
    
      }
      return c;
    }
};