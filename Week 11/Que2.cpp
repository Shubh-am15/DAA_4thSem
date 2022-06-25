#include<bits/stdc++.h>
using namespace std;

int change(int amount, vector<int> &coins) {
        int n=coins.size();
        int t[n+1][amount+1];
        for (int i=0;i<amount+1;i++)
            t[0][i]=0;
        for (int i=0;i<n+1;i++)
            t[i][0]=1;
        
        for (int i=1;i<n+1;i++)
        {
            for (int j=1;j<amount+1;j++)
            {
                if (coins[i-1]<=j)
                    t[i][j]=t[i][j-coins[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][amount];        
    }
int main()
{
    int n;
    cout<<"Enter the n:"<<endl;
    cin>>n;
    cout<<"Enter the n number in array:"<<endl;
    vector<int> arr(n,0);
    for (int i=0;i<n;i++)
       cin>>arr[i];

    int amount;
    cout<<"Enter the amount:"<<endl;
    cin>>amount;
   
    cout<<"Minimum Number of Operations:"<<change(amount,arr);
}