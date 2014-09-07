Stream Logging
=============

A small set of upgrades to C++ streams to make them more suitable for logging. 

Specifically this provides an additional stream that can optionally stream
messages based on severity. The stream can be configured at runtime to respect
only some messages and drop the rest.

The are some stream manipulators provided as well. These are items that when
sent to a stream will change its logging behavior rather than insert actual
content into the stream.

The are 3 files of note in this library

   1. main.cpp - This is a small sample of this libraries intended use and
                 sanity tests. For examples please see this file. To compile
                 this use CMake or include this can the other 2 files in a 
                 build project and compile them.

   2. streamlogging.h - This needs to be included where you would to use the 
                        new LogStream class and the new manipulators.

   3. streamlogging.cpp - The few items that require real code are implented
                          in this file.
