#ifndef __drvGCODE_H
#define __drvGCODE_H

/* 
   drvGCODE.h : This file is part of pstoedit
   Contributed / Copyright 2008 by: Lawrence Glaister VE7IT

   Copyright (C) 1993 - 2013 Wolfgang Glunz, wglunz@pstoedit.net

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/
#include "drvbase.h"

class drvGCODE : public drvbase {

public:

	derivedConstructor(drvGCODE);
	~drvGCODE(); // Destructor

	class DriverOptions : public ProgramOptions {
	public:
	OptionT < bool, BoolTrueExtractor > noheader;
	OptionT < bool, BoolTrueExtractor > nofooter;
	OptionT < RSString, RSStringValueExtractor > speed;
	OptionT < RSString, RSStringValueExtractor > intensity;
	OptionT < RSString, RSStringValueExtractor > traversal;
	DriverOptions():
		noheader(true,"-noheader",0,0,"produce gcode without a header",0,false),
		nofooter(true,"-nofooter",0,0,"produce gcode without a footer",0,false),
		speed(true,"-speed","string",0,
	       "sets the cut speed of the laser in mm/min",
	       0,(const char*)"180"),
		intensity(true,"-intensity","string",0,
	       "sets the firing intensity of the laser as a percentage between 0 and 100",
	       0,(const char*)"100"),
	    traversal(true, "-traversal", "string", 0,
	       "sets the tranversal speed of the laser in mm/min",
	       0, (const char*)"6000")
		{
		ADD(noheader);
		ADD(nofooter);
		ADD(speed);
		ADD(intensity);
		ADD(traversal);
		}
	}*options;

private:

#include "drvfuncs.h"

};
#endif

 
 
