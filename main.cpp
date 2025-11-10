/*
Name: Bhanu Kosuri
Project: LINE EDITOR
*/



#include "Line.h"


// Main Function with CLA
int main(int argc,char **argv)
{
	// Calling Validate_CLA Function to Validate CLA
	Validate_CLA(argc,argv);

	// Declaring Head Pointer
	Lines_Slist *Head = nullptr;

	// Calling Read_Lines Function to Read Lines from File
	Read_Lines(Head,argv[1]);

	// Declaring Choice, Line_Num & Line
	int Choice, Line_Num;
	string Line;

	// Super Loop
	while (1)
	{
		// Displaying a Menu to User
		cout << CYAN << "######### LINE EDITOR ##########\n";
		cout << "1.Insert\n2.Display\n3.Edit\n4.Delete\n5.Exit\n" << NORMAL;

		// Reading Choice from User
		cout << "\nEnter Your Choice: ";
		cin >> Choice;

		// Using Switch Case for Choice
		switch ( Choice )
		{
			// INSERT Operation
			case INSERT:

				// Calling Read_Validate_Line_Num Function to Check Line_Num if Present or Not
				if ( Read_Validate_Line_Num(Line_Num) == FAILURE )
					break;

				// Reading Line
				cout << "Enter Line to Insert: ";
				getline(cin, Line);

				// Calling Insert Function & Validating
				Insert(Head,Line,Line_Num) == NO_LINE ?
				cout << RED << "ERROR: " << Line_Num << " Line is Not Present!\n\n" << NORMAL :
				cout << GREEN << "INFO: Successfully Inserted Line at " << Line_Num << " Line\n\n" << NORMAL;

				break;

			// DISPLAY Operation
			case DISPLAY:

				Display(Head) == FAILURE ?
				cout << RED << "ERROR: No Lines are Present!\n\n" << NORMAL :
				cout << GREEN << "\nINFO: Successfully Displayed all the Lines.\n\n" << NORMAL;

				break;

			// EDIT Operation
			case EDIT:

				// Calling Read_Validate_Line_Num Function to Validate Line_Num
				if ( Read_Validate_Line_Num(Line_Num) == FAILURE )
					break;

				Edit(Head,Line_Num) == NO_LINE ?
				cout << RED << "ERROR: " << Line_Num << " Line is Not Present!\n\n" << NORMAL :
				cout << GREEN << "INFO: Successfully Edited " << Line_Num << " Line.\n\n" << NORMAL;

				break;

			// DELETE Operation
			case DELETE:

				// Calling Read_Validate_Line_Num Function to Validate Line_Num
				if ( Read_Validate_Line_Num(Line_Num) == FAILURE )
					break;

				// Calling Delete Function & Validating
				Delete(Head,Line_Num) == NO_LINE ?
				cout << RED << "ERROR: " << Line_Num << " Line is Not Present!\n\n" << NORMAL :
				cout << GREEN << "INFO: Successfully Deleted " << Line_Num << " Line.\n\n" << NORMAL;

				break;

			// EXIT Operation
			case EXIT:

				// Calling Write_Lines Function to Write Updated Lines Back to the File
				Write_Lines(Head,argv[1]);
				printf("%s\nINFO: Changes have been Saved in the File!\n",GREEN);

				// Calling Free_Lines_List Function to Free Out Lines List Memory
				Free_Lines_List(Head);

				cout << "INFO: Exited from Line Editor!\n" << NORMAL;
				exit(EXIT_SUCCESS);

			// Default Case for Invalid Choice
			default:

				cout << RED << "ERROR: Invalid Choice!\n" << NORMAL;
				break;
		}
	}

	return 0;
}


