import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Arrays.sort(participant, String.CASE_INSENSITIVE_ORDER);
        Arrays.sort(completion, String.CASE_INSENSITIVE_ORDER);
        for(int i = 0; i < participant.length-1; i++){
            if(!participant[i].equals(completion[i])){
                answer = participant[i];
                break;
            }
        }

        if(answer == ""){
            answer = participant[participant.length-1];
        }
        return answer;
    }
}
