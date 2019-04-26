#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;




int main(){
    //IOS
    //freopen("output.txt","w",stdout);

    int n,m;
    int cs=0;
    while(cin>>n>>m){
        cs++;
        bool bl = false;
        int left[100005],right[100005];
        for(int i=0;i<=n+1;i++){
            left[i]=i-1;
            right[i]=i+1;
        }
        for(int j=0;j<m;j++){
            int p;
            cin>>p;
            if(p==4){
                bl = !bl;
            }
            else{
                int x,y;
                cin>>x>>y;

                if((p==1 && bl==false) || (p==2 && bl==true)){
                    int l = left[x];
                    int r = right[x];

                    left[r]=l;
                    right[l]=r;

                    l = left[y];

                    right[l]=x;
                    left[y]=x;
                    left[x]=l;
                    right[x]=y;
                }
                if((p==2 && bl==false) || (p==1 && bl==true)){
                    int l = left[x];
                    int r = right[x];

                    left[r]=l;
                    right[l]=r;

                    r = right[y];

                    right[x]=r;
                    right[y]=x;
                    left[x]=y;
                    left[r]=x;
                }
                if(p==3 ){

                    if(left[x]==y ){
                        int l = left[x];
                        int r = right[x];
                        int l2= left[y];
                        int r2 = right[y];
                        left[y] = x;
                        right[y] = r;
                        left[r]=y;
                        right[x] =y;
                        left[x]=l2;
                        right[l2]=x;
                        continue;
                    }
                    if(right[x]==y){
                        int l = left[x];
                        int r = right[x];
                        int l2= left[y];
                        int r2 = right[y];
                        right[l]=y;
                        left[y]=l;
                        right[y]=x;
                        left[x]=y;
                        right[x]=r2;
                        left[r2]=x;
                        continue;
                    }
                    int l = left[x];
                    int r = right[x];
                    int l2= left[y];
                    int r2 = right[y];
                    left[y]=l;
                    right[l]=y;
                    right[y]=r;
                    left[r]=y;
                    left[x] = l2;
                    right[l2]=x;
                    right[x] = r2;
                    left[r2]=x;
                }
                /*if(bl==false){
                    //cout<<"ok";
                    int i=0;
                    int j=1;
                    while(right[i]<=n+1){
                        if(right[i]==n+1)break;
                        cout<<right[i]<<" ";

                        i = right[i];
                        j++;
                        if(j>n)break;

                    }
                }
                else{
                    int i=n+1;
                    //cout<<"okk";
                    int j=1;
                    while(left[i]>=0){
                        if(left[i]==0)break;
                        cout<<left[i]<<" ";

                        i = left[i];
                        j++;
                        if(j>n)break;

                    }
                }
                cout<<endl<<endl;*/
            }

        }
        vector<int>ans;
        if(bl==false){
            //cout<<"ok";
            int i=0;
            int j=1;
            while(right[i]<=n+1){
                if(right[i]==n+1)break;
                ans.pb(right[i]);

                i = right[i];
                j++;
                if(j>n)break;

            }
        }
        else{
            int i=n+1;
            //cout<<"okk";
            int j=1;
            while(left[i]>=0){
                if(left[i]==0)break;
                ans.pb(left[i]);

                i = left[i];
                j++;
                if(j>n)break;

            }
        }
        ll sum =0LL;
        //cout<<endl;
        for(int i=0;i<ans.size();i++){
            //cout<<ans[i]<<" ";
            if(!(i&1))sum+=ans[i];
        }
        //cout<<endl;
        cout<<"Case "<<cs<<": "<<sum;
        cout<<"\n";
    }

}
