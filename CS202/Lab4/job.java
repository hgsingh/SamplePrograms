/**
 * Created by Harsukh Singh on 5/28/15 For CS 202 assignment 4
 * job class implements a job with a LLL of applications attached to the job
 * the composition here is the application class
 */

public class job {
	
    private int years_worked; //years worked at a company
    private String company_worked_for; //title of company
    private String description; //description of job
    private String job_title; //job title
    private job next; // next pointer
    private application head_node; //head node for application
    
    /*
     * harsukh singh cs 202 assignment 4
     * default constructor
     */
    public job() {
    	next = null;
    	years_worked = 0;
    	company_worked_for = null;
    	description = null;
    	job_title = null;
    	head_node = null;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * copy constructor, copies a job not the LLL to the application pointers
     */
    public job(job to_copy) {
    	next = null;
        years_worked = to_copy.years_worked;
        company_worked_for = to_copy.company_worked_for;
        description = to_copy.description;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for job title
     */
    public String getJob_title() {
        return job_title;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for job title
     */
    public void setJob_title(String job_title) {
        this.job_title = job_title;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for next pointer
     */
    public job getNext() {
        return next;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * setter for next pointer
     */
    public void setNext(job next) {
        this.next = next;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter years worked
     */
    public int getYears_worked() {
        return years_worked;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for years worked
     */
    public void setYears_worked(int years_worked) {
        this.years_worked = years_worked;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter for company worked for
     */
    public String getCompany_worked_for() {
        return company_worked_for;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for company worked for
     */
    public void setCompany_worked_for(String company_worked_for) {
        this.company_worked_for = company_worked_for;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * getter description
     */
    public String getDescription() {
        return description;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * setter for description
     */
    public void setDescription(String description) {
        this.description = description;
    }

    /*
     * harsukh singh cs 202 assignment 4
     * display function, displays all the values of the private variables
     */
    public void display()
    {
        System.out.println(years_worked);
        System.out.println(company_worked_for);
        System.out.println(description);
        System.out.println(job_title);
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * display job function will only display the company name, title and description of job
     * this is to be used in the LLL of jobs 
     */
    public void display_job()
    {
        System.out.println(company_worked_for);
        System.out.println(job_title);
        System.out.println(description);
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * display applicatoin lll, displays all applications attached to LLL
     */
    public void display_application() {
        if (head_node == null) {
            return;
        } else {
            application current = head_node;
            while (current != null) {
                current.display();
                current = current.getNext();
            }
        }
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * insert app function  inserts the application based on type (late binding is used here) through the char type
     */
    private application insert_application(application head_node, application to_insert, char type) {
        if(type == 'w') {
            if (head_node == null) {
                head_node = new work_application( (work_application) to_insert);
                return head_node;
            } else {
                application temp = head_node;
                head_node = new work_application((work_application) to_insert);
                head_node.setNext(temp);
                return head_node;
            }
        }
        if(type == 't') {
            if (head_node == null) {
                head_node = new technical_application((technical_application) to_insert);
                return head_node;
            } else {
                application temp = head_node;
                head_node = new technical_application((technical_application) to_insert);
                head_node.setNext(temp);
                return head_node;
            }
        }
        else return head_node;
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * insert app function wrapper for the original to return by value
     */
    public void insert_application(application to_insert, char type)
    {
    	head_node = insert_application(head_node, to_insert, type);
    }
    
    /*
     * harsukh singh cs 202 assignment 4
     * remove app function
     */
    private application remove_application(application head_node, String name) {
        if (head_node == null) {
            return head_node;
        } else {
            if (head_node.getName().equals(name)) {
                return head_node.getNext();
            }
            head_node.setNext(remove_application(head_node.getNext(), name));
            return head_node;
        }

    }

    /*
     * harsukh singh cs 202 assignment 4
     * remove application wrapepr
     */
    public void remove_application(String name) {
        head_node =  remove_application(head_node, name);
    }

    /*
     * harsukh singh cs 202 assignment 4
     * application retrieve
     */
    public application retrieve_applicant(String name) {
        if (head_node == null) {
            throw new RuntimeException("cannot retrieve with null list");
        } else {
            application current = head_node;
            while (current != null) {
                if (current.getName().equals(name)) {
                    return current;
                }
                current = current.getNext();
            }
            return current;
        }
    }
}

