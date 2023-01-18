#include <iostream>

using namespace std;

unsigned int fibonacci(int num);

int main()
{
	int input;

	cin >> input;

	cout << fibonacci(input) << endl;

	return 0;
}

unsigned int fibonacci(int num)
{
	if (num < 0)
		return 0;

	if (num <= 1)
		return num;

	return fibonacci(num - 1) + fibonacci(num - 2);
}