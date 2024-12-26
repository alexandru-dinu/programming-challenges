use std::io::*;

struct Point {
    x: i32,
    y: i32,
}

fn order(a: i32, b: i32, c: i32) -> bool {
    (a < b && b < c) || (a > b && b > c)
}

fn same_row(a: &Point, b: &Point, c: &Point) -> bool {
    (a.y == b.y) && (b.y == c.y)
}

fn same_col(a: &Point, b: &Point, c: &Point) -> bool {
    (a.x == b.x) && (b.x == c.x)
}

fn solve(input: &mut Input) -> () {
    let a = Point {
        x: input.next(),
        y: input.next(),
    };
    let b = Point {
        x: input.next(),
        y: input.next(),
    };
    let f = Point {
        x: input.next(),
        y: input.next(),
    };

    let mut ans: i32 = (a.x - b.x).abs() + (a.y - b.y).abs();

    let row_test: bool = same_row(&a, &b, &f) && order(a.x, f.x, b.x);
    let col_test: bool = same_col(&a, &b, &f) && order(a.y, f.y, b.y);

    if row_test || col_test {
        ans += 2
    };

    println!("{}", ans);
}

fn main() {
    let input = &mut Input::new();

    let tc: i32 = input.next();

    for _ in 1..=tc {
        solve(input);
    }
}

// boilerplate

struct Input {
    buf: Vec<String>,
}

impl Input {
    fn new() -> Self {
        Input { buf: Vec::new() }
    }

    fn next_line(&mut self) -> String {
        let mut line = String::new();
        stdin().read_line(&mut line).expect("ERROR: read_line");
        line = line.trim().to_string();

        if line.len() == 0 {
            return self.next_line();
        }

        line
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        if self.buf.is_empty() {
            self.buf = self
                .next_line()
                .split_whitespace()
                .rev() // because of pop()
                .map(String::from)
                .collect();
        }

        self.buf.pop().unwrap().parse().ok().expect("ERROR: parse")
    }
}
