PROG = pipex

SRCS = srcs/pipex.c srcs/pipex_aux.c
OBJS = ${SRCS:.c=.o}

HEADER = -Iincludes

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

# This is for the easter egg
WAIT_TIME = 4

.c.o:	%.o : %.c
		@ gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all:	${PROG}

${PROG}:	${OBJS}
			@echo "\033[33m|-----Compiling Pixpex-----|"
			@make re -C ./libft
			@$(CC) $(OBJS) -Llibft -lft -o ${PROG}
			@echo "\033[32mPipex Successfuly Compiled! - 🎉\033[0m"

clean:	
		@make clean -C ./libft
		@rm -rf ${OBJS}

fclean:	clean
		@make fclean -C ./libft
		@rm -rf ${NAME}
		@rm -rf ${PROG}
		@echo "\n\033[31mEXPLOSION NUCLEAR!💥\033[0m"

re:		fclean all

easteregg:
			@clear
			@echo "\033[35m(NARRADOR)---->\033[0m La noche cae sobre la mansion Encantada. \n Un rayo ilumina la silueta del investigador que se aproxima a la puerta principal. \n Ha sido llamado para investigar la muerte del Sr. Brown, un acaudalado hombre de negocios, \n durante una fiesta en la mansion. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Investigador)---->\033[0m [Toca la puerta] - TOC; TOC; TOC \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Sr.Black)----->\033[0m [Abre la puerta, visiblemente nervioso] - Buenas Noches, inspector. Le estabamos esperando. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Investigador)----->\033[0m Buenas noches, Sr Black. \n Soy el detective a cargo de este caso. \n Necesito entrar y examinar este crimen. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Sr. Black)----->\033[0m Por supuesto, siga adelante. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(NARRADOR)----->\033[0m El investigador ingresa a la mansión, \n un lugar lleno de muebles antiguos y retratos de familia. \n El ambiente es lúgubre y cargado de tensión. \n"
			@sleep ${WAIT_TIME}
			@clear
			@echo "\033[35m<-----EMPIEZA LA INVESTIGACIÓN----->\033[0m \n"
			@sleep 5
			@clear
			@echo "\033[35m(NARRADOR)----->\033[0m El investigador examina el cuerpo del Sr. Brown, que se encuentra en la biblioteca. \n Observa una herida de cuchillo en el pecho. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Investigador)----->\033[0m [Hablando consigo mismo] - ¿Quien pudo haber hecho esto? \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Sra. White)----->\033[0m [Entra a la habitación, llorando] ¡No puedo creerlo! \n ¡Era un hombre tan bueno! \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Investigador)----->\033[0m Tranquilicese, Señora White. \n Necesito hacerle algunas preguntas. \n ¿Vio algo sospechoso anoche? \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Sra. White)----->\033[0m No, nada. Solo vi al Sr. Brown discutiendo con el Sr. Green en el jardín antes de la cena. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Investigador)----->\033[0m ¿Y de qué discutían? \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Sra. White)----->\033[0m No lo sé, pero se veían muy enojados. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(NARRADOR)----->\033[0m El investigador interroga al Sr. Green, quien confirma la discusión, pero niega haber cometido el crimen. \n"
			@sleep 5
			@echo "\033[35m(Sr. Green)----->\033[0m Es cierto que discutimos, pero yo no lo maté. ¡Alguien más lo hizo! \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Investigador)----->\033[0m ¿Tiene alguna sospecha de quién podría ser? \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Sr. Green)----->\033[0m No, señor. \n"
			@sleep ${WAIT_TIME}
			@clear
			@echo "\033[35m<-----LLEGAMOS A UNA CONCLUSION----->\033[0m \n"
			@sleep 5
			@clear
			@echo "\033[35m(NARRADOR)----->\033[0m Tras analizar las pistas y los testimonios, el investigador llega a una conclusión. \n"
			@sleep ${WAIT_TIME}
			@echo "\033[35m(Investigador)----->\033[0m (Reuniendo a los sospechosos) He reunido suficiente evidencia para saber quién es el responsable de la muerte del Sr. Brown. El culpable es... \n"
			@bash ~/scripts/conclusion.sh



.PHONY: all clean fclean re
