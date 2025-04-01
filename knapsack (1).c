#include <stdio.h>
int main(){
    float weight[50],profit[50],ratio[50],total=0,capacity,temp;
    int n,i,j;
    printf("enter no.of items:");
    scanf("%d",&n);
    printf("enter weights;");
    for(i=0;i<n;i++){
        scanf("%f",&weight[i]);
    }
    printf("enter profit:");
    for(i=0;i<n;i++)
        scanf("%f",&profit[i]);
    printf("enter capacity;");
    scanf("%f",&capacity);

    for(i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(ratio[i]<ratio[j]){
                    temp=ratio[i];
                    ratio[i]=ratio[j];
                    ratio[j]=temp;

                    temp=weight[i];
                    weight[i]=weight[j];
                    weight[j]=temp;

                    temp=profit[i];
                    profit[i]=profit[j];
                    profit[j]=temp;

            }
        }
    }
    for(i=0;i<n;i++){
        if(weight[i]<=capacity){
            total+=profit[i];
            capacity-=weight[i];
        }
        else{
            total+=ratio[i]*capacity;
            break;
        }
    }
    printf("%.2f",total);
}
