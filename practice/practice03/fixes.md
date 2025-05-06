The problems or bugs of the program casued the sum Range(1, 5) return a 10 instead of 15
        Off-by-one: for (int i = start; i < end; i++) excludes end.

Also, the original code contains Negative({-1}) returns false
    Incorrect comparison: should check for < 0, not > 0.
    Loop goes out of bounds: i <= numbers.size() should be i < numbers.size().

Another bug is findMax({1, 2, 3}) crashes or returns wrong result
    Loop bounds error and out-of-bounds access.
    Should use i < numbers.size() and check > not >=.
