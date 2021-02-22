@rem ##########################################################
@rem # Sample application                                     #
@rem #       Batchfile to build project                       #
@rem ##########################################################

@rem ##########################################################
@rem # Prevent printing of each command to standard output    #
@rem ##########################################################
@echo off

rem ##########################################################
rem # Adjust path variable to be sure to use correct make    #
rem ##########################################################
path=%WINDIR%;%WINDIR%\System32\

rem ##########################################################
rem # Show some additional information                       #
rem ##########################################################
echo.
echo.
echo.
echo ##########################################################
echo # Build EEPROM Emulation sample application             #
echo ##########################################################
echo.

rem ##########################################################
rem # Build software                                         #
rem ##########################################################
make.exe SampleApp register=22
echo.
echo ##########################################################
echo.
echo.
echo.

rem ##########################################################
rem # Enable printing of each command to standard output     #
rem ##########################################################
@echo on


