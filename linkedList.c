#include <stdio.h>

struct linknode{
	int data;
	//void* next;
	linknode* next;
};


static struct linknode *list=NULL;


struct linknode *create_node(int value) {
	
	struct linknode* ptr;
	
	ptr = (struct linknode*)malloc(sizeof(struct linknode));
	if (ptr !== NULL) {
		ptr->data = value;
	    ptr->next = NULL;
	}
	
	return ptr;
}

int insertDataTail(int value) {
	
	linknode *nodePtr;
	linknode *srchPtr;
	
	//node create
	nodePtr = create_node(value);
	if (nodePtr == NULL)
	{
		printf("memory allocation error!\n");
		return -1;
	}
	
	//find the tail node
	if (list == NULL)
	{
		list = nodePtr;	
	}
	else
	{
		srchPtr = list;
		while(srchPtr->next != NULL) {
			srchPtr = srchPtr->next;
		}
		//linking
		srchPtr->next = nodePtr;
	}
	
	return 0;
}

void print_list(void) {
	linknode *ptr = list;
	int i;
	
	while(ptr !=NULL && ptr->next !=NULL) {
		printf("%i \n", ptr->data);
		ptr->next = ptr;
	}
}
	
void print_node(int n) {
	linknode *ptr = list;
	int i = 0;
	while (ptr !=NULL && ptr->next !=NULL) {
		if (i==n){
			printf("%i'th data : %i\n",i,ptr->data);
			return;
		}
		i++;
	}
	
	printf("no data\n");
}	
	
	
	
	
	
	

