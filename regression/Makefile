TESTS=test001 test002 test003 test004 test005 test006 test007 test008

RC=~/development/nox/target/debug/nox
RT=./runtime.c

.PHONY: check $(TESTS)

check: $(TESTS)

$(TESTS): %: %.expr
	@$(RC) compile $< > $@.s && gcc -m32 $(RT) $@.s -o $@ && cat $@.input | ./$@ > $@.log && diff $@.log orig/$@.log
	@cat $@.input | $(RC) interpret $< > $@.log && diff $@.log orig/$@.log
	@cat $@.input | $(RC) sm $< > $@.log && diff $@.log orig/$@.log

clean:
	rm -f test*.log *.s *~ $(TESTS)
