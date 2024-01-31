@echo off

@REM 실행할 모드입니다.
SET mode=%1

@REM 프로젝트 이름입니다.
SET project=%2

@REM 실행 파일 경로입니다.
SET path="%~dp0..\..\Solution\%mode%\%project%.exe"

@REM 루트 경로입니다.
SET rootPath=%~dp0..\..\

if "%mode%" == "Debug" (
    echo Run %mode% mode...
) else if "%mode%" == "Release" (
    echo Run %mode% mode game...
) else if "%mode%" == "RelWithDebInfo" (
    echo Run %mode% mode game...
) else if "%mode%" == "MinSizeRel" (
    echo Run %mode% mode game...
) else (
    echo "%mode%" is illegal mode...
    GOTO:EOF
)

echo %path%
echo rootPath="%rootPath%"

start "" %path% devMode=on rootPath=%rootPath%