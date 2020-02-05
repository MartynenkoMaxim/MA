#include "Create&Count_Field.h"

using namespace std;


bool WaitSec (){
	bool t = true;
	int start,end;
	start=clock();
	cout << endl << start/1000 << " seconds have passed from the start.";
	bool a = true;
	while (a)
	{
		end=clock();
		if (((end-start)/CLK_TCK)==1)
		{
			return t;
		}
	}
	return false;
}

int main() {
	bool q = 0;
	cout << "Press '0' if needed random matrix or press '1' for read from file";
	cin >> q;
	Field field(q);
	bool a = true;
	while (a)
	{
		if (WaitSec())
		{
			field.PrintResult();
		}
	}
	return 0;
}
