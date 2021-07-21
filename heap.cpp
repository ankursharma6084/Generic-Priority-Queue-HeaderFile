#include<iostream>
#include"heap.h"
using namespace std;

bool comp(int a,int b)
{ 
   return a<b;
}

int main()
{

    Heap<int> h(comp);

    int n; cin>>n;


    for(int i=0;i<n;i++)
    {
        int no; cin>>no;

        h.push(no);
    }

    cout<<h.size()<<endl;

    while(h.size()>0)
    {
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}

