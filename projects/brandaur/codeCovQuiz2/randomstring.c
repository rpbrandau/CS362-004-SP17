//Riley Brandau
//CS 362 - Code Coverage Quiz 2
//Due 4/30/17


/*
Description: Implement a random tester for the function testme() in testme.c that is capable of printing the error message.  
You should implement inputChar() and inputString() to produce random values. 
Write up the development of your random tester and how it finds the error message as randomstring.c. 
Submit testme.c and randomstring.c under your onid directory in class github. (under your onid directory and not under dominion directory). 
The randomstring.c is a text file that outlines how you developed your solution and how it works!

*/


/*
Initial Thoughts
~~~~~~~~~~~~~~~~~~~
After running the program and seeing what it does (infinitely looping and printing to the screen),
and trying to figure out how to cause the program to print its error message,
it looks like these things must be satisfied:

1) the state variable must be == 9.
2) the inputString() must return "reset\0"

if both of those two criteria are satisfied, the program should print the error message and exit w/ 200.

inputChar()
~~~~~~~~~~~~~~~~~~~
inputChar() needs to return characters in a specific order to successfully increment the state variable.
It needs to return [({ ax})] 

In order to do this, I will try to use a loop (although, since there are no variables being passed in, and
no global variables to manipulate, keeping track might be an issue...).

As I was thinking about this, I decided against the loop and instead used random numbers to 
select one of the 9 characters needed for changing the state. While not the most efficient way,
it worked!


inputString()
~~~~~~~~~~~~~~~~~~~
I will simply set inputString()'s return value to "reset\0", which will cause the program to terminate
once the state is set to 9. At least, this is what I am assuming.


After Thoughts
~~~~~~~~~~~~~~~~~~~
My assumptions were correct! Although I didn't end up using a for-loop, a switch statement (crudely implemented
as multiple if statements...) worked like a charm. Also, "DUH! Of course a random tester should use the rand() function..."
*/