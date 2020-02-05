#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

bool WaitSec ();

class Field {
public:

	Field(bool q);
	pair<int, int> DimensionField(ifstream& stream);
	void ReadFromFile ();
	void CreatRandomField ();
	int GetValue (int row, int columm) const;
	void SuccessorField ();
	void PrintResult ();
	int CheckNeighbors (int i, int j);

private:

	vector <vector<char>> field;
	int row = 0;
	int columm = 0;
};




