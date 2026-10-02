// CSES Problem "Range Update Queries"

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 200005

ll arr[mx];
struct info{
    ll prop, sum;
};
info tree[MAXN * 3];

void makeTree(int node, int b, int e){
    if (b == e){
        tree[node].sum = arr[e];
        return;
    }

    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b + e) / 2;

    makeTree(left, b, mid);
    makeTree(right, mid + 1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, int b, int e, int i, int j, ll x){
    if (e < i || b > j)
        return;
    if (b >= i && e <= j){
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }

    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b + e) / 2;

    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry){
    if (e < i || b > j)return 0;
    if (b >= i && e <= j)return tree[node].sum + carry * (e - b + 1);

    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (b + e) / 2;

    ll p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);
    return p1 + p2;
}

int main(){
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    makeTree(1, 1, n);

    while (q--){
        int type;
        cin >> type;

        if (type == 1){
            int a, b;
            ll u;
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u);
        }
        else{
            int k;
            cin >> k;
            cout << query(1,1,n,k,k,0) << '\n';
        }
    }

}


