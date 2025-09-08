#include<iostream>
static inline int count_even(int v[], int n)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (!(v[i] & 1));
    return cnt;
}
static inline double avarage_odd(int v[], int n)
{
    int cnt = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] & 1) 
        {
            cnt++;
            sum += v[i];
        }
    }
    if(cnt == 0) return 0;
    return (double)sum / cnt;
}

static inline int decimal(int num, int **hariu)
{
    int cnt = 0;
    int tmp = num;
    while(tmp > 0)
    {
        cnt++;
        tmp /= 10;
    }
    *hariu = new int[cnt];
    for(int i = 0; i < cnt; i++)
    {
        (*hariu)[cnt - i - 1] = num % 10;
        num /= 10;
    }
    return cnt;
}

int main()
{
    using namespace std;
    int a[] = {1, 2, 3, 4, 5};
    cout << count_even(a, 5) << "\n";
    cout << avarage_odd(a, 5) << "\n";

    int *ans;
    int n = decimal(101, &ans);
    cout << "orongiin too : " << n << "\n";
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";

}
