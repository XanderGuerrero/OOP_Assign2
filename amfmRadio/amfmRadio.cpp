///FileName:		AmFmRadio.cpp
///Project:		AmFmRadio
///Author:		Alex Guerrero	
///Date:			March 23, 2014
///Description:	This program runs through the functions of a radio with menu input from the user
///	
/* -- FILEHEADER COMMENTS -- 
	NAME	:	AmFmRadio
	PURPOSE :	This program uses a class to mimic radio functionailty.  The user can switch bands, 
				scan stations up and down, change volume levels set radio presets and toggle the radio on and off.

*/


//Include files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"AmFmRadio.h"
#include"PioneerCarRadio.h"


/// Function name: AmFmRadio
/// \brief Called upon to <i>construct</i> a radio object - once it loses <b>scope</b>
/// \details <b>Details</b>
///
/// Description: This method sets the each button to the lowest frequency, sets the current station, sets the
/// frequency to AM, sets the volume to 0 and sets on to false
///	constructors
///	as soon as object is instantiated, set radio to off
///
///	Parameters: bool newRadio_On
/// \return Returns:As this is a <i>constructor</i> nothing is returned
///
AmFmRadio::AmFmRadio( bool newRadio_On )
{
	if(newRadio_On == true)///<if the radio is on, set Radio_On to true
	{
		radio_On = newRadio_On;
	}
	else
	{
		radio_On = false;///<Otherwise, set the radio to false
	}

	for( int i = 0; i < 5; ++i )
	{
		button[i].AMFreq = 530;///<set each of the five stations to the default am 530 station
	}
	for( int j = 0; j < 5; ++j )
	{
		button[j].FMFreq = 87.9;///<set each of the five stations to the default fm 87.9 station
	}

	previous_station = 530;///<Previous station is set to  530
	volume = 0;///<initial volume is 0
	current_station = 530;///<current station initialized to 530
	strcpy( frequency, "AM" );///< and set frequency to AM
}



/// Function name: AmFmRadio
/// \brief Called upon to <i>construct</i> a radio object - once it loses <b>scope</b>
/// \details <b>Details</b>
///
/// Description: This method sets the each button to the lowest frequency, sets the current station, sets the
/// frequency to AM, sets the volume to 0 and sets on to false
///	constructors
///	as soon as object is instantiated, set radio to off
///
///	Parameters: bool newRadio_On, struct Freqs[], double newCurrent_station, int newVolume, char newFrequency[]
/// \return Returns:As this is a <i>constructor</i> nothing is returned
///
AmFmRadio::AmFmRadio( bool newRadio_On, struct Freqs[], double newCurrent_station, int newVolume, char newFrequency[] )
{
	
	if(newRadio_On == true)
	{
		radio_On = newRadio_On;///<if the radio is on, set Radio_On to true
	}
	else
	{
		radio_On = false;///<Otherwise, set the radio to false
	}

	current_station = 530;///<current station initialized to 530
	strcpy( frequency, "AM" );///< and set frequency to AM
	volume = 0;///<initial volume is 0
	previous_volume = 0;///<initial volume is 0
	previous_station = 530;///<Previous station is set to  530


	for( int i = 0; i < 5; ++i )
	{
		button[i].AMFreq = 530;///<set each of the five stations to the default am 530 station
	}
	for( int j = 0; j < 5; ++j )
	{
		button[j].FMFreq = 87.9;///<set each of the five stations to the default fm 87.9 station
	}
}


/// Function name: ~AmFmRadio
/// \brief Called upon to <i>destroy</i> a radio object - once it loses <b>scope</b>
/// \details <b>Details</b>
///
/// Description: This method destroys a radio object
///
///	Parameters: void
/// Returns: Nothing
AmFmRadio::~AmFmRadio(void)
{
	///>print out a statement indicating the object has been destroyed 
	printf("Destroying AmFmRadio\n");
}



