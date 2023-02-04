## Project Description 


	This project uses the MSP430 to create a motion detector which uses the integrated LEDs on the board to notify the user of the presecence of motion within the DIYmall passive infrared sensor's range.
	
	
## Project Goal 


	The goal of this project was to create three states that correspond to the sensor being armed, warning the user of motion, and lastly alerting the user that someone is in the presence of the sensor for an extended period of time. 
	
	
## Inputs 


	The program uses two inputs. The integrated button at pin 4.1 and the sensor connected to pin 2.1. 
```
 P2DIR &= ~BIT1;                        // Set 2.1 as an input
 P4DIR &= ~BIT1;                        // set button 4.1 as an input
 ```
## Outputs

The outputs are both the red and green LEDs which are associated with pins 
## Conclusion

## Submission
There is a sample file in this folder you will need to import into your Code Composer and work on. You will need to submit that file, documented well, and a README.md file (you can replace this one) with the documentation that tells someone about what the code is, what it does, how it works etc. For an audience for your README, imagine you at the beginning of the lab, looking for code which does, well, this. 
