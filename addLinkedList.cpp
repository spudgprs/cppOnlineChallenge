/*Given two numbers in Linked List format. Print the result in Linked List by adding bith the linked list.*/
#include <iostream>
using namespace std;
struct node 
{
	int value;
	node * next;
}*fhead, *shead, *rhead;
int main()
{
	fhead = NULL;
	shead = NULL;
	rhead = NULL;
	struct node * ftail = NULL, * stail = NULL, * rtail = NULL;
	int con =1;
	while(con)
	{
		int choice=0, digit =0;
		cout<<"1. Initialize first single list\n2. Initialize second linked list\n3. Sum\n0. Exit\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				{
					cout<<"enter the digit to insert in first list : ";
					cin>>digit;
					node * temp = new node;
					temp->value = digit;
					temp->next = NULL;
					if(fhead == NULL)
					{
						fhead = temp;
						ftail = temp;
					}
					else
					{
						ftail->next = temp;
						ftail = ftail->next;
					}
					break;
				}
			case 2 :
				{
					cout<<"enter the digit to insert in second list : ";
					cin>>digit;
					node * temp = new node;
					temp->value = digit;
					temp->next = NULL;
					if(shead == NULL)
					{
						shead = temp;
						stail = temp;
					}
					else
					{
						stail->next = temp;
						stail = stail->next;
					}
					break;
				}
			case 3 :
				{
					int f=0, s=0, r=0;
					if(fhead!=NULL)
					{
						node * temp1 = new node;
						temp1 = fhead;
						while(temp1)
						{
							f = f*10 + temp1->value;
							temp1 = temp1->next;
						}
					}
					else
						cout<<"first element is NULL so initializing to zero\n";
					if(shead!=NULL)
					{
						node * temp1 = new node;
						temp1 = shead;
						while(temp1)
						{
							s = s*10 + temp1->value;
							temp1 = temp1->next;
						}
					}
					else
						cout<<"second element is NULL so initializing to zero\n";
					r = f+s;
					cout<<"sum is : "<<f<<" + "<<s<<" = "<<r<<endl;
					//constructing result list;
					if(r>0)
					{
						int tempr = r;
						while(tempr>0)
						{
							node * rtemp = new node;
							rtemp->value = tempr%10;
							rtemp->next = NULL;
							tempr /=10;
							if(rhead == NULL)
							{
								rtail= rtemp;
								rhead = rtail;
							}
							else
							{
								rtemp->next = rhead;
								rhead = rtemp;
							}
						}
						// printing the result list
						cout<<"Result List : ";
						node * restemp = new node;
						restemp = rhead;
						while(restemp)
						{
							cout<<restemp->value<<" -> ";
							restemp = restemp->next;
						}
						cout<<"NULL\n";
					}

					break;
				}
			case 0:
				{
					cout<<"EXIT\n";
					con =0;
					break;
				}


			default :
			{
				cout<<"wrong choice in your life\n";
				break;
			}
		}
	}

	return 0;

}