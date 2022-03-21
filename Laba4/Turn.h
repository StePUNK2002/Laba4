#ifndef DATE_H
#define DATE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
class Turn
{
private:
	int size;
	HANDLE heaphandle;
	int* mass;
public:
	Turn();
	void AddElement();
	void EjectionElemet();
	void Viewing();
	int GetFirstEl();
	int GetSize();
	~Turn();
};
#endif