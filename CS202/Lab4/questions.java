

/**
 * Created by Harsukh Singh on 5/28/15. CS 202 assignment 4
 * questions class used as a LLL in other classes 
 */
public class questions
{
    private String question; //question string
    private int numeric; //numeric answer only
    private questions next; //next pointer
    
    /*
     * harsukh singh cs 202 assignment 4
     * default constructor
     */
    public questions() {
        next = null;
        question = null;
        numeric = 0;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     *  non default constructor
     */
    public questions(String question) {
    	this.question = question;
    	numeric = 0;
        next = null;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy constructor
     */
    public questions(questions to_copy)
    {
        question = to_copy.question;
        numeric = to_copy.numeric;
        next = null;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * getter for question
     */
    public String getQuestion() {
        return question;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * setter for question
     */
    public void setQuestion(String question) {
        this.question = question;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for numeric answer
     */
    public int getNumeric() {
        return numeric;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for numeric answer
     */
    public void setNumeric(int numeric) {
        this.numeric = numeric;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for the next pointer
     */
    public questions getNext() {
        return next;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for the next pointer
     */
    public void setNext(questions next) {
        this.next = next;
    }
    /*
     * harsukh singh cs 202 assignment 4
     * display questions
     */
    public void display_questions()
    {
        System.out.println(question);
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * display function
     */
    public void display()
    {
        System.out.println(question);
        System.out.println(numeric);
    }
}

