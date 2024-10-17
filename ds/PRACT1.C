#include<stdio.h>
#include<conio.h>

#define max 100

int arr[max],n=0;

void add();
void del();
void mod();
void sort();
void simples();
void binarys();
void disp();

void main()
{
	int c;
	clrscr();
	do{
	   printf("\n MENU:");
	   printf("\n 1) Add Element");
	   printf("\n 2) Delete Element");
	   printf("\n 3) Modify Element");
	   printf("\n 4) Sort Element");
	   printf("\n 5) Simple search");
	   printf("\n 6) Binary Search");
	   printf("\n 7) Display Element");

	   printf("\n Enter Your choice: ");
	   scanf("%d",&c);

	   switch(c)
	   {
		case 1:add();
			break;

		case 2:del();
			break;

		case 3:mod();
			break;

		case 4:sort();
			break;

		case 5:simples();
			break;

		case 6:binarys();
			break;

		case 7:disp();
			break;
	   }

	}while(c >=1 && c<=7);
	getch();

}
void add()
{
	if(n < max)
	{
		printf("Enter the element to add: ");
		scanf("%d",&arr[n]);
		n++;
	}
	else
	{
		printf("\n Array is Full");
	}
}
void del()
{
	int pos,i;
	if(n > 0)
	{
		printf("\n Enter the position if element to delete (1 to %d): ",n);
		scanf("%d",&pos);
		if(pos>=1 && pos<=n)
		{
			for(i=pos-1; i<n-1; i++)
			{
			 arr[i]=arr[i+1];
			}
			n--;
		}
		else
		{
			printf("\n Invalid position");
		}
	}
	else
	{
		printf("\n Array is Empty");
	}
}
void mod()
{
	int pos,value;
	if(n > 0)
	{
		printf("\n Enter position of element to modify(1 to %d):",n);
		scanf("%d",&pos);
		if(pos >=1 && pos <=n)
		{
		 printf("\n Enter new value: ");
		 scanf("%d",&value);
		 arr[pos - 1] = value;
		}
		else
		{
			printf("\n Invalid Position");
		}
	}
	else
	{
		printf("\n Array is Empty");
	}
}
void sort()
{
	int i,j,mid,temp;
	for (i=0;i<n-1;i++)
	{       mid=i;

		for (j=i+1;j < n;j++)
		{
			if(arr[j] < arr[mid])
			{
			 mid =j;
			}
		}
		temp = arr[mid];
		arr[mid]=arr[i];
		arr[i]=temp;
	}
	printf("\n Array is sorted");
}
void simples()
{
	int key,i;
	if(n == 0)
	{
		printf("\ Array is empty");
		return;
	}
	printf("\n Enter element to search: ");
	scanf("%d",&key);
	for (i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			printf("\n Element %d found at position %d",key ,i+1);
			return;
		}
	}
	printf("\n Element %d not found in array.",key);
}
void binarys()
{
	int key,low=0,high=n-1,mid;
	if(n>0)
	{
		printf("\n Enter the elemnt to search: ");
		scanf("%d",&key);
		while(low<+high)
		{
			mid =(low+ high)/2;
			if(arr[mid]==key)
			{
				printf("\n Element found at position %d",mid + 1);
				return;
			}
			else if(arr[mid]<key)
			{
			 low = mid+1;
			}
			else
			{
			 high = mid-1;
			}
		}
		printf("\n Element not found");
	}
	else
	{
	 printf("\n Array is empty");
	}
}
void disp()
{
	int i;
	if(n>0)
	{
		printf("\n Array Elements: ");
		for(i=0;i<n;i++)
		{
			printf("\n %d",arr[i]);
		}
		printf("\n");
	}
	else
	{
	 printf("\n Array is empty");
	}
}