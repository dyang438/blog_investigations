#include <iostream>
#include <string>

clock_t timer_start_time (std::string test_name)
{
	std::cerr<<"\n_________________\n"<<test_name<<"\n";
	return clock();
}


double timer_end_time (std::string test_name, clock_t start_time)
{
	clock_t end_time = clock();
	double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	std::cerr<<"Time spent in " <<test_name<<": "<<time_spent<<" seconds\n_________\n";
	std::cout<<time_spent<<"\n";
	return time_spent;
}
