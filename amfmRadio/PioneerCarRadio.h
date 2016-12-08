///FileName:		PioneerCarRadio.h
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
				This file contains the class for the pioneer car radio

*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"amfmRadio.h"



//disables warnings
#pragma warning(disable: 4996)///<#pragma warning used for depricated functions



#ifndef _PIONEERCARRADIO_H
#define _PIONEERCARRADIO_H



/// 
/// \class PioneerCarRadio
///
/// \brief The purpose of this class is to realistically model the functions of an AmFm radio.
///
/// This comment block is <i>required</i> for all class declarations.  This is the place 
/// where the <b>Class header Comment</b> appears. 
///
/// \author A <i>Alex Guerrero</i>
///
class PioneerCarRadio : public AmFmRadio
{
private:

public:
	//constructor
	PioneerCarRadio();
	//destructor
	PioneerCarRadio::~PioneerCarRadio(void);
	//method
	void PioneerCarRadio::userChoice();//input validation
	void ShowSettings();
};
#endif