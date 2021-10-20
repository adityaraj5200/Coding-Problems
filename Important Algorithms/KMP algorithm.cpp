class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length(), m=needle.length(), cnt=0, i=1, j=0;
        if(m==0) return 0;;
        vector<int> lps(m,0);
        for(;i<m;i++){
            if(needle[i] == needle[j]) cnt++,j++;
            else j = cnt = 0;
            
            lps[i] = cnt;
        }
        
        i = j = 0;
        while(i<n-m+1){
            if(haystack[i]==needle[j]) i++,j++;
            else {
                if(j!=0) j = lps[j-1];
                else i++;
            }
            if(j==m)
                return i-m;
        }
        
        return -1;
    }
};
