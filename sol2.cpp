#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    using namespace std;
    int n;
    cout << "husnegiin hemjeeg oruulna uu : ";
    cin >> n;
    cout << "husnegtiin elementuuding oruulna uu :\n";
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    
    cout << "max element :" << *max_element(a.begin(), a.end()) << "\n";
}