


#include "Line.h"

// Edit Function Definition
Status Edit(Lines_Slist *&Head,int Line_Num)
{
	// Returning NO_LINE if Head is NULL
	if ( Head == nullptr ) //empty
	{
		cerr << RED << "ERROR: Lines List is Empty!\n" << NORMAL;
		return NO_LINE;
	}

	// Calling Get_Line Function to Get Edit Line's Address
	Lines_Slist *Edit_Line = Get_Line(Head,Line_Num);

	// Returning NO_LINE if Edit_Line is Not Found
	if ( Edit_Line == nullptr )
		return NO_LINE;

	// Declaring New_Line
	string New_Line;

	// Displaying Current Content at Line_Num & Reading New Content
	cout << "INFO: Current Content at " << Line_Num << " Line is: " << Edit_Line -> Line_str;
	cout << "\nEnter New Content: ";
	getline(cin, New_Line);

	// Replacing Old Content with New Content & Returning SUCCESS
	Edit_Line -> Line_str = New_Line;

	return SUCCESS;
}






