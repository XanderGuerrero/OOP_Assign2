//FileName:		driver.cpp
//Project:		AmFmRadio
//Author:		Alex Guerrero	
//Date:			Marc 1, 2014
//Description:	This program runs through the functions of a radio with menu input from the user
//				



//Include files
#include <stdio.h>
#include <stdlib.h>
#include "AmFmRadio.h"
#include"PioneerCarRadio.h"
#include <iostream>
using namespace std;



//defined Enums
enum menuItems
{
	kMenuNothing = 0,	// special constant for initialization only
	kMenuTogglePower = 1, kMenuSetVolume, kMenuToggleAMFM, kMenuSetButton, kMenuSelectButton,
	kMenuShowCurrentSettings, kMenuScanUp, kMenuScanDown, kMenuQuit
};



int main()
{
	//variables
	AmFmRadio thing( true );
	int volume_OK = 0;
	int button_OK = 0;
	int button_num = 0;
	menuItems choice = kMenuNothing;
	char buf[20] = {0};
	//AmFmRadio jazzy(true);
	bool on = false;
	cout << "a";


	//This section of code, displays a menu to the user 
	//for functionality.  The user enters a choice and runs
	//through a switch statement to excute the user choice
	do
	{
		printf("\n\nMAIN MENU\n");
		printf("=========\n\n");
		printf("1.  Toggle Power\n");
		printf("2.  Set Volume\n");
		printf("3.  Toggle AM / FM\n");
		printf("4.  Set a Button \n"); 
		printf("5.  Select a Button \n"); 
		printf("6.  Show Current Settings\n"); 
		printf("7.  Scan Up \n"); 
		printf("8.  Scan Down\n");
		printf("9.  Quit Program\n");

		//get user inpit, store in buffer
		//extract the value of the choice using atoi
		fgets(buf, sizeof buf, stdin);
		choice = (menuItems) atoi(buf);
		
		//switch statment to execute methods
		switch( choice )
		{
			//case 1 turn power on and off
		case kMenuTogglePower:
			thing.PowerToggle();
			break;
			//case 2 set volume.  if volume equals 0, inform user
			//if volume equals 2, volume was set to 100
		case kMenuSetVolume: 
			volume_OK = thing.SetVolume();
			if( volume_OK == 0 )
			{
				printf("\nVolume was set to 0.");
			}
			else if( volume_OK == 2 )
			{
				printf("\nVolume was set to 100.");
			}
			break;
			//case 3 switch between am and fm frequencies
			//if on, toggle amfm frequency otherwise, the radio is not on
			//and inform user
		case kMenuToggleAMFM:
			on = thing.IsRadioOn();
			if( on )
			{
				thing.ToggleFrequency();
			}
			else
			{
				printf("\nThe radio must be turned on before the "
					"band can be toggled!");
			}
			break;
			//case 4 set which preset you wish to use
			//
		case kMenuSetButton:
			on = thing.IsRadioOn();
			if( on )
			{
				//if radio is on, get user input and set button
				printf("\nWhich button do you want to set?");
			    fgets(buf, sizeof buf, stdin);
			    button_num = atoi(buf) - 1;
			    button_OK = thing.SetButton(button_num);
				//if return is 0, invalid entry
			    if( button_OK == 0 )
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else
			{
				//otherwise, radio is off
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
			//select a preset to listen to
		case kMenuSelectButton:
			on = thing.IsRadioOn();
			if( on )
			{
				printf("\nEnter the number of the button: ");
			    fgets(buf, 20, stdin);
			    button_num = atoi(buf) - 1;
			    button_OK = thing.SelectCurrentStation(button_num);
				//if return is 0, invalid entry
				if( button_OK == 0 )
				{
					printf("\nYou entered an invalid button number!");
				}
			}
			else
			{
				//otherwise, radio is off
				printf("\nYou must turn the radio on before you set the buttons!\n");
			}
			break;
			//show the current radio settings
		case kMenuShowCurrentSettings:
			thing.ShowCurrentSettings();
			break;
			//scan up the frequencies
		case kMenuScanUp:
			on = thing.IsRadioOn();
			if( on )
			{
				thing.ScanUp();
			}
			else
			{
				//otherwise, radio is off
				printf("\nYou must turn the radio on before you can use the scan button!\n");
			}
			break;
			//scan down the radio frequencies
		case kMenuScanDown:
			on = thing.IsRadioOn();
			if( on )
			{
				thing.ScanDown();
			}
			else
			{
				//otherwise, radio is off
				printf("\nYou must turn the radio on before you can use the scan button!\n");
			
			}
			break;
			//exit the menu
		case kMenuQuit:
		    break;
		default:
			//any other invalid input
			printf("You have entered an invalid selection. Please make \n"
				   "another selection.\n");
			break;

		}
		//if the choice was not to show the current settings and the choice was not exit the program
		//display current radio settings
		if( (choice != kMenuShowCurrentSettings) && (choice != kMenuQuit) )
			thing.ShowCurrentSettings();
	//if choice was to exit
	}while( choice != kMenuQuit );
	//exit
	printf("\nGoodbye!\n");
	return 0;
}