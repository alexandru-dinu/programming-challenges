INPUT=input

.PHONY: solve
solve: solve1.py solve2.py
	# cat $(INPUT) | python3 $(word 1,$^)
	cat $(INPUT) | python3 $(word 2,$^)

# .PHONY: test
# test: solve1.py solve2.py
# 	pytest -vv $^
