#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define NUMBER_OF_ROW_IN_INPUT_NUMBERS_VECTOR 0
#define NUMBER_OF_COLUMN_IN_INPUT_NUMBERS_VECTOR 1
#define TABLE_VECTOR_START_NUMBER 2
#define POSSIBLE_MOVE 4
#define POSSIBLE_RIGHT_MOVE 1
#define POSSIBLE_LEFT_MOVE -1
#define POSSIBLE_UP_MOVE -1
#define POSSIBLE_DOWN_MOVE 1
#define DONT_MOVE 0
#define ZERO 0
#define LOOP_START 0
#define VISITED_ELEMENT 1
#define NOT_VISITED_ELEMENT 0
#define EMPTY_ELEMENT 0

vector<vector<int> > input_number(int &row, int &column);
vector<vector<int> > create_table_element_visited_vector(int row, int column);
int find_sum(vector<vector<int> >table_element_number, int row, int column, int current_row, int current_column, vector<vector<int> > table_element_visited, vector<int> &result_of_sums, int row_delta[POSSIBLE_MOVE], int col_delta[POSSIBLE_MOVE], int sum);
vector<int> calculate_the_sums_of_numbers_in_table(vector<vector<int> >table_element_number, int row, int column);
void find_max_result(vector<int> result_of_sums);

vector<vector<int> > input_number(int &row, int &column)
{
	int number, table_vector_start_number = TABLE_VECTOR_START_NUMBER;
	vector<int> input_number;
	while (cin >> number)
		input_number.push_back(number);
	row = input_number[NUMBER_OF_ROW_IN_INPUT_NUMBERS_VECTOR];
	column = input_number[NUMBER_OF_COLUMN_IN_INPUT_NUMBERS_VECTOR];
	vector<vector<int> > table_element_number(row);
	for (int current_row = LOOP_START; current_row < row; current_row++)
		for (int current_column = LOOP_START; current_column < column; current_column++, table_vector_start_number++)
			table_element_number[current_row].push_back(input_number[table_vector_start_number]);
	return table_element_number;
}

vector<vector<int> > create_table_element_visited_vector(int row, int column)
{
	vector<vector<int> > table_element_visited(row);
	for (int current_row = LOOP_START; current_row < row; current_row++)
		for (int current_column = LOOP_START; current_column < column; current_column++)
			table_element_visited[current_row].push_back(NOT_VISITED_ELEMENT);
	return table_element_visited;
}

int find_sum(vector<vector<int> >table_element_number, int row, int column, int current_row, int current_column, vector<vector<int> > table_element_visited, vector<int> &result_of_sums, int row_delta[POSSIBLE_MOVE], int col_delta[POSSIBLE_MOVE], int sum)
{
	sum += table_element_number[current_row][current_column];
	table_element_visited[current_row][current_column] = VISITED_ELEMENT;
	for (int possible_delta = LOOP_START; possible_delta < POSSIBLE_MOVE; possible_delta++) {
		int new_row = current_row + row_delta[possible_delta];
		int new_col = current_column + col_delta[possible_delta];
		if ((new_row >= ZERO) && (new_row < row) && (new_col >= ZERO) && (new_col < column) && (table_element_number[new_row][new_col] != EMPTY_ELEMENT) && (table_element_visited[new_row][new_col] == NOT_VISITED_ELEMENT))
			find_sum(table_element_number, row, column, new_row, new_col, table_element_visited, result_of_sums, row_delta, col_delta, sum);
	}
	result_of_sums.push_back(sum);
	return 1;
}

vector<int> calculate_the_sums_of_numbers_in_table(vector<vector<int> >table_element_number, int row, int column)
{
	int row_delta[POSSIBLE_MOVE] = { DONT_MOVE, DONT_MOVE, POSSIBLE_DOWN_MOVE , POSSIBLE_UP_MOVE };
	int col_delta[POSSIBLE_MOVE] = { POSSIBLE_RIGHT_MOVE, POSSIBLE_LEFT_MOVE, DONT_MOVE, DONT_MOVE };
	vector<int> result_of_sums;
	for (int current_row = LOOP_START; current_row < row; current_row++)
		for (int current_column = LOOP_START; current_column < column;current_column++) {
			if (table_element_number[current_row][current_column] != EMPTY_ELEMENT)
			{
				vector<vector<int> > table_element_visited = create_table_element_visited_vector(row, column);
				find_sum(table_element_number, row, column, current_row, current_column, table_element_visited, result_of_sums, row_delta, col_delta, 0);
			}
		}
	return result_of_sums;
}

void find_max_result(vector<int> result_of_sums)
{
	if (result_of_sums.size() == 0)
		cout << 0 << endl;
	else
	{
		int max = result_of_sums[0];
		for (int current = LOOP_START; current < result_of_sums.size(); current++)
			if (result_of_sums[current] >= max)
				max = result_of_sums[current];
		cout << max << endl;
	}
}

int main()
{
	int row, column;
	vector<vector<int> > table_element_number = input_number(row, column);
	vector<int> result_of_sums = calculate_the_sums_of_numbers_in_table(table_element_number, row, column);
	find_max_result(result_of_sums);
	return 0;
}