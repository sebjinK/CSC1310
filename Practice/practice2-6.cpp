#include <iostream>

using namespace std;

int main()
{      
    /*
    Bubble sort - 

    unsorted set
    16 72 56 87 65

    will compare the first 2 #s in the set and if the largest one is on the left ex. [72 56]
    then it will switch those two nums [72 56] => [56 72]
    will then compare the # on the left with the next num in the set [72 87]
    if the num on the right is lower than the num on the left then the bubble chooses the bigger num 
    [72 87] => [72 87 65] => [72 65 87] 

    this will repeated until the list is sorted
    [16 56 72 65 87]
    => [72 65] => [65 72]

    Os of bubble sort
    Best case: O(n)
    Avg case: O(n^2)
    Worst case: O(n^2)
    space compexity : O(1)
    */
   int temp;
   const int size = 10;
   int arr[size];
   bool swapped = false;
do//bubble array example
{
    swapped = false;
   for (int j = 0; j <= size; j++)
   {
        if (arr[j] > arr[j + 1])//if [72] is the first element that is compared
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapped = true;
        }
        else if(arr[j] )

   }
} while (!swapped);
   

   /*
   selection sort - 
   repeatedly searches the remaining unsorted data
   finds the samllest data and moves it to  the correct
   position
   */

    return 0;
}