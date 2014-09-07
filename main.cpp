// © Copyright 2010 - 2014 BlackTopp Studios Inc.
/* This file is part of The Mezzanine Engine.

    The Mezzanine Engine is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Mezzanine Engine is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Mezzanine Engine.  If not, see <http://www.gnu.org/licenses/>.
*/
/* The original authors have included a copy of the license specified above in the
   'Docs' folder. See 'gpl.txt'
*/
/* We welcome the use of the Mezzanine engine to anyone, including companies who wish to
   Build professional software and charge for their product.

   However there are some practical restrictions, so if your project involves
   any of the following you should contact us and we will try to work something
   out:
    - DRM or Copy Protection of any kind(except Copyrights)
    - Software Patents You Do Not Wish to Freely License
    - Any Kind of Linking to Non-GPL licensed Works
    - Are Currently In Violation of Another Copyright Holder's GPL License
    - If You want to change our code and not add a few hundred MB of stuff to
        your distribution

   These and other limitations could cause serious legal problems if you ignore
   them, so it is best to simply contact us or the Free Software Foundation, if
   you have any questions.

   Joseph Toppi - toppij@gmail.com
   John Blackwood - makoenergy02@gmail.com
*/

#include <iostream>

#include "streamlogging.h"

/// @brief This serves as a simple example and sanity test of what this library is intended todo 
int main()
{
    /*SetStandardLoggingLevel(MergeLogLevel(Trace,Debug));
    std::cout << "Should be displayed - Default" << std::endl;
    std::cout << LogWarn << "Should be NOT displayed - Warning" << std::endl;
    std::cout << LogTrace << "Should be displayed - Trace" << std::endl;*/

    LogStream<char> LogOut(std::cout);
    LogOut.SetLoggingLevel(LL_DebugAndHigher);
    LogOut << "Part 1 - Logging against a LogStream" << std::endl;
    LogOut << "Should be displayed - Default" << std::endl;
    LogOut << LogWarn << "Should be displayed - Warning" << std::endl;
    LogOut << LogError << "Should be displayed - Error" << std::endl;
    LogOut << LogTrace << "Should be NOT displayed - Trace" << std::endl;
    LogOut << LogFatal << "Should be displayed - Fatal" << std::endl;

    SetStandardLoggingLevel(MergeLogLevel(LL_Trace,LL_Debug,LL_Warn));
    std::cout << "Part 2 - Logging against any other stream" << std::endl;
    std::cout << "Should be displayed - Default" << std::endl;
    std::cout << LogWarn << "Should be displayed - Warning" << std::endl;
    std::cout << LogError << "Should be NOT displayed - Error" << std::endl;
    std::cout << LogTrace << "Should be displayed - Trace" << std::endl;
    std::cout << LogFatal << "Should be NOT displayed - Fatal" << std::endl;

}
