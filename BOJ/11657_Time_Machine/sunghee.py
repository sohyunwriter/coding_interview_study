import queue

N, M = map(int, input().split())
adj = [[] for i in range(0, N)]
dist = [9999999 for i in range(0, N)]
in_queue = [False for i in range(0, N)]
cnt = [0 for i in range(0, N)]
q = queue.Queue()


for i in range(0, M):
    u, v, w = map(int, input().split())
    adj[u - 1].append([v - 1, w])

q.put(0)
dist[0] = 0
cnt[0] = 1

while not q.empty():
    now = q.get()
    in_queue[now] = False
    for edge in adj[now]:
        cost = edge[1]
        nxt = edge[0]

        if cost + dist[now] < dist[nxt]:
            dist[nxt] = cost+dist[now]
            if not in_queue[nxt]:
                cnt[nxt] += 1
                if cnt[nxt] >= N:
                    print(-1)
                    quit(0)
                q.put(nxt)
                in_queue[nxt] = True

for i in range(1, N):
    print(dist[i] if dist[i] != 9999999 else -1)





