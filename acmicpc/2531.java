import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	//본래는 자바 파일이름과 class 이름이 같아야겠지만 백준 사이트의 채점 규칙에 따라
	//class 이름을 바꿨습니다.
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(reader.readLine());
		int n = Integer.parseInt(tok.nextToken()),
			d = Integer.parseInt(tok.nextToken()),
			k = Integer.parseInt(tok.nextToken()),
			c = Integer.parseInt(tok.nextToken()),
			answer = 0;

		ArrayList<Integer> table = new ArrayList<>();
		for(int i = 0; i < n; i++){
			tok = new StringTokenizer(reader.readLine());
			table.add(Integer.parseInt(tok.nextToken()));
		}

		HashMap<Integer, Integer> dishes = new HashMap<Integer, Integer>();
		for(int i = 0; i < k; i++){
			int sushi_num = table.get(i);
			if(dishes.containsKey(sushi_num)){
				dishes.put(sushi_num, dishes.get(sushi_num)+1);
			}
			else{
				dishes.put(sushi_num, 1);
			}
		}
		answer = dishes.size();
		if(!dishes.containsKey(c))
			answer++;

		for(int i = k; i < n+k-1; i++){
			int delete_sushi_num = table.get(i-k);
			int new_sushi_num = table.get(i % n);

			int count_delete_sushi = dishes.get(delete_sushi_num)-1;
			if(count_delete_sushi <= 0){
				dishes.remove(delete_sushi_num);
			}
			else{
				dishes.put(delete_sushi_num, count_delete_sushi);
			}

			if(dishes.containsKey(new_sushi_num)){
				dishes.put(new_sushi_num, dishes.get(new_sushi_num)+1);
			}
			else{
				dishes.put(new_sushi_num, 1);
			}

			int temp = dishes.size();
			if(!dishes.containsKey(c))
				temp++;
			answer = maxx(answer, temp);
		}
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		writer.write(answer + "\n");
		writer.flush();
	}

	static int maxx(int a, int b){
		if(a > b)
			return a;
		return b;
	}

}
