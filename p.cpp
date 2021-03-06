#include<iostream>
#include<conio.h>
#include<malloc.h>
#define MAX_LEN 1000				//MAX_LEN for data length
using namespace std;
static int increment=0;
struct record
{
	struct timestamp						//nested structure for the timestamp
	{
		int ss;
		int min;
		int hr;
		int day;
		int month;
		int year;
	}time;
	
	char str[MAX_LEN];
	int value;          
	int nodenumber;
	char nodeid[5];
	struct record *referenceNodeId;
	struct record *childReferenceNodeId;
	struct record *genesisReferenceNodeId;
	char HashValue[4];
	
	struct record *leftnext=NULL;					//* taken the binary tree here.
	struct record *rightnext=NULL;
}*GenesisNode=NULL,*tempNode=NULL;

void create_tree()
{
	
	
	int ch='n';
	
	if(GenesisNode==NULL)
	{
		increment++;

		GenesisNode=(record *)malloc(sizeof(record *));
		
		cout<<"Enter data for the root node";
		
		//Entering data for GenesisNode
		cout<<"Enter seconds";
		cin>>(*GenesisNode).time.ss;
		cout<<"Enter min";
		cin>>(*GenesisNode).time.min;
		cout<<"Enter hours";
		cin>>(*GenesisNode).time.hr;
	    cout<<"Enter day";
		cin>>(*GenesisNode).time.day;
		cout<<"Enter months";		
		cin>>(*GenesisNode).time.month;
		cout<<"Enter year";
		cin>>(*GenesisNode).time.year;	
		cout<<"Enter length";
		cin>>(*GenesisNode).str;
	    cout<<"Enter value";			
		cin>>(*GenesisNode).value;
		(*GenesisNode).nodenumber=increment;
		cout<<"Enter nodeid";
		cin>>(*GenesisNode).nodeid;
		(*GenesisNode).referenceNodeId=NULL;  //Genesis parent node NULL
		(*GenesisNode).childReferenceNodeId=NULL;
		(*GenesisNode).genesisReferenceNodeId=GenesisNode;
			cout<<"Enter hashvalue";
		cin>>(*GenesisNode).HashValue;
	}
		cout<<"Want to enter more nodes";
		cin>>ch;
	
	while(ch="y"||"Y")
	{
		int value=0;      //for checking against root value;	
		
		
		if((*GenesisNode).leftnext||(*GenesisNode).rightnext)
		{
			cout<<"Enter value for the record first";
		
			if(value<(*GenesisNode).value)
			{
				increment++;
		
				tempNode=(record *)malloc(sizeof(record *));
		
				//Entering data for GenesisNode children's
				cin>>(*tempNode).time.ss;
				cin>>(*tempNode).time.min;
				cin>>(*tempNode).time.hr;
				cin>>(*tempNode).time.day;
				cin>>(*tempNode).time.month;
				cin>>(*tempNode).time.year;
			
				cin>>(*tempNode).str;
				cin>>(*tempNode).value;
				(*tempNode).nodenumber=increment;
				cin>>(*tempNode).nodeid;
				(*tempNode).referenceNodeId=GenesisNode;
				(*tempNode).childReferenceNodeId=NULL;
				(*tempNode).genesisReferenceNodeId=GenesisNode;
				cin>>(*tempNode).HashValue;
			}
			if((*GenesisNode).leftnext==NULL)
			{
				(*GenesisNode).leftnext=tempNode;
			}
			else
			{
				(*GenesisNode).rightnext=tempNode;
			}
		}
		cout<<"Want to enter more nodes";
		cin>>ch;
	}
}
int main()
{
	create_tree();
		
	return 0;	
}
