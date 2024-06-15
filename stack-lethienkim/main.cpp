/* ******************************************
 * File:   main.cpp
 * Author: Thienkim Le
 * Purpose of the file:
 * The purpose of the code in this file is to accept command-line arguments specifying the
 * size of a stack, create a stack with the specified size, and perform various tests on
 * the stack's functionality, including testing for underflow, overflow, and mid-stack scenarios.
 ********************************************/

#include "main.h"


int main(int argc, char **argv) {

    /*********************************************
    * This function serves as the entry point for the program.
    * It accepts command-line arguments, creates a stack with
    * the specified size, and performs various tests on the stack.
    *
    * @param argc : The number of command-line arguments.
    * @param argv : An array of command-line argument strings.
    *
    * @return 0 on successful execution.
    *
    * @note Ensure correct usage of the program by providing the
    * required command-line arguments. The function tests
    * stack functionality for underflow, overflow, and
    * mid-stack scenarios.
    *********************************************/

    int ret = 0;

    srand(time(NULL));

    // Extract stack size from command line argument
    int stackSize = std::atoi(argv[1]);

    //Ensure correct usage of the program
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <stack_size>" << std::endl;
        ret = 1;
    }
    // Check if stack size is valid
    else if (stackSize <= 0) {
        std::cerr << "Error: Stack size must be a positive integer." << std::endl;
        ret = 1;
    }
    else
    {

        // Create stack
        Stack stack(stackSize);



        // generic int used for testing
        int value;

        // counters for tests
        int is_empty = 0;
        int peeked = 0;
        int popped = 0;
        int pushed = 0;
        std::string some_string = "your_string_here";

        std::cout << "Beginning tests..." << std::endl;

		/************************************************
		 * UNDERFLOW TESTS
		 ************************************************/
		
		std::cout << "  underflow tests ==> ";
		
		// Perform push operations on the stack
		for (int i = 0; i < STACKMAX * MULTIPLIER; ++i) {
			if (stack.isEmpty()) {
		        // should always increment
		        is_empty++;
		    } else if {
		        is_empty--;
		    } else{
		    	peeked--;
			}
	
		    Data peekedData;
		    if (stack.peek(peekedData)) {
		        peeked++;
		    }else {
		    	peek--;
			}
		    
		    
		    try {
		    	value = stack.pop();
		    	poped++;
			}catch(...){
				poped--;
			}
		    
			// Perform peek and pop operations
			Data poppedData;
		    if (stack.pop(poppedData)) {
		    	
		        popped++;
		    }
		    else {
		        popped--;
		        
		    Data peekedData;
		    if (stack.peek(peekedData)) {
		        peeked++;
		    }
			}
		}
		
		if (stack.push(i + 1, some_string)) {
		                // should always increment
		                pushed++;
		
		                if (stack.peek(peekedData)) {
		                    peeked++; // should always increment
		                } else {
		                    peeked--;
		                }
		
		                if(stack.pop(poppedData)) {
		                    popped++;
		                }
		                else {
		                    popped--;
		                }
		
		            } else {
		                pushed--;
		            }
		        }
		
		
		// Display results
		std::cout << "popped = " << popped<< " ";
		std::cout << "peeked = " << peeked<< " ";
		std::cout << "pushed = " << round(STACKMAX * MULTIPLIER)<< " ";
		std::cout << "is_empty = " << is_empty<< " ";

		if (popped == 0 &&
            peeked == 0 &&
            pushed == round(STACKMAX * MULTIPLIER) &&
            is_empty == round(STACKMAX * MULTIPLIER)) {
            std::cout << "pass" << std::endl;
        } else {
            std::cout << "failed" << std::endl;
        }

		
/****
        std::cout << "  overflow tests ==> ";

        // reset counters for tests
        is_empty = 0;
        peeked = 0;
        popped = 0;
        pushed = 0; 
        std::cout << " popped" << popped;
        std::cout << " peeked" << peeked;
        std::cout << " pushed" << pushed;
        std::cout << " is_empty" << is_empty;
        // fill stack
        for (int i = 0; i <= STACKMAX; i++) { 
            value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number
            stack.push(value, some_string);
        }

        for (int i = 0; i < STACKMAX*MULTIPLIER; i++) {

            if (stack.isEmpty()) {
                is_empty++;
            } else {
                // should always decrement
                is_empty--;
            }

            Data peekedData;
            if(stack.peek(peekedData)){
                peeked++;
            } else {
                peeked--;
            }
            
            Data poppedData;
            Try{
                value = stack.pop(poppedData);
                popped ++;
            } catch(...){
                popped--;
            }   

            if (stack.push(i + 1, some_string)) {
                // should always increment
                pushed++;
            } else{
                pushed--;
            }

            if (stack.push(i + 1, some_string)) {
                // should always increment
                pushed++;
            } else{
                pushed--;
            }
        }
        std::cout << " popped" << popped;
        std::cout << " peeked" << peeked;
        std::cout << " pushed" << pushed;
        std::cout << " is_empty" << is_empty;
        // notice these numbers are logical
        // in overflow,
        if(popped == round(STACKMAX*MULTIPLIER) &&
            peeked == round(STACKMAX*MULTIPLIER) &&
            pushed == 0 && 
            -is_empty == round(STACKMAX*MULTIPLIER)) {
            std::cout << "pass" << std::endl;
        } else {
            std::cout << "failed" << std::endl;
        }

        /************************************************
        ******** EMPTYING AND MORE UNDERFLOW TESTS ******
        ************************************************/
