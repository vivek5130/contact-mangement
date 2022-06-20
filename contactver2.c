#include <stdio.h>
#include <string.h>

struct cont {
	char name[20];
	char ph[20];
}list[10];

int main()
{
	int opt,n=0,i;
	printf("\t\t\t **********WELCOME TO CONTACT MANAGEMENT SYSTEM ********\n");
	printf("\t\t\t\t Main Menu\n\t\t\t\t 1)Add contact\n\t\t\t\t 2)list contact\n\t\t\t\t 3)search contact \n\t\t\t\t 4)edit contact\n\t\t\t\t 5)delete contact\n\t\t\t\t Entering any other value will result in end of program\n");
	printf("Enter your option:  ");
	scanf("%d",&opt);
	while(opt==1||opt==2||opt==3||opt==4||opt==5)
	{
		switch(opt)
		{
			//Add contact
			case 1:
				printf("Enter you name\n");
				scanf("%s",&list[n].name);
				printf("Enter your contact\n");
				scanf("%s",&list[n].ph)	;
				++n;				
				break;	
				  //list contact
			case 2:
				for(i=0;i<n;i++)
				{
					printf("List of contacts is:\n");
					printf("Name   : %s\n",list[i].name);
					printf("PH.NO. : %s\n",list[i].ph);
				}
				break;
				//search contact
			case 3:
				printf("Enter the name of contact you want to search:\n");
				char query[20];
				int found = 0,i;
				scanf("%s",&query);
				for(i=0;i<n;i++)
				{
					if(strcmpi(list[i].name,query)==0)
					{
						printf("contact of %s is:\n",query);
						printf("Name   : %s\n",list[i].name);
						printf("PH.NO. : %s\n",list[i].ph);
						found++;
					}
				}
				if(found==0){
					printf("Contact of %s is not found\n",query);
				}
				break;
				  // edit contact
			case 4:
				printf("Enter the name you want to edit\n");
				char orgname[20];
				int a=-1;
				scanf("%s",&orgname);
				for(i=0;i<n;i++)
				{
					if(strcmpi(orgname,list[i].name)==0)
					{
						a=i;
						break;
						
					}	
				}
				if(a!=(-1))
				{
					//printf("element is found\n");
					printf("Enter new name\n");
					scanf("%s",list[a].name);
					printf("Enter new ph.no.\n");
					scanf("%s",list[a].ph);
				}
				else 
				{
					printf("There is no contact available with name %s\n",orgname);
				}
				break;
				//Remove contact
	    case 5:
			printf("Enter name of contact to delete\n");
			char realname[20];
			int b=-1;
			scanf("%s",&realname);
			for(i=0;i<n;i++)
			{
				if(strcmpi(realname,list[i].name)==0)
				{
					b=i;
					break;
					
				}
			}
			if(b!=(-1))
			{
				//printf("element is found\n");
				for(i=b;i<n;i++)
				{
					strcpy(list[i].name,list[i+1].name);
					strcpy(list[i].ph,list[i+1].ph);
					n--;	
				}
			}
			else 
			{
				printf("There is no contact available with name %s\n",realname);
			}
			break;
		}
		printf("\nEnter your option\n");
		scanf("%d",&opt);
	}
}

