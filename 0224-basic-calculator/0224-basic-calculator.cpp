class Solution {
public:
// yt -> https://youtu.be/rK_00b5pMb0?si=SRgU1rlzZcPW3l_D
    int calculate(string s) {
        stack<long long  > nums , operation;

        long long int num=0;
        long long int result=0;
        long long int sign=1;

        for(char ch:s){
            if(isdigit(ch)){
                num=num * 10 + ch  -'0';
            }
            else{
                 result =result + (sign * num);
                 num=0;

                 if(ch=='+') sign =1;
                 if(ch=='-') sign =-1;
                 if(ch=='('){
                    nums.push(result);
                    operation.push(sign);
                    result=0;
                    sign=1;
                 }

                 if(ch==')' && operation.size()){
                    result=operation.top() * result + nums.top();
                    operation.pop();
                    nums.pop();
                 }
            }
        }
        result  += sign *num;
    return result;
    }
};