class Solution {
public:
    int reverse(int temp){
            int t = 0;
            while(temp>0){
                t = t*10 + temp%10; 
                temp=temp/10;
            }
            return t;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            int t = reverse(temp);
            while(temp>0){
                int y = t%10;
                t = t/10;
                temp = temp/10;
                answer.push_back(y);
            }
        }
    return answer;
    }
};