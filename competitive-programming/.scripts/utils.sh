run-cpp () {
    local prog="$1"
    g++ -o $prog $prog.cpp
    diff <( ./$prog < "in" ) "out"
    rm $prog
}

run-rust () {
    local prog="$1"
    rustc $prog.rs
    diff <( ./$prog < "in" ) "out"
    rm $prog
}
