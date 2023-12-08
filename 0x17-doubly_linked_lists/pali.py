def is_palindrome(n):
    return str(n) == str(n)[::-1]

max_palindrome = 0
for i in range(999, 99, -1):
    for j in range(i, 99, -1):
        prod = i * j
        if is_palindrome(prod) and prod > max_palindrome:
            max_palindrome = prod

print(max_palindrome, end='')
