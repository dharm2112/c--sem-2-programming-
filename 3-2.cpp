/*
3.2 Recursive vs Iterative Sum of Array
Calculates the sum of an array using both recursive and iterative approaches for comparison.
Accepts user-defined array size and elements, with a focus on performance and memory usage.
Main Concept: Recursion, iteration, dynamic arrays, and function comparison.

*/
#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
int simplesum (vector <int>&v1 ,int size);
int recursionsum (vector <int>&v1 , int size);
int main() 
{
    int size,number;
    cout << "enter size of array :";
    cin >> size;

    vector<int> v1;
    for(int i=0;i<size ; i++)
    {
        cout << "\nEnter elements " << i+1 << " :";
        cin >> number;
        v1.emplace_back(number);
    }

    // Measure time for recursive sum
    auto start_recursive = chrono::high_resolution_clock::now();
    int recursive_sum = recursionsum(v1, size);
    auto end_recursive = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_recursive = end_recursive - start_recursive;

    // Measure time for iterative sum
    auto start_iterative = chrono::high_resolution_clock::now();
    int iterative_sum = simplesum(v1, size);
    auto end_iterative = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_iterative = end_iterative - start_iterative;


    cout << "\nRecursive sum result: " << recursionsum(v1 ,size) << endl;
    cout << "Iterative sum result: " << simplesum(v1,size) << endl;

      // Output execution times
      cout << "\nTime taken for recursive sum: " << duration_recursive.count() << " seconds." << endl;
      cout << "Time taken for iterative sum: " << duration_iterative.count() << " seconds." << endl;
return 0 ;
}

int recursionsum (vector <int>&v1 ,int size)
{
    if (size == 0)
        return 0;

    return v1[size - 1] + recursionsum(v1, size - 1);
}
int simplesum (vector <int>&v1,int size)
{
    int sum=0;
    for(int i=0;i<size ;i++)
    {
    sum += v1[i];
    }
    return sum;
}
