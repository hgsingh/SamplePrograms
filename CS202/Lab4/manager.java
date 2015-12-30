
/*
 *@author harsukh singh assignment 4 CS 202 
 *manager class for managing objects in the program dynamic binding is partcularly used here to deal with the heirarchy of the applications 
 */
import java.util.Scanner;
import java.io.IOException;
import java.lang.Character;

public class manager {
	private job head; //head pointer for the job object
	private questions head_node; //head node for the questions list
	
	/*
	 * @author harsukh singh Assignment 4 CS 202
	 * default constructor initializes the jobs for the manager
	 * note that the jobs are hard coded in this function, head is called each time to return the new list the global head of jobs contained within the class
	 */
	public manager() throws IOException
	{
		head = null;
		head_node = null;
		head  = make_list(head, "Grader", "Grades students");
		head  = make_list(head, "Lab Assistant", "Assists students throughout lab class");
		head  = make_list(head, "Lab Facilitator", "Facilitates labs ");
		head  = make_list(head, "Lab Administrator", "Administrates labs");
		make_question_list();
		remove_question();
		make_application_wrapper();
		
	}
	
	/*
	 * @author harsukh singh CS 202 Assignment 4
	 * make applications wrapper function. takes the users input to add an application to the list jobs that the user wants to apply for
	 * this function displays all the applications in the list 
	 */
	public void make_application_wrapper() throws IOException
	{
		char choice;
		Scanner in = new Scanner(System.in);
		System.out.println("Would you like to make an application? If so, press 'y'");
		choice  = in.next().charAt(0);
		choice = Character.toLowerCase(choice);
		while(choice == 'y')
		{
			make_application();
			System.out.println("Would you like to add another application? If so, press 'y'");
			choice  = in.next().charAt(0);
			choice = Character.toLowerCase(choice);
			display_all();
		}
	}
	
	/*
	 * @author harsukh singh CS 202 Assignment 4
	 * make questions to put into the application, takes the supervisors input to put questions pertaining to the jobs
	 */
	public void make_question_list()
	{
		System.out.println("Please enter questions for the job.");
		System.out.println("Please limit the answer to the question as a numerical integer value.");
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		head_node =  insert_question(head_node, input);
		System.out.println("Would you like to add more questions? Please press 'y'");
		char choice  = in.next().charAt(0);
		in.nextLine();
		choice = Character.toLowerCase(choice);
		while(choice == 'y' )
		{
			System.out.println("Please enter a question for the application class.");
			System.out.println("Please limit the answer to the question as a numerical integer value.");
			input = in.nextLine();
			head_node = insert_question(head_node, input);
			System.out.println("Would you like to add more questions? Please press 'y'");
			choice  = in.next().charAt(0);
			in.nextLine();
			choice = Character.toLowerCase(choice);
		}
	}
	
