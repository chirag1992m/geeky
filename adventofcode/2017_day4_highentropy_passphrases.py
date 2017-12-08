# Part 2
passes = open('input.txt', 'r').readlines()


def valid_passphrase(password):
    words = sorted(password.split(' '))

    for i in range(len(words) - 1):
        if words[i] == words[i+1]:
            return False

    return True


ans = 0
for password in passes:
    if valid_passphrase(password.strip()):
        ans += 1

print(ans)


# Part 2
def valid_passphrase_2(password):
    words = sorted([sorted(x) for x in password.split(' ')])

    for i in range(len(words) - 1):
        if words[i] == words[i+1]:
            return False

    return True


ans = 0
for password in passes:
    if valid_passphrase_2(password.strip()):
        ans += 1

print(ans)
