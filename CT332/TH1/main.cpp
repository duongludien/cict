/*
 * main.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: dldien
 */

#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

#define MAX_X 9
#define MAX_Y 4
#define GOAL 6

struct State {
	int x, y;
	struct State *parent;
	int behavior;
};

typedef struct State * PState;

bool is_goal(PState state) {
	return state->x == GOAL || state->y == GOAL;
}

int min(int a, int b) {
	return a < b ? a : b;
}

PState x2y(PState state) {
	if(state->x > 0 && state->y < MAX_Y) {
		PState result = new State;
		result->y = state->y + min(MAX_Y - state->y, state->x);
		result->x = state->x - (result->y - state->y);
		return result;
	}
	return NULL;
}

PState y2x(PState state) {
	if(state->y > 0 && state->x < MAX_X) {
		PState result = new State;
		result->x = state->x + min(MAX_X - state->x, state->y);
		result->y = state->y - (result->x - state->x);
		return result;
	}
	return NULL;
}

PState full_fill_x(PState state) {
	if(state->x < MAX_X && state->y != MAX_Y) {
		PState result = new State;
		result->x = MAX_X;
		result->y = state->y;
		result->parent = state->parent;

		return result;
	}
	return NULL;
}

PState full_fill_y(PState state) {
	if(state->y < MAX_Y && state->x != MAX_X) {
		PState result = new State;
		result->y = MAX_Y;
		result->x = state->x;
		result->parent = state->parent;

		return result;
	}
	return NULL;
}

PState make_empty_x(PState state) {
	if(state->x > 0 && state->y != 0) {
		PState result = new State;
		result->x = 0;
		result->y = state->y;
		result->parent = state->parent;

		return result;
	}
	return NULL;
}

PState make_empty_y(PState state) {
	if(state->y > 0 && state->x != 0) {
		PState result = new State;
		result->y = 0;
		result->x = state->x;
		result->parent = state->parent;

		return result;
	}
	return NULL;
}

PState call_operator(PState state, int op_no) {
	switch(op_no) {
	case 1:
		return x2y(state);
	case 2:
		return y2x(state);
	case 3:
		return full_fill_x(state);
	case 4:
		return full_fill_y(state);
	case 5:
		return make_empty_x(state);
	case 6:
		return make_empty_y(state);
	}
	return NULL;
}

// Compare two states
bool equals(PState state1, PState state2) {
	return state1->x == state2->x && state1->y == state2->y;
}

// Check the existence of state in vector v
bool exist(PState state, std::vector<PState> v) {
	for(PState tmp : v) {
		if(equals(tmp, state))
			return true;
	}
	return false;
}

PState depth_first_search(PState start) {
	std::stack<PState> frontier;
	std::vector<PState> explored;

	// Initialize open list
	frontier.push(start);

	while(!frontier.empty()) {
		PState current = frontier.top();
		frontier.pop();

		if(is_goal(current))
			return current;

		// Push current to closed list
		explored.push_back(current);

		// Generate current's child
		for(int i=1; i<=6; i++) {
			PState child = call_operator(current, i);

			if(child != NULL) {
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

PState breath_first_search(PState start) {
	std::queue<PState> frontier;
	std::vector<PState> explored;

	// Initialize open list
	frontier.push(start);

	while(!frontier.empty()) {
		PState current = frontier.front();
		frontier.pop();

		if(is_goal(current))
			return current;

		// Push current to closed list
		explored.push_back(current);

		// Generate current's child
		for(int i=1; i<=6; i++) {
			PState child = call_operator(current, i);

			if(child != NULL) {
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
		printf("X to Y: (x = %d, y = %d)\n", state->x, state->y);
		break;
	case 2:
		printf("Y to X: (x = %d, y = %d)\n", state->x, state->y);
		break;
	case 3:
		printf("Full fill X: (x = %d, y = %d)\n", state->x, state->y);
		break;
	case 4:
		printf("Full fill Y: (x = %d, y = %d)\n", state->x, state->y);
		break;
	case 5:
		printf("Make empty X: (x = %d, y = %d)\n", state->x, state->y);
		break;
	case 6:
		printf("Make empty Y: (x = %d, y = %d)\n", state->x, state->y);
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

int main(int argc, char **argv) {
	PState start = new State;
	start->x = 0;
	start->y = 0;
	start->parent = NULL;

	//PState result = depth_first_search(start);

	PState result = breath_first_search(start);

	print_result(result);

	return 0;
}
