#include<stdio.h>
#include<stdlib.h>

/*
	snake = 0, if no snake is present.
	snake = 1, if snake is present.


	ladder = 0, if no ladder is present.
	ladder = 1, if ladder is present.
*/
struct node {

	int snake;
	int ladder;
	int position;

} board[31];

// Function to find minimum number of steps from a point to another point.
int minSteps(int position, int steps, int endPosition);

// Function to find the position after a snake bite or reaching a ladder.
int findPosition(int currentPosition);

// Function to give maximum possible position where snake is not present.
int checkSnake(int currentPosition);


int main() {

	int snakeCount, ladderCount, i, j, minCount, counter;
	
	snakeCount = 0;
	ladderCount = 0;
	counter = 0;

	// Position - 0
	board[0].snake = 0;
	board[0].ladder = 0;
	board[0].position = 0;

	// Position - 1
	board[1].snake = 0;
	board[1].ladder = 0;
	board[1].position = 0;

	// Position - 2
	board[2].snake = 0;
	board[2].ladder = 0;
	board[2].position = 0;

	// Position - 3 - Ladder(22).
	board[3].snake = 0;
	board[3].ladder = 1;
	board[3].position = 19;

	//Position - 4
	board[4].snake = 0;
	board[4].ladder = 0;
	board[4].position = 0;

	//Position - 5 - Ladder(8).
	board[5].snake = 0;
	board[5].ladder = 1;
	board[5].position = 3;

	//Position - 6
	board[6].snake = 0;
	board[6].ladder = 0;
	board[6].position = 0;

	//Position - 7
	board[7].snake = 0;
	board[7].ladder = 0;
	board[7].position = 0;

	//Position - 8
	board[8].snake = 0;
	board[8].ladder = 0;
	board[8].position = 0;

	//Position - 9
	board[9].snake = 0;
	board[9].ladder = 0;
	board[9].position = 0;

	//Position - 10
	board[10].snake = 0;
	board[10].ladder = 0;
	board[10].position = 0;

	//Position - 11
	board[11].snake = 0;
	board[11].ladder = 1;
	board[11].position = 15;

	//Position - 12
	board[12].snake = 0;
	board[12].ladder = 0;
	board[12].position = 0;

	//Position - 13
	board[13].snake = 0;
	board[13].ladder = 0;
	board[13].position = 0;

	//Position - 14
	board[14].snake = 0;
	board[14].ladder = 0;
	board[14].position = 0;

	//Position - 15
	board[15].snake = 0;
	board[15].ladder = 0;
	board[15].position = 0;

	//Position - 16
	board[16].snake = 0;
	board[16].ladder = 0;
	board[16].position = 0;

	//Position - 17 - Snake(4).
	board[17].snake = 1;
	board[17].ladder = 0;
	board[17].position = -13;

	//Position - 18
	board[18].snake = 0;
	board[18].ladder = 0;
	board[18].position = 0;

	//Position - 19 - Snake(7).
	board[19].snake = 1;
	board[19].ladder = 0;
	board[19].position = -12;

	//Position - 20 - Ladder(29).
	board[20].snake = 0;
	board[20].ladder = 1;
	board[20].position = 9;

	//Position - 21 - Snake(9).
	board[21].snake = 1;
	board[21].ladder = 0;
	board[21].position = -12;

	//Position - 22
	board[22].snake = 0;
	board[22].ladder = 0;
	board[22].position = 0;

	//Position - 23
	board[23].snake = 0;
	board[23].ladder = 0;
	board[23].position = 0;

	//Position - 24
	board[24].snake = 0;
	board[24].ladder = 0;
	board[24].position = 0;

	//Position - 25
	board[25].snake = 0;
	board[25].ladder = 0;
	board[25].position = 0;

	//Position - 26
	board[26].snake = 0;
	board[26].ladder = 0;
	board[26].position = 0;

	//Position - 27 - Snake(1).
	board[27].snake = 1;
	board[27].ladder = 0;
	board[27].position = -26;

	//Position - 28
	board[28].snake = 0;
	board[28].ladder = 0;
	board[28].position = 0;

	//Position - 29
	board[29].snake = 0;
	board[29].ladder = 0;
	board[29].position = 0;

	//Position - 30
	board[30].snake = 0;
	board[30].ladder = 0;
	board[30].position = 0;
	// Number of snakes and ladders in the game.
	for(i=1; i<30; i++) {

		if(board[i].snake == 1)
			snakeCount++;

		else if(board[i].ladder == 1)
			ladderCount++;
	}

	printf("\nNumber of snakes: %d", snakeCount);
	printf("\nNumber of ladders: %d", ladderCount);
	

	minCount = 100;

	// To find the minimum number of steps to finish the game.
	for(i=0; i<30; i++) {

		// Find the shortest path to a ladder.
		if(board[i].ladder == 1) {

			// Number of steps to reach the position of the ladder.
			counter = minSteps(0, 0, i);
			// Number of steps to reach the final position after reaching the ladder end point.
			counter = counter + minSteps(findPosition(i), 0, 30);

			if(counter < minCount)
				minCount = counter;
		}
	}



	printf("\nMinimum number of dice throws. - %d", minCount);

	minCount = 100;

	// To find the shortest path with atleast one snake bite.
	for(i=0; i<30; i++) {

		// Find the shortest path to snake bite.
		if(board[i].snake == 1) {

			// Number of steps to reach the position of the snake.
			counter = minSteps(0, 0, i);
			// Number of steps to reach the final position after the snake bite.
			counter = counter + minSteps(findPosition(i), 0, 30);

			if(counter < minCount)
				minCount = counter;
		}
	}

	printf("\nMinimum number of dice throws while encountering atleast one snake. - %d", minCount);

	printf("\n");

	return 0;
}


int minSteps(int position, int steps, int endPosition) {

	int j;
	int max = 0;
	int newPosition;

	if(position == endPosition)
		return steps;

	else if((position + 6) >= endPosition) {
		steps++;
		return steps;
	}

	else {
		steps++;
		
		// Check if ladder is present.
		for(j = position; j<=(position+6); j++)
		{
			if(board[j].position > 0) {

				if((board[j].position + j) > max && (board[j].position + j <= endPosition))
					max = j + board[j].position;
			}
		}

		// If no ladder is present, max will be zero.
		if(max == 0){
			newPosition = checkSnake(position + 6);
			minSteps(newPosition, steps, endPosition);
		}

		// If ladder is present.
		else
			minSteps(max, steps, endPosition);
	}
}

int findPosition(int currentPosition) {
	int position;
	position = currentPosition + board[currentPosition].position;
	return position;
}

int checkSnake(int currentPosition)
{
	if(board[currentPosition].snake == 1)
		return checkSnake(currentPosition - 1);

	else
		return currentPosition;
}