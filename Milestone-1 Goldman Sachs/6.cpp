// 1071. Greatest Common Divisor of Strings
//Name: Arun Pratap Singh
//https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? 
            str2.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};