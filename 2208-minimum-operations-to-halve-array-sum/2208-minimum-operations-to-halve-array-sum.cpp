class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            sum = sum + nums[i];
        }
        int ans = 0;
        double y=sum/2;
        while (sum > y) {
            double a = pq.top();
            pq.pop();
            a = a / 2;
            pq.push(a);
            sum -= a;
            ans++;
        }
        return ans;
    }
};