/// Function name: bool AmFmRadio::SetCurrentStation
/// Description: This method sets thecurrent station for the user.
///	Parameters: void
/// Returns: Nothing
bool AmFmRadio::SetCurrentStation( double newCurrentStation )
{
	bool retCode = false;///<bool variable set to false
	///<if the station is less than upper bound or greater than the lower bound,
	if( newCurrentStation < 107.9 || newCurrentStation > 87.9 )
	{
		current_station = newCurrentStation;///< set station to current station
		retCode = true;///<return true
	}

	return retCode;
}


///FunctionName:AmFmRadio::SetButton(int button_num)
///Parameters:	(int button_num)
///Description:	Sets the current station to the user entered button
///returns:		int num
int AmFmRadio::SetButton(int button_num)
{
	///<initialize variables and decrement the parameter by one.
	int num = 0;
	--button_num;

	///<if the button choice is greater than or equal to 0 and less than or equal to 4
	if( (button_num >= 0) && (button_num <= 4) )
	{
		///<if the frquency is AM....
		if( strcmp("AM", frequency) == 0 )
		{
			button[button_num].AMFreq = (int) current_station;///<set the current station to the button selected
		}
		else///<otherwise
		{
			button[button_num].FMFreq = (float) current_station;///<set the current station to the button selected for the FM band
		}
		num = 1;
	}
	return num;
}



///FunctionName:SetVolume()
///Parameters:	void
///Description:	Sets the volume
///returns:		int number
int AmFmRadio::SetVolume()
{
	///<initialize variables
	char buf[20] = "";
	int number = 0;
	///<prompt the user for a volume level between 0 and 100
	///< user fgets to get user input and place data into buf[20]
	///<extract the number using atoi and assign to volume variable
	printf("\nEnter the volume level (0 - 100). ");
	fgets(buf, sizeof buf, stdin);
	volume = atoi(buf);
	///<if the volume is less than 0
	if( volume < 0 ) //if user enters volume less than 0, volume = 0
	{
		volume = 0;///<volume is set to 0
		number = 0;///<number is set to 0
	}
	///<if the volume is greater than 100
	if( volume > 100 ) //if user enters volume greater than 100, volume = 100
	{
		volume = 100;///<set volume to 100
		number = 2;///<number is set to 2
	}
	return number;
}



///FunctionName:ToggleFrequency()
///Parameters:	void
///Description:	Sets the volume
///returns:		int number
void AmFmRadio::ToggleFrequency()
{
	if( strcmp(frequency, "AM") == 0 )
	{
		strcpy(frequency, "FM");
		previous_station = current_station;
		current_station = 87.9;
	}
	else
	{
		strcpy(frequency, "AM");
		previous_station = current_station;
		current_station = 530;
	}
}

//methods()
//FunctionName:	ScanDown()
//Project:		AmFmRadio
//Parameters:	void 
//Description:	Scans down to find a radio frequency, if at the last station wrap around
//returns:		int void
void AmFmRadio::ScanDown()
{
	if( strcmp("AM", frequency) == 0 )
	{
		//if current_station is 1700, the current_station becomes 530
		if( current_station <= 530 )
		{
			current_station = 1700;
		}
		else
		{
			current_station = current_station - 10;
		}
	}
	else
	{
		//if the current_station is 87.9, the current_station becomes 107.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if( current_station <= 87.9 )
		{
			current_station = 107.9;
		}
		else
		{
			current_station = current_station - .2;
		}
	}
}



//FunctionName:	AmFmRadio::PowerToggle()
//Project:		AmFmRadio
//Parameters:	void 
//Description:	turns the radio on of off
//returns:		void
void AmFmRadio::PowerToggle()
{
	///<if defualt parameter is used to set to off
	///<turn on the radio
	///<radio defualt off is set in the AmFmRadio constructor prototype 
	if( radio_On == false )
	{
		radio_On = true;
	}
	else
	{
		radio_On = false;
		volume = 0;
	}
}



