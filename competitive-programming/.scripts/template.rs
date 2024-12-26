// Thanks to https://codeforces.com/profile/Bassel

use std::io::*;

fn solve(input: &mut Input) -> () {
    ;
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

        // TODO: find a better way to deal with whitespace...
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