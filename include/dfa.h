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

#ifndef _DFA
#define _DFA

typedef int state_t;
typedef int symbol_t;

// Deterministic finite automaton
struct dfa
{
	size_t num_states;
	size_t num_symbols;
	state_t *table;
	state_t state;
};

// Returns pointer to a new deterministic finite automaton
struct dfa *dfa_new(size_t num_states, size_t num_symbols, state_t initial_state);

// Frees memory allocated by deterministic finite automaton
void dfa_free(struct dfa *d);

// Adds a transition to the automaton (state, input) -> new_state
void dfa_add(struct dfa *d, state_t state, symbol_t input, state_t new_state);

// Set the automaton to a new state based on current state and input
void dfa_read(struct dfa *d, symbol_t input);

// Returns the state of the automaton
state_t dfa_state(struct dfa *d);

#endif

