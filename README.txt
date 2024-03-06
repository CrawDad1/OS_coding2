# Operating Systems : Coding Assignment 2

This is a coding assignment for the Operating Systems course at WSU

This code defines both a Process and Scheduler class, each with a static member to keep track of unique ID's within each class type. 

Each Scheduler maintains a list of pointers to Process type objects. 

when creating a process, it is given 5 tickets in sequence based on the Scheduler::next_ticket variable. then, a pointer to this new process is added to Scheduler::p_list.

when drawing lottery tickets, a Scheduler checks the tickets held by each process in that scheduler's p_list. When a match is found, Process.Run() is called for the matching process. 

