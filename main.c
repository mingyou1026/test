//
//  main.c
//  do it now
//
//  Created by 黃玄堯 on 2016/6/15.
//  Copyright © 2016年 黃玄堯. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct{
    char pass[20];     //定義陣列名稱為UserInfo
    char name[20];
}UserInfo;

char *remove_endline(char *ptr)//尋找字串ptr第一次出現\n的地方，將其替換成\0當成字串結尾
{
    char *t;
    if ((t=strchr(ptr, '\n')) != NULL) //EZ way
         *t = '\0';
    return ptr;
}


int main()
{
    FILE * pFile = NULL;//讀檔用
    UserInfo *head = NULL,tmp;//userinfo陣列，tmp一個userinfo暫存用
    int UserNum = 0;//減一
    
    int mode;
    int i;
    
    char user_input[200];
    
    pFile = fopen("login.bin","rb");//開檔準備讀取
    //try to load file
    if( pFile ){
        while( fread(&tmp,sizeof(tmp),1,pFile) ){            //讀出後會自動地將檔案系統指標 stream 增加 count*size bytes 為新指標位置
            head = realloc(head,++UserNum*sizeof(UserInfo)); //realloc()的做法是在新的位置宣告好記憶體位置後
                                                             //把ptr裡的東西都複製到新的記憶體位置然後回傳新的記憶體位置
            memcpy(&head[UserNum-1],&tmp,sizeof(UserInfo));  //会复制 src 所指的内存内容的前 num 个字节到 dest 所指的内存地址上。

            UserNum++;
        }
    }
    while(true){
        puts("1)Reg");
        puts("2)Login");
        scanf("%d%*c",&mode);
        
        if( mode == 1 ){
            memset(&tmp,0,sizeof(tmp));//均改成同位元０
            printf("Reg Name:");
            fgets(tmp.name,20,stdin);//從鍵盤輸入字串到tmp.name
            remove_endline(tmp.name);
            printf("Reg Pass:");
            fgets(tmp.pass,20,stdin);
            remove_endline(tmp.pass);
            
            //Check etc...
            head = realloc(head,++UserNum*sizeof(UserInfo));//分配記憶體空間，將head指標指向起始位置
            memcpy(&head[UserNum-1],&tmp,sizeof(UserInfo));//將tmp的內容複製到head裡
            
            pFile = fopen("login.bin","ab");//開啟檔案準備寫入
            fwrite(&tmp,sizeof(tmp),1,pFile);//寫入檔案
            fclose(pFile);//把檔案關閉
        }else if(mode == 2){
            printf("Name:");
            fgets(user_input,200,stdin);
            remove_endline(user_input);
            for(i=0;i<UserNum;++i)
                if(strcmp(head[i].name,user_input)==0)//比對兩個字串
                    break;
            
            if( i==UserNum ){
                puts("No Such User");
            }else{
                printf("Pass:");
                fgets(user_input,200,stdin);
                remove_endline(user_input);
                if(strcmp(head[i].pass,user_input)==0){
                    puts("Login!");
                }else{
                    puts("ERROR PASS!");
                }
            }
        }else{
            puts("??");
        }
    }
    
}