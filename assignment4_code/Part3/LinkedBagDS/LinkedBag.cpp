//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <type_traits>

//   SORTING ----------------------------------------------------
template<class ItemType>
void LinkedBag<ItemType>::sort(int method){
	if (itemCount <= 1)
		return;
	
	if (method == 0){
		// update function call if you change the prototype. 
		mergeSort();
	}else{
		// for EXTRA CREDIT, update function call if you change the prototype.
		// If you do NOT implement quickSort, NO action needed here
		quickSort(); 
	}
}

template<class ItemType>
void LinkedBag<ItemType>::mergeSort(){
	if (headPtr == nullptr || headPtr->getNext() == nullptr) {
		return;
	}
	headPtr = mergeSortHelper(headPtr);
}

template<class ItemType>
void LinkedBag<ItemType>::quickSort(){
	if (headPtr == nullptr || headPtr->getNext() == nullptr) {
		return;
	}
	
	Node<ItemType>* tail = getTail(headPtr);
	headPtr = quickSortHelper(headPtr, tail);
}
// --------------------------------------------------------------

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0){
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag){
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
	
	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original bag is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		
		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;		// Points to last node in new chain
		origChainPtr = origChainPtr->getNext();	  // Advance original-chain pointer
		
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
				  
			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			
			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			
			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while
		
		newChainPtr->setNext(nullptr);				  // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag(){
	clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)		  
	Node<ItemType>* nextNodePtr = new Node<ItemType>();

	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr);  // New node points to chain
	headPtr = nextNodePtr;			 // New node is now first node
	itemCount++;
	
	return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const{
	std::vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while
	
	return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry){
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem){
		// Copy data from first node to located node
		entryNodePtr->setItem(headPtr->getItem());
		
		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		
		itemCount--;
	} // end if
	
	return canRemoveItem;
}  // end remove

template<class ItemType>
bool LinkedBag<ItemType>::removeAlt(const ItemType& anEntry){
	Node<ItemType>* prev = headPtr;
	Node<ItemType>* cur = headPtr;
	bool found = false;

	while((cur != nullptr) && !found){
		found = (*(cur->getItem()) == *anEntry);
		if (!found){
			prev = cur;
			cur = cur->getNext();
		}
	}

	if (found){
		prev->setNext(cur->getNext());
		// delete cur->getItem();
		delete cur;
		cur = nullptr;
		itemCount--;
	}

	return found;

}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear(){
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr){
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);

		// delete nodeToDeletePtr->getItem(); 
		delete nodeToDeletePtr;
		
		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr
	
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		} // end if
		
		counter++;
		curPtr = curPtr->getNext();
	} // end while
	
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains


// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	
	while (!found && (curPtr != nullptr))
	{
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while
	
	return curPtr;
} // end getPointerTo

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::mergeSortHelper(Node<ItemType>* head) {
	if (head == nullptr || head->getNext() == nullptr) {
		return head;
	}
	
	Node<ItemType>* middle = getMiddle(head);
	Node<ItemType>* nextToMiddle = middle->getNext();
	middle->setNext(nullptr);
	
	Node<ItemType>* left = mergeSortHelper(head);
	Node<ItemType>* right = mergeSortHelper(nextToMiddle);
	
	return merge(left, right);
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getMiddle(Node<ItemType>* head) {
	if (head == nullptr) return head;
	
	Node<ItemType>* slow = head;
	Node<ItemType>* fast = head->getNext();
	
	while (fast != nullptr && fast->getNext() != nullptr) {
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	}
	
	return slow;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::merge(Node<ItemType>* left, Node<ItemType>* right) {
	if (left == nullptr) return right;
	if (right == nullptr) return left;
	
	Node<ItemType>* result = nullptr;
	
	if (left->getItem() <= right->getItem()) {
		result = left;
		result->setNext(merge(left->getNext(), right));
	} else {
		result = right;
		result->setNext(merge(left, right->getNext()));
	}
	
	return result;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::quickSortHelper(Node<ItemType>* head, Node<ItemType>* tail) {
	if (head == nullptr || head == tail) {
		return head;
	}
	
	Node<ItemType>* newHead = nullptr;
	Node<ItemType>* newTail = nullptr;
	
	Node<ItemType>* pivot = partition(head, tail, &newHead, &newTail);
	
	if (newHead != pivot) {
		Node<ItemType>* temp = newHead;
		while (temp->getNext() != pivot) {
			temp = temp->getNext();
		}
		temp->setNext(nullptr);
		
		newHead = quickSortHelper(newHead, temp);
		
		temp = getTail(newHead);
		temp->setNext(pivot);
	}
	
	pivot->setNext(quickSortHelper(pivot->getNext(), newTail));
	
	return newHead;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::partition(Node<ItemType>* head, Node<ItemType>* tail,
											 Node<ItemType>** newHead, Node<ItemType>** newTail) {
	Node<ItemType>* pivot = tail;
	Node<ItemType>* prev = nullptr;
	Node<ItemType>* curr = head;
	Node<ItemType>* smallerTail = pivot;
	
	*newHead = nullptr;
	*newTail = pivot;
	
	while (curr != pivot) {
		if (curr->getItem() < pivot->getItem()) {
			if (*newHead == nullptr) {
				*newHead = curr;
			}
			prev = curr;
			curr = curr->getNext();
		} else {
			if (prev != nullptr) {
				prev->setNext(curr->getNext());
			}
			
			Node<ItemType>* temp = curr->getNext();
			curr->setNext(nullptr);
			smallerTail->setNext(curr);
			smallerTail = curr;
			curr = temp;
		}
	}
	
	if (*newHead == nullptr) {
		*newHead = pivot;
	}
	
	*newTail = smallerTail;
	return pivot;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getTail(Node<ItemType>* head) {
	if (head == nullptr) return nullptr;
	
	while (head->getNext() != nullptr) {
		head = head->getNext();
	}
	
	return head;
}


