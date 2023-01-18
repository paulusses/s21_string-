CC=gcc
OS=$(shell uname)
ifeq ($(OS), Linux)
    LIBS=-lcheck -lpthread -lrt -lm -lsubunit
    OPEN=xdg-open
	
else
    LIBS=-lcheck
    OPEN=open
endif

all: s21_string.a

clean:
	@rm -rf *.o *.gcda *.gcno *.html *.css *.out *.a test gcov_report

s21_string.o: s21_string.c
	gcc -o s21_string.o $^ -c

s21_string.a: s21_string.o
	ar crs $@ $^

test:
	checkmk clean_mode=1 s21_test.check > s21_test.c
	$(CC) s21_string.c -c -o s21_string_test.o
	$(CC) s21_test.c -c -o test_test.o
	$(CC) test_test.o s21_string_test.o -o $@ $(LIBS)
	./$@

install_gcovr:
	echo 'checking if python3 package gcovr is installed ...';
	if python3 -c 'import pkgutil; exit(pkgutil.find_loader("gcovr"))'; then \
		echo 'python package gcovr not found'; \
		echo 'installing gcovr==5.1 ...'; \
		pip3 install gcovr==5.1; \
	fi;
	$(eval GCOVR := $(shell echo $$HOME/Library/Python/$$(pip3 -V | cut -f6 -d" " | cut -c 1-3)/bin/gcovr))

gcov_report: install_gcovr clean s21_string.h s21_string.c s21_test.c
	$(CC) $(CFLAGS)  s21_string.h s21_string.c s21_test.c -o test_cov $(LIBS) --coverage
	./test_cov
	gcov s21_string.gcda s21_string.gcno
	$(GCOVR) --json s21_string.json
	$(GCOVR) -a s21_string.json --html-details coverage.html
	$(OPEN) ./coverage.html
	rm -rf *.gcno *.gcda test_cov *.json s21_string.c.gcov

linter:
	@cp ../materials/linters/CPPLINT.cfg ./
	@find . -name "*.c" -exec python3 ../materials/linters/cpplint.py {} \;
	@find . -name "*.h" -exec python3 ../materials/linters/cpplint.py {} \;
	@rm -f CPPLINT.cfg

.PHONY: linter clean test gcov_report
