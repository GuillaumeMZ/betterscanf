# BetterScanf
 Do you want to read and parse an input from the console without having to clean the trailing \n? You should give this a try...

 I know, I'm certainly no Einstein. This is just a dumb macro, composed of two lines. But this can save you a little time, as you don't need to rewrite it, and some space in your code: without this macro, you would have to write two lines, whereas it is reduced to only one now :joy:

 This is of course license-free. Use it as you want (but avoid using C as possible :wink:).

 # **WARNING**

This code doesn't compile with MSVC if you don't change a compiler option. If you're using the command line interface, please add the /Zc:preprocessor flag when compiling. If you're using Visual Studio, go on Project->Properties->C/C++->Preprocessor->Use a standard compliant processor and set this to YES. 
But why? Because... MSVC doesn't use a standard compliant preprocessor by default: they have rewritten the C preprocessor, and it has a bug involving the \_\_VA_ARGS\_\_ macro. (which is used by this project). So, we need to tell MSCV to use a standard preprocessor (which doesn't mess things up). This is the purpose of this manipulation.

 ## How to use it?

 A little example of code is better than a long, boring paragraph:

 ```c
#include "betterscanf.h"
#include <assert.h>

int main()
{
	int return_value;
	char temp_buffer[50];

	char user_input[50];
	betterscanf("%s", temp_buffer, 50, user_input);
	printf("%s\n", user_input);
	//No need to remove the remaining \n in memory here !

	int x, y;
	printf("Enter a point's coordinates (x y)\n");
	betterscanf_ret("%d %d", temp_buffer, 50, return_value, &x, &y);

	assert(return_value == 2); //2 since we requested two values.

	printf("You created the point of coordinates (%d;%d)\n", x, y);
}

```

There are only four (macro)functions defined in BetterScanf. Two of them are used in this snippet; the other are basically doing the same work but they have another parameter: the file from which the function should retrieve a line. They are all explained in detail inside betterscanf.h, so feel free to get a glance at it.

###### Who knew that this small project would have taken me so much time? Fuck MSVC and Micro$oft.