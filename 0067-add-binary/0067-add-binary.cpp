class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1,j=b.size()-1,carry = 0;
        string res = "";
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0) sum += a[i--]-'0';
            if(j>=0) sum += b[j--]-'0';
            res = char(sum%2 + '0') + res;
            carry = sum/2;
        }
        return res;
    }
};