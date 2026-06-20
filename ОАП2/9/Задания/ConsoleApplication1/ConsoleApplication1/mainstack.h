#pragma once
struct Stack
{
	char data;
	Stack* next;
};
void clear ( Stack*& myStk );
char pop ( Stack*& myStk );
void push ( char x, Stack*& myStk );
void toFile ( Stack*& myStk );
void fromFile ( Stack*& myStk );
bool contains ( Stack* st, char value );
void show ( Stack*& myStk );
void difference ( Stack*& result, Stack* stack1, Stack* stack2 );
