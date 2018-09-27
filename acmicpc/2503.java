package coding_2017_5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class J2503 {

	static ArrayList<bbgame> ar = new ArrayList<bbgame>();
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.valueOf(br.readLine());
		
		for(int i = 0; i < n; i++){
			StringTokenizer tok = new StringTokenizer(br.readLine());			
			ar.add(new bbgame(tok.nextToken(), Integer.valueOf(tok.nextToken()), Integer.valueOf(tok.nextToken())));
		}
		
		int answer = 0;
		
		int number[] = {1, 2, 3};
		
		while(true){
			if(number[0] == 10)
				break;
			int temp = 0;
			
			for(int i = 0; i < n; i++){
				temp += ar.get(i).comp(number);
			}
			
			if(temp == n)
				answer++;
			
			while(true){
				number[2]++;
				for(int i = 2; i >= 0; i--){
					if(number[i] == 10){
						if(i == 0)
							break;
						number[i] = 1;
						number[i-1]++;
					}
					else
						break;
				}
				
				boolean check[] = new boolean[11];
				boolean c = false;
				for(int i = 0; i < 3; i++){
					if(check[number[i]]){
						c = true;
						break;
					}
					check[number[i]] = true;
				}
				if(!c){
					break;
				}
			}
		}
		
		System.out.println(answer);
	}
}

class bbgame{
	int num[];
	int strike;
	int ball;
	
	public bbgame(String num, int strike, int ball){
		this.num = new int[3];
		this.num[0] = num.charAt(0)-48;
		this.num[1] = num.charAt(1)-48;
		this.num[2] = num.charAt(2)-48;
		
		this.strike = strike;
		this.ball = ball;
	}
	
	public int comp(int think[]){
		int s = 0, b = 0;
		boolean check[] = new boolean[3];
		
		for(int i = 0; i < 3; i++){
			if(num[i] == think[i]){
				s++;
				check[i] = true;
			}
		}
		
		for(int i = 0; i < 3; i++){
			if(check[i])
				continue;
			for(int j = 0; j < 3; j++){
				if(num[i] == think[j]){
					b++;
					break;
				}
			}
		}
		
		
		if(s == this.strike & b == this.ball)
			return 1;
		return 0;
	}
}
