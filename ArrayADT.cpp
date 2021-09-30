#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int length;
    int size;
}; 
void Display(struct Array arr)//display all the elements of an array 
{
    for(int i = 0; i< arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}
bool Add(struct Array *arr, int key)//add the end of array 
{
    if(arr->length == arr->size)
        return false;
    else
    {
        arr->A[arr->length++] = key;
        return true;
    }
}
bool Insert(struct Array * arr, int key, int position)//insert to the specific position.
{
    if(arr->length == arr->size || position > arr->size)
        return false;
    else if(position> arr->length)
        {
          arr->A[arr->length++] = key;
          return true;
        }

    else
    {
        arr->length++;
        for(int i = arr->length+1; i>=position; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[position] = key;
        return true;
    }
}

int main()
{
    struct Array arr;
    cout << "Enter the size of your array" << endl;
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    bool flag = true;
    char answer = 'Y';
    cout<<"Enter all the elements"<<endl;
    while(arr.length < arr.size && flag)
    {
        cout<<"Do you want to enter your element Y/N"<<endl;
        cin>>answer;
        if(answer == 'N' || answer == 'n')
            flag = false;
        else
        {
            cout<<"Entre your number: ";
            cin>>arr.A[arr.length++];
        }
    }
    cout<<"Array contains of these elements"<<endl;
    Display(arr);
    cout<<"Add 222 to the end of array"<<endl;
    Add(&arr, 222);
    cout<<"Array contains of these elements"<<endl;
    Display(arr);
    cout<<"Insert 666 into position 3"<<endl;
    Insert(&arr, 666, 3);
    Display(arr);


}