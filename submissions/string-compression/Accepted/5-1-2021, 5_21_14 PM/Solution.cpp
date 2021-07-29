// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size(), i, j, curr_char, curr_count;
        
        curr_char = chars[0];
        curr_count =1;
        j=0;
        
        for(int i=1;i<n;i++){
            if(chars[i]==curr_char)
                curr_count++;
            else{
                
                chars[j]=curr_char;
                j++;
                
                if(curr_count>1){
                    string count_str = to_string(curr_count);
                    int len =0;
                    
                    while(len<count_str.size()){
                        chars[j]=count_str[len];
                        j++;
                        len++;
                    }
                }
                curr_char = chars[i];
                curr_count =1;
            }
        }
        chars[j]=curr_char;
        j++;
        if(curr_count>1){
                    string count_str = to_string(curr_count);
                    int len =0;
                    
                    while(len<count_str.size()){
                        chars[j]=count_str[len];
                        j++;
                        len++;
                    }
                }
        return j;
        
    }
};