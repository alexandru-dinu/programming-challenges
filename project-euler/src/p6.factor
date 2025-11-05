USING: kernel math prettyprint tools.test ;
IN: p6.factor

: sq-sum ( n -- n )
    dup 1 + * 2 /i sq ;

: sum-sq ( n -- n )
    dup [ 1 + ] [ 2 * 1 + ] bi * * 6 /i ;

: solve ( n -- n )
    [ sq-sum ] [ sum-sq ] bi - ;

{ 2640 } [ 10 solve ] unit-test

100 solve
