# PID Control on Simulated Vehicles

The final video of the simulated vehicles controled by my PID controler is here below.
[![IMAGE ALT TEXT](http://img.youtube.com/vi/0H8ghKrc0Cw/0.jpg)](https://youtu.be/0H8ghKrc0Cw "a small networkd ")

## Reflection 
### 1. Describe the effect each of the P, I, D components had in your implementation.
The P component provides a steering angle that is proportional to the cross-track error (CTE). High P component coeffient results in large change in output and leads to unstable system. Using P component alone will cause overshooting problem, and results in larger and larger oscillations.

The D component changes the steering angle proportional to the change of the CTE. It can cancel the overshoting probleblem when a proper D component cofficient value is chosen.

The I component changes the steering angle proportional to the integrated value of the CTE. It can compensate the small bias that the P component can not handle.

### 2. Describe how the final hyperparameters were chosen.

The final hyperparameters were chosen by manual tuning iteratively, even though the Twiddle code is there but did work very well in my case. 
* Started by setting all PID coefficients 0, the car would drive completely straight with no error response. 
* Then increased the P component until it demonstrated a significant response to the cross-track error. I settled at 0.1 for P componet coeffient.
* The oscillations of the car increase over time with only P component. So I increased the D component of the PID until the  the car did not go outside the track. Finally 3.0 was used for the D component.
* Finaly incremented the I component to make the responses a little bit smoother. A value of 0.003 was sufficient. The final performance can be seen above in the video link.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
