// Problem: Reverse a String
// Language: Rust
// Author: Harsh Dubey
// Description: Reverses a string entered by the user.

use std::io;

fn main() {
    println!("Enter a string to reverse:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let input = input.trim();

    let reversed: String = input.chars().rev().collect();
    println!("Reversed string: {}", reversed);
}
