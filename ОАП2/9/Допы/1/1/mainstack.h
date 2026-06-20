#pragma once
struct Stack
{
	int data;
	Stack* next;
};
void clear ( Stack*& myStk );
int pop ( Stack*& myStk );
void push ( int x, Stack*& myStk );
void toFile ( Stack*& myStk );
void fromFile ( Stack*& myStk );
bool contains ( Stack* st, int value );
void show ( Stack*& myStk );
void splitStack ( Stack*& stack1, Stack*& stack2, Stack* source );