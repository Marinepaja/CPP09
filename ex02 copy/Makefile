# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 13:47:46 by mechard           #+#    #+#              #
#    Updated: 2025/03/29 07:37:05 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#======================================================
#                   VARIABLES
#======================================================

#------------------------------------------------------
# Variables globales
#------------------------------------------------------

PROJECT         = cpp09
NAME            = PmergeMe
LANG			= c++

#------------------------------------------------------
# Flags de compilation et compilateur
#------------------------------------------------------

# Compilation pour le c++

CXXFLAGS        = -Wall -Wextra -Werror -std=c++98 -g3
CXX             = c++ $(CXXFLAGS) $(CXXHDRFLAG)
CXXHDRFLAG		= $(addprefix -I, $(CHDR_LOCATION))
CXXCOMPI		= $(CXX) $(CXXSRCS) -I./ -o $(NAME)

# Compilation pour le c

CFLAGS			= -Wall -Wextra -Werror -g3
C				= gcc $(CFLAGS) $(CHDRFLAG)
CHDRFLAG		= $(addprefix -I, $(CHDR_LOCATION))
LIBRARY			= -lreadline -lncurses -lXext -lX11 -lm -lXpm -pthread #-fsanitize=address -fsanitize=undefined
LIBFT_EXIST		= $(shell find . -type d -name "libft" -print -quit)

ifeq ($(LIBFT_EXIST),)
	CCOMPI		= $(C) $(CSRCS) -I./ $(LIBRARY) -o $(NAME)
else
	CCOMPI		= $(C) $(CSRCS) -I./ $(LIBRARY) $(LIB_A) -o $(NAME)
endif

# Compilateur

ifeq ($(LANG), c++)
	COMPILATION	= $(CXXCOMPI)
else ifeq ($(LANG), c)
	COMPILATION	= $(CCOMPI)
endif

#------------------------------------------------------
# Fichiers sources et headers
#------------------------------------------------------

# Fichiers sources pour le c++

CXXSRCS				= $(shell find . -type f -not -path "./inc/*" | awk 'length($$0) >= 4 && substr($$0, length($$0)-3, 4) == ".cpp" { print }')
CXXHDRS				= $(shell find . -type f | awk 'length($$0) >= 4 && substr($$0, length($$0)-3, 4) == ".hpp" { print }')
CXXTPPS				= $(shell find . -type f | awk 'length($$0) >= 4 && substr($$0, length($$0)-3, 4) == ".tpp" { print }')
CXXHDR_LOCATION		= $(shell find . -type f | awk 'length($$0) >= 4 && substr($$0, length($$0)-3, 4) == ".hpp" { cmd="dirname "$$0; cmd | getline d; close(cmd); print d }' | sort -u)
CXXSRC_LOCATION		= $(CXXSRCS) $(CXXHDRS) $(CXXTPPS)

# Fichiers sources pour le c

