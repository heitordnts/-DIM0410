#include <bits/stdc++.h>

using namespace std;

int main()
{  
    int n;

    cin >> n;

    while (n--){
        int m;
        cin >> m;

        vector<int> coins;

        for (int i = 0; i < m; ++i){
            int c;
            cin >> c;
            coins.push_back(c);
        }

        int sum = 1;
        int num_coins = coins.size() > 1 ? 2 : 1;

        for (int i = 1; i < coins.size() - 1; ++i)
            if (sum + coins[i] < coins[i + 1]){
                sum += coins[i];
                num_coins++;
            }
		cout << num_coins << endl;
    }
    return 0;
}

