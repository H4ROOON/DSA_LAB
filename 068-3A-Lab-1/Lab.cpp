#include <iostream>
using namespace std;

int main()
{
	int x = 8;
	int *ptrx = &x;

	cout << "Values before Modifying: " << x << " " << *ptrx << " " << &x << " " << ptrx << endl;
	*ptrx = 25;
	cout << "Values after modifying: " << x << " " << *ptrx << " " << &x << " " << ptrx << endl;

	return 0;
}