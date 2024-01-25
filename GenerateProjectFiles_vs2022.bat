@echo off

SET visualstudio=vs2022
SET project=ProjectB
SET script=GameEngine\Script\GenerateProjectFiles.bat

%script% %visualstudio% %project% On