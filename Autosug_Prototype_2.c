#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char input()
{
    int i,size=0;
    char c,l[50];
    int f;
    do{
        //printf("\nEnter a letter: ");
        size=0;
        fflush(stdin);
        fgets(l,50,stdin);
        for(i=0;l[i]!='\0';i++){
            size++;
        }
        size-=1;
        //printf("size:%d\n",size);
        //printf("string:%s\n ",l);
        if(size==1){
            c=l[0];
            //printf("char: %c \n",c);
            if((c>= 'a' && c<='z') || (c>='A' && c<='Z')){
                f=1;
                //break;
            }
            else{
                printf("Enter an alphabet: ");
            }
        }
        else{
            printf("Enter one character: ");
            f=0;
        }
    }while(f==0);
    return c;
}

 int main(){
 	char x[20][5]={"aaaa","aabb","bbbb","bbcc","cccc"};
 	int n=5,opt,lc,i;
 	char word[5],f,s,t,fo;
	bool flag=false,f1,f2,f3,f4=false;
	while(flag==false){
		printf("Enter the first letter: ");
		fflush(stdin);
		f=input();
		f1=false;
		for(i=0;i<n;i++){
			if(x[i][0]==f){
				printf("%d : %s\n",i+1,x[i]);
				f1=true;
			}
		}
		if(f1==true){
			printf("0 : none of the above\nChoose the option:");
			scanf("%d",&opt);
			if(opt==0){
				printf("Enter the second letter: ");
				s=input();
				f2=false;
				for(i=0;i<n;i++){
					if(x[i][0]==f && x[i][1]==s){
					printf("%d : %s\n",i+1,x[i]);
					f2=true;
					}
				}
				if(f2==true){
					printf("0 : none of the above\nChoose the option:");
					scanf("%d",&opt);
					if(opt==0){
						printf("Enter the third letter: ");
						t=input();
						f3=false;
						for(i=0;i<n;i++){
							if(x[i][0]==f && x[i][1]==s && x[i][2]==t){
								printf("%d : %s\n",i+1,x[i]);
								f3=true;
							}
						}
						if(f3==true){
							printf("0 : none of the above\nChoose the option:");
							scanf("%d",&opt);
							if(opt==0){
								printf("Enter the fourth letter: ");
								fo=input();
								f4=false;
								for(i=0;i<n;i++){
									if(x[i][0]==f && x[i][1]==s && x[i][2]==t && x[i][3]==fo){
										printf("%d : %s\n",i+1,x[i]);
										f4=true;
									}
								}
							}
							else{
								printf("The word is %s.",s[opt-1]);
								strcpy(word,x[opt-1]);
								f4=true;
							}
						}
						else{
							lc=3;
						}
					}
					else{
						printf("The word is %s.",x[opt-1]);
						strcpy(word,x[opt-1]);
						f4=true;
					}
				}
				else{
					lc=2;
				}
			}
			else{
				printf("The word is %s.",x[opt-1]);
				strcpy(word,x[opt-1]);
				f4=true;
			}
		}
		else{
			lc=1;
		}
		flag=true;
	}
	
	return 0;
 }
