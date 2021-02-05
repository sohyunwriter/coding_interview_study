def solution(info, query):
    answer = []
    applicant = []
    inf_map = [{"java": 0, "cpp": 1, "python": 2, "-": 3},
            {"backend": 0, "frontend": 1, "-": 1},
            {"junior": 0, "senior": 1, "-": 1},
            {"chicken": 0, "pizza": 1, "-": 1}]

    for appli in info:
        inf = appli.split()
        applicant.append([(inf_map[0][inf[0]] << 3) + (inf_map[1][inf[1]] << 2)
                          + (inf_map[2][inf[2]] << 1) + inf_map[3][inf[3]], int(inf[4])])

    for q in query:
        inf = q.split()
        inf_val = 0
        dont_care = 0
        for i in range(0, 7, 2):
            if inf[i] == '-':
                dont_care |= (inf_map[int(i / 2)][inf[i]] << (3 - int(i / 2)))
            else:
                inf_val |= (inf_map[int(i / 2)][inf[i]] << (3 - int(i / 2)))

        score = int(inf[7])

        num = 0
        for app in applicant:
            if (app[0] & ~dont_care) == inf_val and app[1] >= score:
                num += 1
        answer.append(num)

    return answer

