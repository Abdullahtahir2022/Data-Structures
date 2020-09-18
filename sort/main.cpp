#include<iostream>
using namespace std;



void insertion(int *array,int n)
{
    int d,s;
    for(int i=0;i<n;i++)
    {
s=i;

    while(i>=0)
    {

      if(array[i]>array[i+1])
      {
         d=array[i];
         array[i]=array[i+1];
         array[i+1]=d;
      }
      i--;

    }
i=s;

    }

}


void insertion1(int *array,int n)
{
int d;
    for(int i=n-1;i>0;i--)
    {




      if(array[i]<array[i-1])
      {
         d=array[i];
         array[i]=array[i-1];
         array[i-1]=d;
      }




    }

}




void insertionsort(int *array,int n)
{

for(int i=1;i<=n;i++)
{
insertion1(array,i);
}

}



void movmin(int *array, int n, int index)
{


int i,a=array[index];

for(int l=index;l<n;l++)
{

    if(a>array[l+1])
    {
        a=array[l+1];
        i=l+1;

    }




}
int b=array[index];
 array[index]=a;
 array[i]=b;


}



void movminsort(int *array,int n)
{

for(int i=0;i<n-1;i++)
{
movmin(array,n,i);

}

}



void merge(int *array1,int *array2,int *array3, int n)
{
    int index1=0;
    int index2=0;
    int index3=0;

    while(index3<n)
    {


    if(array1[index1]<array2[index2])
    {
        array3[index3]=array1[index1];
        index1++;
        index3++;
    }
    if(array1[index1]>array2[index2])
    {
        array3[index3]=array2[index2];
        index2++;
        index3++;
    }


    }




}


void display1(int array3[],int n)
{

        for(int a=0;a<n;a++)
    {
        cout << array3[a] << endl;
    }

}




void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


































void disp(int *array,int n)
{
    for(int i=0;i<n;i++)
    {
        cout << array[i] << endl;
    }
}


int main()
{  //Task3
   /* int array[6]={78,54,22,44,11,23};
    insertion(array,6);
    disp(array,6);*/
//task 2
    /*int array[6]={1,22,21,15,89,0};
    insertionsort(array,6);
    disp(array,6);*/
//task 4
    /*int array[6]={1,22,21,89,15,0};
    movminsort(array,6);
    disp(array,6);*/
//task 5
    /*int array2[]={1,3};
   int array1[]={5,10};
   int s2=sizeof(array2)/sizeof(array2[0]);
   int s1=sizeof(array1)/sizeof(array1[0]);
   int array3[s1+s2];
   int s3=sizeof(array3)/sizeof(array3[0]);


   merge(array1,array2,array3,s3);
   display1(array3,s3);*/

// task 6
/*int array[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(array)/sizeof(array[0]);

    mergeSort(array, 0, arr_size - 1);


    disp(array, arr_size);
    return 0;*/









}
