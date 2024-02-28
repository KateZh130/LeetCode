def merge(a, p, q, r):
    j = q + 1
    if j > r or p == r:
        return
    if a[q] <= a[j]:
        return

    while p <= q and j <= r:
        if a[p] <= a[j]:
            p += 1
        else:
            value = a[j]
            index = j
            while index != p:
                a[index] = a[index - 1]
                index -= 1

            a[p] = value
            p += 1
            q += 1
            j += 1


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
    
