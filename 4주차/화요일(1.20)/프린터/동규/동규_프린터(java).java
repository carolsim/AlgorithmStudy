package programmers;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Solution test = new Solution();
		
		int answer;
		answer = test.solution(new int[] {2,2,2,1,3,4},3);
		
		System.out.println(answer);
	}

}

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        int count = 0;
        ArrayList<Integer> que = new ArrayList<Integer>();
        ArrayList<Boolean> flag = new ArrayList<Boolean>();
        
        int top = priorities.length-1; // Queue�� ž
        
        for(int i = 0; i<priorities.length; i++){ // array list ���·� ��ȯ
            que.add(priorities[i]);
            if(i == location) { flag.add(true);}
            else {flag.add(false);}
        }
        
        while(top >= 0){
            while(!is_max(que,top)){ // ���� ū ���� �ƴϸ� que �� �ڷ� ����
                int temp = que.get(0);
                que.remove(0);
                que.add(temp);
                
                boolean temp2 = flag.get(0);
                flag.remove(0);
                flag.add(temp2);
            }
            que.remove(0); // ���� ū ���� pop�ϰ� top 1 ����
            if(flag.get(0) == true){
                answer = count+1;
                break;
            }
            else{
            	flag.remove(0);
                top--;
                count++;
            }
        }
        return answer;
    }
    
    public boolean is_max(ArrayList<Integer> priorities,int top){
        
        for(int i = 1; i <= top; i++){
            if(priorities.get(i) > priorities.get(0)){
                return false;
            }
        }
        
        return true;
    }
}