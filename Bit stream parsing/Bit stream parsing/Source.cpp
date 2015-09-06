#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

class halfofbyte
{
public:
	int firstbit, secondbit, thirdbit, fourthbit;
};

halfofbyte hextobin(char ch)
{
	halfofbyte h;
	int a, b, c, d;
	switch (ch)
	{
	case '0':
		a = 0; b = 0; c = 0; d = 0;
		break;
	case '1':
		a = 0; b = 0; c = 0; d = 1;
		break;
	case '2':
		a = 0; b = 0; c = 1; d = 0;
		break;
	case '3':
		a = 0; b = 0; c = 1; d = 1;
		break;
	case '4':
		a = 0; b = 1; c = 0; d = 0;
		break;
	case '5':
		a = 0; b = 1; c = 0; d = 1;
		break;
	case '6':
		a = 0; b = 1; c = 1; d = 0;
		break;
	case '7':
		a = 0; b = 1; c = 1; d = 1;
		break;
	case '8':
		a = 1; b = 0; c = 0; d = 0;
		break;
	case '9':
		a = 1; b = 0; c = 0; d = 1;
		break;
	case 'A':
		a = 1; b = 0; c = 1; d = 0;
		break;
	case 'B':
		a = 1; b = 0; c = 1; d = 1;
		break;
	case 'C':
		a = 1; b = 1; c = 0; d = 0;
		break;
	case 'D':
		a = 1; b = 1; c = 0; d = 1;
		break;
	case 'E':
		a = 1; b = 1; c = 1; d = 0;
		break;
	case 'F':
		a = 1; b = 1; c = 1; d = 1;
		break;
	}
	h.firstbit = a; h.secondbit = b; h.thirdbit = c; h.fourthbit = d;
	return (h);
}

int main()
{
	string s;
	halfofbyte bin;
	int *bitstream, i, n, k(1), a, b, c, d;
	getline(cin, s);
	while (s != "EOF")
	{
		n = s.length();
		bitstream = new int[n * 4];
		for (i = 0; i < n - 1; i += 2)
		{
			bin = hextobin(s[i]);
			bitstream[n * 4 - 8 * k] = bin.firstbit; bitstream[n * 4 + 1 - 8 * k] = bin.secondbit; bitstream[n * 4 + 2 - 8 * k] = bin.thirdbit; bitstream[n * 4 + 3 - 8 * k] = bin.fourthbit;
			bin = hextobin(s[i + 1]);
			bitstream[n * 4 + 4 - 8 * k] = bin.firstbit; bitstream[n * 4 + 5 - 8 * k] = bin.secondbit; bitstream[n * 4 + 6 - 8 * k] = bin.thirdbit; bitstream[n * 4 + 7 - 8 * k] = bin.fourthbit;
			k++;
		}
		cout << "Bit stream:\n";
		for (i = 0; i < n * 4; i++)
		{
			cout << bitstream[i];
		}
		cout << "\n";
		delete[] bitstream;
		getline(cin, s);
	}
}