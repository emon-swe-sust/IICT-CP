#include<bits/stdc++.h>
using namespace std;

#define PLAYER1 1
#define PLAYER2 2

int calculateMex(unordered_set<int> Set)
{
	int Mex = 0;

	while (Set.find(Mex) != Set.end())
		Mex++;

	return (Mex);
}

int calculateGrundy(int n, int Grundy[])
{
	Grundy[0] = 0;
	Grundy[1] = 1;
	Grundy[2] = 2;
	Grundy[3] = 3;

	if (Grundy[n] != -1)
		return (Grundy[n]);

	unordered_set<int> Set;

	for (int i=1; i<=3; i++)
			Set.insert (calculateGrundy (n-i, Grundy));

	Grundy[n] = calculateMex (Set);

	return (Grundy[n]);
}

void declareWinner(int whoseTurn, int piles[],
					int Grundy[], int n)
{
	int xorValue = Grundy[piles[0]];

	for (int i=1; i<=n-1; i++)
		xorValue = xorValue ^ Grundy[piles[i]];

	if (xorValue != 0)
	{
		if (whoseTurn == PLAYER1)
			printf("Player 1 will win\n");
		else
			printf("Player 2 will win\n");
	}
	else
	{
		if (whoseTurn == PLAYER1)
			printf("Player 2 will win\n");
		else
			printf("Player 1 will win\n");
	}

	return;
}


int main()
{
	int piles[] = {3, 4, 5};
	int n = sizeof(piles)/sizeof(piles[0]);

	int maximum = *max_element(piles, piles + n);

	int Grundy[maximum + 1];
	memset(Grundy, -1, sizeof (Grundy));

	for (int i=0; i<=n-1; i++)
		calculateGrundy(piles[i], Grundy);

	declareWinner(PLAYER1, piles, Grundy, n);

	/* Test Case 2
	int piles[] = {3, 8, 2};
	int n = sizeof(piles)/sizeof(piles[0]);


	int maximum = *max_element (piles, piles + n);

	int Grundy [maximum + 1];
	memset(Grundy, -1, sizeof (Grundy));

	for (int i=0; i<=n-1; i++)
		calculateGrundy(piles[i], Grundy);

	declareWinner(PLAYER2, piles, Grundy, n); */

	return (0);
}

