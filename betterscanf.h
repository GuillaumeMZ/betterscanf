#ifndef BETTERSCANF_INCLUDED 
#define BETTERSCANF_INCLUDED

	#include <stdio.h> /* fgets */
	#include <string.h> /* sscanf */

	/********************************************	
					    WARNING !
			  If you use MSVC, please read 
			the following paragraph CAREFULLY
	*********************************************/
	
	/*
		This code doesn't compile with MSVC if you don't change a compiler option. If you're using the command line interface,
		please add the /Zc:preprocessor flag when compiling. If you're using Visual Studio, go on Project->Properties->C/C++->Preprocessor->Use a standard compliant processor
		and set this to YES. But why? Because... MSVC doesn't use a standard compliant preprocessor by default: they have rewritten the C preprocessor, and it has a bug involving
		the __VA_ARGS__ macro. (which is used by this project). So, we need to tell MSCV to use a standard preprocessor (which doesn't mess things up). This is the purpose of this manipulation.
	*/

	/*
		Reads a whole line from stdin (and discard the remaining \n in the buffer which can cause problems with multiple stdin reads) then parses the string according to the format, like scanf does.
		file [in/out] The file used by the function to read a line from.
		format [in] The format used to parse the string. It is the same as the one you would use with *scanf functions.
		read_buffer [out] The temporary buffer used to store the line read from stdin.
		max_len [in] the maximum number of chars which can be read from stdin.
		ret_val [out] How many values the function parsed successfully. (only if using betterscanf_ret)
		... [out] variables used to store the parsed values.
	
		Yeah, C is an awful language. I don't really like macros, but since we can't forward parameter packs inside normal functions, we must use one.
	*/
	
	
	#define betterscanf_file(file, format, read_buffer, max_len, ...)fgets(read_buffer, max_len, file);\
																	sscanf(read_buffer, format, __VA_ARGS__)
	
	#define betterscanf_file_ret(file, format, read_buffer, max_len, ret_val, ...) fgets(read_buffer, max_len, file);\
																				   ret_val = sscanf(read_buffer, format, __VA_ARGS__)

	#define betterscanf(...) betterscanf_file(stdin, __VA_ARGS__)

	#define betterscanf_ret(...) betterscanf_file_ret(stdin, __VA_ARGS__)
#endif

