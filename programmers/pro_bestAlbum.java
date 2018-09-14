import java.util.*;

class Solution {
    Map<String, Song> map = new HashMap<String, Song>();
    ArrayList<String> uniq = new ArrayList<String>();
    ArrayList<Song> as = new ArrayList<Song>();

    public int[] solution(String[] genres, int[] plays) {
        int[] answer;

        //장르, 음악 재생 수 Song class로 분류
        for(int i = 0; i < genres.length; i++){
            if(map.containsKey(genres[i])){
                Song s = map.get(genres[i]);
                s.add(plays[i], i);
                map.put(genres[i], s);
            }
            else{
                Song s = new Song();
                s.add(plays[i], i);
                map.put(genres[i], s);
                uniq.add(genres[i]);//Map으로는 어느것이 Key로 있는지 모르니 key들은 따로 저장
            }
        }

        for(int i = 0; i < uniq.size(); i++){
            //Map에서 꺼내 ArrayList로 변환
            Song s = map.get(uniq.get(i));
            as.add(s);
        }
        Collections.sort(as, new Comparator<Song>(){
            //1. 장르 중 많이 재생된 노래
            //순으로 정렬
            @Override
            public int compare(Song s1, Song s2){
                if(s1.totalplay < s2.totalplay)
                    return 1;
                else if(s1.totalplay == s2.totalplay){
                    return 0;
                }
                else{
                    return -1;
                }
            }
        });

        //총 몇개의 곡을 수록할 수 있는지 확인
        int answerindex = 0, realindex = 0;
        for(int i = 0; i < as.size(); i++){
            if(as.get(i).ar.size() < 2)
                answerindex += 1;
            else
                answerindex += 2;
        }
        answer = new int[answerindex];

        for(int i = 0; i < as.size(); i++){
            ArrayList<S> gotoanswer = as.get(i).ar;
            Collections.sort(gotoanswer, new Comparator<S>(){
                //1. 재생횟수
                //2. index가 작은 순
                //으로 정렬
                @Override
                public int compare(S s1, S s2){
                    if(s1.play < s2.play)
                        return 1;
                    else if(s1.play == s2.play){
                        if(s1.index > s2.index)
                            return 1;
                        else if(s1.index == s2.index)
                            return 0;
                        else
                            return -1;
                    }
                    else
                        return -1;
                }
            });

            for(int j = 0; j < 2; j++){
                if(gotoanswer.size() == j)
                    break;
                answer[realindex++] = gotoanswer.get(j).index;
            }
        }
        return answer;
    }

    class Song{
        int totalplay;
        ArrayList<S> ar = new ArrayList<>();
        public Song(){ }
        void add(int play, int index){
            S s = new S(play, index);
            ar.add(s);
            totalplay += play;
        }
    }

    class S{
        int index;
        int play;
        public S(int play, int index){
            this.index = index;
            this.play = play;
        }
    }
}
