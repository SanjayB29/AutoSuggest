#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


char input()
{

    int i,size=0;
    char c,l[50];
    int f;
    do{
        size=0;
        fgets(l,50,stdin);
        for(i=0;l[i]!='\0';i++){
            size++;
        }
        size-=1;
        if(size==1){
            c=l[0];
            if((c>= 'a' && c<='z') || (c>='A' && c<='Z')){
                f=1;
            }
            else{
                printf("Enter an alphabet: ");
                f=0;
            }
        }
        else{
            printf("Enter one character: ");
            f=0;
        }
    }while(f==0);

    return c;
}
void displays(char x[50][20],int n)
{
	int i,m;
	char y,z;
	y=x[0][0];
	if(!(isupper(y)))
	{
		z=toupper(y);
		x[0][0]=z;
	}
	printf("The sentence :");
	for(i=0;i<n;i++)
	{
		printf(" %s",x[i]);
	}
	printf(".");
}


int check(char word[20], char x[50][20], int n)
{
   int flag;
   int i;
   flag = 0;
   for(i=0; i<n; i++)
   {
     if(strcmp(x[i], word) == 0)
     {
       flag = 1;
     }
   }
   return flag;
}
int cont(){
	int f,opt;
	f=1;
	do{
		printf("Do you want to move to the next word?\n1.Yes\n2.No\n-->");
		fflush(stdin);
		scanf("%d",&opt);		
	}while(opt!=1 && opt!=2);
	if(opt==2){
		f=0;
	}
	return f;
}

int checkempty(char x[50][20], int n)
{
      int flag;
    if(x[n-1][0] =='\0')
    {
        flag=1;
}
else{
    flag=0;
}
return flag;
}

struct hellooo
{
	char hello[20];
	char bye[20];
}hell1;

int main()
{
	FILE *fptr;
	strcpy(hell1.hello,"Welcome");
	strcpy(hell1.bye,"Thanks!");
	printf("%s\n",hell1.hello);
	system("color E5");

	char filename[100], c;
	// Open file
	fptr = fopen("text.txt", "r");
	if (fptr == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	// Read contents from file
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf ("%c", c);
		c = fgetc(fptr);
		Sleep(5);
	}

	fclose(fptr);
	printf("\n\n\n");
	system("color E0");
  char x[50][20]={"able", "acid", "aged", "also", "cast", "cats","does", "dogs", "done", "door", "funk", "grey", "grow", "jump", "jury", "just", "lack", "land", "lady", "last", "lazy", "ugly", "unit", "upon"};
  char sent[15][20];
  bool f=false;
  int emptyflag,flag1,flag2 = 0,flag;
  char temp[20];
    int  n = 49;
  int emptyindex=24, i, j, opt, m, k=0;
  int o,z; //FOR CONTINUE FUNCTION
  int opt1,lc,i1;
 	char word[5],fi,s,t,fo;
	bool flag3=false,f1,f2,f3;
  flag = false;
  flag1 = true;
  m = 0;
  while(flag1==1)
  {
  	flag3=false;
  	bool f4=false;
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
										printf("The word is %s\n",x[i1]);
										f4=true;
									}
								}
							}
							else{
								printf("The word is %s\n",x[opt1-1]);
								strcpy(word,x[opt1-1]);
								f4=true;
							}
						}
						else{
							lc=3;
						}
					}
					else{
						printf("The word is %s\n",x[opt1-1]);
						strcpy(word,x[opt1-1]);
						f4=true;
					}
				}
				else{
					lc=2;
				}
			}
			else{
				printf("The word is %s\n",x[opt1-1]);
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
		char new[4];
	int r;
	for(r=0;r<4;r++)
	{
		new[r]=word[r];
	}
		printf("The word is %s\n",new);
		strcpy(sent[m],new);
		
	}
	int q;
	char new1[4];
	for(q=0;q<4;q++)
	{
		new1[q]=word[q];
	}
	strcpy(sent[m],new1);
    m++;
    flag=check(word,x,n);
    if(flag==0){
    	do{
    		printf("Do u want to add the word to the dictionary?\n1.Yes\n2.No\n-->");
    		scanf("%d",&opt);
    		
		}
		while(opt!=1 && opt!=2);
		emptyflag=checkempty(x,n);
		if(emptyflag==1){
			if(opt==1){
			strcpy(x[emptyindex],word);
			emptyindex++;
			char s[100];
			for(i=0;i<emptyindex;i++){
      for(j=i+1;j<emptyindex;j++){
         if(strcmp(x[i],x[j])>0){
            strcpy(s,x[i]);
            strcpy(x[i],x[j]);
            strcpy(x[j],s);
         }
      }
   }
   
			printf("word added to the dictionary successfully!");
		}
		}
		else{
			printf("No more spaces!");
		}
		flag1=cont();
	}
	else{
		flag1=cont();
	}
  } //out of while loop
  displays(sent,m);
   do
  {
  	printf("\nDo you want to see the dictionary?\n1.Yes\n2.No\n-->");
  	scanf("%d",&z);
  if (z==1)
  {
  	for(i=0;i<emptyindex;i++)
  	{
  		printf("%s\n",x[i]);
	  }
	  break;
  }
  if (z==2)
  break;
  }
  while(z!=1 || z!=2);
  printf("\n%s",hell1.bye);
  return 0;
}
