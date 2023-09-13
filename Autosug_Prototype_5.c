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
        //printf("\nEnter a letter: ");
        size=0;
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


int check(char word[20], char x[30][5], int n)
{
   bool flag;
   int i;
   flag = false;
   for(i=0; i<n; i++)
   {
     if(strcmp(x[i], word) == 0)
     {
       flag = true;
     }
   }
   return flag;
}

void sort(char** names, int n)
{
	int i, j;

	// Perform sort operation using bubble sort
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (strcmp(names[j], names[j + 1]) > 0) {
				char* temp;
				temp = (char*)calloc(30, sizeof(char));
				strcpy(temp, names[j]);
				strcpy(names[j], names[j + 1]);
				strcpy(names[j + 1], temp);
			}
}
int checkempty(char x[30][5], int n)
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


int main()
{
  char x[50][20];
  char sent[15][20];
  bool flag, flag1, emptyflag, f=false;
  int flag2 = 0;
  char temp[20];
  int emptyindex, i, j, opt, m, k=0;
  int o; //FOR CONTINUE FUNCTION
  int opt1,lc,i1;
 	char word[5],fi,s,t,fo;
	bool flag3=false,f1,f2,f3,f4=false;
  flag = false;
  flag1 = true;
  printf("Enter dictionary of words of your choice!!!\n");
  for(i=0; i<3; i++) //Instead of 30 3 for example
  {
    fgets(x[i], 100, stdin);
  }
  printf("Words are\n");
  for(i=0; i<3; i++) //Instead of 30 3 for example
  {
    printf("%s", x[i]);
  }
  int  n = 3;
  m = 0;
  while(flag1==true)
  {
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
    strcpy(sent[m], word);
    m = m +1;
    //FUNCTION TO CHECK IF THE WORD ALREADY EXSISTS IN THE Dictionary
    flag = check(word,x,n);
    if(flag == false)
    {
      printf("Do you want to add the word to the dictionary?\n");
      printf("1 for YES 2 for NO\n");
      scanf("%d", &opt);
      //FUNCTION TO CHECK IF THERE ARE EMPTY SPACES AVAILABLE IN THE Dictionary
      emptyflag = checkempty(x,n);
      if(emptyflag == true)
      {
        if(opt == 1)
        {
          while(flag2 == 0 && k<n)
          {
            if(x[k] == "\0")
            {
              flag2 = 1;
            }
            else
            {
              k = k +1;
            }
          }
          strcpy(x[k], word);
          printf("Word added to the dictionary successfully!\n");
          //SORTING THE DICTIONARY
          sort(x , n);

        }
        else
        {
          if(opt == 2)
          {
            printf("INVALID OPTION!!!\n");
          }
          else
          {
            continue;
          }
        }
      }
      else
      {
        printf("No more emptyspaces left :(\n");
      }
      printf("Do you want to move to the next word?\n");
      printf("1 for YES 2 for NO\n");
      scanf("%d", &o);
      while(o != 1 && o != 2)
      {
        printf("Enter a valid option:\n");
        scanf("%d", &o);
      }
      if(o == 1)
      {
        continue;
      }
      else
      {
        f = false;
      }

      flag1 = f;
    }
    else
    {
      printf("Do you want to move to the next word?\n");
      printf("1 for YES 2 for NO\n");
      scanf("%d", &o);
      while(o != 1 && o != 2)
      {
        printf("Enter a valid option:\n");
        scanf("%d", &o);
      }
      if(o == 1)
      {
        flag1 = true;
      }
      else
      {
        flag1 = false;
      }

    }
  } //out of while loop



  return 0;
}
