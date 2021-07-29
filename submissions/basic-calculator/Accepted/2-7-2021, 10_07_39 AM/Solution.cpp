// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s1) {
    string s="("+s1+")";
    int n=s.length();
    string sac="";
    stack<string>dev;
    for(int i=0;i<n;i++)
    {
    if(s[i]==' ')
    {
    continue;
    }
    if(isdigit(s[i]))
    {
    sac+=s[i];
    continue;
    }
    if(sac != "")
    {
    if(!dev.empty()&&(dev.top()=="+"||dev.top()=="-"))
    {
    string t=dev.top();
    dev.pop();
    sac=t+sac;
    }
    dev.push(sac);
    sac="";
    }
    if(s[i]=='+'||s[i]=='-'||s[i]=='(')
    {
    string temp="";
    temp=temp+s[i];
    dev.push(temp);
    continue;
    }
    int exp=0;
    while(dev.top()!="(")
    {
    string k=dev.top();
    dev.pop();
    exp+=stoi(k);
    }
    dev.pop();
    string res=to_string(exp);
    if(!dev.empty()&&(dev.top()=="+"||dev.top()=="-"))
       {
       if(exp<0&&dev.top()=="-")
       {
         res[0]='+';
       }
          else if(exp>=0)
          {
           string t=dev.top();
           res=t+res;
          }
           dev.pop();
       }
      dev.push(res);
    }
     return stoi(dev.top());
    }
};