#include <iostream>
#include <vector>
using namespace std;
//class NumMatrix {
//public:
//	NumMatrix(vector<vector<int>>& matrix) {
//		int rows = matrix.size();
//		int cols = matrix[0].size();
//		matrixPrev.resize(rows, vector<int>(cols, 0));
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < cols; j++)
//			{
//				if (i == 0 && j == 0)
//					matrixPrev[i][j] = matrix[i][j];
//				else if (i == 0)
//					matrixPrev[i][j] = matrixPrev[i][j - 1] + matrix[i][j];
//				else if (j == 0)
//					matrixPrev[i][j] = matrixPrev[i - 1][j] + matrix[i][j];
//				else
//					matrixPrev[i][j] = matrixPrev[i][j - 1] + matrixPrev[i - 1][j] + matrix[i][j] - matrixPrev[i - 1][j - 1];
//			}
//		}
//	}
//	int sumRegion(int row1, int col1, int row2, int col2) {
//		if (row1 == 0 && col1 == 0)
//			return matrixPrev[row2][col2];
//		else if (row1 == 0)
//			return matrixPrev[row2][col2] - matrixPrev[row2][col1 - 1];
//		else if (col1 == 0)
//			return matrixPrev[row2][col2] - matrixPrev[row1 - 1][col2];
//		else
//			return matrixPrev[row2][col2] - matrixPrev[row2][col1 - 1] - matrixPrev[row1 - 1][col2]
//			+ matrixPrev[row1 - 1][col1 - 1];
//	}
//	void Print()
//	{
//		for (auto& line : matrixPrev)
//		{
//			for (auto& elem : line)
//				printf("%3d ", elem);
//			cout << endl;
//		}
//	}
//private:
//	vector<vector<int>> matrixPrev;
//};
class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		matrixPrev.resize(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrixPrev[i + 1][j + 1] = matrixPrev[i][j + 1] + matrixPrev[i + 1][j] - matrixPrev[i][j] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return matrixPrev[row2 + 1][col2 + 1] - matrixPrev[row2 + 1][col1] - matrixPrev[row1][col2 + 1] + matrixPrev[row1][col1];
	}
private:
	vector<vector<int>> matrixPrev;
};
int main()
{
	vector<vector<int>> v = {
		{ 3, 0, 1, 4, 2 },
		{ 5, 6, 3, 2, 1 },
		{ 1, 2, 0, 1, 5 },
		{ 4, 1, 0, 1, 7 },
		{ 1, 0, 3, 0, 5 } 
	};
	NumMatrix obj(v);
	//obj.Print();
	cout << obj.sumRegion(2, 1, 4, 3) << endl;
	cout << obj.sumRegion(1, 1, 2, 2) << endl;
	cout << obj.sumRegion(1, 2, 2, 4) << endl;
	return 0;
}
