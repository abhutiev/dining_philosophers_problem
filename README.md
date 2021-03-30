# dining_philosophers_problem

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation.

# It's a perfect task to learn multithreading. So, common rules for all three version in this repo:

• Philosophers are sitting at a round table and doing three things: eating, sleeping, thinking

• There are as many forks at the table as there are philosophers

• While eating, they are not thinking or sleeping, while sleeping, they are not eating

• Spaghetti is available for every philosopher at the table, but to eat, philo should take two forks

• The philosophers must never be starving, if philosopher not eating more than [time_to_die], he dies

• Philosophers don’t speak with each other, so they don't know when another philosopher is about to die

• Each time a philosopher has finished eating, he will drop his forks and start sleeping

• When a philosopher is done sleeping, he will start thinking

• He can stop thinking when he able to start eating

• The simulation stops when a philosopher dies

• Each program should have the same options:

    • number_of_philosophers: is the number of philosophers and also the number of forks.
  
    • time_to_eat:  time in ms it takes for a philosopher to eat. During that time he will need to keep the two forks, obviously.
  
    • time_to_sleep: time in ms the philosopher will spend sleeping.
    
    • [number_of_times_each_philosopher_must_eat]: optional. If all philosophers eat at least this times the simulation should stop.
  
# Non-common rules for cases

# philo_one

In this version the non common rules will be:

• One fork between each philosopher, therefore there will be a fork at the right and
at the left of each philosopher.

• To avoid philosophers duplicating forks, you should protect the forks state with a
mutex for each of them.

• Each philosopher should be a thread.

# philo_two

In this version the non common rules will be:

• All the forks are in the middle of the table.

• They have no states in memory but the number of available forks is represented by
a semaphore.

• Each philosopher should be a thread.

# philo_three

In this version the non common rules will be:

• All the forks are in the middle of the table.

• They have no states in memory but the number of available forks is represented by
a semaphore.

• Each philosopher should be a process and the main process should not be a philosopher.
