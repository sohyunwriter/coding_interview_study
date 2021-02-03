import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        ArrayList<Integer> result = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
			if (map.isEmpty()) {
				map.put(genres[i], plays[i]);
			} else {
				if (map.containsKey(genres[i])) {
					map.put(genres[i], map.get(genres[i]) + plays[i]);
				} else {
					map.put(genres[i], plays[i]);
				}
			}
		}
		List<String> list = new ArrayList<>(map.keySet());
        Collections.sort(list, (o1, o2) -> (map.get(o2).compareTo(map.get(o1))));
        
        for(String key : list) {
            Map<Integer, Integer> song = new HashMap<>();
            for(int i=0; i<genres.length; i++) {
                if(key.equals(genres[i])) {
                    song.put(i, plays[i]);
                }
            }
            List<Integer> songlist = new ArrayList<>(song.keySet());
            songlist.sort((s1, s2) -> song.get(s2).compareTo(song.get(s1)));
            int cnt = 0;
            for(Integer idx : songlist) {
                if(cnt > 1) break;
                result.add(idx);
                cnt++;
            }
        }
        answer = new int[result.size()];
        for(int i=0; i<result.size(); i++) {
            answer[i] = result.get(i);
        }
        return answer;
    }
}
