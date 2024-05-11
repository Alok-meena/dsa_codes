#include <iostream>
using namespace std;

void heapify(int heap[], int index, int n) {
    int largest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    // Check if left child exists and is greater than current node
    if (leftChild <= n && heap[leftChild] > heap[largest])
        largest = leftChild;

    // Check if right child exists and is greater than current node
    if (rightChild <= n && heap[rightChild] > heap[largest])
        largest = rightChild;

    // If largest is not the current node, swap and continue heapifying down
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(heap, largest, n);
    }
}

void deleteRandom(int arr[], int index, int &n) {
    arr[index] = arr[n];
    n--;

    // If the deleted node is not a leaf node, heapify it down because then no required to do heapfiy as it is the leaf node
    if (index * 2 <= n) {
        heapify(arr, index, n);
    }

    //instead of this heapify u can use this the following code also
    int i=1;
    int size=n;
        while(i<size){
            int leftindex=2*i;
            int rightindex=2*i+1;

            if(leftindex<size && arr[leftindex]>arr[i]){
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[rightindex]>arr[i]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }


        }
}

void print(int arr[], int n) {
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {0, 55, 54, 53, 50, 52}; // 1-indexed array representation
    print(arr, 5); // Print the original array
    int n = 5;
    deleteRandom(arr, 5, n); // Delete the element at index 1
    print(arr, 4); // Print the array after deletion
    return 0;
}
