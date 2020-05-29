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
#include "dfa.h"

int main()
{
	/* Create a deterministic finite automaton
	   with 2 states and 2 symbols.
	   initial state is 0. */
	struct dfa *df = dfa_new(2, 2, 0);

	/* Add transitions. Must be non-negative integers.
	   Format: (state, input, new_state) */
	dfa_add(df, 0, 1, 1);
	dfa_add(df, 0, 0, 0);
	dfa_add(df, 1, 1, 0);
	dfa_add(df, 1, 0, 1);

	printf("Original state: %d\n", dfa_state(df));
	dfa_read(df, 1);
	printf("New state: %d\n", dfa_state(df));
	dfa_read(df, 0);
	printf("New state: %d\n", dfa_state(df));

	// Remove the automaton after we're done.
	dfa_free(df);

	return 0;
}

