#include <bits/stdc++.h>
#include "student.h"


using namespace std;


// simple selection sort by name
void sort_by_name(Student **arr, int n)
{
    for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
    if (arr[j]->before(*arr[min_idx])) min_idx = j;
    }
    if (min_idx != i) swap(arr[i], arr[min_idx]);
    }
}


// simple selection sort by course
void sort_by_course(Student **arr, int n)
{
    for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
    if (arr[j]->lessThan(*arr[min_idx])) min_idx = j;
    }
    if (min_idx != i) swap(arr[i], arr[min_idx]);
    }
}


int main()
{
    cout << "Oyuutnuudiin toog oruulna uu: ";
    int n; if (!(cin >> n) || n <= 0) return 0;


    Student **arr = new Student*[n];
    for (int i = 0; i < n; ++i) {
        cout << "\n" << i+1 << " - r oyuutnii medeellig oruulna uu:\n";
        arr[i] = new Student();
        arr[i]->read();
    }


    cout << "\n--- Erembelnej baisnii daraa ner deer ---\n";
    sort_by_name(arr, n);
    for (int i = 0; i < n; ++i) {
        arr[i]->print(); cout << "\n";
        }


        cout << "\n--- Erembelnej baisnii daraa kurs deer ---\n";
        sort_by_course(arr, n);
        for (int i = 0; i < n; ++i) {
        arr[i]->print(); cout << "\n";
    }


    Student::print_count();


    for (int i = 0; i < n; ++i) delete arr[i];
    delete[] arr;
    return 0;
}