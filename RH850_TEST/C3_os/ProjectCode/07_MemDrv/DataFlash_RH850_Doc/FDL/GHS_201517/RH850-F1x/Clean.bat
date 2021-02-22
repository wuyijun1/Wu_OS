@rem ##########################################################
@rem # Sample application                                     #
@rem #       Batchfile to clean project                       #
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
echo # Clean EEPROM Emulation sample application              #
echo ##########################################################
echo.

rem ##########################################################
rem # Clean software                                         #
rem ##########################################################
make.exe clean
echo.
echo ##########################################################
echo.
echo.
echo.

rem ##########################################################
rem # Enable printing of each command to standard output     #
rem ##########################################################
@echo on


