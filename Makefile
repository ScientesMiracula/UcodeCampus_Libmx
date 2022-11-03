clang_flags := -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME := libmx.a

utils_pack := mx_printchar mx_print_unicode mx_printstr mx_print_strarr mx_printint mx_pow mx_sqrt mx_nbr_to_hex mx_hex_to_nbr mx_itoa mx_foreach mx_binary_search mx_bubble_sort mx_quicksort

string_pack := mx_strlen mx_swap_char mx_str_reverse mx_del_strarr mx_get_char_index mx_strdup mx_strndup mx_strcpy mx_strncpy mx_strcmp mx_strcat mx_strstr mx_get_substr_index mx_count_substr mx_count_words mx_strnew mx_strtrim mx_del_extra_spaces mx_strsplit mx_strjoin mx_file_to_str mx_replace_substr mx_read_line

memory_pack := mx_memset mx_memcpy mx_memccpy  mx_memcmp mx_memchr mx_memrchr mx_memmem  mx_memmove mx_realloc

list_pack := mx_create_node mx_push_front mx_push_back mx_pop_front mx_pop_back mx_list_size mx_sort_list

extra_pack :=  mx_is_digit mx_is_space mx_is_alpha mx_is_upper mx_is_lower mx_strchr mx_strncmp mx_pop_index mx_push_index mx_clear_list

actual_developing_parts := $(extra_pack) $(utils_pack) $(string_pack) $(memory_pack) $(list_pack)

all: $(NAME) clean

$(NAME): 
	make objects
	ar rvs $(NAME) $(addprefix obj/,$(addsuffix .o,$(actual_developing_parts)))

objects:
	mkdir -p obj
	clang $(clang_flags) -c -I inc $(addprefix src/,$(addsuffix .c,$(actual_developing_parts)))
	cp $(addsuffix .o,$(actual_developing_parts)) obj
	rm -rf $(addsuffix .o,$(actual_developing_parts))

uninstall:
	make clean
	rm -rf $(NAME) 

clean:
	rm -rf $(addprefix obj/,$(addsuffix .o,$(actual_developing_parts)))

reinstall:
	make uninstall
	make all


