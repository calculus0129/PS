/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : calculus
 * Date : 2024-08-23
 * Source : calculus0129.github.io/ps/PS_template/
 * Description : My cpp PS template.
 */

// For Additional Codes
// https://www.acmicpc.net/blog/view/106
// https://www.acmicpc.net/blog/view/114
#include <bits/stdc++.h>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)

typedef long long ll;
#define X first
#define Y second

// #define P 1000000009
// #define SUM(x,y) (x+y)%P

using namespace std;

// Using the Policy-Based Data Structures
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Define the ordered set using Policy-Based Data Structures
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Define the ordered set using Policy-Based Data Structures
template<typename T>
using om_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
int m_erase(om_set<T> &om, T val) {
    T idx = om.order_of_key(val);
    auto it = om.find_by_order(idx);
    if(*it == val) om.erase(it);
    return val;
}//*/

struct List {
    struct Node {
        bool v;
        Node *prev, *next;
        Node(bool v) : v(v), prev(NULL), next(NULL) {}
    };
    Node *head, *tail;

};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false); // Speed up IO
    int T; cin >> T;
    const auto convert = [](string s) -> vector<bool> {
        vector<bool> ret;
        for(auto c : s) {
            ret.push_back(c == '1');
        }
        return ret;
    };
    while(T--) {

    }
    
    return 0;
}
