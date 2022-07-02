// Oligo-case-string_Counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>

void oligoStringRandomizeABC(std::string &S, int N)
{
	S = "";
	for (size_t i = 0; i < N; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			S = S + "A";
			break;
		case 1:
			S = S + "B";
			break;
		case 2:
			S = S + "C";
			break;
		}
	}
}

class ABC_oligoStringScanner
{
public:
	ABC_oligoStringScanner()
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "ABC_oligoStringScanner SAYS: defaulted, you need re-initialize with arguments to get a result";
		std::cout << std::endl;
		std::cout << std::endl;
	}
	ABC_oligoStringScanner(std::string& S)
	{
		for (std::string::iterator it = S.begin(); it != S.end(); ++it)
		{
			switch (*it)
			{
			case 'A':
				++_A;
				break;
			case 'B':
				++_B;
				break;
			case 'C':
				++_C;
				break;
			}
		}
		ppResult_3[0] = _A;
		ppResult_3[1] = _B;
		ppResult_3[2] = _C;
	}
	~ABC_oligoStringScanner()
	{
		delete ppResult_3;
	}

	int* outPut()
	{
		if (ppResult_3[0] && ppResult_3[1] && ppResult_3[2] == 0)
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "ABC_oligoStringScanner.outPut() SAYS: zero count occured";
			std::cout << std::endl;
			std::cout << std::endl;
		}
		return ppResult_3;
	}
private:
	int _A{0};
	int _B{0};
	int _C{0};
	int* ppResult_3 = new int[3]{};
};

int main()
{
	// We initialize random creae a string and generate a secuens of 3 unique characters (A, B & C), usin a custom function
		srand(time(NULL));
		int length{30};
		std::string ABC_oligo_sting{""};
		oligoStringRandomizeABC(ABC_oligo_sting, length);

	// We create a an object that initially counts the number of A's, B's & C's in the string and stores the count.
		ABC_oligoStringScanner a(ABC_oligo_sting);
		int* scannerOutput = a.outPut();

	// We end by visualizeing the result
		std::cout << std::endl;
		std::cout << "ABC-oligo-string:\n\t";
		std::cout << ABC_oligo_sting;
		std::cout << std::endl;
		std::cout << "result:\n\t";
		std::cout << "A:";
		std::cout << scannerOutput[0];
		std::cout << " "; 
		std::cout << "B:";
		std::cout << scannerOutput[1];
		std::cout << " ";
		std::cout << "C:";
		std::cout << scannerOutput[2];
		std::cout << " ";
		std::cout << std::endl;

		std::cout << "A:";
		for (size_t i = 0; i < scannerOutput[0]; i++)
		{
			std::cout << "|";
		}
		std::cout << std::endl;

		std::cout << "B:";
		for (size_t i = 0; i < scannerOutput[1]; i++)
		{
			std::cout << "|";
		}
		std::cout << std::endl;

		std::cout << "C:";
		for (size_t i = 0; i < scannerOutput[2]; i++)
		{
			std::cout << "|";
		}
		std::cout << std::endl;

		return 0;
}
