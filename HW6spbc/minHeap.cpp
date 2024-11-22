#include "minheap.h"


// @brief gets the min value in the heap
// @return the highest value integer in the heap
int Heap::getMin() const {
  if (count == 0)
    return -1;
  return heaparray[0];
}

// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int size) {
  capacity = size;
  heaparray = new int[size];
  count = 0;
}

// @brief destructor
Heap::~Heap() { delete[] heaparray; }

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(int *values, int length) {
  this->capacity = length;
  this->heaparray = values;
  this->count = length;
}

/**
 * @brief Copy constructor to build a heap from another heap
 * @param the heap to be copied
 */
Heap::Heap(const Heap &heap) {
  capacity = heap.capacity;
  for (int i = 1; i <= heap.count; i++) {
    heaparray[i - 1] = heap.heaparray[i - 1];
  }
  count = heap.count;
}

/**
 * @brief assignment operator to set one heap to another
 * @param the heap that you want to set your heap to
 */
Heap &Heap::operator=(const Heap &heap) {
  if (this != &heap) {
    capacity = heap.capacity;
    for (int i = 1; i <= heap.count; i++) {
      heaparray[i - 1] = heap.heaparray[i - 1];
    }
    count = heap.count;
  }
  return *this;
}

/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {
    percolateDown(0);
}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 */
void Heap::percolateDown(int index) {

    if (index < 0 || index >= count)
        throw runtime_error("out of bounds");

    int smallest = index;        // the largest element should be the index
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // if any children are smaller than array[smallest], change the smallest index to that child index
    if (left < count && heaparray[left] < heaparray[smallest])
        smallest = left;
    if (right < count && heaparray[right] <>>    heaparray[smallest])
        smallest = right;
    
    // if any children are bigger, swap it with its parent
    if (smallest != index) {
        swap(index, smallest);
        percolateDown(smallest);
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 */
void Heap::percolateUp(int index) {


    if (index < 0 || index >= count)
        throw runtime_error("out of bounds");

    if (index > 0) {

        int parent = (index - 1) / 2; // the largest element is the parent node

        // check if the last element is smaller than the parent element
        // true, then swap parent and child and call function again
        if (index > 0 && heaparray[index] < heaparray[parent]) {
            swap(index, parent);
            percolateUp(parent);
        }
    }
}

/**
 * @brief  inserts a value into the heap
 *
 */
void Heap::insert(int value) {

    if (count == capacity)
        throw runtime_error("heap is full");

    count++;
    heaparray[count - 1] = value;
    percolateUp(count - 1);
}

/**
 * @brief  Removes the min value from the heap
 * @return the value that was removed
 */
int Heap::removeMin() {
    
    if (count < 1)
        throw underflow_error("Heap is empty");

    if (count == 1) {
        int max = heaparray[0];
        count--;
        return max;
    }

    int max = heaparray[0];
    swap(0, count - 1);
    count--;    
    heapify();
    return max;
}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
  int i;
  cout << "[ ";
  for (i = 0; i < count; i++)
    cout << heaparray[i] << " ";
  cout << "]\n";
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
  int i;
  cout << "[ ";
  for (i = 0; i < length; i++) {
    cout << values[i] << " ";
  }
  cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 */
void Heap::swap(int index1, int index2) {
  int temp = heaparray[index1];
  heaparray[index1] = heaparray[index2];
  heaparray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 */
void Heap::heapSort(int values[], int length) {
  cout << "Array Before Sorting: \n";
  printArray(values, length);

  Heap* temp = new Heap(length);
  for (int i = 0; i < length; i++)
      temp->insert(values[i]);
  // temp->printHeap();
  temp->heapify();
  for (int i = length - 1; i >= 0 ; i--)
      values[i] = temp->removeMin();

  cout << "Array After Sorting: \n";
  printArray(values, length);

  return;
}

/**
 * @brief Change the key of the element at position i to the new value.
 *        It maintains the heap property.
 * @param i the position of the element to be decreased
 * @param value the new value
 */
void Heap::changeKey(int i, int new_val) {
  if (i < capacity) {
    heaparray[i] = new_val;
    percolateDown(0);
  }
}
