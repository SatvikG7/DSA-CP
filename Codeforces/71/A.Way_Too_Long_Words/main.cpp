#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string in[n];
    string out[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        in[i] = s;

        if (s.size()>10)
        {
            char f = s.front();
            char l = s.back();
            out[i] = f + to_string(s.size() - 2) + l;
        }
        else{
            out[i] = s;
        }
   }
   for (int i = 0; i < n; i++)
   {
       cout << out[i]<<endl;
   }
   
    return 0;
}