#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly less(greater) than k
//find_by_order(k) : K-th element in a set (counting from zero)
//s.erase(s.upper_bound(val)) : Erase from multiset
