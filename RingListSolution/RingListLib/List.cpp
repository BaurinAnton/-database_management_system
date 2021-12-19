#include "pch.h"
#include "List.h"

List::~List()
{
	while (sizeList != 0)
	{
		Node *temp = Head->nextItem;
		if (Head != nullptr)
		{
			delete Head;
			Head = nullptr;
		}
		Head = temp;
		sizeList--;
	}
}

void List::addItem(const int dataItem)
{
	sizeList++;
	Node *temp = new Node;
	temp->nextItem = Head;
	temp->dataItem = dataItem;
	if (Head != nullptr)
	{
		Tail->nextItem = temp;
		Tail = temp;
	}
	else 
	{
		Head = Tail = temp;
	}
}

void List::read()
{
	setlocale(LC_ALL, "Russian");
	Node *tempHead = Head;
	size_t temp = sizeList;
	if (Head == nullptr) 
	{
		cout << "Список пуст.";
	}
	else 
	{
		while (temp != 0)
		{
			cout << tempHead->dataItem << " ";
			tempHead = tempHead->nextItem;
			temp--;
		}
	}
}

size_t List::size()
{
	return sizeList;
}

void List::updateItem(const size_t numberItem, const int setDataItem)
{
	Node* tempHead = Head;
	size_t temp = numberItem;
	const size_t beginningItem = 1;
	while (temp != beginningItem)
	{
		tempHead = tempHead->nextItem;
		temp--;
	}
	tempHead->dataItem = setDataItem;
}

void List::searchItem(const size_t searchItem, vector<int> &setSearch)
{
	Node *tempHead = Head;
	size_t temp = sizeList;
	const size_t correctionNumberItem = 1;
	while (temp != 0)
	{
		if (tempHead->dataItem == searchItem) {
			setSearch.push_back(sizeList - temp + correctionNumberItem);
		}
		tempHead = tempHead->nextItem;
		temp--;
	}
}

void List::deleteItem(const size_t numberItem)
{
	const size_t singleNumberItem = 1;
	const size_t previousNumberItem = 1;
	Node *tempNode = Head;
	if (numberItem == singleNumberItem) {
		if (sizeList == singleNumberItem) {
			if (tempNode != nullptr)
			{
				delete tempNode;
				tempNode = nullptr;
			}
			Head = nullptr;
			Tail = nullptr;
		}
		else {
			Tail->nextItem = Head->nextItem;
			if (Head != nullptr)
			{
				delete Head;
				Head = nullptr;
			}
			Head = Tail->nextItem;
		}
	}
	else if (numberItem == sizeList) {
		for (size_t i = 1; i < sizeList - previousNumberItem; i++) {
			tempNode = tempNode->nextItem;
		}
		tempNode->nextItem = Tail->nextItem;
		if (Tail != nullptr)
		{
			delete Tail;
			Tail = nullptr;
		}
		Tail = tempNode;
	}
	else {
		for (size_t i = 1; i < numberItem - previousNumberItem; i++) {
			tempNode = tempNode->nextItem;
		}
		Node *deletionItem = tempNode->nextItem;
		tempNode->nextItem = deletionItem->nextItem;
		if (deletionItem != nullptr)
		{
			delete deletionItem;
			deletionItem = nullptr;
		}
	}
	sizeList--;
}

void List::iteratorItem()
{
	Node *tempHead = Head;
	size_t temp = sizeList;
	const size_t previousNumberItem = 1;
	vector<int> list;
	vector<int> ::iterator iterator;
	while (temp != 0)
	{
		list.push_back(tempHead->dataItem);
		tempHead = tempHead->nextItem;
		temp--;
	}
	for (iterator = list.begin(); iterator <= list.end() - previousNumberItem; iterator++) {
		cout << endl << "Разыменованный элемент: " << *iterator << " ";
	}
}