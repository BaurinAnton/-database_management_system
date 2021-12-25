#include "pch.h"
#include "List.h"

const vector<int> List::getList()
{
	Node* tempHead = head;
	vector<int> list;
	for (size_t count = 0; count < this->size(); count++) {
		list.push_back(tempHead->dataItem);
		tempHead = tempHead->nextItem;
	}
	return list;
}

List::~List()
{
	while (this->size() != 0)
	{
		Node *temp = head->nextItem;
		if (head != nullptr)
		{
			delete head;
			head = nullptr;
		}
		head = temp;
		sizeList--;
	}
}

void List::addItem(const int dataItem)
{
	Node* temp = new Node(dataItem, head);
	if (head != nullptr)
	{
		tail->nextItem = temp;
		tail = temp;
	}
	else 
	{
		head = tail = temp;
	}
	sizeList++;
}

const size_t List::size()
{
	return sizeList;
}

void List::updateItem(const size_t numberItem, const int setDataItem)
{
	Node* tempHead = head;
	size_t temp = numberItem;
	const size_t beginningItem = 1;
	while (temp != beginningItem)
	{
		tempHead = tempHead->nextItem;
		temp--;
	}
	tempHead->dataItem = setDataItem;
}

const vector<int> List::searchItem(const size_t searchItem) {
	Node* tempHead = head;
	size_t temp = this->size();
	const size_t correctionNumberItem = 1;
	vector<int> setSearch;
	while (temp != 0)
	{
		if (tempHead->dataItem == searchItem) {
			setSearch.push_back(this->size() - temp + correctionNumberItem);
		}
		tempHead = tempHead->nextItem;
		temp--;
	}
	return setSearch;
}

void List::deleteItem(const size_t numberItem)
{
	const size_t singleNumberItem = 1;
	const size_t previousNumberItem = 1;
	Node *tempNode = head;
	if (numberItem == singleNumberItem) {
		if (this->size() == singleNumberItem) {
			if (tempNode != nullptr)
			{
				delete tempNode;
				tempNode = nullptr;
			}
			head = nullptr;
			tail = nullptr;
		}
		else {
			tail->nextItem = head->nextItem;
			if (head != nullptr)
			{
				delete head;
				head = nullptr;
			}
			head = tail->nextItem;
		}
	}
	else if (numberItem == this->size()) {
		for (size_t i = 1; i < this->size() - previousNumberItem; i++) {
			tempNode = tempNode->nextItem;
		}
		tempNode->nextItem = tail->nextItem;
		if (tail != nullptr)
		{
			delete tail;
			tail = nullptr;
		}
		tail = tempNode;
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

ostream& operator<< (ostream& shift, List& point)
{
	vector<int> list = point.getList();
	for (vector<int>::iterator it = list.begin(); it != list.end(); it++)
		shift << *it << " ";
	return shift;
}