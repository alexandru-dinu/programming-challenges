USING: kernel math prettyprint ranges sequences ;
IN: p9.factor

! TODO: unhardcode 1000 (currying?)
! TODO: second loop should start from the 1st
1000 dup [ [1..b] ] dup bi
[
    [ + 2 * 1000 * ]    ! 2s(a+b)
    [ * 2 * 1000 sq + ] ! 2ab+s^2
    2bi =
]
cartesian-find
rot 2over + - * *
