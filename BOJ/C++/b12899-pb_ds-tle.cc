#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define the ordered set using Policy-Based Data Structures
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int m_erase(ordered_multiset<int> &om, int val) {
    int idx = om.order_of_key(val);
    ordered_multiset<int>::iterator it = om.find_by_order(idx);
    if(*it == val) om.erase(it);
    return val;
}

int main() {
    ordered_multiset<int> om;

    int n; cin >> n;
    while(n--) {
        int a, x;
        cin >> a >> x;
        if(a == 1) om.insert(x);
        else cout << m_erase(om, *om.find_by_order(x-1)) << '\n';
    }
    return 0;
}
