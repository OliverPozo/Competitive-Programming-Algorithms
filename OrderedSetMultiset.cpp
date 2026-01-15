#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


//ELIMINA DEFINE INT LONG LONG SI LO TIENES, PUEDE CAUSAR PROBLEMAS !!!!!
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//creo que el multiset falla con las eliminaciones 

// order_of_key te da la pos, find_by_order te da el elem dado una posicion
// order_of_key(k): Gives the count of elements smaller than k. — O(log n)
// find_by_order(pos): Returns the iterator for the kth element (use pos = 0 for the first element). — O(log n)
// sz(ord)
// ord.clear()
// ord.erase(val)
// ord.erase(ord.find_by_order(pos)) -> Si quieres eliminar una determinada posicion

// ordered_multiset<int> ss;

// // Inserting elements into 'ss'
// ss.insert(5);
// ss.insert(2);
// ss.insert(7);
// ss.insert(2); // Allows duplicates
// ss.insert(1);



// // Displaying elements 
// cout << "Elements in the ordered_multiset: ";
// for (auto it : ss) { // 1 2 2 5 7
//     cout << it << " ";
// }
// cout << endl;

// // Counting elements less than 5 using order_of_key
// cout << "Elements less than 5: " << ss.order_of_key(5) << endl; // 3

// // Deleting an element, e.g., deleting value 2
// auto it = ss.find_by_order(ss.order_of_key(2)); // Find iterator to the element 2
// if (it != ss.end()) {
//     ss.erase(it); // Erase the found element O(log n)
//     cout << "Element 2 removed from the ordered_multiset." << endl;
// } else {
//     cout << "Element not found in the ordered_multiset." << endl;
// }