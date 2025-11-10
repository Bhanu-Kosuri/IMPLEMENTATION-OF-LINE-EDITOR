
#ifndef LINE_H
#define LINE_H

// Including Header Files
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Macros
#define MAX_LINE	1024
#define RED     	"\x1b[31m"
#define NORMAL      "\x1b[0m"
#define GREEN       "\033[1;32m"
#define BLUE        "\x1b[034;1m"
#define MAGENTA     "\033[35m"
#define CYAN		"\033[36m"


// Structure For Lines List
typedef struct Node
{
	string Line_str;
	struct Node *Link;
}Lines_Slist;



// Enum for Status
typedef enum 
{
	SUCCESS = 1, 
	FAILURE = -1, 
	NO_LINE
}Status;


// Enum for Operations
typedef enum
{
	INSERT = 1, 
	DISPLAY, 
	EDIT, 
	DELETE, 
	EXIT
}Operation;



// Function Prototypes
void Validate_CLA(int argc, char **argv);

//void Read_Lines(Lines_Slist **Head, const string &File); //valid
void Read_Lines(Lines_Slist *&Head, const string &File); //reference, valid

//void Store_Lines(Lines_Slist **Head, const string &Line); //valid
void Store_Lines(Lines_Slist *&Head, const string &Line); //reference, valid

Status Read_Validate_Line_Num(int &Line_Num);

void Write_Lines(Lines_Slist *Head, const string &File);

void Free_Lines_List(Lines_Slist *Head);

//Status Insert(Lines_Slist **Head, const string &Line, int Line_Num); //valid
Status Insert(Lines_Slist *&Head, const string &Line, int Line_Num); //reference, valid 

Status Display(Lines_Slist *Head);

//Status Delete(Lines_Slist **Head, int Line_Num); //valid
Status Delete(Lines_Slist *&Head, int Line_Num); //reference, valid

//Status Edit(Lines_Slist **Head, int Line_Num); //valid
Status Edit(Lines_Slist *&Head, int Line_Num); //reference, valid

Lines_Slist *Get_Line(Lines_Slist *Head, int Line_Num);

#endif

