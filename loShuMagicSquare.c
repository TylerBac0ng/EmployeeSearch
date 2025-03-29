#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Checks if arr (3x3) is a Lo Shu Magic Square
// Returns 1 if yes, 0 if no
int isLoShu(int arr[3][3]) {
	// 1) Check the sums (each row, column, diagonal must be 15)
	for (int r = 0; r < 3; r++) {
		if (arr[r][0] + arr[r][1] + arr[r][2] != 15) return 0;
	}
	for (int c = 0; c < 3; c++) {
		if (arr[0][c] + arr[1][c] + arr[2][c] != 15) return 0;
	}
	if ((arr[0][0] + arr[1][1] + arr[2][2] != 15) ||
		(arr[0][2] + arr[1][1] + arr[2][0] != 15)) return 0;

	// 2) Check digits are 1..9 exactly once
	int count[10] = {0};
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			int val = arr[r][c];
			if (val < 1 || val > 9) return 0; // out of range
			count[val]++;
			if (count[val] > 1) return 0;     // repeated digit
		}
	}
	// If all checks pass:
	return 1;
	}

	// Helper to print the square
	void printSquare(int arr[3][3]) {
	for (int r = 0; r < 3; r++) {
		printf("[ %d %d %d ]\n", arr[r][0], arr[r][1], arr[r][2]);
	}
	}

	int main() {
	
	// Check a known 3x3 to see if it is Lo Shu
	int valid[3][3] = {
		{4, 9, 2},
		{3, 5, 7},
		{8, 1, 6}
	};
	int invalid[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	printf("Testing a VALID square:\n");
	printSquare(valid);
	if (isLoShu(valid)) 
		printf("This is a Lo Shu Magic Square!\n\n");
	else
		printf("Not a Lo Shu Magic Square.\n\n");

	printf("Testing an INVALID square:\n");
	printSquare(invalid);
	if (isLoShu(invalid)) 
		printf("This is a Lo Shu Magic Square!\n\n");
	else
		printf("Not a Lo Shu Magic Square.\n\n");


	// Generate random squares until we find a Lo Shu
	srand((unsigned)time(NULL));
	int square[3][3], tries = 0;
	int found = 0;

	while (!found) {
		// Create array of digits 1..9
		int digits[9];
		for (int i = 0; i < 9; i++) {
			digits[i] = i + 1;
		}

		// Shuffle them
		for (int i = 0; i < 9; i++) {
			int r = rand() % 9;
			int temp = digits[i];
			digits[i] = digits[r];
			digits[r] = temp;
		}

		// Copy to square
		int index = 0;
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				square[r][c] = digits[index++];
			}
		}

		tries++;
		// Check if it's Lo Shu
		if (isLoShu(square)) {
			found = 1;
		}
	}

	printf("Found a Lo Shu Magic Square after %d tries:\n", tries);
	printSquare(square);

	return 0;
}
