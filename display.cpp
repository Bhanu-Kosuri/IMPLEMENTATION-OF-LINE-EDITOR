


#include "Line.h"

// Display Function Definition
Status Display(Lines_Slist *Head)
{
	// Returning FAILURE if Head is NULL
	if ( Head == nullptr ) //empty
		return FAILURE;

	// Declaring Line_Num
	int Line_Num = 0;

	// Running a Loop until Head Reaches NULL
	while ( Head )
	{
		// Printing Line_Num & Line's Data
		cout << MAGENTA << "\nLINE " << ++Line_Num << " : " << Head -> Line_str << NORMAL;

		// Moving Head
		Head = Head -> Link;
	}

	return SUCCESS;
}







