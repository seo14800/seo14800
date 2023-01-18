#include <iostream>

#define MAX_COIN	10

using namespace std;

int cal_coin(int cost);

int coin_wallet[MAX_COIN] = { 0, };

int main()
{
	int N, K;

	cin >> N >> K;

	if (N <= 0 || N > MAX_COIN)
		return 0;

	for (int i = 0; i < N; i++)
	{
		cin >> coin_wallet[i];
	}

	cout << cal_coin(K) << endl;

	return 0;
}

int cal_coin(int cost)
{
	int total = 0;
	int coin = 0;

	if (cost <= 0)
		return 0;

	for (int i = MAX_COIN - 1; i >= 0; i--)
	{
		if (coin_wallet[i] == 0)
			continue;

		coin = cost / coin_wallet[i];
		if (coin == 0)
			continue;

		cost -= coin * coin_wallet[i];
		total += coin;
	}

	return total;
}