class Solution {
  public:
    bool isPossible(int a, int b) {
        return (a==2 && (b==1 || b==3)) || (b==2 && (a==1 || a==3));
        
    }
};