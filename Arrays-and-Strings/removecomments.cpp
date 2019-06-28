#include<iostream>
 #include<vector>
 using namespace std;
 vector<string> removeComments(vector<string>& source) {
    vector<string> ans;
    bool dontpick = 0;
    for(int i = 0 ; i < source.size() ;i++)
    {
        string cur = source[i];
        string currans;

        string s = cur;
        for(int i = 0; i < s.length();i++)
        {
            bool lineoff = 0;
            if(i+1 < cur.length() && s[i]=='/' && s[i+1] == '/')
            {
                lineoff = 1;
            }
            else if(i+1 < cur.length() && s[i]=='/' && s[i+1] == '*')
            {
                dontpick = 1;
            }
            else if(i+1 < cur.length() && s[i]=='*' && s[i+1] == '/')
            {
                dontpick = 0;
                i++;
            }
            else if(dontpick == 0 && lineoff == 0)
            {
                currans += s[i];
            }
//            cout<<currans<<endl;
        }
        if(currans.length() > 0)
            ans.push_back(currans);
    }
    return ans;
 }

 void display(vector<string> & res){
     cout<<"[";
     for(int i=0;i<res.size();i++){
         cout<<res[i];
         if(i!=res.size()-1){
             cout<<", ";
         }
     }
     cout<<"]";
 }

 int main(int argc, char** argv){
     int n ;
     cin>>n;
     vector<string> source (n);
     cin.ignore();
     for (int i = 0; i < n; i++) {
         getline(cin,source[i]);
     }

     vector<string> res=removeComments(source);
     display(res);

 }
