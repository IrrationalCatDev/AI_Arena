@echo off
if exist "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" (
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
) else (
    call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
)
set compilerflags=/Od /Zi /EHsc /std:c++latest /I include /I C:\SDL2-2.0.10\include /I SDL2_Game_Framework
set linkerflags=/OUT:bin\main.exe /SUBSYSTEM:WINDOWS /LIBPATH:"lib" SDL2.lib SDL2main.lib SDL2_image.lib
cl.exe %compilerflags% src\*.cpp SDL2_Game_Framework\*.cpp /link %linkerflags%
del bin\*.ilk *.obj *.pdb