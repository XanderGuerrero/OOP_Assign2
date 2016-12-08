///FileName:		PioneerCarRadio.cpp
///Project:		PioneerCarRadio
///Author:		Alex Guerrero	
///Date:			March 23, 2014
///Description:	This program runs through the functions of a Car radio with menu input from the user
///				using inheritance dervived from the AmFmRadio class.
///	
/* -- FILEHEADER COMMENT -- 
	NAME	:	PioneerCarRadio
	PURPOSE :	This program uses a class to mimic radio functionailty.  The user can switch bands, 
				scan stations up and down, change volume levels set radio presets and toggle the radio on and off.

*/
//include files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include"PioneerCarRadio.h"


/// Function name: PioneerCarRadio
/// \brief Called upon to <i>construct</i> a radio object - once it loses <b>scope</b>
/// \details <b>Details</b>
///
/// Description: This method calls the constructor from AmFmRadio to instantiate an object
//  and sets the each button to the lowest frequency, sets the current station, sets the
/// frequency to AM, sets the volume to 0 and sets on to false
///	constructors
///	as soon as object is instantiated, set radio to off
///
///	Parameters: bool newRadio_On
/// \return Returns:As this is a <i>constructor</i> nothing is returned
///
PioneerCarRadio::PioneerCarRadio() 
{
	AmFmRadio::AmFmRadio();
}



/// Function name: ~PioneerCarRadio
/// \brief Called upon to <i>destroy</i> a radio object - once it loses <b>scope</b>
/// \details <b>Details</b>
/// Description: This method destroys a Pioneer radio object
///	Parameters: void
/// Returns: Nothing
PioneerCarRadio::~PioneerCarRadio(void)
{
	// print out a statement indicating 
	printf("Destroying PioneerCarRadio\n");
}



/// Function name: userChoice()
/// \brief Called upon to <i>destroy</i> a radio object - once it loses <b>scope</b>
/// \details <b>Details</b>
///
/// Description: This method uses getch() to get user input.  This input is used to set
/// the various radio functions for the user.
///
///	Parameters: void
/// Returns: Nothing
void PioneerCarRadio::userChoice()
{
	///<initialized variables
	int choice = NULL;
	int volume = 0;
	int num = 0;
	int scan = 0;

	do
	{
		///< this section of code gets input from the user and checks whether the choice was a
		///< number or character.  Based on this input, certain radio functions are carried out by calling the
		///< appropriate inherited functions.  Once the input has been processed, an update of the current
		///< radio settings is printed to the screen.
		printf("\n");
		choice = getch();///<get user input
		///<if input is 1,2,3,4,5 select a station preset.
		if(choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5')
		{
			if(choice == '1')
			{
				choice = 1;
			}
			if(choice == '2')
			{
				choice = 2;
			}
			if(choice == '3')
			{
				choice = 3;
			}
			if(choice == '4')
			{
				choice = 4;
			}
			if(choice == '5')
			{
				choice = 5;
			}
			AmFmRadio::SelectCurrentStation(choice);///<turn on preset
			system("cls");///<clear the screen
			ShowSettings();///< show current settings
		}
		//if the input is !,@,#,$,%, set the current station to the appropriate button.
		if(choice == '!' || choice == '@' || choice == '#' || choice == '$' || choice == '%')
		{
			if(choice == '!')
			{
				choice = 1;
			}
			if(choice == '@')
			{
				choice = 2;
			}
			if(choice == '#')
			{
				choice = 3;
			}
			if(choice == '$')
			{
				choice = 4;
			}
			if(choice == '%')
			{
				choice = 5;
			}
			AmFmRadio::SetButton(choice);///<set current station to button preset
			system("cls");///<clear the screen
			ShowSettings();///<show the settings
		}
	switch( choice )
		{
			///<case 1 turn power on and off
		case 'o':
			AmFmRadio::PowerToggle();///<method to toggle power
			system("cls");///<clear the screen
			ShowSettings();///<show the currents settings
			break;
		case '+':///<set volume up
			volume = 1;///<volume is positive one
			AmFmRadio::SetVolume(volume);///<pass the paramter to method to set volume up by one
			system("cls");///<clear screen
			ShowSettings();///<show the current settings
			break;
		case '_':///<set volume down
			volume = -1;///<volume is negative one
			AmFmRadio::SetVolume(volume);///<pass parameter to method to lower volume by one
			system("cls");///<clear screen
			ShowSettings();///<show settings
			break;
		case '=':///<scan up
			AmFmRadio::ScanUp();///<scan the station up one 
			system("cls");///<clear screen
			ShowSettings();///<show settings
			break;
		case '-':///<scan station down
			AmFmRadio::ScanDown();///<scan down one station
			system("cls");///<clear screen
			ShowSettings();///<show settings
			break;
		case 'b':///<change frequency
			ToggleFrequency();///<toggle frequency
			system("cls");///<clear screen
			ShowSettings();///<show current settings
			break;
		case 'x':///<exit the program
			break;
		}
	
	}while( choice != 'x' );
}



/// Function name: ShowSettings()
/// \brief Called upon to <i>destroy</i> a radio object - once it loses <b>scope</b>
/// \details <b>Details</b>
///
/// Description: This method is used to to print comments to the screen and inherit/call the abilities of
///				 AmFmRadio::ShowCurrentSettings() to display the current settings of the radio.  This method
///				 also gains access to the private data memeber IsRadioOn() to determine if the radio is on.
///				 If so, show the current settings, if not, do not show the current setting bc radio is off.
///	Parameters: void	
/// Returns: Nothing
void PioneerCarRadio::ShowSettings()
{
	///<initialize variables
	bool value = false;
	system("cls");///<clear the screen
	printf("Pioneer XS440\n");///<print to screen
	///<get the pivate data member bool value to determine if radio is on
	value = AmFmRadio::IsRadioOn();
	///<if value is true, show current settings
	///<using the AmFmRadio's public method
	if( value == true)
	{
		AmFmRadio::ShowCurrentSettings();
	}
	else
	{
		///<otherwise, if radio is off, display to screen
		printf("Radio is off\n");
	}
	
}