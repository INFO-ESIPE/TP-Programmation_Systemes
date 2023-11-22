CFLAGS=-Wall
GENFILES=man_gcc buffered unbuffered

.PHONY: test
test: $(GENFILES)
	@echo "--"
	time ./buffered <man_gcc >/dev/null
	@echo "--"
	time ./unbuffered <man_gcc >/dev/null

man_gcc: makefile
	rm -f man_gcc
	for i in $$(seq 10); do man gcc >>man_gcc 2>/dev/null; done

.PHONY: clean
clean:
	rm -f $(GENFILES)

