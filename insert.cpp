

#include "Line.h"

// Insert Function Definition
Status Insert(Lines_Slist *&Head, const string &Line, int Line_Num)
{
	//Without (nothrow),if memory allocation fails,new throws a std::bad_alloc exception — it does not return nullptr, then the if (New == nullptr) check becomes useless (never reached).

	//without nothrow usage
	/*
	try
	{
   		New = new Lines_Slist;
	}
	catch (const bad_alloc &e)
	{
    	cerr << "ERROR: Failed to Create Line! (" << e.what() << ")\n";
    	return FAILURE;
	}	
	*/


	// Creating a New Node, using nothrow
	Lines_Slist *New = new (nothrow) Lines_Slist;

	// New Validation
	if ( New == nullptr )
	{
		cerr << RED << "ERROR: Failed to Create Line!\n" << NORMAL;
		return FAILURE;
	}

	// Updating Fields of New
	New -> Line_str = Line;
	New -> Link = nullptr;

	// Inserting New Line at First if Line_Num is 1
	if ( Line_Num == 1 )
	{
		New -> Link = Head;
		Head = New;
		return SUCCESS;
	}

	// Calling Get_Line Function to Get Previous Line Address
	Lines_Slist *Prev = Get_Line(Head,Line_Num - 1);

	// Returning NO_LINE if Previous Line is Not Found
	if ( Prev == nullptr )
	{
		delete New;
		return NO_LINE;
	}

	// Updating New's Link with Next Link & Prev's Link with New
	New -> Link = Prev -> Link;
	Prev -> Link = New;

	return SUCCESS;
}










