#include<stdio.h>
#include<stdbool.h>

int main(){
	char a[10][10]={"sanj","bald","hell","bood"},ch,word[10];
	int i,opt,m=0;
	bool flag=false,f1=false;
	while (flag==false){
		printf("Enter ch: ");
		scanf("%c",&ch);
		for(i=0;i<4;i++){
			if(a[i][0]==ch){
				printf("%d : %s\n",i+1,a[i]);
				f1=true;
			}
		}
		
		
		if(f1==true){
			printf("0 : none of the above\n enter option : ");
			scanf("%d",&opt);
			if(opt==0){
				word[m++]=ch;
				printf("Enter ch: ");
				scanf("%c",&ch);
				for(i=0;i<4;i++){
					if(a[i][0]==word[0]&&a[i][1]==ch){
						printf("%d : %s\n",i+1,a[i]);
						f1=true;
					}
				}
			}
			
		}
	}
	return 0;
}