import java.io.IOException;

/**
 * Created by Harsukh Singh on 5/28/15.
 * CS202 assignment 4
 */
//applications have to be available for grader, lab assistant, lab administrator, lab facilitator
//this is the most base class that has setters and getters for the application

public abstract class application {
	
    private String name; //general name
    private float gpa; //gpa standing of the 
    private String standing; //standing of the person academically
    private String address; //address
    private String city; //city 
    private String state; //state
    private int zip_code; //zip code
    private String email; //email
    private String position_applying_for; //position applying for
    private String class_applying_for; //class applying for 
    private int key; //application key (password)
    private application next; //next pointer for list
    private int score; //application score
    private application left; //left for bst
    private application right; //right for bst
    
    /*
     * harsukh singh cs 202 assignment 4
     * default constructor
     * 
     */
    public application() {
    	name = null;
    	gpa = 0;
    	standing = null;
    	address = null;
    	city = null;
    	state = null;
    	zip_code = 0;
    	email = null;
    	position_applying_for = null;
    	class_applying_for = null;
    	key = 0;
    	next = null;
    	score = 0;
    	right =  null;
    	left = null;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy constructor
     * 
     */
    public application(application to_copy)
    {
        name = to_copy.name;
        gpa = to_copy.gpa;
        standing = to_copy.standing;
        address = to_copy.address;
        city = to_copy.city;
        state = to_copy.state;
        zip_code = to_copy.zip_code;
        email = to_copy.email;
        position_applying_for = to_copy.position_applying_for;
        class_applying_for = to_copy.class_applying_for;
        key = to_copy.key;
        next = null;
        left = null;
        right = null;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * virtual display function
     */
    public abstract void display();
    
    /*
     * harsukh singh cs 202 assignment 4
     * virtual writes application to file for storage
     */
    public abstract void write_to_file(String name) throws IOException;
    
     /*
     * harsukh singh cs 202 assignment 4
     * getter for class applying for
     */
    public String getClass_applying_for() {
        return class_applying_for;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * setter for class applying for
     */
    public void setClass_applying_for(String class_applying_for) {
        this.class_applying_for = class_applying_for;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for name
     */
    public String getName() {
        return name;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * getter for gpa
     */
    public float getGpa() {
        return gpa;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * getter for standing
     */
    public String getStanding() {
        return standing;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for address
     */
    public String getAddress() {
        return address;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * getter for residing city
     */
    public String getCity() {
        return city;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for state
     */
    public String getState() {
        return state;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for zipcode
     */
    public int getZip_code() {
        return zip_code;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for email
     */
    public String getEmail() {
        return email;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for position
     */
    public String getPosition_applying_for() {
        return position_applying_for;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * setter for position
     */
    public void setPosition_applying_for(String position_applying_for) {
        this.position_applying_for = position_applying_for;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for name
     */
    public void setName(String name) {
        this.name = name;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * setter gpa
     */
    public void setGpa(float gpa) {
        this.gpa = gpa;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for standing
     */
    public void setStanding(String standing) {
        this.standing = standing;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for address
     */
    public void setAddress(String address) {
        this.address = address;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for city
     */
    public void setCity(String city) {
        this.city = city;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for state
     */
    public void setState(String state) {
        this.state = state;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for zip
     */
    public void setZip_code(int zip_code) {
        this.zip_code = zip_code;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for email
     */
    public void setEmail(String email) {
        this.email = email;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for key
     */
    public int getKey() {
        return key;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for key
     */
    public void setKey(int key) {
        this.key = key;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * getter for next pointer
     */
    public application getNext() {
        return next;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for next pointer
     */
    public void setNext(application next) {
        this.next = next;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * setter for the application score
     */
    public void setScore(int num) {
        this.score = num;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * getter for the application score
     */
    public int getScore() {
        return score;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * increments the application score by the number amount
     */
    public void incrementScore(int to_add) {
        score = score + to_add;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * sets the left reference by the parameter passed in
     */
    public void setLeft(application left)
    {
    	this.left = left;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * sets the right reference by the parameter passed in
     */
    public void setRight(application right)
    {
    	this.right = right;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * returns the left reference used in the BST
     */
    public application getLeft()
    {
    	return left;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * returns the right reference used in the BST
     */
    public application getRight()
    {
    	return right;
    }
}

