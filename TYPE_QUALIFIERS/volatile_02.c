struct Nec { 
	int x; 
	const int cx; 
} nec;

//the type of nec.x is int  
//the type of nec.cx is const int  

volatile struct Nec vnec;

//the type of vnec.x is volatile int  
//the type of vnec.cx is const volatile int  
