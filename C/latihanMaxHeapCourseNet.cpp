#include<stdio.h>
int count = 0;
struct participantData {
	
	int priorityMaxHeap[100];
	long long int studentID;
	char studentName[11];
};

participantData participantDatas[30];

int getParentIndex(int index) {
	
	return index/2;
}

int getLeftChildParentIndex(int index) {
	
	return index*2;
}

int getRightChildParentIndex(int index) {
	
	return index*2+1;
}

void menu() {
	printf("\n");
	printf("Menu\n");
	printf("1. Add Student to queue\n");
	printf("2. Call Student from queue\n");
	printf("3. Exit\n");
}

void upheapmax( int index) {
	
	int parent = getLeftChildParentIndex(index);
	
	if ( participantDatas[count].priorityMaxHeap[index] > participantDatas[count].priorityMaxHeap[parent]){
		
		int temp = participantDatas[count].priorityMaxHeap[index];
		participantDatas[count].priorityMaxHeap[index] = participantDatas[count].priorityMaxHeap[parent];
		participantDatas[count].priorityMaxHeap[parent] = temp;
		
		upheapmax(participantDatas[count].priorityMaxHeap[parent]);
	}
		
}

void view() {
	
	for ( int i = 0; i <= count; i++) {
		printf("%d\t%s\t%d\n",participantDatas[i].studentID,participantDatas[i].studentName
		,participantDatas[i].priorityMaxHeap[i]);
	}
}

void push(int value) {
	
	count++;
	
	participantDatas[count].priorityMaxHeap[count] = value;
	
	upheapmax(count);
}

void callStudent() {
	
	
	
}

void addStudentData() {
	
	int priorityHeapMax;

	printf("Input student ID [10 digit] : ");
	scanf("%lld",&participantDatas[count].studentID);
	
	printf("Input Name : ");
	scanf("%s",participantDatas[count].studentName);
	
	printf("Input MaxHeapQueue : ");
	scanf("%d",&priorityHeapMax);
	
	push(priorityHeapMax);
}

int main() {
	
	int chooseMenu = 0;
	
	do
	{	
		view();
		do
		{
			menu();
			printf("choose menu : ");
			scanf("%d",&chooseMenu);
		} while ( chooseMenu < 1 || chooseMenu > 3);
		
		switch(chooseMenu) {
			case 1 : {
				addStudentData();
				break;
			}
			
			case 2 : {
				callStudent();
				break;
			}
			
			case 3 : {
				printf("Exit");
				break;
			}
		}
	} while ( chooseMenu != 3);

	
	
	
	return 0;
}
