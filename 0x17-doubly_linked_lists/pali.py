def is_palindrome(n):
    return str(n) == str(n)[::-1]

max_palindrome = 0
for i in range(999, 99, -1):
    if i * i < max_palindrome:
        break
    for j in range(i, 99, -1):
        prod = i * j
        if prod < max_palindrome:
            break
        if is_palindrome(prod):
            max_palindrome = prod

print(max_palindrome, end='')

