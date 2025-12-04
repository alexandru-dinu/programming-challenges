INPUT=input

.PHONY: solve
solve: solve.py
	cat $(INPUT) | python3 $^

.PHONY: test
test: solve.py
	pytest -vv $^

.PHONY: viz
viz: viz.py
	cat $(INPUT) | python3 $^
