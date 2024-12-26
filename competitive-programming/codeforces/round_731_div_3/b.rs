use std::io::*;

fn solve(input: &mut Input) -> () {
    let s: Vec<char> = input.next_line().chars().collect();

    let k = s.iter().position(|&c| c == 'a');

    if k.is_none() {
        println!("NO");
        return;
    }

    let idx: usize = k.unwrap();
    let mut l: Option<usize> = if idx == 0 { None } else { Some(idx - 1) };
    let mut h: usize = idx + 1;

    for i in 1..s.len() {
        let c: char = (('a' as u8) + (i as u8)) as char;

        if l.is_some() && s[l.unwrap()] == c {
            l = if l.unwrap() == 0 {
                None
            } else {
                Some(l.unwrap() - 1)
            };
        } else if h < s.len() && s[h] == c {
            h += 1;
        } else {
            println!("NO");
            return;
        }
    }

    println!("YES");
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
