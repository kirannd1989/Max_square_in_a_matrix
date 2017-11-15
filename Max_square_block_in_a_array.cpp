#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Find_Max_Square_in_Matrix(vector<vector<int>>&Matrix, int m, int n) {
	vector<vector<int>> DP(m, vector<int>(n, 0));
	int count = 0;
	/*
	initialise the first element of the matrix with the number same as input
	if its 0 the size would be zero, if its 1 the size of a matrix would be 1
	*/
	for (size_t i = 0; i < m; i++)
		DP[i][0] = Matrix[i][0];
	for (size_t i = 0; i < n; i++) 
		DP[0][i] = Matrix[0][i];
	

	for (size_t i = 1; i < m; i++) {
		for (size_t j = 1; j < n; j++) {
			if (Matrix[i][j] == 1) {
			DP[i][j] = min(min(DP[i - 1][j], DP[i - 1][j - 1]), DP[i][j - 1]) + 1;
			if (count < DP[i][j])
				count = DP[i][j];
		}
			else
				DP[i][j] = 0;
	}
	}
	return count;
}

int main() {
	freopen("input.txt", "r", stdin);
	int size_of_matrix_row, size_of_matrix_col;
	cin >> size_of_matrix_col >> size_of_matrix_row;
	vector<vector<int>> Matrix(size_of_matrix_col, vector<int>(size_of_matrix_row, 0));


	cout << Matrix.size() << endl;
	for (size_t i = 0U; i < size_of_matrix_col; i++) {
		for (size_t j = 0U; j < size_of_matrix_row; j++)
			cin >> Matrix[i][j];
	}
	cout << Find_Max_Square_in_Matrix(Matrix, size_of_matrix_col, size_of_matrix_row) << endl;
}