#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool check(char* input);

int main()
{
	int T;
	char bracket[50];
	int *caseNum;

	scanf("%d", &T);
	while (getchar() != '\n');
	caseNum = (int  *)malloc(T * sizeof(int));
	for (int i = 0; i < T; i++)
	{
		scanf("%s", bracket);
		caseNum[i] = check(bracket);
	}

	for (int i = 0; i < T; i++)
	{
		if (caseNum[i])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

bool check(char* input)
{
	int test = 0;

	int i = 0;
	while (input[i] != NULL)
	{
		if (input[i] == '(')
			test++;
		if (input[i] == ')')
			test--;
		if (test < 0)
			break;
		i++;
	}
	if (test == 0)
		return true;
	else
		return false;
}