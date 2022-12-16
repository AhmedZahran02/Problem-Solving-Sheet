class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> qStudents = new LinkedList<>();

        for (int value : students) {
            qStudents.add(value);
        }

        int topPositionOfSandwich = 0;
        int numStudentsUnableEat = 0;
        while (!qStudents.isEmpty() && numStudentsUnableEat < qStudents.size()) {
            if (sandwiches[topPositionOfSandwich] == qStudents.peek()) {
                numStudentsUnableEat = 0;

                ++topPositionOfSandwich;
                qStudents.poll();
            }
            else {
                ++numStudentsUnableEat;

                qStudents.add(qStudents.poll());
            }
        }

        return numStudentsUnableEat;
    }
}