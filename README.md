Stream Logging
=============

A small set of upgrades to C++ streams to make them more suitable for logging. 

Specifically this provides an additional stream that can optionally stream
messages based on severity. The stream can be configured at runtime to respect
only some messages and drop the rest. When creating a LogStream another streamlog
must be passed to configure where and how it will write streamed data.

The are some stream manipulators provided as well. These are items that when
sent to a stream will change its logging behavior rather than insert actual
content into the stream.

There are some facilities for using these manipulators and loglevels with the
normal std streams. All std streams share a single configuration for what they
will and will not write, for this reason it is inadvisable to use this with std
streams in a multi threaded situation.

The LogLevels used in this library are a bitmap mask. Instead of assigning each
LogLevel a number and logging everything of that level or higher the severity
of each message is compared bitwise with the list of severities to be logged.
If any match the messages is written, otherwise it is dropped. There is a 
series of default LogLevel values that make duplicating the 'this severity or
higher' behavior, but this allows for fine grained control should it be needed.

The are 3 files of note in this library

   1. main.cpp - This is a small sample of this libraries intended use and
                 sanity tests. For examples please see this file. To compile
                 this use CMake or include this can the other 2 files in a 
                 build project and compile them.

   2. streamlogging.h - This needs to be included where you would to use the 
                        new LogStream class and the new manipulators.

   3. streamlogging.cpp - The few items that require real code are implented
                          in this file.

To use this library in your project simply include streamlogging.h and
streamlogging.cpp as you would any other C++ files.

