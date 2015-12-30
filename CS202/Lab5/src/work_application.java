

import java.util.Scanner;
import java.io.*;
/**
 * Created by Harsukh Singh on 5/28/15. For CS 202 Assignment 4
 *  Work application has a LLL of questions and jobs
 */

public class work_application extends application {
	
    private job head; //head pointer to job list
    private questions head_node; //head pointer to questions list

    /*
     * harsukh singh cs 202 assignment 4
     * default constructor 
     */
    public work_application() {
        head = null;
        head_node = null;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy constructor for the work application
     */
    public work_application(work_application to_copy)
    {
        copy_lll(to_copy.head_node);
        copy_lll(to_copy.head);
        this.setName(to_copy.getName());
        this.setGpa(to_copy.getGpa());
        this.setStanding(to_copy.getStanding());
        this.setAddress(to_copy.getAddress());
        this.setCity(to_copy.getCity());
        this.setState(to_copy.getState());
        this.setZip_code(to_copy.getZip_code());
        this.setEmail(to_copy.getEmail());
        this.setPosition_applying_for(to_copy.getPosition_applying_for());
        this.setClass_applying_for(to_copy.getClass_applying_for());
        this.setKey(to_copy.getKey());
        this.setScore(to_copy.getScore());
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy linked list for questions
     */
    private questions copy_lll(questions copy_to, questions to_copy)
    {
        if(to_copy == null)
        {
            return null;
        }
        copy_to = new questions(to_copy);
        copy_to.setNext(copy_lll(copy_to.getNext(), to_copy.getNext()));
        return copy_to;
        
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy linked list for jobs wrapper
     */
    public int copy_lll(job to_copy)
    {
    	head = copy_lll(head, to_copy);
    	return 1;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy linked list for questions wrapper
     */
    public int copy_lll(questions to_copy)
    {
    	head_node = copy_lll(head_node, to_copy);
    	return 1;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy function for job list
     */
    private job copy_lll(job copy_to, job to_copy)
    {
        if(to_copy == null)
        {
            return null;
        }
        copy_to = new job(to_copy);
        copy_to.setNext(copy_lll(copy_to.getNext(), to_copy.getNext()));
        return copy_to;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * insert function into a linked list
     */
    public void insert_job()
    {
    	job new_job = new job();
    	Scanner in = new Scanner(System.in);
    	String temp;
    	System.out.println("Please enter the job title.");
    	temp = in.nextLine();
    	new_job.setJob_title(temp);
    	System.out.println("Please enter the company worked for.");
    	temp = in.nextLine();
    	new_job.setCompany_worked_for(temp);
    	System.out.println("Please enter the description of the job.");
    	temp = in.nextLine();
    	new_job.setDescription(temp);
    	System.out.println("Please enter the years worked.");
    	int years = in.nextInt();
    	new_job.setYears_worked(years);
    	new_job.setNext(null);
    	insert_job(new_job);
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * insert function into a linked list
     */
    public job insert_job(job head, job to_insert) {
        if (head == null) {
            head = new job(to_insert);
            return head;
        } else {
            job temp = head;
            head = new job(to_insert);
            head.setNext(temp);
            return head;
        }
    }

    /*
     * harsukh singh cs 202 assignment 4
     * insert function for a question into a list wrapper function 
     */
    public void insert_job(job to_insert)
    {
    	head = insert_job(head ,to_insert );
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * remove function from a linked list
     */
    private job remove_job(job head, String company, String title) {
        if (head == null) {
            return head;
        } else {
            if (head.getJob_title().equals(title) && head.getCompany_worked_for().equals(company)) {
                return head.getNext();
            }
        }
        head.setNext(remove_job(head.getNext(), company, title));
        return head;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * remove function from a linked list wrapper function
     */
    public int remove_job(String company, String title) {
        head = remove_job(head, company, title);
        return 1;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * retrieve function from a linked list
     */
    public job retrieve(String company, String title) {
        if (head == null) {
            throw new RuntimeException("cannot retrieve with null list");
        } else {
            job current = head;
            while (current != null) {
                if (current.getJob_title().equals(title) && current.getCompany_worked_for().equals(company)) {
                    return current;
                }
                current = current.getNext();
            }
            return current;
        }
    }

    /*
     * harsukh singh cs 202 assignment 4
     * display entire application with questions
     */
    public void display() {
        System.out.println(getName());
        System.out.println(getGpa());
        System.out.println(getStanding());
        System.out.println(getAddress());
        System.out.println(getCity());
        System.out.println(getState());
        System.out.println(getZip_code());
        System.out.println(getEmail());
        System.out.println(getPosition_applying_for());
        System.out.println(getClass_applying_for());
        display_questions();
        if (head == null) {
            return;
        } else {
            job current = head;
            while (current != null) {
                current.display();
                current = current.getNext();
            }
        }
    }

    /*
     * harsukh singh cs 202 assignment 4
     * course eval returns the grade received in cs 202
     */
    public int course_eval() {
        int priority = 0;
        float grade;
        char response;
        Scanner in = new Scanner(System.in);
        System.out.println("Have you taken CS 202? Please enter 'y' for yes or 'n' for no.");
        response = in.nextLine().charAt(0);
        if (response == 'y') {
            System.out.println("Please enter your grade as a numerical value from 0 to 100.");
            grade = in.nextFloat();
            while (Math.floor(grade) < 0 || Math.floor(grade) > 100) {
                System.out.println("Please enter your grade as a numerical value from 0 to 100.");
                grade = in.nextFloat();
                priority = (int) Math.floor(grade);
                return priority;
            }
        }
        this.setScore(priority);
        return priority;

    }

    /*
     * harsukh singh cs 202 assignment 4
     * display functions in a linear linked list
     */
    public void display_questions() {
        if (head_node == null) {
            return;
        } else {
            questions current = head_node;
            while (current != null) {
                current.display();
                current = current.getNext();
            }
        }
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * insert function for a question into a list 
     */
    public questions insert_question(questions head_node, questions to_insert) {
        if (head_node == null) {
            head_node = new questions(to_insert);
            return head_node;
        } else {
            questions temp = head_node;
            head_node = new questions(to_insert);
            head_node.setNext(temp);
            return head_node;
        }
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * insert function for a question into a list wrapper function 
     */
    public void insert_question(questions to_insert)
    {
    	head_node = insert_question(head_node,to_insert );
    }


    /*
     * harsukh singh cs 202 assignment 4
     * removes a question from LLL, not used in the assignment
     */
    private questions remove_question(questions head_node, String question) {
        if (head_node == null) {
            return head_node;
        } else {
            if (head_node.getQuestion().equals(question)) {
                return head_node.getNext();
            }
            head_node.setNext(remove_question(head_node.getNext(), question));
            return head_node;
        }

    }

    /*
     * harsukh singh cs 202 assignment 4
     * remove function from a linked list, not used so much in the assignment
     */
    public int remove_question(String question) {
        head_node = remove_question(head_node, question);
        return 1;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * retrieve function from a question LLL retrieves a question from the LLL 
     */
    public questions retrieve_question(String question) {
        if (head_node == null) {
            throw new RuntimeException("cannot retrieve with null list");
        } else {
            questions current = head_node;
            while (current != null) {
                if (current.getQuestion().equals(question)) {
                    return current;
                }
                current = current.getNext();
            }
            return current;
        }
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * Answer questions in application goes through the lists and has user input the answers 
     * this is originally set by the supervisor
     */
    public void answer_questions()
    {
    	if(head_node == null)
    	{
    		return;
    	}
    	questions temp = head_node;
    	Scanner in = new Scanner(System.in);
    	int answer;
    	while(temp != null)
    	{
    		System.out.println("Please answer the question");
    		temp.display_questions();
    		answer  = in.nextInt();
    		temp.setNumeric(answer);
    		temp = temp.getNext();
    	}
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * writes application to file writes the base class and the attached lists both to the file
     */
    public void write_to_file(String name) throws IOException
    {
    	FileWriter writer = new FileWriter(name + ".txt");	
		writer.write(this.getName());
		writer.write(System.lineSeparator()); //new line
		writer.write(Float.toString(this.getGpa()));
		writer.write(System.lineSeparator()); //new line
		writer.write(this.getClass_applying_for());
		writer.write(System.lineSeparator()); //new line
		writer.write(this.getPosition_applying_for());
		writer.write(System.lineSeparator()); //new line
		writer.write(Integer.toString(this.getScore()));
		writer.write(System.lineSeparator());
		writer.write(this.getStanding());
		writer.write(System.lineSeparator());
		writer.write(this.getAddress());
		writer.write(System.lineSeparator());
		writer.write(this.getCity());
		writer.write(System.lineSeparator()); //new line
		writer.write(this.getState());
		writer.write(System.lineSeparator()); //new line
		writer.write(Integer.toString(this.getZip_code()));
		writer.write(System.lineSeparator()); //new line
		writer.write(this.getEmail());
		writer.write(System.lineSeparator()); //new line
    	questions temp = head_node;
    	while(temp != null)
    	{
    		writer.write(temp.getQuestion());
    		writer.write(System.lineSeparator()); //new line
    		writer.write(Integer.toString(temp.getNumeric()));
    		writer.write(System.lineSeparator()); //new line
    		temp = temp.getNext();
    	}
        job current = head;
        while (current != null) {
        	//writer.write(current.getJob_title());
        	writer.write(System.lineSeparator()); //new line
        	writer.write(current.getDescription());
        	writer.write(System.lineSeparator()); //new line
        	writer.write(current.getCompany_worked_for());
        	writer.write(System.lineSeparator()); //new line
            current = current.getNext();
        }
    	writer.close();
    }
}