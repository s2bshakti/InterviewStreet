#include<stdio.h>
#include<malloc.h>
int find_median();
int ins_sort(char,int);
struct node{
	int data;
	struct node *next;
}*head,*temp,*ptr,*ptr1;
int main()
{
	head='\0';
	int no_opr,val,count=0,median,output[100000],var,i;
	char opr;
	scanf("%d",&no_opr);
	//printf("F1");
	for(i=0;i<no_opr;i++)
	{
		scanf("%c%d",&opr,&val);
		printf("F3");
		if(opr=='r'&&head=='\0')
		{output[i]=0;
		printf("F2");}
		else 
		{
			var=ins_sort(opr,val);
			if(var==0)
			{
				output[i]=0;		
			}		
			else
			{
				median=find_median();
				output[i]=median;			
			}		
		}
	}
	for(i=0;i<no_opr;i++)
	{
		output[i]==0?printf("Wrong"):printf("%d",output[i]);	
	}
return 0;
}
int ins_sort(char opr,int val)
{
	if(opr=='a')
	{
		if(head=='\0')
		{		
			temp=(struct node*)malloc(sizeof (struct node));
			temp->data=val;
			temp->next='\0';		
			head=temp;
		}
		else
		{
			ptr=head;
			if(ptr->data<=val)
			{
				while(ptr->data<=val&&ptr->next!='\0')
				{
					ptr=ptr->next;
				}						
				temp=(struct node*)malloc(sizeof (struct node));
				ptr->next=temp;
				temp->next='\0';
				temp->data=val;
			}
			else
			{
				temp=(struct node*)malloc(sizeof (struct node));
				temp->data=val;
				temp->next=head;
				head=temp;
			}		
		}
	}
	else
	{
		ptr=head;
		ptr1=head;
		while(ptr->next!='\0')
		{
			if(ptr->data==val)
			break;
			else
			ptr=ptr->next;					
		}
		while(ptr1->next!=ptr)
		ptr1=ptr1->next;
		if(ptr->next=='\0')
			return 0;
		else	
			ptr1->next=ptr->next;				
	}	
}
int find_median()
{
	int median,count=1,num,pivot,a,b;
	ptr=head;
	while(ptr->next!='\0')
	{
		count++;	
	}
	num=count%2;
	if(num==0)
	{
		ptr=head;
		pivot=count/2;
		while(pivot>1)
		{
			ptr=ptr->next;
			pivot--;		
		}
		a=ptr->data;
		ptr=ptr->next;
		b=ptr->data;
		median=(a+b)/2;		
		return median;	
	}
	else
	{
		ptr=head;
		pivot=count/2;
		while(pivot>0)
		{
			ptr=ptr->next;
			pivot--;					
		}
		median=ptr->data;	
		return median;
	}
}
