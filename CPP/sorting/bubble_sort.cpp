#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr, int n) // Function to perform bubble sort on the vector
{
 for (int i = 0; i < n - 1; i++) // Loop for each pass
 {
  bool swapped = false; // Flag to check if any swapping occurred in this pass

  for (int j = 0; j < n - i - 1; j++) // Loop to compare adjacent elements
  {
   if (arr[j] > arr[j + 1]) // If the current element is greater than the next element
   {
    swap(arr[j], arr[j + 1]);
    swapped = true;
   }
  }
  if (swapped == false) // If no two elements were swapped in the inner loop, the array is sorted
  {
   break;
  }
 }
}

void printArray(vector<int> &arr, int n) // Function to print the elements of the vector
{
 cout << "Sorted Array ";
 for (int i = 0; i < n; i++)
 {
  cout << arr[i] << " ";
 }
}

void inputArr(vector<int> &arr)  // Function to input elements into the vector
{

 int n; 
 cout << "Enter number of elements ";
 cin >> n;
 cout << "Enter elements ";

 for (int i = 0; i < n; i++)  // Loop to read n elements
 {
  int x;
  cin >> x;
  arr.push_back(x);
 }

}

int main()
{
 vector<int> arr; // Declare a vector to hold the array elements

 inputArr(arr); // Input elements into the vector

 int n = arr.size(); // Get the size of the vector

 bubble_sort(arr, n); // Call the bubble sort function

 printArray(arr, n); // Print the sorted array
}
