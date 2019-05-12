#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;

bool pairCompare2(const std::pair<ll, ll >& firstElem, const std::pair<ll, ll >& secondElem) {
  return firstElem.first < secondElem.first;

}
int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        mp[a]++;
    }
    vector<pair<ll,ll> >vec;

    for(auto it=mp.begin();it!=mp.end();it++){
        vec.pb(mkp((*it).second,(*it).first));
    }

    sort(vec.begin(),vec.end());

    priority_queue<pair<ll,ll> >st;

    for(auto it=mp.begin();it!=mp.end();it++){
        st.push(mkp((*it).second,(*it).first));
    }
    bool bl=false;
    int count=0;
    vector<ll>v1,v2,v3;
    while(!st.empty()){
        auto it=st.top();
        ll a = (it).second;
        st.pop();
        if(st.empty())break;
        it=st.top();
        ll b = it.second;
        st.pop();
        if(st.empty())break;
        it=st.top();
        ll c = it.second;
        st.pop();

        ll temp= min(mp[a],min(mp[b],mp[c]));
        count++;

            v1.pb(max(a,max(b,c)));
            v2.pb((a+b+c)-max(a,max(b,c))-min(a,min(b,c)));
            v3.pb(min(a,min(b,c)));


        mp[a]--;
        mp[b]--;
        mp[c]--;
        if(mp[a]>0){
            st.push(mkp(mp[a],a));
        }
        if(mp[b]>0){
            st.push(mkp(mp[b],b));
        }
        if(mp[c]>0){
            st.push(mkp(mp[c],c));
        }

    }

    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<endl;
    }

}
