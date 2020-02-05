#include "Create&Count_Field.h"

////////////////////////////////////////////////////////////////
//	*i-1;j-1		*i-1;j	*i-1;j+1
//	i;j-1		C		*i; j+1
//	*i+1;j-1		*i+1;j	*i+1;j+1
////////////////////////////////////////////////////////////////


int Field::GetValue (int row, int columm)const{
	return (int)field[row][columm];
}

int Field::CheckNeighbors (int i, int j){
	int temp = 0;

	if (i !=0 && j != 0)					temp += field [i - 1][j - 1];
	if (i != 0)								temp += field [i - 1][j];
	if (i != 0 && j != columm - 1)			temp += field [i - 1][j + 1];
	if (j != columm - 1) 					temp += field [i][j + 1];
	if (i != row - 1 && j != columm - 1)	temp += field [i + 1][j + 1];
	if (i != row - 1)						temp += field [i + 1][j];
	if (i != row - 1 && j != 0)				temp += field [i + 1][j - 1];
	if (j != 0)								temp += field [i][j - 1];

	return temp;
}

void Field::SuccessorField (){
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < columm; j++)
		{
			sum = CheckNeighbors(i,j);
			if (sum < 2 || sum > 3) field[i][j] = 0;
			if (field[i][j] == 0 && sum == 3) field[i][j] = 1;
		}
	}
}

void Field::PrintResult (){
	SuccessorField();
	cout << endl;
	for (int i = 0; i < row; i++)
			{
				for (int j = 0; j <columm; j++)
				cout << (char)(field[i][j] + '0') << " ";
				cout << endl;
			}
}
