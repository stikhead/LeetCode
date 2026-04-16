class Solution {
public:
    void recursion(vector<string> &output, int openIndex, int closeIndex, int n, string &op){
        if(openIndex == n && closeIndex == n){
            output.push_back(op);
            return;
        }

        if(openIndex < n){
            op.push_back('(');
            recursion(output, openIndex + 1, closeIndex, n, op);
            op.pop_back();
        }

        if(closeIndex < openIndex){
            op.push_back(')');
            recursion(output, openIndex, closeIndex + 1, n, op);
            op.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> output = {};
        string op = "";
        recursion(output, 0, 0, n, op);
        return output;
    }
};


// class Solution {
// public:
//     void recursion(vector<string> &output, int n, int openIndex, int closeIndex, string &open, string &close, string &op){
//         if(openIndex == n && closeIndex == n){
//             output.push_back(op);
//             return;
//         } 

//         if(openIndex == closeIndex){
//             op.push_back(open[openIndex]);
//             recursion(output, n, openIndex+1, closeIndex, open, close, op);
//             op.pop_back();
//             return;
//         }

//         if(openIndex == n && closeIndex < n){
//             op.push_back(close[closeIndex]);
//             recursion(output, n, openIndex, closeIndex+1, open, close, op);
//             op.pop_back();
//             return;
//         }

//         op.push_back(open[openIndex]);
//         recursion(output, n, openIndex + 1, closeIndex, open , close, op);
//         op.pop_back();
        
//         op.push_back(close[closeIndex]);
//         recursion(output, n, openIndex, closeIndex +1, open , close, op);
//         op.pop_back();

//         return;

//     }
//     vector<string> generateParenthesis(int n) {
//        string open = "";
//        string close = "";
//        for(int i=0; i<n; i++){
//         open.push_back('(');
//         close.push_back(')');
//        }
//         vector<string> output = {};
//         string op = "";
//        recursion(output, n, 0, 0, open, close, op);
//        return output;
//     }
// };