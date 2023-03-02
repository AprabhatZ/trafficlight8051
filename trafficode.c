#include <reg51.h> 


/*
 *
 * Created: 12/7/2022 9:09:35 AM
 * Author :Prabhat Bikram Shah & Anurag Adhikari
 */ 

void delay_ms(unsigned int ms) // Function to create delay in milliseconds
	{
		unsigned int i, j;
			for (i = 0; i < ms; i++)
				for (j = 0; j < 123; j++);
	}
	
int main()
{
	unsigned int delay = 996;
		
	
	//unsigned int ch[]={0x90,0x80,0xF8,0x82,0x92,0x99,0xB0,0xA4,0xF9,0xC0};
	unsigned int ch[]={0xC0,0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	
	unsigned int i;
	unsigned int j;
	
//Set all pins of port 1 as output
 P0 = P0 | 0xFF;
 P2 = P2 | 0xFF;
	
	P1 = P1 | 0xFF;

	

	    while (1)
	    {
				//delay_ms(delay);
				//P1 ^= (1 << 1);
				
				
			P1 = P1 & (~(1<<1));
			P1 = P1 & (~(1<<0));
			P1 =P1 | (1<<2);
			
		    for (j=1; j>0; j--)
		    {	
				
				P0 =ch[j];
			    
			    for (i=10; i>0; i--)
			    {
				    P2 = ch[i];
					delay_ms(delay);
				    
			    }
		    }
			P1 = P1 & (~(1<<2));
			P1 =P1 | (1<<1);
			
			 for (j=1; j>0; j--)
			 {
				 P0 =ch[j];
				 
				 for (i=10; i>0; i--)
				 {
					 P2 = ch[i];
					 delay_ms(delay);
					 
				 }
			 }
			
			P1 = P1 & (~(1<<1));
			P1 = P1 | (1<<0);
			 
			 
			  for (j=2; j>0; j--)
			  {
				  P0 =ch[j];
				  
				  for (i=10; i>0; i--)
				  {
					  P2 = ch[i];
					  delay_ms(delay);
					  
				  }
					
			  }
    }
	}
