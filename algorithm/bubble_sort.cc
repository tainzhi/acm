
#include <iostream>
#include <string>

using namespace std;

void bubbleSort(int array[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()  {
    int array[] = {1, 3, 4, 5, 7};
    int len = 5;
    bubbleSort(array, 5);
    for (int i = 0; array[i] != null; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
