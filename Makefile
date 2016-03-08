echo: echo.c
	gcc -static -o echo echo.c
	execstack -s echo
