#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

#define MAX 3

struct State {
	int board[MAX][MAX];
	int empty_col, empty_row;
	struct State *parent;
	int behavior;
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
	start->parent = NULL;
	fclose(f);

	return start;
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

// bool is_goal(PState state) {
// 	int count = 1;
// 	for(int i=0; i<MAX; i++) 
// 		for(int j=0; j<MAX; j++) {
// 			if(i != MAX-1 && j != MAX-1 && state->board[i][j] != count)
// 				return false;
// 			count++;
// 		}
// 	return true;
// }

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

void print_state(PState state) {
	int i, j;
	for(i=0; i<MAX; i++) {
		for(j=0; j<MAX; j++)
			printf("%3d ", state->board[i][j]);
		printf("\n");
	}
	printf("\n");
}

PState breath_first_search(PState start, PState goal) {
	std::queue<PState> frontier;
	std::vector<PState> explored;

	// Initialize open list
	frontier.push(start);

	while(!frontier.empty()) {
		// printf("Lap\n");
		PState current = frontier.front();
		frontier.pop();

		if(is_goal(current, goal)) {
			// printf("Tim thay!\n");
			// print_state(current);
			return current;
		}

		// Push current to closed list
		explored.push_back(current);

		// Generate current's child
		for(int i=1; i<=4; i++) {
			// printf("Lap call_operator %d\n", i);
			PState child = call_operator(current, i);

			if(child != NULL) {
				// printf("Sinh ra dc\n");
				if(exist(child, explored))
					continue;
				else {
					child->behavior = i;
					child->parent = current;
					frontier.push(child);
				}
			}
		}
	}

	return NULL;
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
		printf("Move down:\n");
		print_state(state);
		break;
	}
}

void print_result(PState result) {
	std::stack<PState> my_stack;

	while(result->parent != NULL) {
		my_stack.push(result);
		result = result->parent;
	}

	while(!my_stack.empty()) {
		PState state = my_stack.top();
		my_stack.pop();
		print_operator(state);
	}
}

int main(int argc, char const *argv[])
{
	PState start, goal;
	char start_file[] = "start.txt";
	char goal_file[] = "goal.txt";

	start = read_file(start_file);
	goal = read_file(goal_file);

	printf("Start state:\n");
	print_state(start);
	
	PState result = breath_first_search(start, goal);

	print_result(result);

	return 0;
}