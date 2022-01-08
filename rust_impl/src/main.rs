use structopt::StructOpt;

#[derive(StructOpt, Debug, Clone)]
struct Args {
    #[structopt(short, long, default_value = "128")]
    limit: u64,
}

#[derive(Debug, Clone)]
pub struct PGeneratorState {
    current: u64,
}

impl Default for PGeneratorState {
    fn default() -> Self {
        Self {
            current: 0,
        }
    }
}

impl PGeneratorState {
    pub fn new() -> Self {
        Self::default()
    }

    fn is_palindrome(n: u64) -> bool {
        // get digit count of n
        let mut digits: u64 = 0;
        let mut temp: u64 = n;
        while temp > 0 {
            digits += 1;
            temp /= 10;
        }

        if digits == 0 {
            panic!("Invalid state, digits == 0");
        }

        // get "end" and "start" digits
        let mut end: u64 = 0;
        let mut start: u64 = digits - 1;
        let mut temp2: u64;
        let mut temp3: u64;

        while end < start {
            // get "end" digit
            temp = n;
            temp2 = 0;
            while temp2 < end {
                temp /= 10;
                temp2 += 1;
            }
            temp %= 10;

            // get "start" digit
            temp2 = n;
            temp3 = 0;
            while temp3 < start {
                temp2 /= 10;
                temp3 += 1;
            }
            temp2 %= 10;

            if temp != temp2 {
                // mismatch, is not a palindrome
                return false;
            }

            // cannot yet prove is palindrome until convergence
            end += 1;
            start -= 1;
        }

        // no mismatches, is palindrome
        true
    }

    pub fn next(&mut self) -> u64 {
        loop {
            self.current += 1;
            if Self::is_palindrome(self.current) {
                return self.current;
            }
        }
    }
}

fn main() {
    let mut args = Args::from_args();
    println!("Using limit of \"{}\"", args.limit);

    let mut sum: f64 = 0.0;
    let mut pgen = PGeneratorState::new();
    while args.limit > 0 {
        args.limit -= 1;
        sum += 1.0 / (pgen.next() as f64);
    }

    println!("Sum is {}, last palindrome is {}", sum, pgen.current);
}
