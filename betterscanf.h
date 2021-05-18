#ifndef BETTERSCANF_INCLUDED 
#define BETTERSCANF_INCLUDED

	#include <stdio.h> //FILE, stdin

	int betterscanf_file(FILE* source, const char* format, char* read_buffer, size_t max_read_size, ...);
	#define betterscanf(...) betterscanf_file(stdin, __VA_ARGS__)
#endif

