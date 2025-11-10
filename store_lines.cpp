


#include "Line.h"


// Store_Lines Function Definition
void Store_Lines(Lines_Slist *&Head,const string &Line)
{
	// Creating a New Node
	//new - throws exception if memory fails, no need to check new == nullptr
	//new (nothrow) - returns nullptr (then you must check manually)

	//Lines_Slist *New = new Lines_Slist; //valid 
	Lines_Slist *New = new (nothrow) Lines_Slist;

	// New Validation
	if ( New == nullptr)
	{
		cerr << RED << "ERROR: Failed to Store Line!\n" << NORMAL;
		return;
	}

	// Updating Fields of New
	New -> Line_str = Line;
	New -> Link = nullptr;

	// Linking New with Head if Head is NULL
	if ( Head == nullptr) //empty
	{
		Head = New;
		return;
	}

	// Not empty, Taking a Pointer to Traverse List
	Lines_Slist *temp = Head;

	// Traversing the List
	while ( temp -> Link != nullptr)
	{
		temp = temp -> Link;
	}

	// Storing New in Traverse's Link
	temp -> Link = New;
	return;
}












