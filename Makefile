build_l:
	g++ -o M3UCreator main.cpp

build_w:
	g++ -o M3UCreator.exe main.cpp

clear_l:
	rm -f M3UCreator M3U_Creator.M3U

clear_w:
	cmd /C del /f M3UCreator.exe M3U_Creator.M3U