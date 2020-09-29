#include<stdio.h>
#include<string.h>

int count=0;

struct Student{
	char studentid[100];
	char nama[100];
	int priority;
}data[100];

void downheap(int index){
	int currentindex=index;
	struct Student currentvalue=data[index];
	
	if(2*index<count && currentvalue.priority<data[2*index].priority && data[2*index].priority > data[2*index+1].priority){
		currentindex=2*index;
		currentvalue=data[2*index];		
	}
	else if(2*index+1<count && currentvalue.priority<data[2*index+1].priority && data[2*index].priority < data[2*index+1].priority){
		currentindex=2*index+1;
		currentvalue=data[2*index+1];		
	}
	else if(currentindex==index)return;
	
	struct Student temp = data[index];
	data[index]=data[currentindex];
	data[currentindex]=temp;
}

struct Student callstudent(){
	if(count==1){
		count--;
		return data[1];
	}	
	struct Student rootvalue=data[1];
	data[1]=data[count];
	count--;
	downheap(1);
	
	return rootvalue;
}

void insert(struct Student student){
	count++;
	data[count]=student;
	
	int currindex=count;
	while(currindex!=1 && data[currindex/2].priority<data[currindex].priority){
		struct Student temp=data[currindex];
		data[currindex]=data[currindex/2];
		data[currindex/2]=temp;
		currindex=currindex/2;
	}
}

void printall(){
	for(int i=1;i<=count;i++){
		printf("%s %d\n",data[i].nama,data[i].priority);
	}
}
int main()
{
	struct Student t;
	strcpy(t.nama,"Jonathan");
	strcpy(t.studentid,"01");
	t.priority=90;
	insert(t);
	strcpy(t.nama,"Jonathan");
	strcpy(t.studentid,"01");
	t.priority=10;
	insert(t);
	strcpy(t.nama,"Jonathan");
	strcpy(t.studentid,"01");
	t.priority=1000;
	insert(t);
	printall();
	return 0;
}
