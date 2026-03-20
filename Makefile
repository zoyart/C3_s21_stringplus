TARGET = s21_string
CC = gcc
# CFLAGS = -std=c11 -Wall -Wextra -Werror
GCOV_FLAGS = --coverage -fprofile-arcs -ftest-coverage
# sudo apt install lcov -y

s21_sprintf:
	$(CC) -g main.c s21_string.c s21_sprintf.c $(CFLAGS) -o s21_sprintf
	./s21_sprintf
# 	rm -f s21_sprintf
test:
	bash tests/test_s21_cat.sh
clean:
	rm -f $(TARGET)
style:
	clang-format -n ./*.c ./*.h
style_fix:
	clang-format -i ./*.c ./*.h
valgrind: $(TARGET)
	valgrind --tool=memcheck --leak-check=yes ./$(TARGET)

# -lcheck - сама библиотека для тестирования
# -lm - математика
# -lsubunit - формат вывода результатов тестов, который использует check
test_s21_sprintf:
	$(CC) ./tests/test_sprintf.c s21_sprintf.c $(CFLAGS) -lcheck -lm -lsubunit -o test_sprintf
	./test_sprintf
	rm -f test_sprintf
test_s21_string:
	$(CC) ./tests/test_string.c s21_string.c $(CFLAGS) -lcheck -lm -lsubunit -o test_string
	./test_string
	rm -f test_string
include_libs:
	sudo apt install check -y
remove_libs:
	sudo apt remove check -y
gcov_report:
	$(CC) ./tests/test_sprintf.c s21_sprintf.c $(CFLAGS) $(GCOV_FLAGS) -lcheck -lm -lsubunit -o test_gcov
	./test_gcov
	gcov test_gcov-s21_sprintf.gcda
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	rm -f *.gcda *.gcno *.gcov coverage.info test_gcov
clean_tests:
	rm -f $(TARGET) test_sprintf test_gcov
	rm -f *.o *.a *.gcda *.gcno *.gcov coverage.info
	rm -rf gcov_report
.PHONY: tests