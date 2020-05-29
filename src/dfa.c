// Copyright 2020 Alan Tseng
// 
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
// 

#include <stdio.h>
#include <stdlib.h>

#include "dfa.h"

const state_t DFA_DEFAULT_STATE = 0;

// Returns pointer to a new deterministic finite automaton
struct dfa *dfa_new(size_t num_states, size_t num_symbols, state_t initial_state)
{
	// Allocate memory for automaton itself
	struct dfa *ptr = malloc(sizeof(struct dfa));
	if (ptr == NULL) {
		fprintf(stderr, "Couldn't allocate memory for automaton.");
		return NULL;
	}

	// Allocate memory for transitions
	state_t *table;
	int n = num_states * num_symbols;
	table = malloc(sizeof(state_t) * n);
	if (table == NULL) {
		fprintf(stderr, "Couldn't allocate memory for transition table.");
		free(ptr);
		return NULL;
	}
	// Initialize the transition table
	for (int i = 0; i < n; ++i) {
		table[i] = DFA_DEFAULT_STATE;
	}

	// Set the parameters
	ptr->num_states = num_states;
	ptr->num_symbols = num_symbols;
	ptr->table = table;
	ptr->state = initial_state;

	return ptr;
}

// Frees memory allocated by deterministic finite automaton
void dfa_free(struct dfa *d)
{
	if (d == NULL) return;
	if (d->table != NULL) {
		free(d->table);
	}
	free(d);
}

// Adds a transition to the automaton (state, input) -> new_state
void dfa_add(struct dfa *d, state_t state, symbol_t input, state_t new_state)
{
	int i = (state * d->num_symbols) + input;
	(d->table)[i] = new_state;
}

// Set the automaton to a new state based on current state and input
void dfa_read(struct dfa *d, symbol_t input)
{
	int i = (d->state * d->num_symbols) + input;
	d->state = (d->table)[i];
}

// Returns the state of the automaton
state_t dfa_state(struct dfa *d)
{
	return d->state;
}

