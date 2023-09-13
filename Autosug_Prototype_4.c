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
 	int n=5,opt1,lc,i1;
 	char word[5],fi,s,t,fo;
 	
	bool flag3=false,f1,f2,f3,f4=false;
	while(flag3==false){
		printf("Enter the first letter: ");
		fflush(stdin);
		fi=input();
		f1=false;
		for(i1=0;i1<n;i1++){
			if(x[i1][0]==fi){
				printf("%d : %s\n",i1+1,x[i1]);
				f1=true;
			}
		}
		if(f1==true){
			printf("0 : none of the above\nChoose the option:");
			scanf("%d",&opt1);
			if(opt1==0){
				printf("Enter the second letter: ");
				s=input();
				f2=false;
				for(i1=0;i1<n;i1++){
					if(x[i1][0]==fi && x[i1][1]==s){
					printf("%d : %s\n",i1+1,x[i1]);
					f2=true;
					}
				}
				if(f2==true){
					printf("0 : none of the above\nChoose the option:");
					scanf("%d",&opt1);
					if(opt1==0){
						printf("Enter the third letter: ");
						t=input();
						f3=false;
						for(i1=0;i1<n;i1++){
							if(x[i1][0]==fi && x[i1][1]==s && x[i1][2]==t){
								printf("%d : %s\n",i1+1,x[i1]);
								f3=true;
							}
						}
						if(f3==true){
							printf("0 : none of the above\nChoose the option:");
							scanf("%d",&opt1);
							if(opt1==0){
								printf("Enter the fourth letter: ");
								fo=input();
								f4=false;
								for(i1=0;i1<n;i1++){
									if(x[i1][0]==fi && x[i1][1]==s && x[i1][2]==t && x[i1][3]==fo){
										printf("The word is %s",x[i1]);
										f4=true;
									}
								}
							}
							else{
								printf("The word is %s.",x[opt1-1]);
								strcpy(word,x[opt1-1]);
								f4=true;
							}
						}
						else{
							lc=3;
						}
					}
					else{
						printf("The word is %s.",x[opt1-1]);
						strcpy(word,x[opt1-1]);
						f4=true;
					}
				}
				else{
					lc=2;
				}
			}
			else{
				printf("The word is %s.",x[opt1-1]);
				strcpy(word,x[opt1-1]);
				f4=true;
			}
		}
		else{
			lc=1;
		}
		flag3=true;
	}
	if(f4==false){
		printf("No word found!!!\n");
		if(lc==1){
			printf("Enter the second letter: ");
			s=input();
			printf("Enter the third letter: ");
			t=input();
			printf("Enter the fourth letter: ");
			fo=input();
			
		}
		else{
			if(lc==2){
				printf("Enter the third letter: ");
				t=input();
				printf("Enter the fourth letter: ");
				fo=input();
			}
			else{
				if(lc==3){
					printf("Enter the fourth letter: ");
					fo=input();
				}
			}
		}
		word[0]=fi;
		word[1]=s;
		word[2]=t;
		word[3]=fo;	
		printf("The word is %s.",word);	
	}
	
//	printf("%s",word);
	
 }
