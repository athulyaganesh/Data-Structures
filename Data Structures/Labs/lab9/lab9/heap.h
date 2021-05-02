#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <list>
using namespace std;




class JobNode
{
    friend void LPT(JobNode *, int, int);
    friend int main(void);

public:
    operator int() const {return time;}


private:
    int ID, time;
};



class MachineNode
{
    friend void LPT(JobNode *, int, int);
    friend int main(void);
public:
    operator int() const {return avail;}
private:
    int ID, avail;//id- mach identity, avail- time that machine becomes available
};





template <class T>

class MinHeap
{
private:
    T data[100];
    int capacity, currentSize;

    void bubbleUp()
    {
        int child = currentSize - 1;
        int parent = getParent(child);

        while(data[child]<data[parent] && child >=0 && parent >=0)
        {
            swap(child, parent);
            child = parent;
            parent = getParent(child);
        }
    }
    void bubbleDown()
    {
        int parent = 0;
        while(1)
        {
            int left = getLeftChild(parent);
            int right = getRightChild(parent);
            int largest = parent;

            if(left<currentSize && data[left]<data[largest])
            {
                largest = left;
            }
            if(right <currentSize && data[right]<data[largest])
            {
              largest = right;
            }
            if(largest!=parent)
            {
                swap(largest, parent);
                parent = largest;
            }
            else
                break;
        }
    }
    void swap(int child, int parent)
    {
        T temp;
        temp = data[child];
        data[child]=data[parent];
        data[parent]=temp;
    }
    int getLeftChild(int parent){return 2*parent+1;}
    int getRightChild(int parent){return 2*parent+2;}
    int getParent(int child)
    {
        if(child%2==0)
        {
            return(child/2)-1;
        }
        return child/2;
    }

public:
    MinHeap(int c)
    {
        capacity = c;
        currentSize = 0;
    }
    MinHeap()
    {
        capacity = 0 ;
                currentSize=0;
    }
    void Insert(T a)
    {
        currentSize++;
        data[currentSize-1]=a;
        bubbleUp();
    }
    T DeleteMin()
    {
        int child = currentSize - 1;
        swap(child,0);

        T value = data[child];
        currentSize--;

        bubbleDown();

        return value;

    }
    int getSize()
    {
        return currentSize;
    }
};

template <class T>
class MaxHeap
{
    friend void HeapSort(JobNode a[], int);
private:
    T data[100];
    int capacity, currentSize;

    void bubbleUp()
    {
        int child = currentSize - 1;
        int parent = getParent(child);

        while(data[child]>data[parent && child >=0 && parent >=0])
        {
            T temp = data[child];
            data[child]=data[parent];
            data[parent]=temp;
            parent = getParent(child);
        }

    }
    void bubbleDown()
    {
        int parent = 0;
        while(1)
        {
            int left = getLeftChild(parent);
            int right = getRightChild(parent);
            int largest = parent;
            if(left < currentSize && data[left]>data[largest])
            {
                largest = left;
            }
            if(right<currentSize && data[right]>data[largest])
            {
                largest = right;
            }
            if(largest != parent)
            {
                int t = largest;
                largest = parent;
                parent = t;

                parent = largest;
            }
            else
                break;
        }
    }

    int getLeftChild(int parent){return 2*parent+1;}
    int getRightChild(int parent){return 2*parent+2;}
    int getParent(int child)
    {
        if (child%2==0)
        {
            return (child/2)-1;
        }
        return child/2;
    }
    void swap(int child, int parent)
    {
        T temp;
        temp = data[child];
        data[child]=data[parent];
        data[parent]=temp;
    }

public:
    MaxHeap(int c)
    {
        capacity = c;
        currentSize = 0;
    }
    void Insert(T a)
    {
        currentSize++;
        data[currentSize-1]=a;
        bubbleUp();
    }
    T DeleteMax()
    {
        int child = currentSize-1;

        T value = data[child];
        currentSize--;
        bubbleDown();


    }
    int getSize()
    {
        return currentSize;
    }

    void heapify(JobNode arr[], int , int);

};

void  heapify(JobNode arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] < arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] < arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void HeapSort(JobNode *arr, int n)
{

    // Build heap (rearrange array)
       for (int i = n / 2 - 1; i >= 0; i--)
           heapify(arr, n, i);

       // One by one extract an element from heap
       for (int i = n - 1; i >= 0; i--) {
           // Move current root to end
           swap(arr[0], arr[i]);

           // call max heapify on the reduced heap
           heapify(arr, i, 0);
       }
}



void LPT(JobNode a[], int n, int m)
{

    if(n<=m)
    {
        cout<<"Schedule one job per machine.. "<<endl;
        return;
    }
    HeapSort(a,n);
    MinHeap<MachineNode> H(m);
    MachineNode x;
    for(int i = 0; i<m; i++)
    {
        x.avail = 0;
        x.ID = i+1;
        H.Insert(x);
    }
    for(int i = 0; i<n; i++)
    {

       MachineNode k= H.DeleteMin();//get first free machine
        cout<<"Schedule Job "<<a[i].ID<<" on machine "<<k.ID
           <<" from "<<k.avail <<" minutes to "<<k.avail + a[i].time <<" minutes"<<endl;
        k.avail +=a[i].time;
                H.Insert(k);
    }
}



#endif // HEAP_H
