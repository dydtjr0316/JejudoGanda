#include "stdafx.h"
#include "CQuadTree.h"
// Driver program 
int main()
{
    CQuadTree center(tPoint(0, 0), tPoint(8, 8));
    tNode a(tPoint(1, 1), 1);
    tNode b(tPoint(2, 5), 2);
    tNode c(tPoint(7, 6), 3);
    center.insert(&a);
    center.insert(&b);
    center.insert(&c);
    cout << "Node a: " <<
        center.search(tPoint(1, 1))->data << "\n";
    cout << "Node b: " <<
        center.search(tPoint(2, 5))->data << "\n";
    cout << "Node c: " <<
        center.search(tPoint(7, 6))->data << "\n";
    cout << "Non-existing node: "
        << center.search(tPoint(5, 5));
    return 0;
}