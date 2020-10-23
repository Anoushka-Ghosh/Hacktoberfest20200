class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)-1
        if length < 1:
            return s
        index = [0, 1]
        for i in range(length):
            l = index[1]-index[0]+1
            for j in range(i+l, length+2):
                s1 = s[i:j]
                if s1 == s1[::-1] and j-i >= l:
                    index = [i, j]
        return s[index[0]:index[1]]
        
