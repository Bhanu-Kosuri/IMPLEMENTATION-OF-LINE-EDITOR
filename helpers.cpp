/*
Name:Bhanu Kosuri
Date:
File name:.cpp
Description:
Sample input:
Sample output:
*/



#include "Line.h"


// Validate_CLA Function Definition
void Validate_CLA(int argc, char **argv)
{
	// Exiting & Printing an Error if File is Not Passed
	if ( argc != 2 )
	{
		cerr << RED << "ERROR: Please Pass a File to Proceed!\n";
		cout << "USAGE: " << argv[0] << " File.txt\n" << NORMAL;
		exit(EXIT_FAILURE);
	}
}


// Read_Lines Function Definition
void Read_Lines(Lines_Slist *&Head, const string &File)
{
	// Opening the File in Read Mode
	ifstream file_obj; //for reading
	file_obj.open(File); 
	
	//ifstream file_obj(File); //valid

	// Printing An Error & Exiting if File is Not Present
	//if( file_obj == NULL) //error, this is wrong, file_obj is not a pointer
	if ( !file_obj ) // if( !file_obj.is_open() )
	{
		cerr << RED << "ERROR: " << File << " File Doesn't Exist!\n" << NORMAL;
		exit(EXIT_FAILURE);
	}

	// Moving File Offset to End
	file_obj.seekg(0, ios::end);

	// Printing an ERROR & Exiting if File is Empty
	//tellg or tellp returns > 0 on success, 0 if file is empty, -1 on failure
	if ( file_obj.tellg() <= 0) 
	{
		cerr << "ERROR: " << File << " File is Empty!\n" << NORMAL;
		exit(EXIT_FAILURE);
	}

	// Moving File Offset Back to Start
	file_obj.seekg(0, ios::beg);

	// Declaring Data
	string Data;

	// Reading Lines from fptr & Calling Store_Lines Function to Store lines in a List
	while ( getline(file_obj, Data) )
	{
		Store_Lines(Head,Data);
	}

	// Closing the File
	file_obj.close();
}


// Read_Validate_Line_Num Function Definition
Status Read_Validate_Line_Num(int &Line_Num)
{
	// Reading Line_Num
	cout << "\nEnter Line Number: ";
	cin >> Line_Num;
	cin.ignore();

	// Returning FAILURE if Line_Num is Less than 0
	if ( Line_Num <= 0 )
	{
		cerr << RED << "ERROR: Invalid Line Number!\n\n" << NORMAL;
		return FAILURE;
	}
	return SUCCESS;
}


// Get_Line Function Definition
Lines_Slist *Get_Line(Lines_Slist *Head,int Line_Num)
{
	// Declaring a Traverse Pointer
	Lines_Slist *temp  = Head;
	//int Current_Line = 1;

	// Traversing the List to Reach Line_Num
	while ( temp && (Line_Num - 1 != 0) ) //or Current_Line < Line_Num
	{
		temp = temp -> Link;
		//Current_Line++;
		Line_Num--;
	}

	// Returning temp
	return temp;
}

// Write_Lines Function Definition
void Write_Lines(Lines_Slist *Head, const string &File)
{
	// Opening the File in Write Mode
	ofstream file_obj; //for writing
	file_obj.open(File);

	//ofstream file_obj(File); //valid

	// Printing An Error & Exiting if File is Not Present
	if ( !file_obj )
	{
		cerr << RED << "ERROR: " << File << " File Doesn't Exist!\n" << NORMAL;
		exit(EXIT_FAILURE);
	}

	// Running a Loop until Head Reaches NULL
	while ( Head )
	{
		// Writing Lines to File (fptr automatically updates) & Moving Head
		file_obj << Head->Line_str << "\n";
		Head = Head -> Link;
	}

	// Closing the File
	file_obj.close();
}

// Free_Lines_List Function Definition
void Free_Lines_List(Lines_Slist *Head)
{
	// Running a Loop until Head Reaches NULL

	while ( Head )
	{
		// Updating temp with temp's Link
		Lines_Slist *temp = Head;
		Head = temp -> Link;

		// Freeing temp
		free(temp);
	}
}