	/*
	 * @author harsukh singh CS 202 Assignment 4
	 *  make application function call goes through to insert the application
	 * application information is taken in from the user and copied into the jobs list dynamic binding used here
	 */
	public void make_application() throws IOException
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Do you want to submit an application with jobs? Please enter 'y' or 'n'.\n");
		char choice  = in.nextLine().charAt(0);
		choice = Character.toLowerCase(choice);
		application new_application;
		if(choice == 'y')
		{
			new_application = new work_application();
			char add_job = 'y';
			while(add_job == 'y')
			{
				((work_application) new_application).insert_job();
				System.out.println("Would you like to add more jobs? Please press 'y'\n");
				add_job  = in.nextLine().charAt(0);
			}
		}
		else
			new_application = new technical_application();
		System.out.println("Please enter basic information about the applicant.");
		System.out.println("Please enter your name.");
		String name = in.nextLine();
		new_application.setName(name);
		System.out.println("Please enter your gpa. Limit to 0-4");
		float temp_num = in.nextFloat();
		new_application.setGpa(temp_num);
		in.nextLine();
		System.out.println("Please enter your standing as a college student, freshman, sophmore, junior, senior.");
		String temp = in.nextLine();
		new_application.setStanding(temp);
		System.out.println("Please enter your current living address.");
		temp = in.nextLine();
		new_application.setAddress(temp);
		System.out.println("Please enter your current city.");
		temp = in.nextLine();
		new_application.setCity(temp);
		System.out.println("Please enter your current state.");
		temp = in.nextLine();
		new_application.setState(temp);
		System.out.println("Please enter your zip code.");
		int zip_code = in.nextInt();
		new_application.setZip_code(zip_code);
		in.nextLine();
		System.out.println("Please enter your email.\n");
		temp = in.nextLine();
		new_application.setEmail(temp);
		System.out.println("Please enter the position applying for.");
		System.out.println("Positions open are Grader, Lab Facilitator, Lab Assistant, Lab Administrator");
		temp = in.nextLine();
		new_application.setPosition_applying_for(temp);
		System.out.println("Please enter the class applying for.");
		temp = in.nextLine();
		new_application.setClass_applying_for(temp);
		new_application.setNext(null);
		System.out.println("Please enter a integer password for your key.");
		zip_code = in.nextInt();
		new_application.setKey(zip_code);
		in.nextLine();
		if(new_application instanceof work_application)
		{
			System.out.println("work application made");
			((work_application) new_application).copy_lll(head_node);
			((work_application) new_application).course_eval();
			((work_application) new_application).answer_questions();
		}
		else
		{
			System.out.println("technical application made.");
			((technical_application)new_application).copy_lll(head_node);
			((technical_application)new_application).course_eval();
			((technical_application)new_application).answer_questions();
		}
		insert_application(new_application);
		new_application.write_to_file(name);
	}
	
	/*
	 * @author harsukh singh CS 202 Assignment 4
	 * Insert application into the jobs sub list
	 * searches through the jobs to find the correct position and is inserted there
	 * application is taken as a parameter to the method
	 */
	public void insert_application(application to_insert)
	{
		if(head == null)
		{
			return; //no jobs to insert into
		}
		job current = head;
		while(current != null)
		{
			if(current.getJob_title().equals(to_insert.getPosition_applying_for()))
			{
				if(to_insert instanceof work_application)
					current.insert_application(to_insert, 'w');
				else
					current.insert_application(to_insert, 't');
				return;
			}
			current = current.getNext();
		}
	}
	
	/*
	 * @author harsukh singh CS 202 Assignment 4
	 * insert application function into the job
	 * takes a string and head as input and inserts the question required
	 */
	public questions insert_question(questions head_node, String input)
	{
		if(head_node == null)
		{
			head_node = new questions(input);
			return head_node;
		}
		else
		{
			questions temp = head_node;
			head_node = new questions(input);
			head_node.setNext(temp);
			return head_node;
		}
	}
	
	/*
	 * @author harsukh singh CS 202 Assignment 4
	 * make list function to insert jobs into the LLL
	 * sets the jobs that will take applications (this is done in the constructor)
	 */
	public job make_list(job head, String job_title, String description)
	{
		if(head == null)
		{
			head = new job();
			head.setJob_title(job_title);
			head.setDescription(description);
			head.setCompany_worked_for("Karla Company");
			return head;
		}
		else
		{
			job temp = head;
			head = new job();
			head.setJob_title(job_title);
			head.setDescription(description);
			head.setCompany_worked_for("Karla Company");
			head.setNext(temp);
			return head;
		}
	}
	
	/*
	 * @author harsukh singh CS 202 Assignment 4
	 * displays all jobs and applications of jobs
	 */
	public void display_all()
	{
		System.out.println("Current available jobs accepting applications.\n");
		if(head == null)
		{
			return;
		}
		job current = head;
		while(current != null)
		{
			current.display_job();
			current.display_application();
			current = current.getNext();
		}
	}
	
    /*
     * harsukh singh cs 202 assignment 4
     * removes a question from LLL goes through recursively to remove from the list 
     * takes node and string to compare
     */
    private questions remove_question(questions head_node, String question) {
        if (head_node == null) {
            return head_node;
        } else {
            if (head_node.getQuestion().equals(question)) {
            	System.out.println("removed " + question);
                return head_node.getNext();
            }
            head_node.setNext(remove_question(head_node.getNext(), question));
            return head_node;
        }
    }

    /*
     * harsukh singh cs 202 assignment 4
     * remove function from a linked list wrapper will take the user (supervisor) on which jobs to remove from the questions list before
     * they are copied into the application lists (work and technical applications).
     */
    public void remove_question() {
    	String question;
    	Scanner in = new Scanner(System.in);
    	System.out.println("If you would like to remove a quesiton please press 'y'");
		char choice  = in.nextLine().charAt(0);
		choice = Character.toLowerCase(choice);
		while(choice == 'y')
		{
			System.out.println("Please enter the question you would like to remove");
			question = in.nextLine();
			System.out.println("removing " + question);
			head_node = remove_question(head_node, question);
			System.out.println("If you would like to remove another quesiton please press 'y'");
			choice  = in.nextLine().charAt(0);
		}
    }
}
