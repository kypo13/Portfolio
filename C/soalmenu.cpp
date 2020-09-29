#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{
	int menu,a,b,c,d,i,j;
	char studentId[25][25];
	char studentName[50][50];
	char studentMark[10][10];
	int total;
	int update;
	do{
	system("CLS");
	printf("Student Mark List\n");
	printf("1. Input Student\n");
	printf("2. See All Data\n");
	printf("3. Edit Data\n");
	printf("4. Exit\n");
	printf("Choose :\n");scanf("%d",&menu);
	switch(menu){
		case 1:
			do{
			printf("How many students[1-5]:");
			scanf("%d",&total);
			}while (total<1||total>5);
			printf("Please input %d data\n",total);
			for (i=0;i<total;i++){
				do{
				printf("Please input student id:");
				scanf("%s",&studentId[i]);fflush(stdin);
				}while (strlen(studentId[i])!=10);
				
				do{
				printf("Please input name:");
				scanf("%s",&studentName[i]);
				}while(strlen(studentName[i])<5||strlen(studentName[i])>20);
				printf("Please input mark:");
				scanf("%s",&studentMark[i]);
				printf("\n\n\n");

			}
			getchar();
			break;
		case 2:
			if (total==0)printf("No Data");
			else{
			for (i=0;i<total;i++){
				printf("ID:%s\n",studentId[i]);
				printf("Name:%s\n",studentName[i]);
				printf("Mark:%s\n",studentMark[i]);
				printf("\n\n");
			}
		}	
			getchar();
			getchar();
			break;
		case 3:
			printf("Input student[1-%d]: ",total);
			scanf("%d",&update);
			update--;
			printf("Student with number %d is\n",update);
			printf("ID:%s\n",studentId[update]);
			printf("Name:%s\n",studentName[update]);
			printf("Mark:%s\n",studentMark[update]);
			printf("\n\n");
			
				printf("Please input student id:");
				scanf("%s",&studentId[update]);
				printf("Please input name:");
				scanf("%s",&studentName[update]);
				printf("Please input mark:");
				scanf("%s",&studentMark[update]);
				printf("Sukses update");
				getchar();
				getchar();
			break;
		
	}
}while(menu!=4);
	printf("Terima Kasih");
	
	return 0;
}
