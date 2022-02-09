#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define NUMBER_OF_PASSWORD_LENGHT_IN_INPUT_ORDER 0
#define NUMBER_OF_VALID_CHARACTER_IN_INPUT_ORDER 1
#define NUMBER_OF_PASSWORD_HASH_IN_INPUT_ORDER 2
#define FOUND 1
#define NOT_FOUND 0
#define LOOP_START 0
#define CUSTOM_CHARACTER 'a'


vector<char> input_order(int &password_lenght, unsigned long long int &passsword_hash);
unsigned long long int generate_password_hash(string password);
int compare_password_hash(unsigned long long int passsword_hash, string current_password, int &result);
int find_password(int password_lenght, vector<char> valid_character, unsigned long long int passsword_hash, string current_password, int current_element, int &result);
void print_result(string current_password, int &result);

vector<char> input_order(int &password_lenght, unsigned long long int &passsword_hash)
{
	vector<char> valid_character;
	vector<string> input_order;
	string line_input;
	while (cin >> line_input)
		input_order.push_back(line_input);
	for (int i = LOOP_START; i < input_order[NUMBER_OF_VALID_CHARACTER_IN_INPUT_ORDER].size(); i++)
		valid_character.push_back(input_order[NUMBER_OF_VALID_CHARACTER_IN_INPUT_ORDER][i]);
	password_lenght = (input_order[NUMBER_OF_PASSWORD_LENGHT_IN_INPUT_ORDER][0] - 48);
	for (int i = LOOP_START; i < input_order[NUMBER_OF_PASSWORD_HASH_IN_INPUT_ORDER].size(); i++)
	{
		passsword_hash += (input_order[NUMBER_OF_PASSWORD_HASH_IN_INPUT_ORDER][i] - 48);
		if (i < input_order[NUMBER_OF_PASSWORD_HASH_IN_INPUT_ORDER].size() - 1)
			passsword_hash *= 10;
	}
	return valid_character;
}

unsigned long long int generate_password_hash(string password)
{
	return hash <string>()(password);
}

int compare_password_hash(unsigned long long int passsword_hash, string current_password, int &result)
{
	unsigned long long int current_passsword_hash = generate_password_hash(current_password);
	if (current_passsword_hash == passsword_hash)
	{
		result = FOUND;
		print_result(current_password, result);
		return FOUND;
	}
	else
		return NOT_FOUND;
}

int find_password(int password_lenght, vector<char> valid_character, unsigned long long int passsword_hash, string current_password, int current_element, int &result)
{
	current_password.push_back(CUSTOM_CHARACTER);
	for (int i = LOOP_START; i < valid_character.size(); i++)
	{
		current_password[current_element] = valid_character[i];
		if (current_element != password_lenght - 1)
			result = find_password(password_lenght, valid_character, passsword_hash, current_password, current_element + 1, result);
		if (result == NOT_FOUND)
			result = compare_password_hash(passsword_hash, current_password, result);
		if (result == FOUND)
			break;
	}
	return result;
}

void print_result(string current_password, int &result)
{
	if (result == FOUND)
		cout << current_password << endl;
	else
		cout << "NOT_FOUND" << endl;
}

int main()
{
	int password_lenght, result = NOT_FOUND;
	unsigned long long int passsword_hash = 0;
	vector<char> valid_character = input_order(password_lenght, passsword_hash);
	string current_password;
	result = find_password(password_lenght, valid_character, passsword_hash, current_password, 0, result);
	if (result == NOT_FOUND)
		print_result(current_password, result);
	return 0;
}