sumRange(1, 5) returns 10 correctly, but the implementation excludes end, which might not be expected.

containsNegative:

Loop runs out-of-bounds (i <= numbers.size()).

Condition is checking > 0 instead of < 0.

findMax:

Loop again out-of-bounds (i <= numbers.size()).

Risk of accessing beyond vector size.

numbers[i] >= maxVal can fail on last element access.

Returning 0 for an empty vector might be misleading—consider std::optional or throwing an exception.

