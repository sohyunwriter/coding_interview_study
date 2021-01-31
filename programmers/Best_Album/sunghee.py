
def get_top2(top2, new_one):
    best, best_val, second, second_val = top2
    if best_val < new_one[0]:
        top2 = [new_one[1], new_one[0], best, best_val]
    elif second_val < new_one[0]:
        top2 = [best, best_val, new_one[1], new_one[0]]
    return top2


def solution(genres, plays):
    answer = []
    played = []
    top2 = []
    mp = {}
    songs_size = len(genres)
    for i in range(0, songs_size):
        if not genres[i] in mp:
            mp[genres[i]] = len(mp)
            played.append(0)
            top2.append([-1, -1, -1, -1])
        played[mp[genres[i]]] += plays[i]
        top2[mp[genres[i]]] = get_top2(top2[mp[genres[i]]], [plays[i], i])

    for i in range(0, len(played)):
        played[i] = [played[i], i]

    played.sort(reverse=True)

    for i in range(0, len(played)):
        best, best_val, second, second_val = top2[played[i][1]]
        answer.append(best)
        if second != -1:
            answer.append(second)

    return answer

print(solution(['classic', 'pop', 'classic', 'classic', 'pop'], [500, 600, 150, 800, 2500]))