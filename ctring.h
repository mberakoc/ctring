#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	FALSE, TRUE
} Boolean;
typedef struct CharList CharList;
typedef CharList * _CharList;
typedef struct String String;
typedef String * _String;

struct CharList
{
	char char_unit;
	_CharList next_ptr;
	_CharList previous_ptr;
};

struct String
{
	_CharList char_list_header;
	_CharList char_list_tail;
	unsigned length;
};

const char ERROR_CHARACTER = (char)(0);

void append_char_unit(_CharList *char_list_header_ptr, _CharList *char_list_tail_ptr, char char_unit);
unsigned length(String string);
String create_string(char char_array[])
{
	_String string = (_String) malloc(sizeof(String));
	if (string != NULL)
	{
		int index = 0;
		string->char_list_header = NULL;
		string->char_list_tail = NULL;
		while (*(char_array + index) != '\0')
		{
			append_char_unit(&(string->char_list_header),
			 &(string->char_list_tail), *(char_array + index++));
		}
		string->length = length(*string);
		return *string;
	}
	else
	{
		create_string(char_array);
	}
	return *string;
}

void append_char_unit(_CharList *char_list_header_ptr, _CharList *char_list_tail_ptr, char char_unit)
{
	_CharList new_char_list_ptr = (_CharList) malloc(sizeof(CharList));
	if (new_char_list_ptr != NULL)
	{
		new_char_list_ptr->char_unit = char_unit;
		new_char_list_ptr->next_ptr = NULL;
		new_char_list_ptr->previous_ptr = NULL;
		if (*char_list_header_ptr == NULL)
		{
			*char_list_header_ptr = new_char_list_ptr;
			*char_list_tail_ptr = new_char_list_ptr;
			return;
		}
		_CharList current_char_list_ptr = *char_list_header_ptr;
		while (current_char_list_ptr->next_ptr != NULL)
		{
			current_char_list_ptr = current_char_list_ptr->next_ptr;
		}
		*char_list_tail_ptr = new_char_list_ptr;
		new_char_list_ptr->previous_ptr = current_char_list_ptr;
		current_char_list_ptr->next_ptr = new_char_list_ptr;
	}
	else
	{
		append_char_unit(char_list_header_ptr, char_list_tail_ptr, char_unit);
	}
}

unsigned length(String string)
{
	_CharList current_char_list_ptr = string.char_list_header;
	unsigned length = 0;
	while (current_char_list_ptr != NULL)
	{
		current_char_list_ptr = current_char_list_ptr->next_ptr;
		++length;
	}
	return length;
}

// For string matching: https://en.wikipedia.org/wiki/String-searching_algorithm
// Plan: Implement one of them. Current one: Naive string matching
char char_at(String string, unsigned index);
int index_of(String string, String key)
{
	int index = -1;
	Boolean is_key_found;
	_CharList current_char_list_ptr = string.char_list_header;
	for (unsigned i = 0; i <= string.length - key.length; ++i)
	{
		for (unsigned j = 0; j < key.length; ++j)
		{
			is_key_found = TRUE;
			if (char_at(string, i + j) != char_at(key, j))
			{
				is_key_found = FALSE;
				break;
			}
		}
		if (is_key_found)
		{
			index = i;
			break;
		}
	}
	return index;
}

char char_at(String string, unsigned index)
{
	if (index >= string.length)
	{
		fprintf(stderr, "%s\n", "Error: Index out of bounds.");
		return ERROR_CHARACTER;
	}
	if (index < (int)(string.length / 2 + 0.5))
	{
		_CharList current_char_list_ptr = string.char_list_header;
		for (unsigned i = 0; i < index; ++i)
		{
			current_char_list_ptr = current_char_list_ptr->next_ptr;
		}
		return current_char_list_ptr->char_unit;
	}
	else 
	{
		_CharList current_char_list_ptr = string.char_list_tail;
		for (unsigned i = 0; i < string.length - index - 1; ++i)
		{
			current_char_list_ptr = current_char_list_ptr->previous_ptr;
		}
		return current_char_list_ptr->char_unit;
	}
}

void reverse(String string)
{
	_CharList left_char_list_ptr = string.char_list_header;
	_CharList right_char_list_ptr = string.char_list_tail;
	for (int i = 0; i < string.length / 2; ++i)
	{
		char temp = left_char_list_ptr->char_unit;
		left_char_list_ptr->char_unit = right_char_list_ptr->char_unit;
		right_char_list_ptr->char_unit = temp;
		left_char_list_ptr = left_char_list_ptr->next_ptr;
		right_char_list_ptr = right_char_list_ptr->previous_ptr;
	}
}

void print_string(String string)
{
	_CharList char_list_header = string.char_list_header;
	while (char_list_header != NULL)
	{
		printf("%c", char_list_header->char_unit);
		char_list_header = char_list_header->next_ptr;
	}
	puts("");
}

char * convert_to_char_array(String string)
{
	char * char_array = (char *) malloc(string.length + 1);
	_CharList current_char_list_ptr = string.char_list_header;
	int index = 0;
	while (current_char_list_ptr != NULL)
	{
		*(char_array + index++) = current_char_list_ptr->char_unit;
		current_char_list_ptr = current_char_list_ptr->next_ptr;
	}
	*(char_array + index) = '\0';
	return char_array;
}

String copy(String string)
{
	return create_string(convert_to_char_array(string));
}

void insert(String core, String node, unsigned index)
{
	if (index > (core).length)
	{
		fprintf(stderr, "%s\n", "Index out of bounds.");
		return;
	}
	_CharList current_char_list_ptr = (core).char_list_header;
	for (unsigned i = 0; i < index - 1; ++i)
	{
		current_char_list_ptr = current_char_list_ptr->next_ptr;
	}
	_CharList end_char_list_ptr = current_char_list_ptr->next_ptr;
	_CharList node_char_list_ptr = node.char_list_header;
	while (node_char_list_ptr != NULL)
	{
		_CharList new_char_list_ptr = (_CharList) malloc(sizeof(CharList));
		if (new_char_list_ptr != NULL)
		{
			new_char_list_ptr->char_unit = node_char_list_ptr->char_unit;
			new_char_list_ptr->next_ptr = NULL;
			new_char_list_ptr->previous_ptr = current_char_list_ptr->next_ptr;
			current_char_list_ptr->next_ptr = new_char_list_ptr;
      current_char_list_ptr = new_char_list_ptr;
			node_char_list_ptr = node_char_list_ptr->next_ptr;
		}
	}
	current_char_list_ptr->next_ptr = end_char_list_ptr;
}