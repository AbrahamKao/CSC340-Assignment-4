#include <iostream>
#include <vector>
#include "LinkedBagDS/LinkedBag.h"

using namespace std;

template<class T>
void displayBag(LinkedBag<T>& bag){
   vector<T> bagItems = bag.toVector();
   for (int i = 0; i < bagItems.size(); i++){
      cout << bagItems[i] << " ";
   } 
   cout << endl;
} 

int main() {
    vector<int> arr = {35, 62, 15, 24, 40, 7, 88, 12, 3, 99, 1};

    cout << "Testing Merge Sort" << endl;
    LinkedBag<int> mergeBag; 
    for(int num : arr){
        mergeBag.add(num);
    }
    cout << "Original: ";
    displayBag(mergeBag);

    mergeBag.sort(0);
    cout << "Sorted: ";
    displayBag(mergeBag);

    cout << "\nTesting Quick Sort" << endl;
    LinkedBag<int> quickBag; 
    for(int num : arr){
        quickBag.add(num);
    }
    cout << "Original: ";
    displayBag(quickBag);

    quickBag.sort(1);
    cout << "Sorted: ";
    displayBag(quickBag);

    return 0;
}