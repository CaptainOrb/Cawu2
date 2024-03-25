package models;

import java.util.*;

public class Teacher extends Person {
	private int numCourses;
	private List<String> courses;
	public Teacher(String name, String address) {
		super(name, address);
		this.numCourses = 0;
		this.courses = new ArrayList<>();
	}
	
	@Override
	public String toString() {
		return "Teacher: " + super.toString();
	}
	
	public boolean addCourse(String course) {
		for (int i = 0; i < numCourses; i++)
			if (courses.get(i).equals(course)) return false;
		if (numCourses == 5) return false;
		
		courses.add(course);
		numCourses++;
		return true;
	}
	
	public boolean removeCourse(String course) {
		for (int i = 0; i < numCourses; i++)
			if (courses.get(i).equals(course)) {
				courses.remove(i);
				numCourses--;
				return true;
			}
		return false;
	}
	
	public List<String> getCourses(){
		return this.courses;
	}

}