///FunctionName:	AmFmRadio::PowerToggle()
///Parameters:	void 
///Description:	turns the radio on of off
///returns:		int
int AmFmRadio::SelectCurrentStation(int button_num)
{
	///<decrement the button_num
	--button_num;
	///<if the button is greater than or equal to 0 and less than or equal to 4...
	if( ( button_num >= 0) && ( button_num <= 4) )
	{
		///< if the frequency is AM....
		if( strcmp("AM", frequency) == 0 )
		{
			current_station = (int)button[button_num].AMFreq;///<set radio to this station
		}
		else
		{
			current_station = button[button_num].FMFreq;///<set radio to this fm station
		}

		return 1;
	}
	return 0;
}



///FunctionName:	ShowCurrentSettings()
///Parameters:	void 
///Description:	Shows the current settings of the radio
///returns:		void
void AmFmRadio::ShowCurrentSettings()
{
	///<if the radio is on.....
	if( radio_On == true )
	{
		printf("\n\nRadio is on. \n");///<display msg to screen
	}
	else
	{
		printf("\n\nRadio is off. \n");///<display msg to screen
	}
	///<this section of code prints out the frequency, volume, current station and the am and fm
	///<radio presets
	printf("Frequency: %s\n", frequency);
	printf("Volume: %d\n", volume);
	printf("Current Station: %.1f %s\n", current_station, frequency);
	printf("AM Button Settings: ");
	for( int i = 0; i < 5; ++i )
	{
		printf("%d) %6d ", i + 1, button[i].AMFreq);
	}

	printf("\nFM Button Settings: ");
	for( int j = 0; j < 5; ++j )
	{
		printf("%d) %6.1f ", j + 1, button[j].FMFreq);
	}
}



///FunctionName:	SetVolume( int volume )
///Parameters:	int volume 
///Description:	Sets the volume up by one if the user presses '+' 
///				or down by one if the user presses '_'
///returns:		int number
int AmFmRadio::SetVolume( int newVolume )
{
	///<if the user choose to increase the volume and the volume is still under 100
	if( (newVolume == 1) && (volume < 100) ) 
	{
		++volume;///< increment the volume
	}
	///<if the user choose to decrease the volume and the volume is stil greater than 0
	if( (newVolume == -1) && (volume > 0) ) 
	{
		--volume;///<decrement the volume
	}
	
	return volume;///<return volume
}

///FunctionName:ScanUp()
///Parameters:	void 
///Description:	scans up through the radio frequencies
///returns:		int number
void AmFmRadio::ScanUp()
{
	if( strcmp("AM", frequency) == 0 )
	{
		///<if current_station is 1700, the current_station becomes 530
		if( current_station >= 1700 )
		{
			current_station = 530;
		}
		else
		{
			///<otherwise increment to the next station
			current_station = current_station + 10;
		}
	}
	else
	{
		///<if the current_station is equal or greater than 107.9, the current_station
		///<becomes 87.9. 
		if( current_station >= 107.9 )
		{
			current_station = 87.9;
		}
		else
		{
			///<otherwise increment to the next station
			current_station = current_station + .2;
		}
	}
}



///Accessors
///FunctionName:GetStation(void)
///Parameters:	void 
///Description:	gets the value of private data memeber
///returns:		double current_station
double AmFmRadio::GetStation(void)
{
	///< return the current station
	return current_station;	 
}



///FunctionName:	GetPreviousStation(void)
///Parameters:	void 
///Description:	gets the value of private data memeber
///returns:		double previous_station
double AmFmRadio::GetPreviousStation(void)
{
	///< return the previous station
	return previous_station;	 
}



///FunctionName:	GetFrequency(void)
///Parameters:	void 
///Description:	gets the value of private data memeber
///returns:		char frequency
char AmFmRadio::GetFrequency(void)
{
	int i = 0;
	///< return the frequency
	return frequency[i];
}



//FunctionName:	GetVolume(void)
//Parameters:	void 
//Description:	gets the value of private data memeber
//returns:		int volume
int AmFmRadio::GetVolume(void)
{
	///< return the volume
	return volume;
}



//FunctionName:	GetRadioOn(void)
//Parameters:	void 
//Description:	gets the value of private data memeber
//returns:		int volume
bool AmFmRadio::GetRadioOn(void)
{
	///< return the value of Radio_On
	return radio_On;
}

