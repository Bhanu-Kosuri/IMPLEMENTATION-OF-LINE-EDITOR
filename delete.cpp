

#include "Line.h"

// Delete Function Definition
Status Delete(Lines_Slist *&Head,int Line_Num)
{
	// Returning NO_LINE if Head is NULL
	if ( Head == nullptr)
	{
		cerr << RED << "ERROR: Lines List is Empty!\n" << NORMAL;
		return NO_LINE;
	}

	// Deleting 1st Line & Updating Head with Next line if Line_Num is 1
	if ( Line_Num == 1 )
	{
		Lines_Slist *temp = Head;
		Head = temp -> Link;
		
		free(temp);
		return SUCCESS;
	}

	// Calling Get_Line Function to get Previous Line Address
	Lines_Slist *Prev = Get_Line(Head,Line_Num - 1);

	// Returning NO_LINE if Previous Line is not Found
	if ( Prev == nullptr || Prev -> Link == nullptr)
		return NO_LINE;
		
	// Updating Prev's Link with temp's Link
	Lines_Slist *temp = Prev -> Link;
	Prev -> Link = temp -> Link;

	// Freeing temp & Returning SUCCESS
	free(temp);
	return SUCCESS;
}








