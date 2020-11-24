/*
Question: 
https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3536/
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        
        /* Nice problem
        
        So there are couple of catches in this.
        
        First we need to use 2 stacks - one for count and one for string
        
        Whenever we encounter a digit need to parse till we have got all the digits
        Then push it into count stack
        
        We need to have a strCurr to maintain current set of chars and stringStack to maintain 
        previously parsed string. Now we start parsing the string from begin to end.
        
        When we encounter a character we put it in the strCurr which maintains the current set.
        
        When we encounter [ we should push whatever string we have formed till now into the stringStack
        we should also clear the currString.
        
        Now comes the trickiest part, when we encounter a ], we pop the last string in stringStack into a temp
        variable. We pop the last count from the count stack to a num variable. Now replicate the currString -
        remember it is the current string - num times and append it to the temp.
        Now make temp as the current string.
        
        This takes care of the recursive handling of [ ]. Cases like 3[ab4[c]]     
        
        */
        
        vector<string> stringStack;
        vector<int> countStack;
        string strCurr = "";
        
        int i = 0;
        while(i < s.length())
        {
            if (s[i] == '[')
            {
                stringStack.push_back(strCurr);
                strCurr = "";
                i++;
            }
            else if (s[i] == ']')
            {
                string tempStr = stringStack.back();
                stringStack.pop_back();
                int num = countStack.back();
                countStack.pop_back();
                for (int i = 0; i < num; i++)
                    tempStr += strCurr;
                
                strCurr = tempStr;
                i++;
 
            }
            else if (isdigit(s[i]) != 0)
            {
                int cnt = 0;
                while(isdigit(s[i]) != 0)
                {
                    cnt = 10 * cnt + s[i] - '0';
                    i++;
                }
                countStack.push_back(cnt);
            }
            else
            {
                strCurr += s[i];
                i++;
            }
            
        }
        return strCurr;
        
    }
};