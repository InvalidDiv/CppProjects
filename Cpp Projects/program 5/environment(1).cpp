/* environment.cpp
 *     Use environment variables to test what system we are on.  This can be
 *     useful if you want to run different sections of your code depending what
 *     machine you are on.  For instance, you might want to run a different
 *     clear screen command on linux as opposed to Windows.
 *
 *     See a sample run at the bottom of this file.
 *
 *  Author: Dale Reed
 *  System: Dev-C++ compiler on Windows XP, also g++ on linux
 *  Date: Jan 26, 2006
 */

#include <iostream>
using namespace std;

//-------------------------------------------------------------
// Main part of program.  You may not have previously seen
// the items inside of the parenthesis following main().
// These can be left off if you are not using them.
// 
int main( int argc,       // command line argument counter 
          char *argv[],   // command line argument vector (an array)
          char *env[])    // environment variable array
{
   char clearCommand[ ] = "     ";  // will store the clear string
   bool runningOnLinux = true;      // flag to mark what system we're on, default to linux 

   // The 8th entry of the env array is "OSTYPE=linux" on oscar.cs.uic.edu
   // The strcmp command below does a string comparison between entry 8 of the 
   // environment variables array, and the expected string "OSTYPE=linux"
   // The comparison returns a value of 0 if they are equal.
   if ( strcmp(env[ 8],"OSTYPE=linux") == 0) {
        // we are on linux
        cout << "OSTYPE is linux \n";
        // set the clear command for linux
        strcpy( clearCommand, "clear");
   }
   else {
        // we are not on linux
        cout << "OSTYPE is NOT linux \n";
        // set the clear command for windows
        strcpy( clearCommand, "cls");
        runningOnLinux = false;         // set flag to indicate not on linux
   }   
   
   // Display message and pause, using the appropriate clear command
   cout << "Press enter to clear the screen and display other environment variables....";
   cin.ignore();        // ignore the next character of input
   // clear the screen using the system command
   system( clearCommand);

   // Now display ALL the environment variables, probably more stuff than you want 
   for ( int i = 0; env[i] != NULL; ++i ){
       cout<<env[i]<<endl;
   }

   // check if we're not on linux, in which case we'll assume windows
   if ( !runningOnLinux) {
        // pause the display, assuming we're running Dev-C++ on windows
        system("PAUSE");
   }

   // Display message and pause, using the appropriate clear command
   cout << "Press enter to clear the screen and exit this program..."; 
   cin.ignore();        // ignore the next character of input
   // clear the screen using the system command
   system( clearCommand);
   
   return 0;        // Keep C++ happy
}


/* Below you can find the results of running this program on both Windows and linux
   Note that both property names as well as values are different.

Running this program on a Windows machine gives:
        
    OSTYPE is NOT linux
    Press enter to clear the screen and display other environment variables....
    
    ALLUSERSPROFILE=C:\Documents and Settings\All Users
    APPDATA=C:\Documents and Settings\Dale Reed\Application Data
    CLASSPATH=C:\Program Files\Java\jre1.5.0_04\lib\ext\QTJava.zip
    CommonProgramFiles=C:\Program Files\Common Files
    COMPUTERNAME=TELEMACHUS
    ComSpec=C:\WINDOWS\system32\cmd.exe
    FP_NO_HOST_CHECK=NO
    HOMEDRIVE=C:
    HOMEPATH=\
    LOGONSERVER=\\TELEMACHUS
    NUMBER_OF_PROCESSORS=1
    NWLANGUAGE=ENGLISH
    NWUSERNAME=reed
    OS=Windows_NT
    Path=C:\Dev-Cpp\Bin;C:\Dev-Cpp\Bin;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\Sys
    tem32\Wbem;C:\WINDOWS\system32\nls;C:\WINDOWS\system32\nls\ENGLISH;C:\PROGRA~1\C
    OMMON~1\Odbc\FILEMA~1;C:\Program Files\Java\jdk1.5.0_04\bin;C:\Program Files\Qui
    ckTime\QTSystem\;c:\matlab\bin\win32;C:\Program Files\SSH Communications Securit
    y\SSH Secure Shell;X:.;
    PATHEXT=.COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH
    PROCESSOR_ARCHITECTURE=x86
    PROCESSOR_IDENTIFIER=x86 Family 15 Model 2 Stepping 4, GenuineIntel
    PROCESSOR_LEVEL=15
    PROCESSOR_REVISION=0204
    ProgramFiles=C:\Program Files
    QTJAVA=C:\Program Files\Java\jre1.5.0_04\lib\ext\QTJava.zip
    SystemDrive=C:
    SystemRoot=C:\WINDOWS
    TEMP=C:\DOCUME~1\DALERE~1\LOCALS~1\Temp
    TMP=C:\DOCUME~1\DALERE~1\LOCALS~1\Temp
    USERDOMAIN=TELEMACHUS
    USERNAME=Dale Reed
    USERPROFILE=C:\Documents and Settings\Dale Reed
    windir=C:\WINDOWS
    WINDOWS_LOGIN=0
    Press any key to continue . . .
    
    Press enter to clear the screen and exit this program...

Running on linux (oscar.cs.uic.edu) gives:

    OSTYPE is linux 
    Press enter to clear the screen and display other environment variables....
    
    TERM=vt100
    HOME=/home4/fac4/reed
    SHELL=/bin/tcsh
    USER=reed
    LOGNAME=reed
    PATH=./:/usr/kerberos/bin:/usr/local/bin:/bin:/usr/bin:/usr/X11R6/bin:/usr/java/j2sdk/bin:/usr/java/jgrasp/bin:/usr/java/eclipse:/usr/local/vw7.2.1nc:/home4/fac4/reed/bin:/home4/fac4/reed/sml/bin
    HOSTTYPE=i386-linux
    VENDOR=intel
    OSTYPE=linux
    MACHTYPE=i386
    SHLVL=1
    PWD=/home4/fac4/reed/109
    GROUP=faculty
    HOST=oscar.cs.uic.edu
    REMOTEHOST=logos.cs.uic.edu
    MAIL=/var/spool/mail/reed
    LS_COLORS=no=00:fi=00:di=01;34:ln=01;36:pi=40;33:so=01;35:bd=40;33;01:cd=40;33;01:or=01;05;37;41:mi=01;05;37;41:ex=01;32:*.cmd=01;32:*.exe=01;32:*.com=01;32:*.btm=01;32:*.bat=01;32:*.sh=01;32:*.csh=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.gz=01;31:*.bz2=01;31:*.bz=01;31:*.tz=01;31:*.rpm=01;31:*.cpio=01;31:*.jpg=01;35:*.gif=01;35:*.bmp=01;35:*.xbm=01;35:*.xpm=01;35:*.png=01;35:*.tif=01;35:
    G_BROKEN_FILENAMES=1
    SSH_ASKPASS=/usr/libexec/openssh/gnome-ssh-askpass
    KDEDIR=/usr
    LANG=en_US.UTF-8
    SUPPORTED=en_US.UTF-8:en_US:en
    LESSOPEN=|/usr/bin/lesspipe.sh %s
    HOSTNAME=oscar.cs.uic.edu
    VISUALWORKS=/usr/local/vw7.2.1nc
    XKEYSYMDB=/usr/local/X11/lib/X11/XKeysymDB
    XNLSPATH=/usr/local/X11/lib/X11/nls
    LD_LIBRARY_PATH=/usr/local/gnu/lib:/usr/local/X11/lib:/usr/openwin/lib:/opt/SUNWspro/lib:/usr/dt/lib:/usr/local/lib
    Press enter to clear the screen and exit this program...

 */
