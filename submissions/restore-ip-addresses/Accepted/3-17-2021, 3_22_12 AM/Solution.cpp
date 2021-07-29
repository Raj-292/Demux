// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:
    //this function is used a part is valid or not.
    bool isvalid(string &part)
    {
        if(part[0]=='0' && part.size()>1)return false;
        int x=stoi(part);
        if(x>=0 && x<=255)return true;
        return false;
    }
    
    void f(string &s,vector<string>&res,string &cont,int &partion_count,int start)
    {
        int n=s.size();
        //base case
        if(partion_count==4 && start==n)
        {
            //here we remove first .
           cont=cont.substr(1,cont.size()-1);
            res.push_back(cont);
            //here we again add that . which ever we delete.
            string x="."+cont;
            cont=x;
            return;
        }
        //if we take more than 4 partion than return.
        if(partion_count>=4)return;
        string part;
        for(int i=start;i<n && i<start+3;i++)
        {
            //here we calculated the part
            part=s.substr(start,i-start+1);
            if(isvalid(part))
            {   
                partion_count++;
                cont.push_back('.');
                cont+=part;
                f(s,res,cont,partion_count,i+1);
                while(cont[cont.size()-1]!='.')cont.pop_back();
                cont.pop_back();
                partion_count--;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cont;
        //if string length is greater than 12 than return 
        if(s.size()>12)return {};
        //its counting the number of partion
        int partion_count=0;
        f(s,res,cont,partion_count,0);
            return res;
    }
};