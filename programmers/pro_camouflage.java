import java.util.*;

class Solution {
    HashMap<String, Integer> hm = new HashMap<>();
    ArrayList<Integer> ar = new ArrayList<>();

    public int getanswer(int index, int value, int length, int arlen){

        if(index+length-arlen > ar.size())
            return 0;

        int answer = 0;
        for(int i = index; i < ar.size(); i++){
            int temp = ar.get(i);
            if(i+1 >= ar.size() && arlen+1 < length)
                continue;
            if(arlen+1 == length){
                answer += value * temp;
                continue;
            }
            answer += getanswer(i+1, value * temp, length, arlen+1);
        }
        return answer;
    }

    public int getanswer2(int index, int value, int arlen){

        int answer = 0;
        for(int i = index; i < ar.size(); i++){
            int temp = ar.get(i);
            answer += getanswer2(i+1, value * temp, arlen+1);
            answer += value * temp;
        }
        return answer;
    }

    public int solution(String[][] clothes) {
        int answer = 0;

        for(int i = 0; i < clothes.length; i++){
            if(hm.containsKey(clothes[i][1])){
                int index = hm.get(clothes[i][1]);
                ar.set(index, ar.get(index)+1);
            }
            else{
                hm.put(clothes[i][1], ar.size());
                ar.add(1);
            }
        }

        answer += getanswer2(0, 1, 0);
        return answer;
    }
}
