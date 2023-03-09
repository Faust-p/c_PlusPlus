#include <stdio.h>
#include <iostream>
using namespace std;

//������� 1
bool is_prime(unsigned long long value)
{
	for (unsigned long long i = sqrtl(value); i > 1; i--)
	{
		if (value % i == 0)
		{
			return false;
		}
	}

    return true;
}

//������� 2
long double read_int_value()
{
	string input;
	long double result = 0;
	bool Comma = false;
	int decimalPlaces = 0;
	cout << "������� 2. ������� ������: ";
	cin >> input;


	for (char symbol : input)
	{
		if (!Comma && (symbol == ',' || symbol == '.'))  
			Comma = true;
		else if (symbol >= '0' && symbol <= '9')  
		{
			result = result * 10 + symbol - '0';

			if (Comma)
			{
				decimalPlaces++;
			}
		}
	}

	while (decimalPlaces > 0)
	{
		result /= 10;
		decimalPlaces--;
	}

	return result;
}


//������� 3
unsigned long long currentSimple = 1;

bool current_is_prime()
{
	for (unsigned long long i = currentSimple / 2; i > 1; i--)
	{
		if (currentSimple % i == 0)
		{
			return false;
		}
	}

	return true;
}

unsigned long long next_prime()
{
	do
	{
		currentSimple++;
	} while (!current_is_prime());

	return currentSimple;
}

//������� 4
void reset_prime()
{
	currentSimple = 1;
}

//������� 5
unsigned long long factorial(int N)
{
	if (N == 1)
	{
		return 1;
	}

	return N * factorial(N - 1);
}

//������� 6
unsigned long long fib(int N)
{
	if (N <= 1)
	{
		return N;
	}

	return fib(N - 1) + fib(N - 2);
}

//������� 7
void print_binary(unsigned long long value)
{
	if (value == 0)
	{
		cout << 0;
	}
	else if (value == 1)
	{
		cout << 1;
	}
	else
	{
		unsigned long long quotient = value / 2;
		unsigned long long remainder = value % 2;
		print_binary(quotient);
		cout << remainder << endl;
	}
}

//������� 8
unsigned long long hex_to_dec(string hex, unsigned long long pos)
{
	if (pos == 0)
	{
		return 0;
	}
	else
	{
		unsigned long long val;
		char c = hex[pos - 1];

		if (c >= '0' && c <= '9')
		{
			val = c - '0';
		}
		else if (c >= 'a' && c <= 'f')
		{
			val = c - 'a' + 10;
		}
		else if (c >= 'A' && c <= 'F')
		{
			val = c - 'A' + 10;
		}
		else
		{
			return hex_to_dec(hex, pos - 1);
		}

		return hex_to_dec(hex, pos - 1) + val * (1 << (4 * (hex.length() - pos)));
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
	unsigned long long temp;
	//������� 1
	cout << "������� 1. ������� �����: ";
	cin >> temp;
    string result = is_prime(temp) ? "�������\n" : "�� �������\n";
    cout << result;

	//������� 2
	long double temp1 = read_int_value();
	printf("%f", temp1);

	//������� 3
	cout << "\n������� 3" << endl;
	cout << next_prime() << endl;
	cout << next_prime() << endl;
	cout << next_prime() << endl;

	//������� 4
	reset_prime();

	//������� 5
	int N;
	cout << "������� 5. ������� �����: \n";
	cin >> N;

	cout << factorial(N) << endl;

	//������� 6
	cout << "������� 6. ������� �����: \n";
	cin >> N;

	cout << fib(N) << endl;

	//������� 7
	cout << "������� 7. ������� �����: \n";
	cin >> N;

	print_binary(N);

	//������� 8
	string n1;
	cout << "������� 8. ������� ������ �����: \n";
	cin >> n1;
	unsigned long long n1_dec = hex_to_dec(n1, n1.length());

	string n2;
	cout << "������� ������ �����: ";
	cin >> n2;
	unsigned long long n2_dec = hex_to_dec(n2, n2.length());

	printf("%llu + %llu = %llu", n1_dec, n2_dec, n1_dec + n2_dec);
}