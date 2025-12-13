.PHONY: solve
solve: solve.ipynb
	uv run jupyter nbconvert --to script $< --stdout 2>/dev/null | uv run python3 -
