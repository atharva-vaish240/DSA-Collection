// Problem: Find Maximum and Minimum in an Array (User Input)
// Language: Rust
// Author: Harsh Dubey
// Description: This program reads an array of integers from the user and finds the largest and smallest elements.

use std::io;

/// Function to find the maximum and minimum values in an array
fn find_max_min(arr: &[i32]) -> (i32, i32) {
    if arr.is_empty() {
        panic!("Array cannot be empty");
    }

    let mut max_val = arr[0];
    let mut min_val = arr[0];

    for &num in arr.iter() {
        if num > max_val {
            max_val = num;
        }
        if num < min_val {
            min_val = num;
        }
    }

    (max_val, min_val)
}

fn main() {
    println!("Enter the number of elements in the array:");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let n: usize = input.trim().parse().expect("Please enter a valid number");

    let mut arr = Vec::new();

    println!("Enter {} integers separated by Enter:", n);
    for _ in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let num: i32 = input.trim().parse().expect("Please enter a valid integer");
        arr.push(num);
    }

    println!("Array entered: {:?}", arr);

    let (max_val, min_val) = find_max_min(&arr);

    println!("Maximum value: {}", max_val);
    println!("Minimum value: {}", min_val);
}
