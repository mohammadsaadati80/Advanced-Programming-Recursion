#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> read_input();
vector<int> multiplty_the_number_of_current_element_to_the_another_element(vector<int> numbers, int size, int current_element, int number_of_current_element);
vector<int> special_factorail(vector<int> numbers, int size, int current_element);
void print_vector(vector<int> numbers, int size);

vector<int> read_input()
{
	vector<int> numbers;
	int number;
	while (cin >> number)
		numbers.push_back(number);
	return numbers;
}

vector<int> multiplty_the_number_of_current_element_to_the_another_element(vector<int> numbers, int size, int current_element, int number_of_current_element)
{
	if (current_element <= size)
		numbers = multiplty_the_number_of_current_element_to_the_another_element(numbers, size, current_element + 1, number_of_current_element);
	if (current_element <= size)
		numbers[current_element] = number_of_current_element*numbers[current_element];
	return numbers;
}

vector<int> special_factorail(vector<int> numbers, int size, int current_element)
{
	int number_of_current_element = 1;
	if (current_element < size)
	{
		number_of_current_element = numbers[current_element];
		numbers[current_element] = 1;
		numbers = special_factorail(numbers, numbers.size(), current_element + 1);
	}
	numbers = multiplty_the_number_of_current_element_to_the_another_element(numbers, size - 1, current_element + 1, number_of_current_element);
	numbers = multiplty_the_number_of_current_element_to_the_another_element(numbers, current_element - 1, 0, number_of_current_element);
	return numbers;
}

void print_vector(vector<int> numbers, int size)
{
	if (numbers.size() == 0)
		return;
	int lastNumber = numbers.back();
	numbers.pop_back();
	print_vector(numbers, size);
	cout << lastNumber;
	numbers.push_back(lastNumber);
	if (numbers.size() == size)
		cout << endl;
	else
		cout << " ";
}

int main()
{
	vector<int> numbers = read_input();
	numbers = special_factorail(numbers, numbers.size(), 0);
	print_vector(numbers, numbers.size());
	return 0;
}