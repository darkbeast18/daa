#include<stdio.h>
void minmax(int arr[],int i,int j,int *min,int *max){
    if(i==j){
        *min=*max=arr[i];
    }
    else if (i==j-1){
        if(arr[i]<arr[j]){
            *min=arr[i];
            *max=arr[j];
        }
        else{
            *min=arr[j];
            *max=arr[i];
        }
    }
    else{
        int mid=(i+j)/2;
        int min1,min2,max1,max2;
        minmax(arr,i,mid,&min1,&max1);
        minmax(arr,mid+1,j,&min2,&max2);
        *min=(min1<min2)?min1:min2;
        *max=(max1>max2)?max1:max2;
    }
}
int main(){
    int n;
    printf("enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("enter ele:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int mini,maxi;
    minmax(arr,0,n-1,&mini,&maxi);
    printf("%d\n",mini);
    printf("%d",maxi);
}
