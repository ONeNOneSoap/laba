#pragma once
#include "Sequence.h"
#include "DynamicArray.h"

template <class T> class ArraySequence : public Sequence<T>
{
private:
	DynamicArray<T>* array_sequence_items;
public:
	// ������������:
	ArraySequence() 
	{
		array_sequence_items = new DynamicArray<T>(0);
	} // ������� ������ ������
	ArraySequence(T* arr, int count) {
		array_sequence_items = new DynamicArray<T>(0);
		array_sequence_items->Resize(count);
		for (int i = 0; i < count; i++)
		{
			array_sequence_items->Set(i, arr[i]);
		}
	} // ���������� �������� �� ����������� �������

	ArraySequence(int count) {
		array_sequence_items = new DynamicArray<T>(count);
		T defaul = T();
		for (int i = 0; i < count; i++)
		{
			array_sequence_items->Set(i, defaul);
		}
	} // ���������� �������� �� ����������� �������

	// ������� �� ������ ������� - ���������� �����������
	ArraySequence(const ArraySequence <T>& arr)
	{
		array_sequence_items = new DynamicArray<T>(*(arr.array_sequence_items));
	}// ������� �� ������ ������� - ���������� �����������

	ArraySequence<T>* clone() const override {
		auto arr = new ArraySequence(*this);
		return arr;
	}
	
	//�������� �� Sequence
	T GetFirst()
	{
		return this->Get(0);
	}
	T GetLast()
	{
		return this->Get(array_sequence_items->GetSize()-1);
	}
	T& Get(int index)
	{
		return array_sequence_items->Get(index);
	}
	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		ArraySequence<T>* buf = new ArraySequence<T>;
		int dif = endIndex - startIndex+1;
		buf->Resize(dif);
		for (int i = 0; i< dif;i++)
		{
			buf->Set(i, this->Get(startIndex+i));
		}
		return buf;
	}
	int GetLength()
	{
		return array_sequence_items->GetSize();
	}
	void Set(int index, T value) // ������ ������� �� �������. ����� ��������� IndexOutOfRange
	{
		array_sequence_items->Set(index, value);
	}

	// ��������� ������� � ����� ������
	// TODO: ������� ���������� ��� resize � Append, Prepend, InsertAt
	void Append(T item)
	{
		array_sequence_items->Resize(array_sequence_items->GetSize() + 1);
		array_sequence_items->Set(array_sequence_items->GetSize()-1, item);
	}
	// ��������� ������� � ������ ������
	
	// TODO: �������� ��� ������������� �������.
	void Prepend(T item)
	{
		array_sequence_items->ResizeRight(array_sequence_items->GetSize() + 1);
		array_sequence_items->Set(0, item);
	}
	// ��������� ������� � �������� �������
	void InsertAt(T item, int index)
	{
		int newLenght = this->GetLength() + 1;
		this->Resize(newLenght);
		T buf;
		int dif = newLenght - index -1 ;
		for (int i = 0; i < dif; i++)
		{
			buf = this->Get(newLenght - i - 2);
			this->Set(newLenght - i - 1, buf);
		}
		this->Set(index + 1, item);
	}
	Sequence <T>* Concat(Sequence <T>* list)
	{
		Sequence <T>* buf = NULL;
		int oldLenght = this->GetLength();
		this->Resize(this->GetLength() + ((ArraySequence <T>*)list)->GetLength());
		for (int i = 0 ;i < ((ArraySequence <T>*)list)->GetLength(); i++)
			this->Set(i + oldLenght,((ArraySequence <T>*)list)->Get(i));
		return (Sequence <T>*)buf;
	}
	/*bool1 subsequenceSearch()1111
	{

	}*/
	void Resize(int newSize)
	{
		array_sequence_items->Resize(newSize);
	}
	void ResizeRight(int newSize)
	{
		array_sequence_items->ResizeRight(newSize);
	}
};

//ArraySequence<int> arrInt;