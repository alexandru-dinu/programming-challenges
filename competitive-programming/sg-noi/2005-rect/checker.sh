for i in $(seq 1 5); do
    echo Input $i
    time diff <(python rect.py tests/RECT.IN$i) tests/RECT.OU$i
    perl -E "print '*' x 64" && echo
done
