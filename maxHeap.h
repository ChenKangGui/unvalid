// heap implementation of a max priority queue
// derives from the ADT maxPriorityQueue

#ifndef maxHeap_
#define maxHeap_

#include <sstream>
#include <algorithm>

using namespace std;

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
    if (newLength < 0)
    {
        cout << "new length must be >= 0" << endl;
        exit(1);
    }

    T* temp = new T[newLength];              // new array
    int number = min(oldLength, newLength);  // number to copy
    copy(a, a + number, temp);
    delete[] a;                             // deallocate old memory
    a = temp;
}

template<class T>
class maxHeap
{
public:
    maxHeap(int initialCapacity = 10);
    ~maxHeap() { delete[] heap; }
    bool empty() const { return heapSize == 0; }
    int size() const
    {
        return heapSize;
    }
    const T& top()
    {// return max element
        if (heapSize == 0)
            exit(1);
        return heap[1];
    }
    void pop();
    void push(const T&);
    void initialize(T*, int);
    void deactivateArray()
    {
        heap = NULL; arrayLength = heapSize = 0;
    }
    void output(ostream& out) const;
private:
    int heapSize;       // number of elements in queue
    int arrayLength;    // queue capacity + 1
    T* heap;            // element array
};

template<class T>
maxHeap<T>::maxHeap(int initialCapacity)
{// Constructor.
    if (initialCapacity < 1)
    {
        cout << "Initial capacity = " << initialCapacity << " Must be > 0";
        exit(1);
    }
    arrayLength = initialCapacity + 1;
    heap = new T[arrayLength];
    heapSize = 0;
}

template<class T>
void maxHeap<T>::push(const T& theElement)
{// Add theElement to heap.

   // increase array length if necessary
    if (heapSize == arrayLength - 1)
    {// double array length
        changeLength1D(heap, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    // find place for theElement
    // currentNode starts at new leaf and moves up tree
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < theElement)
    {
        // cannot put theElement in heap[currentNode]
        heap[currentNode] = heap[currentNode / 2]; // move element down
        currentNode /= 2;                          // move to parent
    }

    heap[currentNode] = theElement;
}

template<class T>
void maxHeap<T>::pop()
{// Remove max element.
   // if heap is empty return null
    if (heapSize == 0)   // heap empty
    {
        cout << "heap is empty!" << endl;
        exit(1);
    }

    // Delete max element
    heap[1].~T();

    // Remove last element and reheapify
    T lastElement = heap[heapSize--];

    // find place for lastElement starting at root
    int currentNode = 1,
        child = 2;     // child of currentNode
    while (child <= heapSize)
    {
        // heap[child] should be larger child of currentNode
        if (child < heapSize && heap[child] < heap[child + 1])
            child++;

        // can we put lastElement in heap[currentNode]?
        if (lastElement >= heap[child])
            break;   // yes

         // no
        heap[currentNode] = heap[child]; // move child up
        currentNode = child;             // move down a level
        child *= 2;
    }
    heap[currentNode] = lastElement;
}

#endif
