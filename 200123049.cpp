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
void spl(vector<vector<int>> &buckets,vector<int> &ld, map<int,int> &rel, int gd, int bno, int* bs){
    int val=buckets[bno][0];
    int tld=ld[rel[val%int(pow(2,gd))]]+1;
    int tre=int(pow(2,tld-1))+val%(int(pow(2,tld-1)));
    if(buckets[bno].empty()||tre>=int(pow(2,gd))) return;
    vector<int> tmp;
        int rem=val%int(pow(2,gd));
        if(!buckets[rel[val%int(pow(2,gd))]].empty()){
        For(i,0,buckets[rel[val%int(pow(2,gd))]].size()){
            tmp.pb(buckets[rel[val%int(pow(2,gd))]][i]);
        }
        buckets[rel[val%int(pow(2,gd))]].clear();
        }
        int nld=++ld[rel[val%int(pow(2,gd))]];
        (*bs)++;
        int nre=int(pow(2,nld-1))+val%(int(pow(2,nld-1)));
        For(i,0,int(pow(2,gd))){
            if(i%int(pow(2,nld))==nre){
                rel[i]=(*bs)-1;
            }
        }
        ld[*(bs)-1]=nld;
        if(!tmp.empty()){
        For(i,0,tmp.size()){
            buckets[rel[tmp[i]%int(pow(2,gd))]].pb(tmp[i]);
        }}
        return;}
void swap(int* a, int* b){
    int tmp=(*a);
    *a=*b;
    *b=tmp;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int gd,bc;double m;
    cin>>gd>>bc>>m;
    map<int,int> rel;
    int ini=pow(2,gd);
    vector<vector<int>> buckets(int(pow(2,20)));
    vector<int> ld(int(pow(2,20)),gd);
    int bs=ini;
    For(i,0,ini){
        rel[i]=i;
    }
    int overflow=0;
    while(1){
        int tmp;cin>>tmp;
        if(tmp==6) break;
        else if(tmp==2){
            int val;cin>>val;
            buckets[rel[val%int(pow(2,gd))]].pb(val);
            if(buckets[rel[val%int(pow(2,gd))]].size()==bc+1&&ld[rel[val%int(pow(2,gd))]]<gd){
                spl(buckets,ld,rel,gd,rel[val%int(pow(2,gd))],&bs);
                overflow=0;
                For(i,0,bs){
                    if(buckets[i].size()>bc) overflow++;
                }
            }
            else if(buckets[rel[val%int(pow(2,gd))]].size()==bc+1){
                overflow++;
                while(overflow*100/double(bs)>=m){
                    For(i,0,int(pow(2,gd))){
                        rel[i+int(pow(2,gd))]=rel[i];
                    }
                    gd++;
                    int tpp=bs;
                    For(i,0,tpp){
                        if(buckets[i].size()>bc) spl(buckets,ld,rel,gd,i,&bs);
                    }
                    overflow=0;
                    For(i,0,bs){
                        if(buckets[i].size()>bc) overflow++;
                    }
                }
            }
        }
        else if(tmp==3){
            int val;cin>>val;int flag=0;
            if(!buckets[rel[val%int(pow(2,gd))]].empty()){
            For(i,0,buckets[rel[val%int(pow(2,gd))]].size()){
                if(val==buckets[rel[val%int(pow(2,gd))]][i]){
                    flag=1;break;
                }
            }
            }
            //if(flag) cout<<"YES\n";
            //else cout<<"NO\n";
        }
        else if(tmp==4){
            int val;cin>>val;int flag=0;int id=-1;int siz=int(buckets[rel[val%int(pow(2,gd))]].size())-1;
            if(!buckets[rel[val%int(pow(2,gd))]].empty()){
            For(i,0,buckets[rel[val%int(pow(2,gd))]].size()){
                if(val==buckets[rel[val%int(pow(2,gd))]][i]){
                    id=i;flag=1;break;
                }
            }
            if(flag){
                swap(buckets[rel[val%int(pow(2,gd))]][siz],buckets[rel[val%int(pow(2,gd))]][id]);
                buckets[rel[val%int(pow(2,gd))]].pop_back();
            }
            }
        }
        else if(tmp==5){
            /*For(i,0,int(pow(2,gd))){
                cout<<i<<" "<<rel[i]<<"\n";
            }
            For(i,0,bs){
                For(j,0,buckets[i].size()){
                    cout<<buckets[i][j]<<" ";
                }cout<<"\n";
            }cout<<"\n";*/
            cout<<gd<<" "<<bs<<"\n";
        }
    }
    return 0;
}