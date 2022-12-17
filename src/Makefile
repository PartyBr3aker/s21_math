CC=gcc
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
SRCS = $(filter-out test_s21_math.c, $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
TEST_NAME = test_math

all: s21_math.a gcov_report

s21_math.a: $(OBJS)
	ar rc s21_math.a $(OBJS) 
	ranlib s21_math.a

test: $(OBJS) ./Test/*.c test_s21_math.c
	$(CC) $(CFLAGS) $(CHECK_FLAGS) ./Test/*.c test_s21_math.c $(OBJS) -o $(TEST_NAME)
	./$(TEST_NAME)

gcov_report: ./Test/*.c test_s21_math.c
	$(CC) -o $(TEST_NAME) $(SRCS) ./Test/*.c test_s21_math.c $(ALL_FLAGS) 
	./$(TEST_NAME)
	geninfo *.gcda *.gcno -b . -o check_res 
	genhtml check_res -o report

clean:
	rm -rf $(OBJS) *.o *.gcno *.gcda *.info *.a $(TEST_NAME) report check_res