/****
        // reset counters for tests
        is_empty = 0;
        peeked = 0;
        popped = 0;
        pushed = 0;

        std::cout << "  empty and more underflow tests ==> ";

        std::cout << "popped" << popped;
        std::cout << " peeked" << peeked;
        std::cout << " pushed" << pushed;
        std::cout << " is_empty    " << is_empty;

        // emptying stack
        for (int i = 0; i < STACKMAX+1; i++) {
            if(stack.isEmpty()){
                is_empty++;
            } else {
                is_empty--;
            }

            Data peekedData;
            if(stack.peek(peekedData)){
                peeked++;
            } else {
                peeked--;
            }

            Data poppedData;
            try {
                value = stack.pop(poppedData);
                popped++;

            } catch (...) {
                popped--;
            }
        }

        std::cout << "popped" << popped;
        std::cout << " peeked" << peeked;
        std::cout << " pushed" << pushed;
        std::cout << " is_empty    " << is_empty;

        if(popped == STACKMAX-1 &&
            peeked == STACKMAX -1 &&
            pushed == 0 &&
            -is_empty == STACKMAX -1) {
            std::cout << "pass" << std::endl;
        }
        else {
            std::cout << "failed" << std::endl;
        }

        /************************************************
        ******** MID-STACK TESTS ************************
        ************************************************/
/***
        // reset counters for tests
        is_empty = 0;
        peeked = 0;
        popped = 0;
        pushed = 0;

        // need a stack of reasonable size
        // to perform tests
        std::cout << "  mid-stack tests ==> ";

        std::cout << "popped" << popped;
        std::cout << " peeked" << peeked;
        std::cout << " pushed" << pushed;
        std::cout << " is_empty    " << is_empty;

        if(STACKSIZE >= 4){

            // fill stack half-way
            for (int i = 0; i< int(STACKMAX / 2); i++) {
                // using positive and negative "big" numbers
                value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                rand_string(&some_string);
                stack.push(value, some_string);
            }

            for (int i = 0; i < STACKMAX*MULTIPLIER; i++) {
                if(stack.isEmpty()){
                    is_empty++;
                } else {
                    is_empty--;
                }
                Data peekedData;
                if(stack.peek(peekedData)){
                    peeked++;
                } else {
                    peeked--;
                }
                Data poppedData; // Declare a variable to store the popped data
                try {
                    value = stack.pop(poppedData);
                    popped++;
                } catch (...) {
                    popped--;
                }
                // using positive and negative "big" numbers
                value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                rand_string(&some_string);
                if(stack.push(value, some_string)){
                    pushed++;
                } else {
                    pushed--;
                }
            }

            std::cout << "popped" << popped;
            std::cout << " peeked" << peeked;
            std::cout << " pushed" << pushed;
            std::cout << " is_empty    " << is_empty;

            // notice these numbers are logical
            // in mid-stack, we should expect these numbers
            if(popped == round(STACKSIZE*MULTIPLIER) &&
                peeked == round(STACKSIZE*MULTIPLIER) &&
                pushed == round(STACKSIZE*MULTIPLIER) &&
                -is_empty == round(STACKSIZE*MULTIPLIER)) {
                std::cout << "pass" << std::endl;
            } else {
                std::cout << "failed" << std::endl;
            }

        } else{
            std::cout << "skipped, stack too small" << std::endl;
        }


        /************************************************
        ******** RANDOM TESTS ***************************
        ** essentially this is only a crash test ********
        *************************************************/


/***
        std::cout << "  random testing ==> ";

        Data data; // Variable to store popped data

        // Clearing stack to start
        while (!stack.isEmpty()) {
           
            stack.pop(data);
            popped++;

        }

        std::cout << "popped" << popped;
        std::cout << " peeked" << peeked;
        std::cout << " pushed" << pushed;
        std::cout << " is_empty    " << is_empty;

        // Filling the stack halfway with random numbers to begin random tests
        for (int i = 0; i < STACKSIZE / 2; i++) {
            int value = rand() % MAX_INT + 1;
            stack.push(value, "test");
        }

        // The following will test random operations. push() and pop()
        // are called twice as often as peek and isempty because they
        // change the stack and should be tested more rigorously.
        // The point of these tests are a "crash test." If it runs
        // and the code does not crash, we just assume success.
        // We don't check operations, we don't care now, we just want
        // to observe the code does not crash.
        int choice = rand() % CHOICES + 1;
        for (int i = 0; i < STACKSIZE * RANDOM_MULTIPLIER; i++) {
            int value;
            switch (choice) {
            case 1:
            case 2:
                // Push
                value = rand() % MAX_INT + 1;
                stack.push(value, "test");
                break;
            case 3:
            case 4:
                // Pop
                
                try {
                    value = stack.pop(data);
                } catch (...) {
                    // Do nothing because we don't
                    // care about this case now and we
                    // expect it to happen sometimes
                }
                break;
            case 5:
                // Peek
                stack.peek(data);
                break;
            case 6:
                // IsEmpty
                stack.isEmpty();
                break;
            }
            choice = rand() % CHOICES + 1;
        }

        std::cout << "popped" << popped;
        std::cout << " peeked" << peeked;
        std::cout << " pushed" << pushed;
        std::cout << " is_empty    " << is_empty;

        // If we made it here, no crash
        std::cout << "pass" << std::endl;

        std::cout << "Testing complete." << std::endl;
    }
***/
	}
    return ret;
}