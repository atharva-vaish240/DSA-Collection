// Problem: Palindrome Checker
// Language: Rust
// Author: Harsh Dubey
// Description: Checks if a string entered by the user is a palindrome.

use std::io;

fn is_palindrome(s: &str) -> bool {
    let s = s.chars().collect::<Vec<_>>();
    let mut start = 0;
    let mut end = s.len() - 1;

    while start < end {
        if s[start] != s[end] {
            return false;
        }
        start += 1;
        end -= 1;
    }
    true
}

fn main() {
    println!("Enter a string to check for palindrome:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let input = input.trim();

    if is_palindrome(input) {
        println!("'{}' is a palindrome!", input);
    } else {
        println!("'{}' is not a palindrome.", input);
    }
}
