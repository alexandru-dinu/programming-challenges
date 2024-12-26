// https://leetcode.com/problems/tenth-line

# Read from the file file.txt and output the tenth line to stdout.

awk 'NR==10' file.txt

# sed -n "10p" file.txt

# cat file.txt | head -n10 | tail -n1 # will give last line if num lines < 10

# python3 -c '
# with open("file.txt") as fp:
#     xs = fp.readlines()
# try:
#     print(xs[9].strip())
# except IndexError:
#     print('')
# '