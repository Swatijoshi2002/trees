/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int buildsegtree(vector<int>&segTree,vector<int>& arr,int sl,int sr,int i)
{
    if(sl==sr)
    {
      return  segTree[i]=arr[sl];
        
    }
    else {
        int mid=(sl+sr)/2;
      return  segTree[i]=buildsegtree(segTree,arr,sl,mid,2*i+1)+buildsegtree(segTree,arr,mid+1,sr,2*i+2);
    }
   
}
void update_tree(vector<int>&segTree,int l,int r,int i,int index,int val)
{
    if(l<=index && index<=r)
    {
        segTree[i]+=val;
    if(l==r)return;
    int mid=(l+r)/2;
    update_tree(segTree,l,mid,2*i+1,index,val);
    update_tree(segTree,mid+1,r,2*i+2,index,val);
    }
    return;
}

int rangesum(vector<int>& segTree,int sl,int sr,int i,int ql,int qr)
{
    if(qr<sl || sr<ql) return 0;
    if(ql<=sl && sr<=qr) return segTree[i];
    
        int mid=(sl+sr)/2;
      return  rangesum(segTree,sl,mid,2*i+1,ql,qr)+rangesum(segTree,mid+1,sr,2*i+2,ql,qr);
}
int main()
{
   int n;
   cin>>n;
   int size=pow(2,ceil(log(n))+1)-1;
   vector<int>segTree(size);
   vector<int>arr(n,0);
   cout<<"enter values of array"<<endl;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
    
   buildsegtree(segTree,arr,0,n-1,0);
   for(int i=0;i<size;i++)
   {
       cout<<segTree[i]<<" ";
   }
   while(1)
   {
       int t;
       cout<<"enter the op 1.update tree 2.rangesum 3.toexit"<<endl;
       cin>>t;
       switch(t)
       {
           case 1:
           {
            cout<<"enter new value and index"<<endl;
           int new_val,index;
           cin>>new_val>>index;
           int change_val=new_val-arr[index];
           arr[index]=new_val;
           update_tree(segTree,0,n-1,0,index,change_val);
           for(int i=0;i<size;i++)
          {
          cout<<segTree[i]<<" ";
          }
        break;
           }
        case 2:
        int ql,qr;
        cin>>ql>>qr;
        cout<<rangesum(segTree,0,n-1,0,ql,qr);
        
        break;
        
       }
   }
   
}
