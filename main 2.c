//
//  main.c
//  practice
//
//  Created by 黃玄堯 on 2016/6/2.
//  Copyright © 2016年 黃玄堯. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define k 3       // 定義一個Len以方便修改數字

int Largest_function(int a[],int length)  //function用來找最大
{
    int Largest=a[0];  //令最大的數Largest是a[0]
    int i;
    for(i=0;i<length;i++)
    {
        if(a[i]>=Largest)//如果有一個數大於等於Largest
        {
            Largest=a[i];//Largest就等於它
        }
    }
    return Largest;  //回傳Largest
}

int Average_function(int a[],int length)//function用來找平均
{
    int all=0,average;  //先令all=0用來計算陣列總和
    int i;
    for(i=0;i<length;i++)
    {
        all=all+a[i];    //用for迴圈加總
    }
    average=all/length;  //總值除於length即是平均
    return average; //回傳
}

int Positive_function(int a[],int length)//function用來找正數的數量
{
    int i,sum=0;
    for(i=0;i<length;i++)//用迴圈偵測
    {
        if(a[i]>0)//如果有一個a[i]大於0
        {
            sum=sum+1;//就+1
        }
    }
    return sum;
}




int main()
{
    int a[k];
    int i;
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);/*任意輸入值*/
    }
    printf("Largest:%d\n",Largest_function(a,k));
    printf("Average:%d\n",Average_function(a,k));
    printf("the number of positive elements:%d\n",Positive_function(a,k));
    
    return 0;
}