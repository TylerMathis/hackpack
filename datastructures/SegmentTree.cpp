#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
using namespace std;

// range xor (invert)
// range sum
// segtree with lazy propagation
struct node {
    int l, r, m, val, lazy;
    node *left, *right;
    node() {}
    node(int ll, int rr) {
        l = ll;
        r = rr;
        m = (ll+rr)/2;
        val = 0;
        lazy = 0;
        left = nullptr;
        right = nullptr;
    }
    void prop() {
        check();
        if (lazy == 1) {
            left->lazy ^= 1;
            right->lazy ^= 1;
            lazy = 0;
        }
    }
    int get() {
        if (lazy == 1)
            return (r-l+1)-val;
        return val;
    }
    bool check() {
        if (left)
            return;
        left = new node(l, m);
        right = new node(m+1, r);
    }
    void update(int ll, int rr) {
        if (rr < l || ll > r)
            return;
        if (ll <= l && rr >= r) {
            lazy ^= 1;
            return;
        }
        prop();
        left->update(ll, rr);
        right->update(ll, rr);
        val = left->get() + right->get();
    }
    int query(int ll, int rr) {
        if (rr < l || ll > r)
            return 0;
        if (ll <= l && rr >= r)
            return get();

        prop();
        val = left->get() + right->get();
        return left->query(ll, rr) + right->query(ll, rr);
    }
};