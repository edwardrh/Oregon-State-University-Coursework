// File:   barbershop.h

#include <iostream>
#include <queue>
#include <time.h>
#include <pthread.h>
#include <vector>
#include <stdlib.h>

using namespace std;

#ifndef _BARBERSHOP_H
#define	_BARBERSHOP_H

#endif	/* _BARBERSHOP_H */

enum status {ASLEEP, BUSY, AWAKE};

class barbershop {
private:
    const static int MAX_HAIR_TIME = 600000;
    queue<int> chairs;   // A queue of chairs, the int value is the customer ID
    int MAX_CHAIRS;
    int NUM_BARBERS;
    bool shop_state;  // False is closed, true is open
    status* barber_state;  // State of each barber
    clock_t* barber_tosleep; // Times when the barbers went to sleep
    
    pthread_mutex_t mutex;  // Used for mutual exclusion of barbershop data
    pthread_cond_t cond_cust;  // Used to synchronize the customers in the shop
    pthread_cond_t* cond_barber; // Used to synchronize the barbers, this is an array
    
public:
    barbershop();
    void cleanup();
    
    void open(int num_chairs, int num_barbers);
    void close();
        
    void cut_hair(int barber_id);
    
    bool get_hair_cut(int cust_id);
    
};
