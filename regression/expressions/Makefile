TESTS=$(sort $(basename $(wildcard generated*.expr)))

RC=~/development/nox/target/debug/nox
RT=../runtime.c

.PHONY: check $(TESTS)

check: $(TESTS)

$(TESTS): %: %.expr
	@printf "$@.."
	@$(RC) compile $< > $@.s && gcc -m32 $(RT) $@.s -o $@ && cat $@.input | ./$@ > $@.log && diff $@.log orig/$@.log
	@cat $@.input | $(RC) interpret $< > $@.log && diff $@.log orig/$@.log
	@cat $@.input | $(RC) sm $< > $@.log && diff $@.log orig/$@.log
	@printf " success\n"

clean:
	rm -f test*.log *.s *~ $(TESTS)
