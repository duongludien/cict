#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

#define MAX 3

struct State {
	int board[MAX][MAX];
	int empty_col, empty_row;
	struct State *parent;
	int behavior;
	int f, g, h;
};

typedef struct State* PState;

PState read_file(char *file_name) {
	FILE *f = fopen(file_name, "rt");
	PState start = new State;
	int i, j;

	for(i=0; i<MAX; i++)
		for(j=0; j<MAX; j++) {
			fscanf(f, "%d", &start->board[i][j]);
			if(start->board[i][j] == 0) {
				start->empty_row = i;
				start->empty_col = j;
			}
		}
	fclose(f);

	return start;
}

void print_state(PState state) {
	int i, j;
	for(i=0; i<MAX; i++) {
		for(j=0; j<MAX; j++)
			printf("%3d ", state->board[i][j]);
		printf("\n");
	}
	printf("\n");
}

int h1(PState state, PState goal) {
	int count = 0;
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			if(state->board[i][j] != goal->board[i][j])
				count++;
	return count;
}

int manhattan(int x1, int y1, int x2, int y2) {
	return abs(x1-x2) + abs(y1-y2);
}

bool find_element(int arr[][MAX], int x, int *row, int *col) {
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++) {
			if(arr[i][j] == x) {
				*row = i;
				*col = j;
				return true;
			}
		}
	return false;
}

int h2(PState state, PState goal) {
	int distance = 0;
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++) {
			if(state->board[i][j] != 0) {
				int row, col;
				find_element(goal->board, state->board[i][j], &row, &col);
				distance += manhattan(i, j, row, col);
			}
		}
	return distance;
}

bool equals(PState state1, PState state2) {
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++)
			if(state1->board[i][j] != state2->board[i][j])
				return false;
	}
	return true;
}

bool is_goal(PState state, PState goal) {
	return equals(state, goal);
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void copy_state(PState source, PState &destination) {
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) 
			destination->board[i][j] = source->board[i][j];
	}
	destination->empty_col = source->empty_col;
	destination->empty_row = source->empty_row;
}

PState move_up(PState state) {
	if(state->empty_row != 0) {
		PState result = new State;
		copy_state(state, result);
		swap(&result->board[result->empty_row-1][result->empty_col], &result->board[result->empty_row][result->empty_col]);
		result->empty_row = state->empty_row-1;
		result->empty_col = state->empty_col;
		return result;
	}
	return NULL;
}

PState move_down(PState state) {
	if(state->empty_row != MAX-1) {
		PState result = new State;
		copy_state(state, result);
		swap(&result->board[result->empty_row+1][result->empty_col], &result->board[result->empty_row][result->empty_col]);
		result->empty_row = state->empty_row+1;
		result->empty_col = state->empty_col;
		return result;
	}
	return NULL;	
}

PState move_left(PState state) {
	if(state->empty_col != 0) {
		PState result = new State;
		copy_state(state, result);
		swap(&result->board[result->empty_row][result->empty_col-1], &result->board[result->empty_row][result->empty_col]);
		result->empty_row = state->empty_row;
		result->empty_col = state->empty_col-1;
		return result;
	}
	return NULL;
}

PState move_right(PState state) {
	if(state->empty_row != MAX-1) {
		PState result = new State;
		copy_state(state, result);
		swap(&result->board[result->empty_row][result->empty_col+1], &result->board[result->empty_row][result->empty_col]);
		result->empty_row = state->empty_row;
		result->empty_col = state->empty_col+1;
		return result;
	}
	return NULL;
}

PState call_operator(PState state, int op_no) {
	switch(op_no) {
	case 1:
		return move_up(state);
	case 2:
		return move_down(state);
	case 3:
		return move_left(state);
	case 4:
		return move_right(state);
	}
	return NULL;
}

bool exist(PState state, std::vector<PState> v) {
	for(PState tmp : v) {
		if(equals(tmp, state))
			return true;
	}
	return false;
}

void erase_specific_element(std::vector<PState> &v, PState state) {
	for(std::vector<PState>::iterator it = v.begin(); it != v.end(); it++) {
		if(equals(*it, state))
			v.erase(it);
	}
}

bool comp(PState state1, PState state2) {
	return state1->f < state2->f;
}

PState a_star_search(PState start, PState goal) {
	std::vector<PState> frontier;
	std::vector<PState> explored;

	start->g = 0;
	start->h = h2(start, goal);
	start->f = start->h;
	start->parent = NULL;

	frontier.push_back(start);

	while(!frontier.empty()) {
		//printf("Lap\n");
		PState node = *(frontier.begin());
		frontier.erase(frontier.begin());

		if(is_goal(node, goal)) {
			//printf("Tim thay\n");
			// print_state(node);
			return node;
		}

		for(int i=1; i<=4; i++) {
			PState child = call_operator(node, i);
			if(child != NULL) {
				int tmp = node->g + 1;
				if(!exist(child, frontier) && !exist(child, explored)) {
					child->g = tmp;
					child->h = h2(child, goal);
					child->f = child->g + child->h;
					child->parent = node;
					child->behavior = i;
					frontier.push_back(child);
				}
				else if(exist(child, frontier)) {
					if(tmp < child->g) {
						child->g = tmp;
						child->h = h2(child, goal);
						child->f = child->g + child->h;
						//child->behavior = i;
						child->parent = node;
					}
				}
				else if(exist(child, explored)) {
					if(tmp < child->g) {
						child->h = h2(child, goal);
						child->g = tmp;
						child->f = tmp + child->h;
						child->parent = node;
						child->behavior = i;
						frontier.push_back(child);
						erase_specific_element(explored, child);
					}
				}
			}

			std::sort(frontier.begin(), frontier.end(), comp);
		}
	}
}

void print_operator(PState state) {
	switch(state->behavior) {
	case 1:
		printf("Move up:\n");
		print_state(state);
		break;
	case 2:
		printf("Move down:\n");
		print_state(state);
		break;
	case 3:
		printf("Move left:\n");
		print_state(state);
		break;
	case 4:
		printf("Move right:\n");
		print_state(state);
		break;
	}
}

void print_result(PState result) {
	std::stack<PState> my_stack;

	while(result->parent != NULL) {
		my_stack.push(result);
		// printf("Push\n");
		result = result->parent;
	}

	while(!my_stack.empty()) {
		PState state = my_stack.top();
		my_stack.pop();
		print_operator(state);
		//print_state(state);
	}
}

int main(int argc, char const *argv[])
{
	PState start, goal;
	char start_filename[] = "start1.txt";
	char goal_filename[] = "goal.txt";

	start = read_file(start_filename);
	goal = read_file(goal_filename);

	printf("Start state:\n");
	print_state(start);
	//print_state(goal);
	
	PState result = a_star_search(start, goal);

	print_result(result);

	return 0;
}