#ifndef INSERTIONSORT_HPP_INCLUDED
#define INSERTIONSORT_HPP_INCLUDED

#include <vector>
#include <limits>

#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
void insertionSort(std::vector<T>&, std::size_t);

template <typename T>
void insertionSort(std::vector<T>& A) { insertionSort(A, A.size()); }

template <typename T>
void insertionSort(std::vector<T>& a, std::size_t n) {
    // int n = a.size();

    // Base Case
    if (n <= 1)
        return;
    else {
        // Recursively call function
        insertionSort(a, n - 1);
        //std::c << out "recursion";

        // Use the last element of the array (key) and compare it to the array
        auto key = a[n - 1];
        int i = n - 2;

        // Interate through the array and move the elements forward one index
            // until we reach the index key needs to be inserted at
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }

        // Insert key
        a[i + 1] = key;
    }
}
// T(n) = c1*n + c2*(n-1) + c3*(n-1) + c4*SUM_j=1_to_n-1(tj) + c5*SUM_j=1_to_n-1(tj-1) + c6*SUM_j=1_to_n-1(tj-1) + c7*(n-1)

// Best case
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c5*0 + c6*0 + c7*(n-1)
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c7*(n-1)
//      = c1*n + c2*n - c2 + c3*n - c3 + c4*n - c4 + c7*n - c7
//      = c1*n + c2*n + c3*n + c4*n + c7*n - c2 - c3 - c4 - c7
//      = (c1+c2+c3+c4+c7)*n + (-c2 - c3 - c4 - c7)
//      = An + B

// Worst case
//      = c1*n + c2*(n-1) + c3*(n-1) + c4*(n-1) + c5*0 + c6*0 + c7*(n-1)

#endif // INSERTIONSORT_HPP_INCLUDED