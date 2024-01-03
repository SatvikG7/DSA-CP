#include <iostream>
using namespace std;

int main(){
    int n,a,b,c,cn(0);
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        if (a+b+c>1)
        {
            cn++;
        }
    }
    cout << cn;
    return 0;
}