#include <assert.h>
#include <string.h>
#include <stdarg.h>

#include "betterscanf.h"

int betterscanf_file(FILE* source, const char* format, char* read_buffer, size_t max_read_size, ...)
{
    assert(read_buffer != NULL && max_read_size < strlen(read_buffer)); //bof

    int result;
    va_list args;

    fgets(read_buffer, max_read_size, source);

    va_start(args, max_read_size);
    result = vsscanf(read_buffer, format, args);
    va_end(args);

    return result;
}