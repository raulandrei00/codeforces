def solve(n , a):
    
    
    ans = 0
    pos = [[] for _ in range(n + 1)]
    for i in range(n):
        pos[a[i]].append(i)
    # Try each x as candidate median
    for x in range(1, n + 1):
        b = []
        for val in a:
            if val >= x:
                b.append(1)
            else:
                b.append(-1)
        
        prefix = [0]
        for v in b:
            prefix.append(prefix[-1] + v)
        seen = {}
        min_prefix = 0
        seen[0] = -1
        min_so_far = float('inf')
        for i in range(1, n + 1):
            if prefix[i] - min_prefix >= 1:
                # Subarray a[j+1 .. i-1] has x as a possible median
                # Try to find min in that range
                j = seen[min_prefix]
                min_in_range = min(a[j+1:i])
                ans = max(ans, x - min_in_range)
            if prefix[i] not in seen:
                seen[prefix[i]] = i - 1
            min_prefix = min(min_prefix, prefix[i])
    return ans

t = int(input())

while t:

    n = int(input())
    arr = [int(x) for x in input().split()]

    print(solve(n , arr))

    t -= 1
