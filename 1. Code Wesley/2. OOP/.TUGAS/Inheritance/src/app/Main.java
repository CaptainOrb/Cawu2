package app;

import java.util.*;

import models.*;

public class Main {
	/*
	 *	WESLEY ALDRICH
	 *	2702363613
	 *	PPTI 17
	 *	TUGAS INHERITANCE
	 */

	public static void main(String[] args) {
		List<Person> people = new ArrayList<>();
		
		// Regular People
		Person person = new Person("Reina", "Home 1");
		people.add(person);
		
		// Student
		Student student = new Student("Claudio", "Home 2");
		people.add(student);
		student.addCourseGrade("OOP", 99);
		student.addCourseGrade("HCI", 88);
		
		// Teacher
		Teacher teacher = new Teacher("Kazuya", "Home 3");
		people.add(teacher);
		teacher.addCourse("OOP");
		teacher.addCourse("HCI");
		teacher.addCourse("DS");
		teacher.addCourse("SC");
		teacher.addCourse("Calculus");
		teacher.addCourse("CB"); // this course won't be added due to max size
		teacher.removeCourse("Calculus");

		
		// Check toString
		for (Person i : people) {
			System.out.println(i.toString());
		}
		
		// Check Student
		student.printGrades();
		System.out.println("Average: "+student.getAverageGrade());

		// Check Teacher
		System.out.println(teacher.getCourses());
	}

}
