INPUT=input

.PHONY: solve
solve: solve.py
	cat $(INPUT) | uv run python3 $^

.PHONY: test
test: solve.py
	uv run pytest -vv $^
