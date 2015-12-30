/**
* Created by Harsukh Singh on 5/28/15. For CS 202 assignment 4
* technical application class (only implements a list of questions and inherits all members of the application class) 
*/
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class technical_application extends application {

    private questions head_node; //head node of questions

    /*
     * harsukh singh cs 202 assignment 4
     * default constructor
     */
    public technical_application()
    {
        head_node = null;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy constructor used for replicating an application
     */
    public technical_application(technical_application to_copy)
    {
        copy_lll(to_copy.head_node);
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
     * copy linear linked list function goes through to copy all the questions in the list
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
     * copy linked list for questions wrapper
     */
    public int copy_lll(questions to_copy)
    {
    	head_node  = copy_lll(head_node, to_copy);
    	return 1;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * course evaluation function used to set the score of the application based solely on the grade of CS202
     * more can be added to this
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
     * display function for the questions only
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
     * removes a question from LLL
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
     * remove function from a linked list of questions, this is used if the user derives from this class
     */
    public int remove_question(String question) {
        head_node = remove_question(head_node, question);
        return 1;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * retrieve function from a question LLL, retrieve is mostly used as a check 
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
     * Displays completed application
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
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * Answer questions in application goes through the LLL and has the user answer all the questions
     * the questions are to be answered through an int value which is set in the questions object
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
     * writes application to file using the FileWriter object the throw is used upward through the heirarchy
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
    	writer.close();
    }
}
