
dp = [-1 for _ in range(0, 20)]


def solution(now, N, T, P):
    if now >= N:
        return 0
    if dp[now] != -1:
        return dp[now]

    if now+T[now] > N:
        dp[now] = solution(now+1, N, T, P)
    else:
        case_a = solution(now + T[now], N, T, P) + P[now]
        case_b = solution(now + 1, N, T, P)
        dp[now] = max(case_a, case_b)
    return dp[now]


def main():
    N = int(input())
    T = []
    P = []
    for i in range(0, N):
        t_i, p_i = map(int, input().split())
        T.append(t_i)
        P.append(p_i)

    print(solution(0, N, T, P))


main()