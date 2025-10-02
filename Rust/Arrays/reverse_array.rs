// Problem: Reverse an Array
// Language: Rust
// Author: Harsh Dubey
// Description: This program reverses the elements of an integer array and prints the result.

/// Reverses a mutable array in place
fn reverse_array(arr: &mut [i32]) {
    let mut start = 0;
    let mut end = arr.len() - 1;

    while start < end {
        arr.swap(start, end);
        start += 1;
        if end == 0 { break; } // Prevent underflow
        end -= 1;
    }
}

fn main() {
    // Example array
    let mut arr = [1, 2, 3, 4, 5];

    println!("Original array: {:?}", arr);

    // Reverse the array
    reverse_array(&mut arr);

    println!("Reversed array: {:?}", arr);
}

