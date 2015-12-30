//@author harsukh singh homework 5 cs201

#include <stdio.h>
#include <stdlib.h>
//structure and function prototypes
typedef unsigned int mem_address; //define mem_address to use later when calculating addresses

//define struct here for the cache line
typedef struct
{
    unsigned int valid; //used for the valid bit
    mem_address tag; //used for the tag bits
    int  time_store; //least recently used
}cache_line;

void delete_all(cache_line **to_delete, int size); //destructor
int compute_exp(int to_compute); //compute exponential

//main declaration
int main (int argc, char ** argv) {
    //check arguments that are passed into main
    if (argc != 6) {
        printf ("Usage: program <int> <int> <int> <int> <int>\n");
        exit (-1);
    }
    int set_size = atoi(argv[1]); //convert args to ints
    int line_size = atoi(argv[2]);
    int block_size = atoi(argv[3]);
    int hit_time = atoi(argv[4]);
    int miss_time = atoi(argv[5]);

    //check arguments if the arguments are not valid then exit
    if(set_size <= 0)
    {
        printf("set size cannot be zero.");
        exit(0);
    }
    if(line_size <= 0)
    {
        printf("number of lines cannot be zero.");
        exit(0);
    }
    if(block_size <= 0)
    {
        printf("block size cannot be zero.");
        exit(0);
    }
    if(hit_time < 0)
    {
        printf("hit time cannot be less than zero.");
        exit(0);
    }
    if(miss_time < 0)
    {
        printf("miss time cannot be less than zero.");
        exit(0);
    }

    //find parameters related to cache based on inputs
    int s = compute_exp(set_size);//computes log base 2
    int b = compute_exp(line_size); //computes log base 2
    unsigned int m = 32; //we are simulating a 32 bit memory address cache since the program is compiled with -m32 flag
    mem_address tag_size = m -(s + b); //find number of tag bits
    cache_line* l1[set_size]; //cache block size

    //declare variables that need to be used 
    int miss_counter = 0; 
    int hit_counter = 0;
    int total_cycles = 0;
    int i;
    int j;
    
    //allocating memory array of arrays
    for(i = 0; i<set_size;++i)
    {
        l1[i] = malloc(line_size * sizeof(cache_line));
        for(j = 0; j< line_size; ++j)
        {
            l1[i][j].valid = 0;
            l1[i][j].time_store = 0;
        }
    }

    mem_address memory; //memory for the read in
    while(scanf("%x", &memory) == 1 || scanf("0x%x", &memory) == 1) //scanf reading from stdin
    {
        mem_address tag_bits = memory >> (s + b); //shift to read for the tag bits
        mem_address temp = memory << tag_size; //shift for finding the temp
        mem_address id_bits = temp >> (tag_size + b); //find the id bits for the set
        printf("tag bits : %d\n", tag_bits); //these prints are commented out since they're not used
        printf("id bits : %d\n", id_bits);
        printf("memory address: %d\n", memory);
        printf("memory address in hex: %x\n", memory);
        cache_line* iterator = l1[id_bits]; //point at the current set id
        int i; //index for loop
        int check = hit_counter; //check for counter
        for(i = 0; i< line_size; ++i)
        {
            if(iterator->valid == 1 && iterator ->tag == tag_bits) //if valid and tags match
            {
                ++hit_counter; //increment hit counter and then break
                total_cycles = total_cycles + hit_time; //increment the hit time
                iterator->time_store = iterator->time_store + 1; //increment the tag bits
                break;
            }
            iterator = iterator + 1; //increment iterator
        }
        if((hit_counter - check) == 0) //hit was not found
        {
            ++miss_counter; //increment miss counter
            total_cycles = total_cycles + miss_time; //update the total cycles
            iterator = l1[id_bits];//find lru start here
            int i; //index for loop
            int index = 0; //index containing the smallest lru
            int lru = iterator -> time_store; // store the current time
            for(i = 0; i<line_size; ++i) //iterate throught the array to find the least lru
            {
                if(iterator->time_store <= lru) //check lru here
                {
                    index = i; //get index here
                }
                iterator = iterator + 1; //increment iterator
            }
            iterator = l1[id_bits]; //go back to top of array
            iterator[index].valid = 1; //set valid bits
            iterator[index].time_store =  iterator[index].time_store + 1; //increment the time store
            iterator[index].tag = tag_bits; //update the tag bits
        }
    }

    //computer the total miss and hits
    int total = miss_counter + hit_counter;
    float miss_rate = (float)miss_counter/(float)total;

    //print values here
    printf("Number of hits = %d\n", hit_counter);
    printf("Number of misses = %d\n", miss_counter);
    printf("Miss rate = %4.2f %% \n", (double)miss_rate*100);
    printf("Total cycles = %d \n", total_cycles);

    //destroy allocated memory
    delete_all(l1, set_size);
    return 0;
}


//@author harsukh singh
//computes a logarithm base 
int compute_exp(int to_compute)
{
    int count = -1;
    while(to_compute)
    {
        to_compute = to_compute >> 1;
        ++count;
    }
    return count;
}

//@author harsukh singh
//delete all function will delete the cache lines in the 
//array of pointers
void delete_all(cache_line **to_delete, int size)
{
    if(to_delete == NULL)
    {
        return;
    }
    int i;
    for(i = 0; i<size; ++i)
    {
        if(to_delete[i] != NULL)
        {
            free(to_delete[i]);
        }
    }
}
