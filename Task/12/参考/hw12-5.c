#include <stdio.h>

struct time
{
    int  hour;
    int  minutes;
    int  seconds;
};

// calculate elapsed time (assume t2 is later than t1)

struct time  elapsed_time (struct time  t1, struct time  t2)
{
    
    struct time  result = { 0, 0, 0 };
    
    // first subtract the seconds
    
    result.seconds = t2.seconds - t1.seconds;
    
    // if seconds < 0, need to borrow one minute
    
    if (result.seconds < 0) 
	{
        result.seconds += 60;
        --t2.minutes;
    }
    
    // now subtract the minutes
    
    result.minutes = t2.minutes - t1.minutes;
    
    // if minutes < 0, need to borrow one hour
    
	if (result.minutes < 0)
	{
		result.minutes += 60;
		--t2.hour;
	}
    
    // now subtract the hours
    
    result.hour = t2.hour - t1.hour;
    
    // if hour < 0, need to borrow one day (crossed midnight)
    
    if (result.hour < 0)
        result.hour += 24;
        
        return  result;
}

int main (void)
{
    struct time  elapsed_time (struct time  t1, struct time  t2);
    struct time t1,t2;
    
    scanf("%d %d %d",&t1.hour,&t1.minutes,&t1.seconds);
    scanf("%d %d %d",&t2.hour,&t2.minutes,&t2.seconds);
    
    struct time  result;
    
    result = elapsed_time (t1, t2);
    printf ("Time between %.2d:%.2d:%.2d and %.2d:%.2d:%.2d is %.2d:%.2d:%.2d\n",
            t1.hour, t1.minutes, t1.seconds, t2.hour, t2.minutes,
            t2.seconds, result.hour, result.minutes, result.seconds);
    return 0;  
}  
