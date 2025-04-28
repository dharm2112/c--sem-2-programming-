/*
6.3 Merging Two Sorted Arrays Using Pointers
Merges two independently sorted arrays into one fully sorted array using dynamic memory allocation without STL containers.
Ensures flexible handling of variable-sized datasets with efficient memory management using new and delete.
Main Concept: Pointers, dynamic memory allocation, array merging without STL.
*/
#include<iostream>
using namespace std;

int main()
{
    int s1,s2;

    cout << "Enter first array size :" ;
    cin >> s1 ;
    cout << "enter second array size :" ;
    cin >> s2;

    int *ptr1 = new int[s1];
    int *ptr2 = new int[s2];
    
    cout << "Enter elements of first sorted array (in order):" << endl;
    for(int i=0;i<s1;i++)
    {
        cout << "enter elements " << i+1 << " :";
        cin >> ptr1[i];
    }

    cout << "Enter elements of second sorted array (in order):" << endl;
    for(int j=0;j<s2;j++)
    {
        cout << "enter elements " << j+1 << " :";
        cin >> ptr2[j];
    }

    int *merges = new int [s1 + s2];
    int i=0,j=0,k=0;

    //merges logic
    while(i<s1 && j <s2)
    {
        if(ptr1[i] <= ptr2[j])
            merges[k++] = ptr1[i++];
        else
            merges[k++] = ptr2[j++];
    }
    //remainibng copy elements
    while (i < s1) {
        merges[k++] = ptr1[i++];
    }
    
    while (j < s2) {
        merges[k++] = ptr2[j++];
    }

    cout << "Merged sorted array : " << endl;
    for(int i=0;i<s1+s2;i++)
    {
        cout << merges[i] << " " ;
    }

    cout << endl;
    delete[] ptr1;
    delete[] ptr2;
    delete[] merges;
    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}