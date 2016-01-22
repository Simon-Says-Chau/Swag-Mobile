#Swag-Mobile

This project is a basic attempt at utilizing arduinos and a spark core to create moving vehicles to play tag.  

#Description

To make this project, one Arduino board was used to program the moving vehicle while the spark core was used to receive and transmit data for movement.  The goal of the game is tag where one vehicle is the chaser and the other vehicle is the runner.  We use Infrared Transmitter to determine whether or not a vehicle was officially "tagged" or not.

Vehicles have basic movement, forward, backwards, turn left, and turn right.  These movements are powered by commands issued via a JavaScript command prompt.  Using the input "particle call <name_of_core> <function>" the spark core is able to run what the given function is programmed to do.  Either a 9V battery or a USB connector, powered the vehcile itself to function.

#Bugs

Some errors that we had were detecting specific values for the Infrared Transmitters.  We did not consider the IR light from the Sun and our values varied greatly due to exposure of various frequencies of light.  
