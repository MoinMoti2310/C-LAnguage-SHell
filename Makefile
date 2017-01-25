COMPILER=gcc
FLAGS=-c -Wall

all: clash

clash: main.o clash_print_prompt.o clash_loop.o clash_sendsig.o clash_killallbg.o clash_listjobs.o clash_fg.o clash_execute.o clash_read_line.o clash_split_line.o clash_piping_handler.o clash_redirection.o clash_signal.o clash_ctrlz.o clash_ctrlc.o clash_cd.o clash_echo.o clash_pwd.o clash_exit.o clash_pinfo.o
	$(COMPILER) main.o clash_print_prompt.o clash_loop.o clash_sendsig.o clash_killallbg.o clash_listjobs.o clash_fg.o clash_execute.o clash_read_line.o clash_split_line.o clash_piping_handler.o clash_redirection.o clash_signal.o clash_ctrlz.o clash_ctrlc.o clash_cd.o clash_echo.o clash_pwd.o clash_exit.o clash_pinfo.o -o clash

main.o: main.c
	$(COMPILER) $(FLAGS) main.c

clash_print_prompt.o: clash_print_prompt.c
	$(COMPILER) $(FLAGS) clash_print_prompt.c

clash_loop.o: clash_loop.c
	$(COMPILER) $(FLAGS) clash_loop.c

clash_killallbg.o: clash_killallbg.c
	$(COMPILER) $(FLAGS) clash_killallbg.c

clash_sendsig.o: clash_sendsig.c
	$(COMPILER) $(FLAGS) clash_sendsig.c

clash_listjobs.o: clash_listjobs.c 
	$(COMPILER) $(FLAGS) clash_listjobs.c

clash_fg.o: clash_fg.c
	$(COMPILER) $(FLAGS) clash_fg.c

clash_execute.o: clash_execute.c
	$(COMPILER) $(FLAGS) clash_execute.c

clash_read_line.o: clash_read_line.c
	$(COMPILER) $(FLAGS) clash_read_line.c

clash_split_line.o: clash_split_line.c
	$(COMPILER) $(FLAGS) clash_split_line.c

clash_piping_handler.o: clash_piping_handler.c
	$(COMPILER) $(FLAGS) clash_piping_handler.c

clash_redirection.o: clash_redirection.c
	$(COMPILER) $(FLAGS) clash_redirection.c

clash_signal.o: clash_signal.c
	$(COMPILER) $(FLAGS) clash_signal.c

clash_ctrlz.o: clash_ctrlz.c
	$(COMPILER) $(FLAGS) clash_ctrlz.c

clash_ctrlc.o: clash_ctrlc.c
	$(COMPILER) $(FLAGS) clash_ctrlc.c

clash_cd.o: clash_cd.c 
	$(COMPILER) $(FLAGS) clash_cd.c

clash_echo.o: clash_echo.c
	$(COMPILER) $(FLAGS) clash_echo.c

clash_pwd.o: clash_pwd.c
	$(COMPILER) $(FLAGS) clash_pwd.c

clash_exit.o: clash_exit.c
	$(COMPILER) $(FLAGS) clash_exit.c

clash_pinfo.o: clash_pinfo.c
	$(COMPILER) $(FLAGS) clash_pinfo.c

clean:
	rm -rf *.o clash