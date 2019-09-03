#include "ctring.h"

int main(int argc, char const *argv[])
{
	String string = create_string("Hello World!");
	printf("%s", convert_to_char_array(string));
	return EXIT_SUCCESS;
}