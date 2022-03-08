#ifndef MERGESORT_HPP_INCLUDED
#define MERGESORT_HPP_INCLUDED

#include <limits>

#include <algorithm>
#include <iterator>
#include <iostream>

/* Forward declarations of auxiliary functions. */
template <typename T>
void insertSort(std::vector<T>& A);

template <typename T>
void merge(std::vector<T>&, std::size_t, std::size_t, std::size_t);

template <typename T>
void mergeSort(std::vector<T>&, std::size_t, std::size_t);

/* Primary sorting function. */

template <typename T>
void mergeSort(std::vector<T>& A) { mergeSort(A, 0, A.size()); }

/* Definitions of auxiliary functions. */

// Create insertSort function (insertionSort.hpp)
template <typename T>
void insertSort(std::vector<T>& a) {
    for (auto j = 1; j < a.size(); ++j) {
        auto key = a[j];
        auto i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
    //std::cout << "reached";
}

template <typename T>
void mergeSort(std::vector<T>& A, std::size_t p, std::size_t r) {
    // Include a conditional to check if the size of the array is less than 5,
        // if it is then perform an insertion sort, otherwise perform a merge sort
    if (r - p < 5)
        insertSort(A);
    else {
        std::size_t q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q, r);
        merge(A, p, q, r);
    }
}


template <typename T>
void merge(std::vector<T>& A, std::size_t p, std::size_t q, std::size_t r) {
    auto n1 = q - p;
    auto n2 = r - q;
    auto L = new T[n1 + 1], R = new T[n2 + 1];
    for (auto i = 0; i < n1; ++i)
        L[i] = A[p + i];
    for (auto j = 0; j < n2; ++j)
        R[j] = A[q + j];
    L[n1] = std::numeric_limits<T>::max();
    R[n2] = std::numeric_limits<T>::max();
    auto i = 0;
    auto j = 0;
    for (auto k = p; k < r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        }
        else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

#endif // MERGESORT_HPP_INCLUDED