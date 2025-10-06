#pragma GCC optimize ("O3" , "Ofast", "unroll-loops")
#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
#include<map>
#include<set>
#include<algorithm>
#include<stack>

using namespace std;
using ll = long long;
const int NMAX = 1e5;

struct Lazy {
    int add;
    Lazy () : add(0) {}
    Lazy(int _add) : add(_add) {}

    Lazy& operator += (const Lazy& other) {
        this->add += other.add;
        return *this;
    }
    Lazy& operator += (const int& other) {
        this->add += other;
        return *this;
    }
};

const int INF = 1e9;
struct Node {
    int min_val, first_ap , last_ap;
    ll sum;
    // empty node
    Node () : min_val(1e9) , first_ap(-1) , last_ap(-1) {}
    // leaf node
    Node (int _mv , int pos) : min_val(_mv) , first_ap(pos) , last_ap(pos) {
        // initialise sum to 0 bc. there is no "reverse" pair 
        sum = 0;
    }
    Node friend operator + (const Node& x , const Node& y) {
        // if a node has smaller min we only care about that minimum and the sum assoc. with it
        if (x.min_val < y.min_val) return x;
        else if (y.min_val < x.min_val) return y;
        else {
            Node ret;
            ret.min_val = x.min_val;
            assert(x.first_ap <= y.first_ap); // addition is not commutative
            // i.e. we add left node + right node            
            ret.first_ap = x.first_ap;
            ret.last_ap = y.last_ap;
            // sum = x.sum + y.sum + (first y - last x + 1) choose 2
            ret.sum = x.sum + y.sum + 1ll * (y.first_ap - x.last_ap - 1) * (y.first_ap - x.last_ap) / 2;
            return ret;
        }
    }
    Node& operator += (const Lazy& lazy_tag) {
        this->min_val += lazy_tag.add;
        return (*this);
    }
};

template <typename Node_Type , typename Lazy_type>
struct Aint {
    int n , offset;
    vector<Node_Type> aint;
    vector<Lazy_type> lazy;
    Aint (int _n) : n(_n) {
        offset = 1;
        while (offset < n) offset <<= 1;
        aint.resize(2 * offset , Node());
        lazy.resize(2 * offset , Lazy());
        for (int i = 1; i <= n; i++) {
            aint[i+offset-1] = Node(0,i);
        }
        for (int i = offset-1; i > 0; i--) {
            aint[i] = aint[2*i] + aint[2*i+1];
        }
    }

    void update (int l , int r , int val) {
        if (r < l) {
            return;
        }
        upd(1 , 1 , offset , l , r , val);
    }

    Node query () {
        return aint[1];
    }

private:
    void upd (int nod , int l , int r , int ul , int ur , int val) {
        push_lazy(nod);
        if (ul <= l && r <= ur) {
            lazy[nod] += val;
            push_lazy(nod);
            return;
        }
        else if (l > ur || r < ul) return;
        else {
            push_lazy(nod);
            int f1 = 2*nod , f2 = 2*nod + 1;
            int m = (l+r)/2;
            upd(f1 , l , m , ul , ur , val);
            upd(f2 , m+1, r, ul , ur , val);
            aint[nod] = aint[f1] + aint[f2];
        }
    }
    void push_lazy (int nod) {
        int f1 = 2*nod , f2 = 2*nod + 1;
        aint[nod] += lazy[nod];
        if (f1 < 2*offset) {
            lazy[f1] += lazy[nod];
            lazy[f2] += lazy[nod];
        }
        lazy[nod] = Lazy();
    }

};

// permutations are 1-indexed for easy use of SegTree
vector<int> read_perm (unsigned size) {
    vector<int> ret(size+1);
    for (int i = 1; i <= size; i++) {
        cin >> ret[i]; 
    }
    return ret;
} 
vector<int> inv_perm (vector<int>& perm) {
    unsigned size = perm.size()-1;
    vector<int> ret(size+1);
    for (int i = 1; i <= size; i++) {
        ret[perm[i]] = i;
    }
    return ret;
}
vector<int> comp (vector<int> p , vector<int> q) {
    unsigned size = p.size()-1;
    vector<int> ret(size+1);
    for (int i = 1; i <= size; i++) {
        ret[i] = p[q[i]];
    }
    return ret;
}

void solve () {
    
    int n , q; cin >> n >> q;
    vector<int> p = read_perm(n) , s = read_perm(n);
    // in t "secventele" cu aceleasi numere reprezinta intervale de forma [[1 .. x]] , [[x+1 .. y]] ...
    // vector<int> t = comp(p , inv_perm(s));
    // in retrospectiva o idee foarte nefericita :)))

    // decompose t in transpositions and update SegTree
    Aint<Node , Lazy> seg_tree(n);
    vector<bool> viz(n+1 , 0);
    for (int i = 1; i <= n; i++) {
        // cut cannot be between p[i] and s[i] (c. editorial)
        // ce ne intereseaza in aint sunt pozitiile care raman cu valoarea 0, adica mereu avem un "cut as per editorial" in ele
        seg_tree.update(min(p[i] , s[i]) , max(p[i] , s[i])-1 , 1);
    }

    // partea comuna care e adevarata mereu: more or less mereu putem schimba ceva cu el insusi (n) si cu ceva din spatele lui din p
    ll common_answer = 1ll * n * (n-1) / 2 + n;

    while (q--) {
        int type , x , y; cin >> type >> x >> y;
        
        // undo prev vals
        seg_tree.update(min(p[x] , s[x]) , max(p[x] , s[x])-1 , -1);
        seg_tree.update(min(p[y] , s[y]) , max(p[y] , s[y])-1 , -1);

        if (type == 1) swap(p[x] , p[y]);
        else swap(s[x] , s[y]);

        // correct updates
        seg_tree.update(min(p[x] , s[x]) , max(p[x] , s[x])-1 , 1);
        seg_tree.update(min(p[y] , s[y]) , max(p[y] , s[y])-1 , 1);
        
        Node qry = seg_tree.query();
        cout << common_answer + ((qry.min_val == 0) ? qry.sum + 1ll * qry.first_ap * (qry.first_ap-1) / 2 : 0) << '\n';
        // aici, daca exista macar un cut (minval == 0) afisam sumele pe subsecventele "taiate", SCC_size choose 2
        // qry.first_ap * (qry.first_ap-1) / 2 este pentru primul SCC pe care e greu sa l contorizam in aint
    }

}

int main () {

    #ifdef LOCAL 
    freopen("input.txt" , "r" , stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}