#include <iostream>

int comp_int(const void * num1, const void * num2) 
{
    return *(const int*)num1 - *(const int *)num2;
}

int main()
{
    int (*comp)(const void*, const void *) = comp_int; // pointer to function

    int arr[] = {37,4,56,7,0,0,21,-1};

    const int size = sizeof(arr)/sizeof(int);

    qsort(arr, size, sizeof(int), comp); // using functor
    for (auto num : arr) std::cout << num << " ";
    std::cout << std::endl;

    /*
    -1 0 0 4 7 21 37 56 
    */
}