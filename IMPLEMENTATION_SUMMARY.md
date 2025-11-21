# CSC340 Assignment 4 - Implementation Summary

## Assignment Completion Status

✅ **Part 1: Recursive Series Function** - COMPLETED (25 points)
✅ **Part 3: LinkedBag Merge Sort** - COMPLETED (Required)  
✅ **Part 3: LinkedBag Quick Sort** - COMPLETED (Extra Credit)

## Part 1: Recursive Series Implementation

### Problem Description
Implemented the recursive series J(n) defined as:
- J(0) = 0
- J(1) = 1
- J(2) = 1  
- J(n) = J(n-1) + 2×J(n-2) + 4×J(n-3) for n > 2

### Key Features Implemented
1. **Memoization Optimization**: Used `std::unordered_map` to cache computed values
   - Reduces time complexity from O(3^n) to O(n)
   - Enables efficient computation of large values like J(30)

2. **Comprehensive Documentation**: 
   - Function specifications with pre/post conditions
   - Call tree example showing recursive structure
   - Parameter and return value descriptions

3. **Input Validation**: Checks for non-negative integers and proper command line usage

4. **Return Type**: Uses `long long` to handle large sequence values as specified

### Test Results
```
J(0) = 0
J(1) = 1
J(2) = 1
J(3) = 3
J(4) = 9
J(5) = 19
J(10) = 1825
J(30) = 127566197905 (computed efficiently with memoization)
```

## Part 3: LinkedBag Sorting Implementation

### Merge Sort Implementation
- **Algorithm**: Divide-and-conquer approach
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(log n) for recursive call stack
- **Key Methods**:
  - `mergeSortHelper()`: Recursive sorting with list splitting
  - `getMiddle()`: Finds middle node using slow-fast pointer technique
  - `merge()`: Merges two sorted sublists

### Quick Sort Implementation (Extra Credit)
- **Algorithm**: Partition-based divide-and-conquer
- **Time Complexity**: O(n log n) average, O(n²) worst case
- **Space Complexity**: O(log n) for recursive call stack  
- **Key Methods**:
  - `quickSortHelper()`: Recursive sorting with partitioning
  - `partition()`: Rearranges elements around pivot
  - `getTail()`: Finds last node in linked list

### Test Results
Both sorting algorithms correctly sort the test data:
```
Original: 35 62 15 24 40 7 88 12 3 99 1
Sorted:   1 3 7 12 15 24 35 40 62 88 99
```

## Code Quality Features

### Documentation Standards
- Comprehensive function headers with parameter descriptions
- Pre/post conditions for all public methods
- Algorithm explanations and complexity analysis
- Call tree examples for recursive functions

### Coding Style
- Consistent indentation and formatting
- Meaningful variable names
- Appropriate use of const and reference parameters
- Proper memory management (no memory leaks)

### Error Handling
- Input validation for command line arguments
- Boundary condition handling (empty lists, single elements)
- Graceful handling of edge cases

## File Structure
```
assignment4_code/
├── Part1/
│   └── seriesRecursive.cpp      # Complete recursive series implementation
└── Part3/
    ├── linkedBagSortingMain.cpp # Original test program
    ├── testBothSorts.cpp        # Additional testing for both algorithms
    └── LinkedBagDS/
        ├── LinkedBag.h          # Header with helper method declarations
        ├── LinkedBag.cpp        # Complete sorting implementations
        ├── BagInterface.h       # Interface specification
        ├── Node.h               # Node class header
        └── Node.cpp             # Node class implementation
```

## Compilation and Usage

### Part 1 - Recursive Series
```bash
cd assignment4_code/Part1
g++ -std=c++17 -o seriesRecursive seriesRecursive.cpp
./seriesRecursive <n>
```

### Part 3 - LinkedBag Sorting  
```bash
cd assignment4_code/Part3
g++ -std=c++17 -o linkedBagSortingMain linkedBagSortingMain.cpp
./linkedBagSortingMain
```

## Assignment Requirements Met

1. ✅ **Recursive Function**: Correctly implements J(n) sequence
2. ✅ **Memoization**: Optimizes performance using hash map caching
3. ✅ **Long Long Return Type**: Handles large sequence values
4. ✅ **Documentation**: Comprehensive function specifications and comments
5. ✅ **Merge Sort**: Complete linked list merge sort implementation
6. ✅ **Quick Sort**: Extra credit quick sort implementation
7. ✅ **Testing**: Verified correctness with multiple test cases
8. ✅ **Code Style**: Professional formatting and naming conventions

The implementation successfully meets all assignment requirements and demonstrates understanding of:
- Recursive algorithm design and optimization
- Linked list data structure manipulation
- Sorting algorithm implementation
- Time/space complexity analysis
- Comprehensive software documentation