#include<stdio.h>
#include<conio.h>
#define max 5
int s[max],top=-1;
void push();
void pop();
void peep();
void mod();
void disp();
void main()
{
	int c;
	clrscr();
	do
	{
		printf("\n\n STACK OPERATION");
		printf("\n 1.PUSH \n 2.POP \n 3.PEEP \n 4.MODIFY \n 5.DISPLAY \n ENTER YOUR CHOICE:");
		scanf("%d",&c);

		switch(c)
		{
			case 1:
				push();
				break;

			case 2:
				pop();
				break;

			case 3:
				peep();
				break;

			case 4:
				mod();
				break;

			case 5:
				disp();
				break;
		}
	}
	while(c>=1 && c<=5);
	getch();
}
void push()
{
	int ele;
	if(top==max-1)
	{
		printf("Stack is full");
	}
	else
	{
		printf("ENTER THE ELEMENT:");
		scanf("%d",&ele);
		top++;
		s[top]=ele;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\n STACK IS EMPTY");
	}
	else
	{
	 top=top-1;
	}
}
void peep()
{
	if(top==-1)
	{
		printf("\n STACK IS EMPTY");
	}
	else
	{
	       printf("\n Top Element is %d",s[top]);
	}
}
void mod()
{
	int pos,newv;
	if(top==-1)
	{
		printf("\n Stack is Empty");
	}
	printf("\n Enter the Position to modify :");
	scanf("%d",&pos);

	if(pos<0 || pos > top +1)
	{
		printf("invalid Position");
		return;
	}

	printf("\n Enter the new value");
	scanf("%d",&newv);
	s[top - pos +1]=newv;
	printf("\n Modified position %d with value %d (top = 1)",pos,newv);
}
void disp()
{
	int i;
	if(top==-1)
	{
		printf("\n STACK IS EMPTY");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf(" Element = %d",s[i]);
		}
	}
}



