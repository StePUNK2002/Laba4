#include "Turn.h"

Turn::Turn()
{
	heaphandle = GetProcessHeap();
	size = 0;
	mass = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, size * sizeof(int));
}

void Turn::AddElement() //добавление элемента в очередь
{
	if (size == 0)
	{
		HeapFree(heaphandle, HEAP_NO_SERIALIZE, mass);
		size = 1;
		mass = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, size * sizeof(int));
		printf("¬ведите элемент\n");
		scanf("%d", &mass[0]);
	}
	else
	{	
		//сохран€ю старый массив и переписываю в новый
		HANDLE heap = GetProcessHeap();
		int* mass1 = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, size * sizeof(int));
		for (int i = 0; i < size; i++)
		{
			mass1[i] = mass[i];
		}
		HeapFree(heaphandle, HEAP_NO_SERIALIZE, mass);
		size = size + 1;
		mass = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, size * sizeof(int));
		for (int i = 0; i < size; i++)
		{
			mass[i] = mass1[i];
		}
		printf("¬ведите элемент\n");
		scanf("%d", &mass[size-1]);
		HeapFree(heap, HEAP_NO_SERIALIZE, mass1);
	}
}

void Turn::EjectionElemet() // удаление 1 элемента
{
	//сохран€ю старый массив и переписываю в новый
	if (size == 0)
	{
		printf("ќчередь пуста!\n");
	}
	else
	{
		HANDLE heap = GetProcessHeap();
		int newsize = size - 1;
		int* mass1 = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, newsize * sizeof(int));
		for (int i = 1; i < size; i++)
		{
			mass1[i-1] = mass[i];
		}
		HeapFree(heaphandle, HEAP_NO_SERIALIZE, mass);
		size = newsize;
		mass = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, size * sizeof(int));
		for (int i = 0; i < size; i++)
		{
			mass[i] = mass1[i];
		}
		HeapFree(heap, HEAP_NO_SERIALIZE, mass1);
	}
}

void Turn::Viewing() //просмотр содержимого очереди
{
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			printf("%d ", mass[i]);
		}
	}
	else
	{
		printf("ќчередь пуста!\n");
	}
}

int Turn::GetFirstEl() //получение первого элемента
{
	if (size == 0)
	{
		printf("ќчередь пуста!\n");
		return 0;
	}
	else
	{
		return mass[0];
	}
}

int Turn::GetSize() //получение элемента
{
	return size;
}

Turn::~Turn()
{
	HeapFree(heaphandle, HEAP_NO_SERIALIZE, mass);
}
