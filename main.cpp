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
#include <sstream>
#include <string>

#include "streamlogging.h"

/// @brief Used to ease integration with the mezzanine, not require for external use
typedef std::string String;

/// @brief Used to ease integration with the mezzanine, not require for external use
typedef int Integer;


/// @brief This matches a MACRO in the Mezzanine test suite, and exists solely for compatibility
/// @param Results This is setup to allow a boolean condition to be passed
/// @param TestName The name of the test for Mezzanine metadata purpose, pretty useless he actually.
void TEST(bool Results, const String& TestName)
{
    std::cout << TestName << ": ";
    if(Results)
    {
        std::cout << "Passed.";
    }else{
        std::cout << "Fail!";
    }
    std::cout << std::endl;
}


/// @brief Counts the amount of needles is found in the haystack
/// @param Haystack A String to search through
/// @param Needle A string to find in entirety
Integer FindCount(const String& Haystack, const String& Needle)
{
    Integer Results = 0;
    size_t LastFound = Haystack.find(Needle);
    while(LastFound != String::npos)
    {
        Results++;
        LastFound = Haystack.find(Needle, LastFound+1);
    }
    return Results;
}

/// @brief This serves as a simple example and sanity test of what this library is intended todo 
int main()
{
    {
        std::stringstream TestStealRDBuf;
        LogStream<char> LogOut(TestStealRDBuf);
        LogOut.SetLoggingLevel(LL_DebugAndHigher);
        LogOut << "Part 1 - Logging against a LogStream backedby an std::stringstream" << std::endl;
        LogOut << "Should be displayed - Default" << std::endl;
        LogOut << LogWarn << "Should be displayed - Warning" << std::endl;
        LogOut << LogError << "Should be displayed - Error" << std::endl;
        LogOut << LogTrace << "Should be NOT displayed - Trace" << std::endl;
        LogOut << LogFatal << "Should be displayed - Fatal" << std::endl;
        String Output(TestStealRDBuf.str());
        std::cout << Output << std::endl;
        TEST(0 == FindCount(Output, "NOT"), "InternalNotsDropped");
        TEST(4 == FindCount(Output, "displayed"), "InternalPassedThrough");
        std::cout << "You should have seen no 'NOT's and 4 messages with the word 'displayed'." << std::endl << std::endl;
    }

    {
        std::stringstream TestRawStream;
        SetStandardLoggingLevel( MergeLogLevel(LL_Trace, LL_Debug,LL_Warn) );
        TestRawStream << "Part 2 - Logging against any other stream" << std::endl;
        TestRawStream << "Should be displayed - Default" << std::endl;
        TestRawStream << LogWarn << "Should be displayed - Warning" << std::endl;
        TestRawStream << LogError << "Should be NOT displayed - Error" << std::endl;
        TestRawStream << LogTrace << "Should be displayed - Trace" << std::endl;
        TestRawStream << LogFatal << "Should be NOT displayed - Fatal" << std::endl;
        String Output(TestRawStream.str());
        std::cout << Output << std::endl;
        TEST(0 == FindCount(Output, "NOT"), "StandardExternalNotsDropped");
        TEST(3 == FindCount(Output, "displayed"), "StandardExternalPassedThrough");
        std::cout << "You should have seen no 'NOT's and 3 messages with the word 'displayed'." << std::endl << std::endl;
    }

    return 0;
}
