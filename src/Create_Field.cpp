#include "Create&Count_Field.h"


pair<int, int> Field::DimensionField(ifstream& stream){
	int count = 0;

		int temp;

		while (!stream.eof())
		{
			stream >> temp;
			count++;
		}
		stream.seekg(0, ios::beg);
		stream.clear();
		int count_space = 0;
		char symbol;

		while (!stream.eof())
		{
			stream.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
			}
		stream.seekg(0, ios::beg);
		stream.clear();
		row = count / (count_space + 1);//число строк
		columm = count_space + 1;//число столбцов

	return make_pair (row, columm) ;
}

void Field::ReadFromFile(){
	cout << "Enter name of file:" << endl;
	string nameFile;
	cin >> nameFile;
	ifstream stream(nameFile);
	pair <int, int> p;
	if (stream.is_open())
	{
		p = DimensionField (stream);
	}
	else
	{
		cout << "File not found";
		exit(1);
	}

	row = p. first;
	columm = p.second;

	field.resize(row);
	for(auto& v: field)
	{
		v.resize(columm);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < columm; j++)
		{
			stream >> field[i][j];
			field[i][j] = (int)field[i][j] - (int)'0';
		}
	}

	cout << "First field: "<< endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <columm; j++)
		cout << (char)(field[i][j] + '0') << " ";
		cout << endl;
	}

	stream.close();
}

void Field::CreatRandomField(){
	srand(time(NULL));
	row = 1 + rand() % 30;
	columm = 1 + rand() % 30;

	field.resize(row);
		for(auto& v: field)
		{
			v.resize(columm);
		}

	cout << "First field: "<< endl;
	for (int i =0; i < row; i++)
	{
		for (int j = 0; j < columm; j++)
		{
			field[i][j] =rand()%2;
			cout << (int)field[i][j] << " ";
		}
		cout << endl;
	}
}

Field::Field(bool q){
	if (q)
	{
		ReadFromFile();
	}
	if (!q)
	{
		row = 25;
		columm = 25;
		CreatRandomField();
	}
}
