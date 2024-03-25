package models;

public class Student extends Person {
	private int numCourses;
	private String[] courses;
	private int[] grades;
	
	public Student(String name, String address) {
		super(name, address);
		this.numCourses = 0;
		this.courses = new String[30];
		this.grades = new int[30];
	}
	
	@Override
	public String toString() {
		return "Student: " + super.toString();
	}
	
	public void addCourseGrade(String course, int grade) {
		if (numCourses == 30) {
			System.out.println("Amount of course and grade has reached max.");
			return;
		}
		courses[numCourses] = course;
		grades[numCourses] = grade;
		numCourses++;
	}
	
	public void printGrades() {
		for (int i = 0; i < numCourses; i++)
			System.out.println(courses[i] + " " + grades[i]);
	}
	
	public double getAverageGrade() {
		int sum = 0;
		for (int i = 0; i < numCourses; i++)
			sum += grades[i];
		return sum/numCourses;
	}

}
