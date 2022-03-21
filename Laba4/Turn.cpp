#include "Turn.h"

Turn::Turn()
{
	heaphandle = GetProcessHeap();
	size = 0;
	mass = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, size * sizeof(int));
}

void Turn::AddElement() //���������� �������� � �������
{
	if (size == 0)
	{
		HeapFree(heaphandle, HEAP_NO_SERIALIZE, mass);
		size = 1;
		mass = (int*)HeapAlloc(heaphandle, HEAP_ZERO_MEMORY, size * sizeof(int));
		printf("������� �������\n");
		scanf("%d", &mass[0]);
	}
	else
	{	
		//�������� ������ ������ � ����������� � �����
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
		printf("������� �������\n");
		scanf("%d", &mass[size-1]);
		HeapFree(heap, HEAP_NO_SERIALIZE, mass1);
	}
}

void Turn::EjectionElemet() // �������� 1 ��������
{
	//�������� ������ ������ � ����������� � �����
	if (size == 0)
	{
		printf("������� �����!\n");
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

void Turn::Viewing() //�������� ����������� �������
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
		printf("������� �����!\n");
	}
}

int Turn::GetFirstEl() //��������� ������� ��������
{
	if (size == 0)
	{
		printf("������� �����!\n");
		return 0;
	}
	else
	{
		return mass[0];
	}
}

int Turn::GetSize() //��������� ��������
{
	return size;
}

Turn::~Turn()
{
	HeapFree(heaphandle, HEAP_NO_SERIALIZE, mass);
}
