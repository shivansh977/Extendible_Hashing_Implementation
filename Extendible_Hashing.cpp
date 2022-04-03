#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <cmath>
#define ll int long long
#define makearr int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
#define For(i,j,n) for(int i=j;i<n;i++)
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pll pair<ll,ll>
#define ri(n) int n; cin>>n;
#define rll(n) ll n; cin>>n;
#define di(n) int n;
#define dll(n) ll n;
using namespace std;
void swap(int* a, int* b){
    int tmp=(*a);
    *a=*b;
    *b=tmp;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int gd,bc;
    cin>>gd>>bc;
    map<int,int> rel;
    int ini=pow(2,gd);
    vector<vector<int>> buckets(int(pow(2,20)));
    vector<int> ld(int(pow(2,20)),gd);
    int bs=ini;
    For(i,0,ini){
        rel[i]=i;
    }
    while(1){
        int tmp;cin>>tmp;
        if(tmp==6) break;
        else if(tmp==2){
            int val;cin>>val;
            buckets[rel[val%int(pow(2,gd))]].pb(val);
            while(buckets[rel[val%int(pow(2,gd))]].size()==bc+1){
                vector<int> tmp;
                int rem=val%int(pow(2,gd));
                if(!buckets[rel[val%int(pow(2,gd))]].empty()){
                For(i,0,buckets[rel[val%int(pow(2,gd))]].size()){
                    tmp.pb(buckets[rel[val%int(pow(2,gd))]][i]);
                }
                buckets[rel[val%int(pow(2,gd))]].clear();
                }
                int nld=++ld[rel[val%int(pow(2,gd))]];
                if(nld>gd){
                    For(i,0,int(pow(2,gd))){
                        rel[i+int(pow(2,gd))]=rel[i];
                    }
                    gd++;
                }
                bs++;
                For(i,0,int(pow(2,gd))){
                    int nre=int(pow(2,nld-1))+val%(int(pow(2,nld-1)));
                    if(i%int(pow(2,nld))==nre){
                        rel[i]=bs-1;
                    }
                }
                ld[bs-1]=nld;
                if(!tmp.empty()){
                For(i,0,tmp.size()){
                    buckets[rel[tmp[i]%int(pow(2,gd))]].pb(tmp[i]);
                }}
            }
        }
        else if(tmp==3){
            int val;cin>>val;int flag=0;
            if(!buckets[rel[val%gd]].empty()){
            For(i,0,buckets[rel[val%gd]].size()){
                if(val==buckets[rel[val%gd]][i]){
                    flag=1;break;
                }
            }
            }
            //if(flag) cout<<"YES\n";
            //else cout<<"NO\n";
        }
        else if(tmp==4){
            int val;cin>>val;int flag=0;int id=-1;int siz=int(buckets[rel[val%gd]].size())-1;
            if(!buckets[rel[val%gd]].empty()){
            For(i,0,buckets[rel[val%gd]].size()){
                if(val==buckets[rel[val%gd]][i]){
                    id=i;flag=1;break;
                }
            }
            if(flag){
                swap(buckets[rel[val%gd]][siz],buckets[rel[val%gd]][id]);
                buckets[rel[val%gd]].pop_back();
            }
            }
        }
        else if(tmp==5){
            cout<<gd<<"\n";
            cout<<bs<<"\n";
            For(i,0,bs){
                cout<<buckets[i].size()<<" "<<ld[i]<<"\n";
            }
        }
    }
    return 0;
}