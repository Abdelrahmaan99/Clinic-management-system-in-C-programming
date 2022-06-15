#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int 	Slot;
	int 	ID;
	int 	AGE;
	struct 	node * next;
	char 	Name[20];
	char 	Gender[7];
	
}Information;


int main()
{
	/*declare of data*/
	Information *head = NULL;
	Information *temp = NULL; 
	Information *loop = NULL; 
	
	int Local_intMode , Local_intPass , Local_intID , Local_intChoiceModde , Local_intWrongPass = 0 , Local_intNumberOfPatient = 0 , Local_intCorrectId = 0;
	int	AvailableReverse[5]={0};
	
	Welcome:
	printf("                ********************Welcome in Clinic Management System********************\n\n\n");
	ChoiceMode:
	printf("For Admin Mode Enter 1.\nFor The User Mode Enter 2.\nFor close the program Enter 3.\n");
	printf("Your Choise is: ");
	scanf("%d",&Local_intChoiceModde);
	
	if(Local_intChoiceModde == 1)
	{
		printf("\n                ********************Welcome in Admin Mode********************\n\n");
		EnterPass:
		printf("Please Enter Password: ");
		scanf("%d",&Local_intPass);
		Local_intWrongPass++;
		if(Local_intPass == 1234)
		{
			printf("\n\nFor Adding New Patient Enter 1.\nFor Editing Patient Enter 2.\nFor Reserve a solt With the doctor Enter 3.\nFor Cancel resevation Enter 4.\nTo Exit Enter 5.\n");
			printf("Your choice: ");
			scanf("%d",&Local_intMode);
			while(1)
			{
				/*Add Patient */
				if(Local_intMode == 1)
				{
					Information * new_node = (Information *)malloc(sizeof(Information));					
					printf("\nPlease Enter Name of  Patient: ");
					scanf("%s",&new_node->Name);
					printf("Please Entre AGE of Patient: ");
					scanf("%d",&new_node->AGE);
					printf("Please Enter Gender of Patient: " );
					scanf("%s",&new_node->Gender);
					printf("Please Enter ID of Patient: ");
					scanf("%d",&new_node->ID);
					new_node->next = NULL;
					if(head == NULL)
					{
						head = temp =new_node;
					}
					else
					{
						temp->next = new_node;
						temp = new_node;
					}
					Local_intNumberOfPatient++;
					printf("Information of Patient Added Thank you\n\n");
				}
				
				/*Editing Patient*/
				else if(Local_intMode == 2)
				{
					Enter_EditID:
					if(Local_intNumberOfPatient != 0)
					{
						printf("\nFor Editing, Please Enter ID of Patient: ");
						scanf("%d",&Local_intID);
						loop = head;
						do
						{
							if(loop->ID == Local_intID)
							{
								printf("Please Enter Name of  Patient: ");
								scanf("%s",&loop->Name);
								printf("Please Entre AGE of Patient: ");
								scanf("%d",&loop->AGE);
								printf("Please Enter Gender of Patient: " );
								scanf("%s",&loop->Gender);
								printf("Editing Done\n");
								Local_intCorrectId = 1;
								break;
							}
							else
							{
								loop = loop->next;
							}
						}while(loop != NULL);
						if(Local_intCorrectId == 1)
						{
							printf("Information of Patient Edited Thank you\n\n");
							Local_intCorrectId = 0;
						}
						else
						{
							printf("\n\n********\n");
							printf("Wrong ID\n");
							printf("\n********\n\n");
							goto Enter_EditID;
						}
						loop = head;
					}
					else
					{
						printf("\n\n**************************\n");
						printf("Warning!! No Patient Added\n");
						printf("\n**************************\n\n");	
					}
				}
				
				/*reverse*/
				else if(Local_intMode == 3)
				{
					if(Local_intNumberOfPatient != 0)
					{
						printf("\n----------------------------------------\n");
					    if(AvailableReverse[0] == 0)
					    {
					    	printf("slot available 1: 2pm to 2:30pm\n");
					    }
					    if(AvailableReverse[1] == 0)
					    {
					    	printf("slot available 2: 2:30pm to 3pm\n");
					    }
					    if(AvailableReverse[2] == 0)
					    {
					    	printf("slot available 3: 3pm to 3:30pm\n");
					    }
					    if(AvailableReverse[3] == 0)
					    {
					    	printf("slot available 4: 4pm to 4:30pm\n");
					    }
					    if(AvailableReverse[4] == 0)
					    {
					    	printf("slot available 5: 4:30pm to 5pm\n");
					    }		
					    printf("----------------------------------------\n");
					    
					    Enter_ReverseID:
					    printf("For Reservation, Please Enter ID of Patient: ");
					    scanf("%d",&Local_intID);
					    loop = head;
					    do
					    {
					    	if(loop->ID == Local_intID)
					    	{
					    		printf("Please choose number: ");
					    		scanf("%d",&loop->Slot);
					    		AvailableReverse[(loop->Slot)-1] = 1;
					    		Local_intCorrectId = 1;
					    		break;
					    	}
					    	else
					    	{
				        		loop = loop->next;
					    	}
					    }while(loop != NULL);
					    if(Local_intCorrectId == 1)
					    {
							printf("\n\n********\n");
					    	printf("Reserved");
							printf("\n********\n\n");
					    	Local_intCorrectId = 0;
					    }
					    else
					    {
							printf("\n\n********\n");
							printf("Wrong ID\n");
							printf("\n********\n\n");
					    	goto Enter_ReverseID;
					    }
					    loop = head;
					}
					else
					{
						printf("\n\n**************************\n");
						printf("Warning!! No Patient Added\n");
						printf("\n**************************\n\n");
					}
				}
				
				/*cancel reverse*/
				else if(Local_intMode == 4)
				{
					if(Local_intNumberOfPatient != 0)
					{
						if((AvailableReverse[0] == 0) && (AvailableReverse[1] == 0) && (AvailableReverse[2] == 0) && (AvailableReverse[3] == 0) && (AvailableReverse[4] == 0))
						{
							printf("\n\n*************************\n");
							printf("No Reservation to cancel it\n");
							printf("\n\n*************************\n");
						}
						else
						{
							printf("\n----------------------------------------\n");
							if(AvailableReverse[0] == 1)
							{
								printf("slot available 1: 2pm to 2:30pm\n");
							}
							if(AvailableReverse[1] == 1)
							{
								printf("slot available 2: 2:30pm to 3pm\n");
							}
							if(AvailableReverse[2] == 1)
							{
								printf("slot available 3: 3pm to 3:30pm\n");
							}
							if(AvailableReverse[3] == 1)
							{
								printf("slot available 4: 4pm to 4:30pm\n");
							}
							if(AvailableReverse[4] == 1)
							{
								printf("slot available 5: 4:30pm to 5pm\n");
							}		
							printf("----------------------------------------\n");	
							Enter_CancelReverseID:							
							printf("For cancel Reservation, Please Enter ID of Patient: ");
							scanf("%d",&Local_intID);
							loop = head;
							do
							{
								if(loop->ID == Local_intID)
								{
									AvailableReverse[(loop->Slot)-1] = 0;
									loop->Slot = 0;
									Local_intCorrectId = 1;
									break;
								}
								else
								{
									loop = loop->next;
								}
							}while(loop != NULL);
						    if(Local_intCorrectId == 1)
							{
								printf("\n\n*********************\n");
								printf("Reservation is canceled\n");
								printf("\n\n*********************\n");
								Local_intCorrectId = 0;
							}
							else
							{
								printf("\n\n********\n");
								printf("Wrong ID\n");
								printf("\n********\n\n");
								goto Enter_CancelReverseID;
							}
							loop = head;
						}
					}
					else
					{
						printf("\n\n**************************\n");
						printf("Warning!! No Patient Added\n");
						printf("\n**************************\n\n");
					}
				}
				
				/*out from admin mode*/
				else if(Local_intMode == 5)
				{
					goto Welcome;
				}
				
				/* Wrong Choice */
				else
				{
					printf("\n\n************\n");
					printf("Wrong Choice");
					printf("\n\n************\n");
				}
				printf("\nFor Adding New Patient Enter 1.\nFor Editing Patient Enter 2.\nFor Reserve a solt With the doctor Enter 3.\nFor Cancel resevation Enter 4.\nTo Exit Enter 5.\n");
				printf("Your choice: ");
				scanf("%d",&Local_intMode);
			}
		}
		else
		{
			if(Local_intWrongPass == 3)
			{
				printf("Sorry, Password is incorrect for 3 times\n");
				Local_intWrongPass = 0;
			}
			else
			{
				printf("Password incorect Please Try Again\n");
				goto EnterPass;
			}
		}
	}
	else if(Local_intChoiceModde == 2)
	{
		printf("                ********************Welcome in The User Mode********************\n\n");
		label6:
		printf("\nFor Viewing Patient record Enter 1.\nFor Viewing Today's reservations Enter 2.\nTo Exit Enter 3.\n");
		printf("Your choice: ");
		scanf("%d",&Local_intMode);
		
		while(1)
		{
			/* Viewing Patient record */
			if(Local_intMode == 1)
			{
				if(Local_intNumberOfPatient != 0)
				{
					Enter_ViewingPatientID:
					printf("\nFor Viewing Patient record Enter Patient ID: ");
					scanf("%d",&Local_intID);
					loop = head;
					do
					{
						if(loop->ID == Local_intID)
						{
							printf("\n------------------------\n");
							printf("\nPatient name: %s.\n",loop->Name);
							printf("Patient AGE: %d.\n",loop->AGE);	
							printf("Patient Gender: %s.\n",loop->Gender);
							printf("\n------------------------\n");
							Local_intCorrectId = 1;
							break;
						}
						else
						{
							loop = loop->next;
						}
					}while(loop != NULL);
					if(Local_intCorrectId == 1)
					{
						Local_intCorrectId = 0;
					}
					else
					{
						printf("\n\n********\n");
						printf("Wrong ID\n");
						printf("\n********\n\n");
					goto Enter_ViewingPatientID;
					}
					loop = head;
				}
				else
				{
					printf("\n\n**************************\n");
					printf("Warning!! No Patient Added\n");
					printf("\n**************************\n\n");
				}
			}
			
			/* Viewing Today's reservations */
			else if(Local_intMode == 2)
			{
				if(Local_intNumberOfPatient != 0)
				{
					if((AvailableReverse[0] == 0) && (AvailableReverse[1] == 0) && (AvailableReverse[2] == 0) && (AvailableReverse[3] == 0) && (AvailableReverse[4] == 0))
					{
						printf("\n********************\n");
						printf("No Reservation Today\n");
						printf("\n********************\n\n");
					}
					else
					{
						loop = head;
						while(loop != NULL)
						{
							printf("\n\n************************************\n");
							if(loop->Slot == 1)
							{
								printf("\nslot is 2pm to 2:30pm and ID is %d\n",loop->ID);
							}
							else if(loop->Slot == 2)
							{
								printf("\nslot is 2:30pm to 3pm and ID is %d\n",loop->ID);
							}
							else if(loop->Slot == 3)
							{
								printf("\nslot is 3pm to 3:30pm and ID is %d\n",loop->ID);
							}
							else if(loop->Slot == 4)
							{
								printf("\nslot is 4pm to 4:30pm and ID is %d\n",loop->ID);
							}
							else if(loop->Slot == 5)
							{
								printf("\nslot is 4:30pm to 5pm and ID is %d\n",loop->ID);
					    	}
							printf("\n************************************\n\n");
                        	loop = loop->next;
                        }
                        loop = head;
					}
				}
				else
				{
					printf("\n\n**************************\n");
					printf("Warning!! No Patient Added\n");
					printf("\n**************************\n\n");
				}
			}
			
			/*out from user mode*/
			else if(Local_intMode == 3)
			{
				goto Welcome;
			}
			
			/* Wrong Choice */
			else
			{
				printf("\n\n************\n");
				printf("Wrong Choice");
				printf("\n\n************\n");
			}
			printf("\nFor Viewing Patient record Enter 1.\nFor Viewing Today's resevations Enter 2.\nTo Exit Enter 3.\n");
			printf("Your choice: ");
			scanf("%d",&Local_intMode);
		}
	}
	else if(Local_intChoiceModde == 3)
	{
		printf("\nThank you\nGood Bye\n");
	}
	else
	{
		printf("\n*****************\n");
		printf("Wrong Choice Mode\n");
		printf("\n*****************\n\n");
		goto ChoiceMode;
	}
}