CSRCS				= $(shell find . -type f -not -path "./inc/*" | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".c" { print }')
CHDRS				= $(shell find . -type f -not -path "./inc/libft/*" | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".h" { print }')
CHDR_LOCATION		= $(shell find . -type f | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".h" { cmd="dirname "$$0; cmd | getline d; close(cmd); print d }' | sort -u)
CSRC_LOCATION		= $(CSRCS) $(CHDRS)

# Tout les fichiers sources en une seule variables

ALL					= $(CSRC_LOCATION) $(CXXSRC_LOCATION)

ifeq ($(LANG), c++)
	FILES			= $(CXXSRC_LOCATION)
else ifeq ($(LANG), c)
	FILES			= $(CSRC_LOCATION)
endif

ifeq ($(PROJECT), LIBFT)
	FILES			= $(CSRCS) $(CHDRS)
endif

#------------------------------------------------------
# Couleurs, symboles et autres variables d'affichage
#------------------------------------------------------

# Reset & style
D_COLOR         = \033[0m
BOLD            = \033[1m

# Couleurs texte
BLACK1          = \033[30m
RED1            = \033[31m
GREEN1          = \033[32m
YELLOW1         = \033[33m
BLUE1           = \033[34m
PINK1           = \033[35m
CYAN1           = \033[36m
GREY1           = \033[37m

# Couleurs de fond
BLACK2          = \033[40m
RED2            = \033[41m
GREEN2          = \033[42m
YELLOW2         = \033[43m
BLUE2           = \033[44m
PINK2           = \033[45m
CYAN2           = \033[46m
GREY2           = \033[47m

# Symboles
SUCCESS         = ✅
TELECHARGEMENT  = 🔽🔁
DL_FINISH       = 🔽✅
DELETED         = 💥

# Autres variables
SILENCE         = > /dev/null 2>&1
M           	= make --no-print-directory -C
MAKE			= $(M) ./
LMAKE			= $(M) $(LIB_DIR)
FIN             = =================$(GREEN1)END$(D_COLOR)=================\n

#------------------------------------------------------
# Variables d'affichage (pour les règles begin et under_begin)
#------------------------------------------------------

LINE_WIDTH      = 37
BLOCK_SIZE      = 21
END_SPACES      = 12

#------------------------------------------------------
# Variables pour la librairie
#------------------------------------------------------

# Variables globales pour la librairie

LSRCS 			= $(shell find . -type f -not -path "./inc/*" | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".c" { print }')
LOBJS 			= $(patsubst %.c,%.o,$(notdir $(LSRCS)))
INC				= inc/
EXEC_DIR		= exec/
OBJ_DIR			= obj/
LIB				= libft.a
LIB_DIR			= $(addprefix $(INC), libft/)
LIB_OBJ			= $(addprefix $(LIB_DIR), obj/)
LIB_INC			= $(addprefix $(LIB_DIR), inc/)
LIB_EXEC		= $(addprefix $(LIB_DIR), exec/)
LIB_A			= $(addprefix $(LIB_EXEC), $(LIB))

ifeq ($(PROJECT), LIBFT)
	NAME		= $(addprefix exec/, $(LIB))
endif

# Variable pour la Minilibx

MLX_TITLE			= Minilibx
MLX					= libmlx.a
MIN					= minilibx-linux
LINK_MLX			= https://cdn.intra.42.fr/document/document/26792/minilibx-linux.tgz
MLX_DIR				= $(addprefix $(INC), $(MIN)/)
MLX_A				= $(addprefix $(MLX_DIR), $(MLX))

# Compilation pour la libft

XPM_FLAG 			= -I/usr/include/X11
LHEADERS		 	= -I$(INC) -I$(MLX_DIR) $(XPM_FLAG)
LCC					= cc $(LCFLAG) $(LHEADERS)
LTO_OBJ				= -c
LCOMPI				= $(LCC) $(LIBRARY) $(LTO_OBJ) $(LSRCS)

#======================================================
#                   RÈGLES PRINCIPALES
#======================================================

all: $(NAME)

#------------------------------------------------------
# Compilation de l'exécutable
#------------------------------------------------------

$(NAME): $(FILES)
ifeq ($(filter-out all $(NAME), $(MAKECMDGOALS)), )
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
ifeq ($(LANG), c++)
	@-$(MAKE) c++
else ifeq ($(LANG), c)
ifeq ($(PROJECT), LIBFT)
	@-$(MAKE) compi_libft
else
	@-$(MAKE) c
endif
endif
	@$(MAKE) end

#------------------------------------------------------
# Nettoyage (fichiers temporaires)
#------------------------------------------------------

clean:
ifneq ($(filter-out $(COMPI),$(MAKECMDGOALS)),)
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	@allowed="$(FILES) $(OBJS) $(NAME) Makefile Makefile_OLD"; \
	deleted=0; \
	if [ -d "$(LIB_OBJ)" ]; then \
		$(MAKE) under_begin ARG3="CLEAN"; \
		deleted=1; \
		$(LMAKE) clean $(SILENCE); \
		$(MAKE) suppr_line ARG3=".o dans libft"; \
	fi; \
	for file in $$(find . -type f -not -path "./src/*" -not -path "./inc/*" -not -path "./exec/*" -not -path "./obj/*" -not -name ".gitignore"); do \
		keep=no; \
		for a in $$allowed; do \
			if [ "$$file" = "$$a" ] || [ "$$file" = "./$$a" ]; then \
				keep=yes; \
			fi; \
		done; \
		if [ "$$keep" = "no" ]; then \
			if [ $$deleted -eq 0 ]; then \
				$(MAKE) under_begin ARG3="CLEAN"; \
				deleted=1; \
			fi; \
			rm -f $$file; \
			$(MAKE) suppr_line ARG3=$$file; \
		fi; \
	done; \
	if [ -d $(OBJ_DIR) ]; then \
		if [ $$deleted -eq 0 ]; then \
			$(MAKE) under_begin ARG3="CLEAN"; \
			deleted=1; \
		fi; \
		rm -rf $(OBJ_DIR); \
		$(MAKE) suppr_line ARG3="$(OBJ_DIR)"; \
	fi; \
	if [ -d $(MLX_DIR) ]; then \
		if [ $$deleted -eq 0 ]; then \
			$(MAKE) under_begin ARG3="CLEAN"; \
			deleted=1; \
		fi; \
		rm -rf $(MLX_DIR); \
		$(MAKE) suppr_line ARG3="$(MLX_DIR)"; \
	fi; \
	for dir in $$(find . -type f -name "*.o" -not -path "./src/*" -not -path "./inc/*" -not -path "./exec/*" -exec dirname {} \; | sort -u); do \
	    if [ "$$dir" != "." ]; then \
		    rm -rf $$dir; \
		    $(MAKE) suppr_line ARG3="Directory $$dir"; \
	    fi; \
	done; \
	if [ "$(MAKECMDGOALS)" != "clean" ] && [ $$deleted -eq 1 ]; then \
		printf "|                                   |\n"; \
	fi; \
	if [ $$deleted -eq 0 ]; then \
		echo "|Nothing to be done for 'clean'     |"; \
		if [ -f "$(NAME)" ]; then \
			printf "|                                   |\n"; \
		fi; \
	fi
ifeq ($(MAKECMDGOALS), clean)
	@$(MAKE) end
endif



#------------------------------------------------------
# Nettoyage complet (exécutable, etc.)
#------------------------------------------------------

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(MAKE) under_begin ARG3="FCLEAN"; \
		if [ -d "$(LIB_EXEC)" ]; then \
			rm -rf $(LIB_EXEC); \
			$(MAKE) suppr_line ARG3="$(LIB_EXEC)"; \
		fi; \
		if [ -f "$(NAME)" ]; then \
			rm -rf $(NAME) $(SILENCE); \
			$(MAKE) suppr_line ARG3=$(NAME); \
		fi; \
		if [ -d "$(EXEC_DIR)" ]; then \
			rm -rf $(EXEC_DIR); \
			$(MAKE) suppr_line ARG3="$(EXEC_DIR)"; \
		fi; \
		if [ "$(MAKECMDGOALS)" != "fclean" ]; then \
			echo "|                                   |"; \
		fi; \
	else \
		echo "|Nothing to be done for 'fclean'    |"; \
		if [ $(MAKECMDGOALS) != "fclean" ]; then \
			echo "|                                   |"; \
		fi; \
	fi
ifeq ($(MAKECMDGOALS), fclean)
	@$(MAKE) end
endif

#------------------------------------------------------
# Recompilation totale
#------------------------------------------------------

re: fclean all

#======================================================
#                 AUTRES RÈGLES
#======================================================

#------------------------------------------------------
# Compilation de la librairie statique
#------------------------------------------------------

compi_libft:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		$(MAKE) under_begin ARG3="$(MLX_TITLE)"; \
		echo "|$(PINK1)Téléchargement de la mlx$(D_COLOR)     : $(TELECHARGEMENT)|"; \
		mkdir -p $(MLX_DIR); \
		curl -o $(INC)/minilibx-linux.tgz $(LINK_MLX) $(SILENCE); \
		tar -xzvf $(INC)/minilibx-linux.tgz -C $(INC) $(SILENCE); \
		rm $(INC)/minilibx-linux.tgz; \
		echo "\033[1A\033[2K|$(GREEN1)Minilibx telechargé$(D_COLOR)          : $(DL_FINISH)|"; \
		$(M) $(MLX_DIR) all $(SILENCE); \
		$(MAKE) success ARG3="./minilibx"; \
		printf "|                                   |\n"; \
	fi
	@mkdir -p $(OBJ_DIR)
	@-$(MAKE) under_begin ARG3="$(LIB)"
	@$(LCOMPI)
	@ar rcs $(LIB) $(LOBJS) $(SILENCE)
	@ranlib $(LIB) $(SILENCE)
	@$(MAKE) success ARG3="$(LIB)"
	@mkdir -p $(EXEC_DIR)
	@mv $(LOBJS) $(OBJ_DIR)
	@mv $(LIB) $(EXEC_DIR)

#------------------------------------------------------
# Règle de compilation
#------------------------------------------------------

c :
	@$(MAKE) under_begin ARG3="$(NAME)"
	@if [ ! -f "$(LIB_A)" ] && [ $(LIBFT_EXIST) ]; then \
		$(LMAKE) all $(SILENCE); \
		$(MAKE) success ARG3="$(LIB)"; \
	fi
	@-$(COMPILATION) > res_cmp
	@if [ ! -s res_cmp ]; then \
		rm -rf res_cmp; \
		if [ -s $(NAME) ]; then \
			$(MAKE) success ARG3="$(NAME)"; \
		fi; \
	elif [ -s res_cmp ]; then \
		$(MAKE) error_compi; \
	fi

c++ :
	@$(MAKE) under_begin ARG3="$(NAME)"
	@-$(COMPILATION) > res_cmp
	@if [ ! -s res_cmp ]; then \
		rm -rf res_cmp; \
		if [ -s $(NAME) ]; then \
			$(MAKE) success ARG3="$(NAME)"; \
		fi; \
	elif [ -s res_cmp ]; then \
		$(MAKE) error_compi; \
	fi

#------------------------------------------------------
# Règle de vérification de la norme 42
#------------------------------------------------------

verif_norme :
	-@norminette src/ > res_cmd || true
	-@grep 'Error' res_cmd > norminette || true
	-@norminette $(H_PLACE) > res_cmd || true
	-@grep "Error" res_cmd >> norminette || true
	@rm res_cmd
	@if [ ! -s norminette ]; then \
    	rm norminette; \
		echo "|norminette des .c de $(NAME) : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
	else \
   		echo "\nnorminette des .c de $(NAME) : $(RED1)Erreur ‼️$(D_COLOR)"; \
		cat norminette; \
		echo "\n"; \
	fi

#------------------------------------------------------
# Règle d'affichage "begin"
# Affiche 37 caractères : "=" + bloc central (35) + "="
# Tronque ARG3 (34 + ".") si > 35, " " => "\" \"", 
# puis on centre
#------------------------------------------------------

begin:
	@if [ -z "$(ARG3)" ]; then \
		upper_arg3="\" \""; \
	elif [ "$(ARG3)" = " " ]; then \
		upper_arg3="\" \""; \
	else \
		upper_arg3=$$(echo "$(ARG3)" | tr '[:lower:]' '[:upper:]'); \
	fi; \
	arg_len=$$(echo -n "$$upper_arg3" | wc -c); \
	if [ $$arg_len -gt 35 ]; then \
		truncated_arg3=$$(echo -n "$$upper_arg3" | cut -c1-34).; \
		printf "\n="; \
		printf "$(PINK1)$$truncated_arg3$(D_COLOR)"; \
		printf "=\n|                                   |\n"; \
	else \
		leftover=$$(( 35 - arg_len )); \
		left_equals=$$(( leftover / 2 )); \
		right_equals=$$(( leftover - left_equals )); \
		printf "\n="; \
		for _ in $$(seq 1 $$left_equals); do printf "="; done; \
		printf "$(PINK1)$$upper_arg3$(D_COLOR)"; \
		for _ in $$(seq 1 $$right_equals); do printf "="; done; \
		printf "=\n|                                   |\n"; \
	fi
	@-$(MAKE) under_begin ARG3="$(PROJECT)"
	@-$(MAKE) under_begin ARG3="$(LANG)"

#------------------------------------------------------
# Règle d'affichage "under_begin"
# Affiche une ligne de 37 caractères :
# |  + bloc central de 21 caractères + 12 espaces + |
# Bloc central : si ARG3 > 19 caractères, on tronque à 18 caractères et on ajoute un point.
# Sinon, on centre ARG3 en entourant de '=' pour atteindre 21 caractères.
#------------------------------------------------------

under_begin:
	@if [ -z "$(ARG3)" ]; then \
		upper_arg3=" "; \
	else \
		upper_arg3=$$(echo "$(ARG3)" | tr '[:lower:]' '[:upper:]'); \
	fi; \
	upper_project=$$(echo "$(PROJECT)" | tr '[:lower:]' '[:upper:]'); \
	upper_lang=$$(echo "$(LANG)" | tr '[:lower:]' '[:upper:]'); \
	if [ "$$upper_arg3" = "$$upper_project" ] || [ "$$upper_arg3" = "$$upper_lang" ]; then \
	    block_size=31; \
	    spaces_after=2; \
		color=$(BLUE1); \
	else \
	    block_size=21; \
	    spaces_after=12; \
		color=$(YELLOW1); \
	fi; \
	arg_len=$$(echo -n "$$upper_arg3" | wc -c); \
	printf "|  "; \
	threshold=$$(( block_size - 2 )); \
	if [ $$arg_len -gt $$threshold ]; then \
	    truncated_arg3=$$(echo -n "$$upper_arg3" | cut -c1-$$(( block_size - 3 ))).; \
	    printf "=%s=" "\\$$color$$truncated_arg3$(D_COLOR)"; \
	else \
	    leftover=$$(( block_size - arg_len )); \
	    left_equals=$$(( leftover / 2 )); \
	    right_equals=$$(( leftover - left_equals )); \
	    for _ in $$(seq 1 $$left_equals); do printf "="; done; \
	    printf "\\$$color$$upper_arg3$(D_COLOR)"; \
	    for _ in $$(seq 1 $$right_equals); do printf "="; done; \
	fi; \
	for _ in $$(seq 1 $$spaces_after); do printf " "; done; \
	if [ "$$upper_arg3" != "$$upper_project" ]; then \
	    printf "|\n|                                   "; \
	fi; \
	printf "|\n";

#------------------------------------------------------
# Règle d'affichage "suppr_line"
# Affiche une ligne de 37 caractères contenant ARG3 ajusté
# sur 29 caractères (tronqué ou complété) suivi de " : 💥  "
# pour signaler la suppression d'un fichier.
#------------------------------------------------------

suppr_line:
	@{ \
		if [ -z "$(ARG3)" ]; then \
			display_arg3="\" \""; \
		else \
			display_arg3="$(ARG3)"; \
		fi; \
		arg_len=$$(echo -n "$$display_arg3" | wc -c); \
		if [ $$arg_len -gt 28 ]; then \
			truncated=$$(echo -n "$$display_arg3" | cut -c1-25); \
			field="$$truncated..."; \
		else \
			field="$$display_arg3"; \
			pad=$$((28 - arg_len)); \
			i=1; \
			while [ $$i -le $$pad ]; do \
				field="$$field "; \
				i=$$(( i + 1 )); \
			done; \
		fi; \
		printf "|$(RED2)%s$(D_COLOR) : $(DELETED)  |\n" "$$field"; \
	}

#------------------------------------------------------
# Règle d'affichage "success"
# Affiche une ligne de 37 caractères contenant ARG3 ajusté
# sur 29 caractères (tronqué ou complété) suivi de " : ✅  "
# pour signaler la suppression d'un fichier.
#------------------------------------------------------

success :
	@{ \
		if [ -z "$(ARG3)" ]; then \
			display_arg3="\" \""; \
		else \
			display_arg3="$(ARG3)"; \
		fi; \
		arg_len=$$(echo -n "$$display_arg3" | wc -c); \
		if [ $$arg_len -gt 28 ]; then \
			truncated=$$(echo -n "$$display_arg3" | cut -c1-25); \
			field="$$truncated..."; \
		else \
			field="$$display_arg3"; \
			pad=$$((28 - arg_len)); \
			i=1; \
			while [ $$i -le $$pad ]; do \
				field="$$field "; \
				i=$$(( i + 1 )); \
			done; \
		fi; \
		printf "|%s$(D_COLOR) : $(SUCCESS)  |\n" "$$field"; \
	}

#------------------------------------------------------
# Règle d'affichage "end"
#------------------------------------------------------

end:
	@printf "|                                   |\n"
	@echo "$(FIN)"

#======================================================
#              RÈGLES PHONY (obligatoires)
#======================================================

.PHONY: all clean fclean re begin under_begin suppr_line end