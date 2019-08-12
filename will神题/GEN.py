from cyaron import *

_n = ati([0] + [1000] * 3 + [1e5] * 7)
max_w = int(1e9)

for i in range(1, 11):
    io = IO(file_prefix='data/data', data_id=i)
    print('generating #{0}'.format(i))

    n = _n[i]

    io.input_writeln(n)

    p = [0] * (n + 1)
    a = [0] * (n + 1)

    m = n // 2
    t = max_w // n

    for j in range(1, m + 1):
        p[j] = j - 1
        a[j] = j * t + randint(1, t)

    for j in range(m + 1, n + 1):
        a[j] = randint(1, max_w // 2)
        if 4 <= i <= 6:
            p[j] = j - 1
        else:
            p[j] = randint(1, j - 1)

    for j in range(n):
        io.input_writeln(a[j+1], p[j+1])

    io.output_gen('std.exe')
