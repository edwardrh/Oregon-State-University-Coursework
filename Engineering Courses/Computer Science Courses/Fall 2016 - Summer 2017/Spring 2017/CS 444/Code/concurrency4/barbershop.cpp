// File:   barbershop.cpp

#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <vector>
#include "barbershop.h"

/*
 * barbershop constructor
 * Initialize the mutex and condition variables.
 */
barbershop::barbershop() {
    pthread_mutex_init(&this->mutex, NULL);
    pthread_cond_init(&this->cond_cust, NULL);
}

/*
 * This method opens the barbershop for business.
 * Sets MAX_CHAIRS
 * Inits Barber to sleeping state
 * Sets shop_state to open.
 * A lock was obtained so that no other method could manipulate the data.
 */
void barbershop::open(int num_chairs, int num_barbers) {
    // Only perform when shop is closed
    if (!this->shop_state) {
        pthread_mutex_lock(&mutex);
		
        // Set up the conditional variables
        this->NUM_BARBERS = num_barbers;
        this->cond_barber = new pthread_cond_t[this->NUM_BARBERS];
        this->barber_tosleep = new time_t[this->NUM_BARBERS];
        this->barber_state = new status[this->NUM_BARBERS];
		
        for (int i = 0; i < this->NUM_BARBERS; i++) {
            pthread_cond_init(&this->cond_barber[i], NULL);
			
			//Init sleep time
            this->barber_tosleep[i] = clock();  
            this->barber_state[i] = ASLEEP;
        }
        
        this->MAX_CHAIRS = num_chairs;
        this->shop_state = true;
        pthread_mutex_unlock(&mutex);
        cout << "Welcome! Today we have " << num_chairs
                << " seats" << endl;
    }
}

/*
 * This method will close the barbershop
 * It sends out signals for condition varibable cond_barber
 */
void barbershop::close() {
    pthread_mutex_lock(&mutex);
    cout << "Closing Shop" << endl;
    this->shop_state = false;
	
    if (this->chairs.size() <= 0) {
        for(int i = 0; i < this->NUM_BARBERS; i++) {
            pthread_cond_signal(&this->cond_barber[i]);
        }
    } else {
        cout << "Error: there are still customers" << endl;
    }
	
    pthread_mutex_unlock(&mutex);
    cout << "Barber Shop is now closed."
            << endl;
}

/*
 * Cleanup, delete unneeded variables and such.
 */
void barbershop::cleanup() {
    for(int i = 0; i < this->NUM_BARBERS; i++) {
        pthread_cond_destroy(&this->cond_barber[i]);
    }
	
    pthread_cond_destroy(&this->cond_cust);
    pthread_mutex_destroy(&this->mutex);
    delete[] this->cond_barber;
    delete[] this->barber_state;
    delete[] this->barber_tosleep;
}

/*
 * This is the method to perform the hair cuts
 */
void barbershop::cut_hair(int barber_id) {
    // Continuous loop while shop is open
    while( this->shop_state ) {
        pthread_mutex_lock(&mutex);
		
        if (this->chairs.size() > 0) {
            // Pop off queue, get element
            int cust_id = this->chairs.front(); 
			// Remove element
            this->chairs.pop();     
            this->barber_state[barber_id] = BUSY;
            
            pthread_mutex_unlock(&mutex);
            // Random wait time for hair cut
            int r = rand();
            int wait = r % this->MAX_HAIR_TIME;
			// Sleep for microseconds
            usleep(wait);   
            pthread_mutex_lock(&mutex);
            
            cout << "  Customer " << cust_id - 1 << " is finished with hair cut "
                    << "from barber " << barber_id << endl;
            pthread_cond_signal(&this->cond_cust);
			
        } else {
            cout << " Barber " << barber_id << " going to sleep, no customers."
                    << endl;
            this->barber_state[barber_id] = ASLEEP;
            // Set the time Barber went to sleep
            this->barber_tosleep[barber_id] = clock();
            pthread_cond_wait(&this->cond_barber[barber_id], &mutex);  //wait on specific barber
            this->barber_state[barber_id] = AWAKE;
        }
        pthread_mutex_unlock(&mutex);
    }
}

/*
 * This method will wake the barber if asleep, put the customer
 * in a chair, or send the customer away.
 * A hair cut should take a random amount of time less than MAX_HAIR_TIME
 */
bool barbershop::get_hair_cut(int cust_id) {
    bool got_in = false;
    pthread_mutex_lock(&mutex);
    cout << "  Customer " << cust_id - 1 << " enters the shop." << endl;
    
	// Only proceed if shop is open
    if (this->shop_state) {
        
		if (this->chairs.size() < this->MAX_CHAIRS) {
            // Check if Barber is sleeping
            // Wake up the Barber
            int max_bID = 0;    
            double max_sleeptime = 0.0;
            time_t now;
            time(&now);
            bool asleep = false;
            
			for(int i = 0; i < this->NUM_BARBERS; i++) {
                
				if (this->barber_state[i] == ASLEEP) {
                    asleep = true;
                    // Find sleep time for barber
                    double diff = difftime(now, this->barber_tosleep[i]);
                    
					if (diff > max_sleeptime) {
                        max_sleeptime = diff;
                        max_bID = i;
                    }
                }
            }
			
            if (asleep) {
                cout << "  Customer " << cust_id - 1 << " wakes up Barber "
                        << max_bID + 1 << endl;
                // Signal barber
                pthread_cond_signal(&this->cond_barber[max_bID]);
            }
           
            // Add customer to the queue of chairs
            this->chairs.push(cust_id);
            pthread_cond_wait(&this->cond_cust, &mutex);
            got_in = true;
			
        } else {
            cout << "  Customer " << cust_id - 1 << " leaves (shop is full)." << endl;
        }
        
    } else {
        cout <<  "  customer " << cust_id - 1 << " leaves (shop is closed)." << endl;
    }
	
    pthread_mutex_unlock(&mutex);
    return got_in;
}
