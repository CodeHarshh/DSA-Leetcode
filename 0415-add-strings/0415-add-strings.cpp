class Solution {
public:

 string addStrings(string num1, string num2){
        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        int carry=0;
        int digit=0;
        string ans="";
        
        while(p1>=0 || p2>=0 || carry){

        int x=(p1>=0)? num1[p1]-'0' : 0;
        int y=(p2>=0)? num2[p2]-'0' : 0;
        int sum=x+y+carry;
        digit=sum%10;
        carry=sum/10;
        ans+=digit+'0';
        p1--,p2--;
        }

reverse(ans.begin(),ans.end());
return ans;
    }



    // void add(string& num1, string& num2, int p1, int p2, int carry,
    //          string& ans) {
    //     // base case
    //     if (p1 < 0 && p2 < 0) {
    //         if (carry != 0) {
    //             ans.push_back(carry + '0');
    //         }
    //         return;
    //     }

    //     // ek case sove
    //     int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    //     int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    //     int currsum = n1 + n2 + carry;
    //     int digit = currsum % 10;
    //     carry = currsum / 10;

    //     ans.push_back(digit + '0');
    //     add(num1, num2, p1 - 1, p2 - 1, carry, ans);
    // }

    // string addStrings(string num1, string num2) {
    //     int p1 = num1.size() - 1;
    //     int p2 = num2.size() - 1;
    //     int carry = 0;
    //     string ans = "";
    //     add(num1, num2, p1, p2, carry, ans);
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
};