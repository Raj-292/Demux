#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char input[] = {'a', 'a', 'a', 'b', 'b', 'c', 'c', 'd', 's', 'a'};

    int n = sizeof(input) / sizeof(input[0]);


    vector<char> new_array;

    char temp = input[0];
    new_array.push_back(temp);

    for (int i = 1; i < n; i++) {
        int cnt = 1;
        if (input[i] == temp) {
            cnt++;
        } else {
            temp = input[i];
            if (cnt > 1) {
                new_array.push_back(cnt - 48);
            }

            char z[new_array.size()];

            for (int i = 0; i < new_array.size(); i++) {
                z[i] = new_array[i];
            }


        }

    }

}
