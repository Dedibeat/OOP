#include<iostream>
#define MAX(a, b) (a >= b ? a : b)
#define MAX3(a, b, c) (MAX(MAX(a, b), c))
int main()
{
    using namespace std;
    cout << MAX(1, 2) << " " << MAX3(1, 2, 3) << "\n";
}