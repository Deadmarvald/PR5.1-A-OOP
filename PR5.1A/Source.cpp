#include <iostream>
#include<Windows.h>
#include "Pay.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool res;
	Pay b;
	int N;

	do
	{
		try
		{
			res = true;

			Pay a(5, 9);

			cout << "Enter arguments:" << endl;
			cin >> b;
		}
		catch (invalid_argument ex)
		{
			res = false;
			cerr << ex.what() << endl;
		}
		catch (MyException& ex)
		{
			res = false;
			cerr << ex.What() << endl;
		}
		catch (Exception* ex)
		{
			res = false;
			cerr << ex->What() << endl;
		}

	} while (!res);

	cout << "Кiлькiсть вiдпрацьованих днiв = "; cin >> N;

	cout << "summa = " << b.Summa(N) << endl;

	system("pause");
	return 0;
}