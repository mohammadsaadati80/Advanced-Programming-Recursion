#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string read_input();
string create_new_string(string old_string, int start, int end);
string insert_at_first(string new_string, char character);
string reverse(string new_string);
int encrypt_string(string input_string);
void pirnt_string(string new_string);

string read_input()
{
	string input_string;
	char input;
	while (cin >> input)
		input_string.push_back(input);
	return input_string;
}

string create_new_string(string old_string, int start, int end)
{
	string new_string;
	for (int i = start; i < end; i++)
		new_string.push_back(old_string[i]);
	return new_string;
}

string insert_at_first(string new_string, char character)
{
	if (new_string.size() == 0)
	{
		new_string.push_back(character);
		return new_string;
	}
	char last_character = new_string.back();
	new_string.pop_back();
	new_string = insert_at_first(new_string, character);
	new_string.push_back(last_character);
	return new_string;
}

string reverse(string new_string)
{
	if (new_string.size() == 0)
		return new_string;
	char last_character = new_string.back();
	new_string.pop_back();
	new_string = reverse(new_string);
	new_string = insert_at_first(new_string, last_character);
	return new_string;
}

int encrypt_string(string new_string)
{
	if (new_string.size() == 1)
	{
		pirnt_string(new_string);
		return 1;
	}
	string second_half_string = create_new_string(new_string, new_string.size() / 2, new_string.size());
	string first_half_string = create_new_string(new_string, 0, new_string.size() / 2);
	string second_half_string_after_reverse = reverse(second_half_string);
	string first_half_string_after_reverse = reverse(first_half_string);
	encrypt_string(second_half_string_after_reverse);
	encrypt_string(first_half_string_after_reverse);
	return 1;
}

void pirnt_string(string new_string)
{
	cout << new_string[0];
}

int main()
{
	string input_string = read_input();
	encrypt_string(input_string);
	cout << endl;
	return 0;
}