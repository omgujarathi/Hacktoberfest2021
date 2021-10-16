#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> a, int n){
        vector<vector<int>> arr;
        vector<int> ar;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]){
                if(ar.size()){
                if(ar[ar.size()-1]==i-1){
                    ar.pop_back();
                    ar.push_back(i);
                }
                else{
                    ar.push_back(i-1);
                    ar.push_back(i);
            }}
            else{
                ar.push_back(i-1);
                    ar.push_back(i);
            }
            }
        }
        for(int i=0;i<ar.size();i+=2){
            arr.push_back({ar[i],ar[i+1]});
        }
        return arr;
        
        
    }
};


int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}