#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* addatbeg(struct node* start){
	struct node* temp;
	int val;
	printf("Enter value : ");
	scanf("%d",&val);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=start;
	start=temp;
	return start;
}
void addatend(struct node* start){
	struct node* p;
	struct node* end;
	int v;
	p=start;
	while(p->next!=NULL){
		p=p->next;
	}
	printf("Enter the value : ");
	scanf("%d",&v);
	end=(struct node*)malloc(sizeof(struct node));
	end->data=v;
	p->next=end;
	end->next=NULL;
}

void addafter(struct node* start,int val){
	struct node *ptr,*temp;
	struct node* preptr;
	int v;
	printf("Enter the value : ");
	scanf("%d",&v);
	
    temp=(struct node*)malloc(sizeof(struct node));
	ptr=preptr=start;
	while(preptr->data!=val){
        preptr=ptr;
		ptr=ptr->next;
	}
	temp->data=v;
	preptr->next=temp;
	temp->next=ptr;
}

void addbefore(struct node* start,int val){
	struct node *ptr,*temp;
	struct node* preptr;
	int v;
	printf("Enter the value : ");
	scanf("%d",&v);
	
    temp=(struct node*)malloc(sizeof(struct node));
	ptr=preptr=start;
	while(ptr->data!=val){
        preptr=ptr;
		ptr=ptr->next;
	}
	temp->data=v;
	preptr->next=temp;
	temp->next=ptr;
}

void deleteafter(struct node* start,int val){
	struct node *ptr;
	struct node* preptr;
	ptr=preptr=start;
	while(preptr->data!=val){
        preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}

void deletebefore(struct node* start,int val){
	struct node *ptr;
	struct node* preptr;
	ptr=preptr=start;
	while(ptr->next->data!=val){
        preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}

struct node* deletefirst(struct node* start){
	struct node* temp=start;
	start=start->next;
	free(temp);
	return start;
}
void deletelast(struct node* start){
	struct node* preptr,*ptr;
	ptr=preptr=start;
	while(ptr->next!=NULL){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
}

void printlist(struct node* start){
	struct node* p;
	p=start;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
struct node* insert(struct node* start){
	int n,i;
	char c;
	if(start==NULL){
		printf("Enter start value :- \n");
		start=addatbeg(start);
		printf("Do you want to enter more elements (y or n) : ");
		scanf("%s",&c);
		if(c=='y'){
			insert(start);
		}
	}
	else{
		printf("How many elements do you want to enter : ");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			addatend(start);
		}
	}
	return start;
}

struct node* create(struct node* start){
	int c;
	printf("Enter start value :- \n");
	start=addatbeg(start);
	printf("Do you want to enter more elements (y or n) : ");
	scanf("%s",&c);
	if(c=='y'){
		insert(start);
	}
	return start;
}
 void search(struct node* start,int val){
    struct node* p;
	p=start;
	while(p!=NULL){
		if (p->data==val)
        {
            printf("\nElement found\n");
            break;
        }
		p=p->next;
	}
    if(p==NULL){
        printf("\nElement not found\n");
    }


 }


int main(){
	int choice,val;
	struct node *start=NULL;
	while(1){
	printf("\nOperations : \n");
	printf("\t1. Create a List \n");
	printf("\t2. Display List \n");
	printf("\t3. Search an Element \n");
	printf("\t4. Insert an element at the beg :  \n");
	printf("\t5. Insert an element at the end :  \n");
	printf("\t6. Insert an element after an element :  \n");
	printf("\t7. Insert an element before an element :  \n");
	printf("\t8. Delete an element after an element :  \n");
	printf("\t9. Delete an element before an element :  \n");
	printf("\t10. Delete first element in the List \n");
    printf("\t11. Delete last element in the List \n");
	printf("\t12. Quit \n");
	printf("Enter the choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nCreating a List - \n");
			start=create(start);
			break;
		case 2:
			printf("\nLinked List -\n");
			printlist(start);
			break;
        case 3:
            printf("Enter the value you want to search : ");
            scanf("%d",&val);
            search(start,val);
            break;
        case 4:
            start=addatbeg(start);
            break;
        case 5:
            addatend(start);
            break;
        case 6:
            printf("Enter the element after you want to insert : ");
	        scanf("%d",&val);
            addafter(start,val);
            break;
        case 7:
            printf("Enter the element before you want to insert : ");
	        scanf("%d",&val);
            addbefore(start,val);
            break;
        case 8:
	        if(start==NULL){
	        	printf("\nList is empty\n");
			}
			else{
				printf("Enter the element after you want to delete : ");
	        	scanf("%d",&val);
				deleteafter(start,val);
			}
			break;
		case 9:
	        if(start==NULL){
	        	printf("\nList is empty\n");
			}
			else{
				printf("Enter the element before you want to delete : ");
	        	scanf("%d",&val);
				deletebefore(start,val);
			}
			break;
		case 10:
			if(start==NULL){
	        	printf("\nList is empty\n");
			}
			else{
				start=deletefirst(start);
			}
			break;
		case 11:
			if(start==NULL){
	        	printf("\nList is empty\n");
			}
			else{
				deletelast(start);
			}
			break;

		case 12:
			exit(1);
	}
}
	return 0;
}
