#include <iostream>
#include<vector>
using namespace std;
void solve(int i,vector<int>arr,vector<int>a,vector<int>b,vector<int>c,int total){
    if(i==arr.size()){
        int counta=0;
        for(auto i:a){
            counta+=i;
        }
        int countb=0;
        for(auto i:b){
            countb+=i;
        }
        int countc=0;
        for(auto i:c){
            countc+=i;
        }
        if(counta*100/total==50&&countb*100/total==30&&countc*100/total==20){
            cout<<"YES"<<endl;
        }
        return;
    }
    a.push_back(arr[i]);
    solve(i+1,arr,a,b,c,total);
    a.pop_back();
    b.push_back(arr[i]);
    solve(i+1,arr,a,b,c,total);
    b.pop_back();
    c.push_back(arr[i]);
    solve(i+1,arr,a,b,c,total);

}
int main() {
    cout<<"run distribute_apple"<<endl;
    vector<int>arr;
    while (true)
    {
        cout<<"Enter apple weight in gram (-1 to stop ) : ";
        int apple_weight;
        cin>>apple_weight;
        if(apple_weight==-1) break;
        arr.push_back(apple_weight);
    }

    int total=0;
    for(auto i:arr){
        total+=i;
    }    
    solve(0,arr,{},{},{},total);
    return 0;
}
 