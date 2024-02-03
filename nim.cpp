#include <iostream>
#include <math.h>
using namespace std;

#define COMPUTER 1
#define HUMAN 2

struct move
{
	int pile_index;
	int stones_removed;
};

void showPiles (int piles[], int n)
{
	int i;
	cout <<"Current Game Status -> ";
	for (i=0; i<n; i++)
		cout << " " << piles[i];
	cout <<"\n";
	return;
}

bool gameOver(int piles[], int n)
{
	int i;
	for (i=0; i<n; i++)
		if (piles[i]!=0)
			return (false);

	return (true);
}

void declareWinner(int whoseTurn)
{
	if (whoseTurn == COMPUTER)
		cout <<"\nHUMAN won\n\n";
	else
		cout <<"\nCOMPUTER won\n\n";
	return;
}

int calculateNimSum(int piles[], int n)
{
	int i, nimsum = piles[0];
	for (i=1; i<n; i++)
		nimsum = nimsum ^ piles[i];
	return(nimsum);
}

void makeMove(int piles[], int n, struct move * moves)
{
	int i, nim_sum = calculateNimSum(piles, n);

	if (nim_sum != 0)
	{
		for (i=0; i<n; i++)
		{
			if ((piles[i] ^ nim_sum) < piles[i])
			{
				moves->pile_index = i;
				moves->stones_removed = piles[i]-(piles[i]^nim_sum);
				piles[i] = (piles[i] ^ nim_sum);
				break;
			}
		}
	}
	else
	{
		int non_zero_indices[n], cnt;

		for (i=0, cnt=0; i<n; i++){
			if (piles[i] > 0){
				non_zero_indices [cnt++] = i;
            }
        }

        int randPiles = rand() % cnt;
        int changeablePile = non_zero_indices[randPiles];

        int removeAbleStones = piles[changeablePile];
        int removeStones = 1 + rand() % removeAbleStones;

		moves->pile_index = changeablePile;
		moves->stones_removed = removeStones;
		piles[changeablePile] = removeAbleStones - removeStones;
	}
	return;
}

void playGame(int piles[], int n, int whoseTurn)
{
	cout <<"\nGAME STARTS\n\n";
	struct move moves;

	while (gameOver (piles, n) == false)
	{
		showPiles(piles, n);

		makeMove(piles, n, &moves);

		if (whoseTurn == COMPUTER)
		{
			cout <<"COMPUTER removes" << moves.stones_removed << "stones from pile at index " << moves.pile_index << endl;
			whoseTurn = HUMAN;
		}
		else
		{
			cout <<"HUMAN removes"<< moves.stones_removed << "stones from pile at index " << moves.pile_index << endl;
			whoseTurn = COMPUTER;
		}
	}

	showPiles(piles, n);
	declareWinner(whoseTurn);
	return;
}

void knowWinnerBeforePlaying(int piles[], int n,
							int whoseTurn)
{
	cout <<"Prediction before playing the game -> ";

	if (calculateNimSum(piles, n) !=0)
	{
		if (whoseTurn == COMPUTER)
			cout <<"COMPUTER will win\n";
		else
			cout <<"HUMAN will win\n";
	}
	else
	{
		if (whoseTurn == COMPUTER)
			cout <<"HUMAN will win\n";
		else
			cout <<"COMPUTER will win\n";
	}

	return;
}

int main()
{
	int piles[] = {1,3,5,7};
	int n = sizeof(piles)/sizeof(piles[0]);

	knowWinnerBeforePlaying(piles, n, COMPUTER);

	playGame(piles, n, COMPUTER);

	return(0);
}
