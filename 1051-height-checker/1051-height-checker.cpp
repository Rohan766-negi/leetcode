class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;

priority_queue<int, vector<int>, greater<int>> pq;

for (int x : heights) {
    pq.push(x);
}

for (int x : heights) {
    if (x != pq.top()) {
        count++;
    }
    pq.pop();
}
         return count;
    }
};