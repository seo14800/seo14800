#include <iostream>

unsigned int factorial(int num);

using namespace std;

int main()
{
	int input;

	cin >> input;

	cout << factorial(input) << endl;

	return 0;
}

unsigned int factorial(int num)
{
	if (num <= 1)
		return 1;

	return num * factorial(num - 1);
}