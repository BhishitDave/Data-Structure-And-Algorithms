/*package whatever //do not write package name here */

import java.util.*;
    public class Point {
        int x;
        int y;
        char tag;

        public Point(int x, int y, char tag) {
            this.x = x;
            this.y = y;
            this.tag = tag;
        }

        public char getTag() {
            return tag;
        }

        public double distance() {
            return Math.sqrt(Math.pow(x,2) + Math.pow(y,2));
        }
    }
    
class Microsoft {
	public static void main (String[] args) {
	    int[] A = new int[]{1,-1,2};
	    int[] B = new int[]{1,-1,-2};
		System.out.println(solution("CCD" ,A,B ));
	}
	public static int solution(String S, int[] X, int[] Y) {
        PriorityQueue<Point> priorityQueue = new PriorityQueue(Y.length, Comparator.comparingDouble(Point::distance));
        for (int i = 0; i < X.length; i++) {
            priorityQueue.add(new Point(X[i], Y[i], S.charAt(i)));
        }

        HashMap<Character, Point> map = new HashMap<>();

        while(map.size() != X.length) {
            Point point = priorityQueue.poll();
            if (map.containsKey(point.getTag())) {
                Point firstPoint = map.get(point.getTag());
                return Double.compare(firstPoint.distance(), point.distance()) == 0 ? map.size() - 1 : map.size();
            } else {
                map.put(point.getTag(), point);
            }
        }

        return map.size();
    }
}