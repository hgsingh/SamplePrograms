import java.util.Scanner;
//@author harsukh singh
//implementation of a binary search tree in java
//the root of the tree represents an application (by composition)
public class BST {
	
	private application root;//root is defined as a reference to an application
	
	//@author harsukh singh
	//default constructor
	public BST()
	{
		root = null; //default constructor sets the roots value to null
	}
	
	//@author harsukh singh
	//copy constructor 
	public BST(BST src)
	{
		copy_bst(src.root);
	}
	
	//@author harsukh singh
	//copy binary tree wrapper function
	public void copy_bst(application src)
	{
		root = copy_bst(root, src);
	}
	
	//@author harsukh singh
	//copy binary search tree function, copies entire binary search tree 
	private application copy_bst(application dest, application src)
	{
		if(src == null)
		{
			return null;
		}
		if(src instanceof work_application)
			dest = new work_application((work_application) src);
		else
			dest = new technical_application((technical_application) src);
		dest.setLeft(copy_bst(dest.getLeft(), src.getLeft()));
		dest.setRight(copy_bst(dest.getRight(), src.getRight()));
		return dest;
	}
	
	//@author harsukh singh
	//copy binary search tree function, copies entire binary search tree 
	public void insert_bst(application to_insert)
	{
		root = insert_bst(root, to_insert);
	}
	
	//@author harsukh singh
	//copy binary search tree function, copies entire binary search tree 
	private application insert_bst(application root, application to_insert)
	{
		if(root == null)
		{
			root = to_insert;
			return root;
		}
		else
		{
			if(root.getScore() <= to_insert.getScore())
			{
				root.setRight(copy_bst(root.getRight(), to_insert.getRight()));
			}
			else
			{
				root.setLeft(copy_bst(root.getLeft(), to_insert.getLeft()));
			}
		}
		return root;
	}
	
	//@author harsukh singh
	//display wrapper function
	public void display()
	{
		display(root);
	}
	
	//@author harsukh singh
	//recursive inorder display function
	public void display(application root)
	{
		if(root == null)
		{
			return;
		}
		display(root.getLeft());
		root.display();
		display(root.getRight());
	}
	
	//@author harsukh singh
	//recursive retrieve function that retrieves based on key value and 
	//recurses based on score
	private application retrieve(application root, int key, int score)
	{
		if(root == null)
		{
			return null;
		}
		else if(root.getScore() <= score && key != root.getKey())
		{
			return retrieve(root.getRight(), key, score);
		}
		else if(root.getScore() > score && key != root.getKey())
		{
			return retrieve(root.getLeft(), key, score);
		}
		return root;
	}
	
	
	//@author harsukh singh
	//wrapper function for the retrieve, can edit the application if the user wants
	public void edit(int key, int score)
	{
		Scanner in = new Scanner(System.in);
		application temp = retrieve(root, key, score);
		temp.display();
		System.out.println("would you like to edit the application? possible fields to edit are jobs or class applying for.");
		char choice  = in.nextLine().charAt(0);
		choice = Character.toLowerCase(choice);
		if(choice == 'y')
		{
			if(temp instanceof work_application)
			{
				System.out.println("Would you like to add a new job? Please press 'y'.");
				char add_jobs = in.nextLine().charAt(0);
				add_jobs = Character.toLowerCase(add_jobs);
				while(add_jobs == 'y')
				{
					((work_application) temp).insert_job();
					System.out.println("Would you like to add another job? Please press 'y'.");
					add_jobs = in.nextLine().charAt(0);
					add_jobs = Character.toLowerCase(add_jobs);
				}
				System.out.println("Would you like to remove a job? please press 'y'");
				add_jobs = in.nextLine().charAt(0);
				add_jobs = Character.toLowerCase(add_jobs);
				while(add_jobs == 'y')
				{
					System.out.println("Please press the job title to remove.");
					String job_title = in.nextLine();
					System.out.println("Please press the company of the job to remove.");
					String company = in.nextLine();
					((work_application) temp).remove_job(company, job_title);
					System.out.println("Would you like to remove another job? Please press 'y' or anything to quit.");
					add_jobs = in.nextLine().charAt(0);
					add_jobs = Character.toLowerCase(add_jobs);
				}
			}
			System.out.println("If you would like to change the class applying for please press 'y'.");
			char remove_class = in.nextLine().charAt(0);
			remove_class = Character.toLowerCase(remove_class);
			if(remove_class == 'y')
			{
				System.out.println("Enter the class applying for");
				String position_applying_for = in.nextLine();
				temp.setPosition_applying_for(position_applying_for);
			}
		}
	}
	
	//@author harsukh singh
	//wrapper function for the remove function that takes a key and the score of the application (grade in CS 202)
	public void remove(int key, int score )
	{
		root = remove(root, key, score);
	}
	
	//@author harsukh singh
	//replace the application with the inorder successor 
	//returns the value of the inorder successor and replaces root with that value
	private application replace(application root)
	{
		if(root.getLeft() == null)
		{
			application to_replace;
			if(root instanceof work_application)
				to_replace = new work_application((work_application) root);
			else
				to_replace = new technical_application((technical_application) root);
			return to_replace;
		}
		else
		{
			return replace(root.getLeft());
		}
	}
	
	//@author harsukh singh
	//removes a particular node from the application, both the replace and remove work in synchronously to remove a node from the 
	//binary search tree.
	private application remove(application root, int key, int score)
	{
		if(root == null)
		{
			return null;
		}
		else if(root.getKey() == key && root.getScore() == score)
		{
			if (root.getLeft()==null)
				return root.getRight();
			else if (root.getRight()==null)
				return root.getLeft();
			else{ 
				application l = root.getLeft();
				application r = root.getRight();
				root = replace(root.getRight());
				root.setLeft(l);
				root.setRight(r);
				root.setRight(remove (root.getRight(), root.getKey(), root.getScore()));
				return root;	
			}
		}
		else{
			if(root.getScore() <= score && key != root.getKey())
			{
				root.setRight(retrieve(root.getRight(), key, score));
			}
			else
			{
				root.setLeft(retrieve(root.getLeft(), key, score));
			}
			return root;
		}
	}
}
