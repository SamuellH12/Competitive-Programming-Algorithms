#include <bits/stdc++.h>
using namespace std;
int k = 2; // LATEX_IGNORED_LINE

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,  less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> os;
int okey = os.order_of_key(k);  // Number of items strictly smaller than K
auto kth = os.find_by_order(k); // pointer to K-th element in set (0-index)