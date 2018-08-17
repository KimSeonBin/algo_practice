package coding_2017_5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class J2468 {
	static int arr[][] = new int[101][101];
	static int dir[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	static int answer = 1;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		for(int i = 1; i <= n; i++){
			StringTokenizer tok = new StringTokenizer(reader.readLine());
			int index = 1;
			while(tok.hasMoreTokens())
				arr[i][index++] = Integer.parseInt(tok.nextToken());
		}
		
		while(true){
			Deque<Integer> q = new ArrayDeque<Integer>();
			int tempheight = 0, water = 0;
			boolean check[][] = new boolean[n+1][n+1];
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					arr[i][j]--;
					if(arr[i][j] <= 0){
						check[i][j] = true;
						water++;
					}
				}
			}
			
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(check[i][j])
						continue;
					q.push(i*n + j);
					check[i][j] = true;
					while(!q.isEmpty()){
						int x = q.peek() / n, y = q.peek() % n;
						if(y == 0){
							x--;
							y = n;
						}
						q.remove();
						for(int index = 0; index < 4; index++){
							if(x+dir[index][0] > n || x+dir[index][0] <= 0)
								continue;
							if(y+dir[index][1] > n || y+dir[index][1] <= 0)
								continue;
							if(check[x+dir[index][0]][y+dir[index][1]])
								continue;
							q.push((x+dir[index][0])*n + (y+dir[index][1]));
							check[x+dir[index][0]][y+dir[index][1]] = true;
						}
					}
					tempheight++;
				}
			}
			
			if(answer < tempheight)
				answer = tempheight;
			if(water == n*n)
				break;
			
		}
		
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		writer.write(answer + "\n");
		writer.flush();
	}

}
