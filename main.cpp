#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define DEBUG(x) {cout<< #x <<" = " << x <<endl;}

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;

bool ss(pair<char,int> x , pair<char,int> y){
    return x.second > y.second;
}
int n,m;
int c[123][123];
vector<vector< pair<int,int> > > a;
vector<int> dist;

int get_d(int i, int j) { return ((i-1) * n) + j; }
int const oo = 2e9;

void input(){
    a =  vector<vector<pair<int,int> > >((m+1)*(n+1) + 4);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            {
                if (i-1 > 0)
                    {
                        a[get_d(i,j)].push_back(ii(get_d(i-1,j),c[i][j]));
                    }
                if (j-1 > 0)
                    {
                        a[get_d(i,j)].push_back(ii(get_d(i,j-1),c[i][j]));
                    }
                if (i+1 <= m)
                    {
                        a[get_d(i,j)].push_back(ii(get_d(i+1,j),c[i][j]));
                    }
                if (j+1 <= n)
                    {
                        a[get_d(i,j)].push_back(ii(get_d(i,j+1),c[i][j]));
                    }
            }
}

void disktra(int s){
    dist.assign((n+1)*(m+1),oo);
    dist[s] = 0;
    priority_queue<ii, vector<ii>,greater<ii> > pq;
    pq.push(ii(0,s));
    while (!pq.empty()){
        ii front =  pq.top(); pq.pop();
        int d = front.first;
        int u = front.second;
        if (d == dist[u])
        for(int j = 0; j < a[u].size(); ++j){
            ii v = a[u][j];
            if (dist[u] + v.second < dist[v.first] ){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first],v.first));
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (cin >> m >> n ){
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j){
                cin >> c[i][j];
            }
        input();
//        cout << "ok" << endl;
//        for(int i = 1 ; i < a.size();++i)
//            {
//                for(int j = 0; j<a[i].size(); ++j)
//                    cout<<a[i][j].first<<" ";
//                cout<<endl;
//            }
        disktra(1);
        cout<<dist[n*m] + c[m][n]<<endl;
        a.clear();
        dist.clear();
    }
    return 0;
}
