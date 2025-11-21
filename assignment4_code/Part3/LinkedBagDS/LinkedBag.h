//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.h 
	 Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>{
	private:
		Node<ItemType>* headPtr; // Pointer to first node
		int itemCount;			 // Current count of bag items
		
		// Returns either a pointer to the node containing a given entry
		// or the null pointer if the entry is not in the bag.
		Node<ItemType>* getPointerTo(const ItemType& target) const;
		
		// Merge sort helpers
		Node<ItemType>* mergeSortHelper(Node<ItemType>* head);
		Node<ItemType>* getMiddle(Node<ItemType>* head);
		Node<ItemType>* merge(Node<ItemType>* left, Node<ItemType>* right);
		
		// Quicksort helpers  
		Node<ItemType>* quickSortHelper(Node<ItemType>* head, Node<ItemType>* tail);
		Node<ItemType>* partition(Node<ItemType>* head, Node<ItemType>* tail,
								Node<ItemType>** newHead, Node<ItemType>** newTail);
		Node<ItemType>* getTail(Node<ItemType>* head);
		
	public:
		LinkedBag();
		LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
		virtual ~LinkedBag(); // Destructor should be virtual
		
		//   SORTING ----------------------------------------------------
		void sort(int method=0);
		/**
		 * Sorts the LinkedBag using merge sort algorithm.
		 * Time complexity: O(n log n)
		 */
		void mergeSort(); 
		
		/**
		 * Sorts the LinkedBag using quicksort algorithm (Extra Credit).
		 * Time complexity: O(n log n) average case
		 */
		void quickSort();
		// --------------------------------------------------------------

		int getCurrentSize() const;
		bool isEmpty() const;
		bool add(const ItemType& newEntry);
		bool remove(const ItemType& anEntry);
		void clear();
		bool contains(const ItemType& anEntry) const;
		int getFrequencyOf(const ItemType& anEntry) const;
		std::vector<ItemType> toVector() const;
		bool removeAlt(const ItemType& anEntry);
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif