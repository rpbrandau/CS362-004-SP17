#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	// TODO: rewrite this function
	// The aim of this function is to return only the characters that will increment the program's state.
	// So it generates a number between 0 and 8 and returns the characters associated with that value.
	// Eventually it will have returned the characters needed to increment the program's state to 9,
	// where it will exit with an error (if inputString() returns "reset\0", which it does).
	char c;
	int a;
	a = rand() % 9; //to change states, c needs to be one of 9 characters: [({ ax})] (note the space)
	if (a == 0)
	{
		c = '[';
	}
	if (a == 1)
	{
		c = '(';
	}
	if (a == 2)
	{
		c = '{';
	}
	if (a == 3)
	{
		c = ' ';
	}
	if (a == 4)
	{
		c = 'a';
	}
	if (a == 5)
	{
		c = 'x';
	}
	if (a == 6)
	{
		c = '}';
	}
	if (a == 7)
	{
		c = ')';
	}
	if (a == 8)
	{
		c = ']';
	}

	return c;
}

char *inputString()
{
	// TODO: rewrite this function
	//didn't really have to rewrite anything here...
	//just needed to set the return value to "reset\0" :)
	return "reset\0";
}

void testme()
{
	int tcCount = 0;
	char *s;
	char c;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
			&& s[2] == 's' && s[3] == 'e'
			&& s[4] == 't' && s[5] == '\0'
			&& state == 9)
		{
			printf("error ");
			exit(200);
		}
	}
}


int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}
