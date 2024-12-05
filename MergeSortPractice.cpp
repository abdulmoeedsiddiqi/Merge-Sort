#include<iostream>
using namespace std;


void conquer(int arr[] , int s , int mid , int e) {
    int n1 = mid - s + 1 , n2 = e - mid ; 
    int* first = new int[n1];
    int* second = new int[n2];
     for ( int i = 0 ; i < n1 ; i++){
        first[i] = arr[s+i];
     }

     for ( int i = 0 ; i < n2 ; i++){
        second[i] = arr[mid+1+i ];
     }

    int i = 0 , j = 0 , k = s ; 
     while(i < n1  && j  < n2 ){
        if( first[i] <  second[j] ){
            arr[k++] = first[i++] ; 
        }
        else{
              arr[k++] = second[j++] ;
        }
     }


     while( i < n1 ){
        arr[k++] = first[i++] ; 
     }

     while( j < n2 ){
        arr[k++] = second[j++] ; 
     }
}
void divide(int arr[] , int s  , int e) {
    if (s >= e) return ; 
    int mid = s + ( e - s ) / 2 ; 
    divide(arr , s , mid ) ; 
    divide(arr , mid + 1 , e) ;
    conquer(arr , s , mid , e); 

}

void show(int arr[] , int n ){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ; 
}
int main()
{
    int arr[] = { 1 , 9 , 8, 4, 3 ,10} ;
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr,  0 , n-1 ) ; 
    show(arr , n) ; 
    return 0;
}