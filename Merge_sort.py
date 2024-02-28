def merge(a, p, q, r):
    b = a.copy()
    i = p
    k = p
    j = q+1
    while i <= q and j <= r:
        if a[i] <= a[j]:
            b[k] = a[i]
            k = k + 1
            i = i + 1
        else:
            b[k] = a[j]
            k = k + 1
            j = j + 1
    while i <= q:
        b[k] = a[i]
        k = k + 1
        i = i + 1
    for i in range(p, r+1):
        a[i] = b[i]


def sort(a, p, r):
    if p < r:
        q = int((r+p)/2)
        sort(a, p, q)
        sort(a, q+1, r)
        merge(a, p, q, r)


if __name__ == '__main__':
    a = [3, 2, 1, 6, 5, 2]
    p = 0
    r = len(a) - 1
    print(f"Array: {a}, p={p}, r={r}")
    sort(a, p, r)
    print(f"Result: {a}")
